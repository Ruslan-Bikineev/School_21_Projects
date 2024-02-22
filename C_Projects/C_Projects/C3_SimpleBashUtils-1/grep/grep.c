#include "grep.h"

void changeFlags(FLAGS *flags, int argc, char *argv[]) {
  int opt;
  opterr = 0;  // Отключаем вывод ошибок getopt в stderr
  while ((opt = getopt(argc, argv, "e:f:ivclnhso")) != -1) {
    switch (opt) {
      case 'e':
        flags->e = true;
        break;
      case 'i':
        flags->cflags = REG_ICASE;
        break;
      case 'v':
        flags->v = true;
        break;
      case 'c':
        flags->c = true;
        break;
      case 'l':
        flags->l = true;
        break;
      case 'n':
        flags->n = true;
        break;
      case 'h':
        flags->h = true;
        break;
      case 's':
        flags->s = true;
        break;
      case 'f':
        flags->f = true;
        break;
      case 'o':
        flags->o = true;
        break;
      default:
        flags->ERROR = true;
        break;
    }
  }
}

void firstTask(FLAGS flags, char *argv[], int argc) {
  optind = (!(flags.e) && !(flags.f)) ? optind + 1 : optind + 0;
  int firstFile = optind, numPattern = firstFile - 1;
  int sumFiles = argc - firstFile;
  for (int numberFile = firstFile; numberFile < argc; numberFile++) {
    FILE *fPtr = fopen(argv[numberFile], "r");
    if (fPtr == NULL) {
      if (!(flags.s)) {
        fprintf(stderr, "ERROR: File %s could not be found!\n",
                argv[numberFile]);
      }
    } else {
      regex_t regex;
      int errComp = 1;
      char *patternPtr = "[]";
      if (flags.f || flags.e) { /* Implementation flag -f and -e */
        patternPtr = flagFAndE(argc, argv);
        if (patternPtr == NULL) {
          fprintf(stderr, "ERROR: File %s is empty or not found file!\n",
                  argv[numPattern]);
          free(patternPtr);
          patternPtr = NULL;
        }
      } else {
        patternPtr = argv[numPattern];
      }
      if (patternPtr != NULL) {
        /* Функция regcomp предназначена для компиляции рег. выражения */
        errComp = regcomp(&regex, patternPtr, flags.cflags);
        if (errComp != 0) {
          fprintf(stderr, "ERROR: Compliling regex %d.\n", errComp);
        } else {
          secondTask(flags, fPtr, regex, argv, numberFile, sumFiles);
          regfree(&regex);
        }
        if (flags.e || flags.f) {
          free(patternPtr);
        }
      }
      fclose(fPtr);
    }
  }
}

void secondTask(FLAGS flags, FILE *fPtr, regex_t regex, char *argv[],
                int numberFile, int sumFiles) {
  char *linePtr = NULL;
  size_t len = 0;
  ssize_t read;
  regmatch_t pmatch;
  int countEqual = 0, countUnEqual = 0, countLine = 1, errComp = 1;
  for (; (read = getline(&linePtr, &len, fPtr)) != -1; countLine++) {
    errComp = regexec(&regex, linePtr, 1, &pmatch, 0);
    /* Implementation flag v */
    if (!(errComp == 0) && flags.v) {
      countUnEqual++;
      if (!(flags.c) && !(flags.l) && !(flags.o)) {
        firstPrintLine(flags, argv, numberFile, linePtr, sumFiles, countLine,
                       read);
      }
    } else if (errComp == 0 && !(flags.c) && !(flags.l) && !(flags.v)) {
      if (flags.o) { /* Implementation flag o*/
        flagO(flags, linePtr, regex, pmatch, argv, numberFile, countLine,
              sumFiles);
        /* Implementation flags e, i, h, s, f, n */
      } else {
        firstPrintLine(flags, argv, numberFile, linePtr, sumFiles, countLine,
                       read);
      }
    } else if (errComp == 0 && *linePtr != '\n') {
      countEqual++;
    }
  }
  /* Implementation flag -l and -c */
  secondPrintLine(flags, argv, numberFile, countEqual, countUnEqual, sumFiles);
  free(linePtr);
}

void firstPrintLine(FLAGS flags, char *argv[], int numberFile, char *linePtr,
                    int sumFiles, int countLine, ssize_t read) {
  if (sumFiles > 1 && !(flags.h)) {
    printf("%s:", argv[numberFile]);
  }
  if (flags.n) {
    printf("%d:", countLine);
  }
  (10 != *(linePtr + read - 1) ? printf("%s\n", linePtr)
                               : printf("%s", linePtr));
}

void secondPrintLine(FLAGS flags, char *argv[], int numberFile, int countEqual,
                     int countUnEqual, int sumFiles) {
  /* Implementation flags -l whithout -v */
  if (flags.l && !(flags.v) && countEqual > 0) {
    printf("%s\n", argv[numberFile]);
    /* Implementation flags -l and-v */
  } else if (flags.l && flags.v && countUnEqual > 0) {
    printf("%s\n", argv[numberFile]);
    /* Implementation flags -c whithout -v whithout -l */
  } else if (flags.c && !(flags.v) && !(flags.l)) {
    if (sumFiles > 1 && !(flags.h)) {
      printf("%s:%d\n", argv[numberFile], countEqual);
    } else {
      printf("%d\n", countEqual);
    }
    /* Implementation flags -c and -v whithout -l */
  } else if (flags.c && flags.v && !(flags.l)) {
    if (sumFiles > 1 && !(flags.h)) {
      printf("%s:%d\n", argv[numberFile], countUnEqual);
    } else {
      printf("%d\n", countUnEqual);
    }
  }
}

void flagO(FLAGS flags, char *linePtr, regex_t regex, regmatch_t pmatch,
           char *argv[], int numberFile, int countLine, int sumFiles) {
  // rm_so сохраняет начальную позицию соответствующей текстовой строки
  // rm_eo сохраняет конечную позицию
  int len = (int)(pmatch.rm_eo - pmatch.rm_so);
  if (sumFiles > 1 && !(flags.h) && !(flags.n)) {
    printf("%s:%.*s\n", argv[numberFile], len, linePtr + pmatch.rm_so);
  } else if (sumFiles > 1 && flags.n && !(flags.h)) {
    printf("%s:%d:%.*s\n", argv[numberFile], countLine, len,
           linePtr + pmatch.rm_so);
  } else if (flags.n) {
    printf("%d:%.*s\n", countLine, len, linePtr + pmatch.rm_so);
  } else {
    printf("%.*s\n", len, linePtr + pmatch.rm_so);
  }
  char *offset = linePtr + pmatch.rm_eo;
  while (!(regexec(&regex, offset, 1, &pmatch, 0))) {
    len = (int)(pmatch.rm_eo - pmatch.rm_so);
    if (sumFiles > 1 && !(flags.h) && !(flags.n)) {
      printf("%s:%.*s\n", argv[numberFile], len, offset + pmatch.rm_so);
    } else if (sumFiles > 1 && flags.n && !(flags.h)) {
      printf("%s:%d:%.*s\n", argv[numberFile], countLine, len,
             linePtr + pmatch.rm_so);
    } else if (flags.n) {
      printf("%d:%.*s\n", countLine, len, offset + pmatch.rm_so);
    } else {
      printf("%.*s\n", len, offset + pmatch.rm_so);
    }
    offset = offset + pmatch.rm_eo;
  }
}

char *flagFAndE(int argc, char *argv[]) {
  bool flag = true;
  int move = 0, len = 512;
  char *str = NULL;
  char *buffer = (char *)calloc(len, (sizeof(char)));
  if (buffer == NULL) {
    fprintf(stderr, "ERROR: Malloc no memory available!");
  } else {
    for (int i = 1; flag && i < argc; i++) {
      str = argv[i];
      if (flag && strlen(str) == 2 && str[0] == '-' && str[1] == 'f') {
        flag = flagF(argv, &buffer, &move, &i, &len);
      } else if (flag && str[0] == '-' && strchr(str, 'e')) {
        flag = flagE(argv, &buffer, &move, &i, &len);
      }
    }
    if (len == 1 || buffer == NULL || !(flag)) {
      free(buffer);
      buffer = NULL;
    } else if (buffer != NULL && buffer[move - 1] == '|') {
      buffer[move - 1] = '\0';
    }
  }
  return buffer;
}

bool flagE(char *argv[], char **buffer, int *move, int *i, int *len) {
  bool flag = true;
  char *str = argv[(*i)], *aCh = strchr(str, 'e');
  unsigned locationE = aCh - str + 1, lenStr = (strlen(str));
  if ((lenStr == 2 && str[0] == '-' && str[1] == 'e') ||
      (lenStr == locationE)) {
    str = argv[++(*i)];
    for (int j = 0; flag && str[j] != '\0'; j++) {
      (*buffer)[(*move)++] = str[j];
      if (*len - *move <= 10 && flag) {
        flag = reallocBuffer(len, buffer);
      }
    }
  } else if (lenStr > 2 && str[0] == '-' && strchr(str, 'e') && flag) {
    for (unsigned k = locationE; flag && k < lenStr; k++) {
      (*buffer)[(*move)++] = str[k];
      if (*len - *move <= 10) {
        flag = reallocBuffer(len, buffer);
      }
    }
  }
  if (flag) {
    (*buffer)[(*move)++] = '|';
  }
  return flag;
}

bool flagF(char *argv[], char **buffer, int *move, int *i, int *len) {
  bool flag = true;
  FILE *fPtr = fopen(argv[++(*i)], "r");
  if (fPtr == NULL) {
    fprintf(stderr, "ERROR: FILE %s could not be opened!\n", argv[(*i)]);
    flag = false;
    free((*buffer));
    (*buffer) = NULL;
  } else {
    char ch = ' ';
    while (flag && ((ch = fgetc(fPtr)) != EOF)) {
      if (*len - *move <= 10) {
        flag = reallocBuffer(len, buffer);
      }
      if (flag && ch == ' ') {
        continue;
      } else if (flag && (ch == '\n' || ch == '\r') &&
                 (*buffer)[(*move) - 1] != '|') {
        (*buffer)[(*move)++] = '|';
      } else if (flag) {
        (*buffer)[(*move)++] = ch;
      }
    }
    fclose(fPtr);
  }
  return flag;
}

bool reallocBuffer(int *len, char **buffer) {
  bool flag = true;
  (*len) += 100;
  char *temp = (char *)realloc((*buffer), (*len) * sizeof(char));
  if (temp == NULL) {
    fprintf(stderr, "ERROR: Realloc no memory availiable!\n");
    free((*buffer));
    (*buffer) = NULL;
    flag = false;
  } else {
    *buffer = temp;
  }
  return flag;
}