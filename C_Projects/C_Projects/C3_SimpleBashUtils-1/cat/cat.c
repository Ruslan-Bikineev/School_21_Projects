#include "cat.h"

const struct option long_option[] = {
    {"number-nonblank", no_argument, NULL, 'b'},
    {"number", no_argument, NULL, 'n'},
    {"squeeze-blank", no_argument, NULL, 's'},
    {NULL, 0, NULL, 0}};

void changeFlags(FLAGS *flags, int argc, char *argv[]) {
  int opt;
  opterr = 0;
  while ((opt = getopt_long(argc, argv, "benstvTE", long_option, NULL)) != -1 &&
         !flags->ERROR) {
    switch (opt) {
      case 'b':
        flags->b = true;
        break;
      case 'e':
        flags->e = flags->v = true;
        break;
      case 'E':
        flags->e = true;
        break;
      case 'n':
        flags->n = true;
        break;
      case 's':
        flags->s = true;
        break;
      case 't':
        flags->t = flags->v = true;
        break;
      case 'v':
        flags->v = true;
        break;
      case 'T':
        flags->t = true;
        break;
      default:
        flags->ERROR = true;
        break;
    }
  }
  if (flags->b && flags->n) {
    flags->n = false;
  }
}

void flagV(char ch) {
  if (ch < -96) {
    printf("M-^%c", ch + 192);
  } else if (ch < -1) {
    printf("M-%c", ch + 128);
  } else if (ch == -1) {
    printf("M-^?");
  } else if ((ch < 32) && ch != 9 && ch != 10) {
    printf("^%c", ch + 64);
  } else if (ch == 127) {
    printf("^%c", ch - 64);
  } else {
    printf("%c", ch);
  }
}

void printFile(int argc, char *argv[], FLAGS flags) {
  char ch, prevCh = '\n';
  unsigned long long line_number = 1, countEnter = 0;
  for (int i = optind; i != argc; i++) {
    FILE *fPtr = fopen(argv[i], "r");
    if (fPtr == NULL && argc != 2) {
      fprintf(stderr, "ERROR: File %s could not be found!\n", argv[i]);
    } else {
      while ((ch = fgetc(fPtr == NULL ? stdin : fPtr)) != EOF) {
        if (prevCh == '\n') {
          if (flags.s) {
            countEnter = (ch == '\n') ? countEnter + 1 : 0;
            if (countEnter > 1) {
              continue;
            }
          }
          if (flags.n) {
            printf("%6llu\t", line_number++);
          } else if (flags.b && ch != '\n') {
            printf("%6llu\t", line_number++);
          }
        }
        if (flags.e && ch == '\n') {
          printf("$");
        }
        if (flags.t && ch == '\t') {
          printf("^I");
          prevCh = ch;
          continue;
        }
        if (flags.v) {
          flagV(ch);
        } else {
          printf("%c", ch);
        }
        prevCh = ch;
      }
      if (fPtr != NULL) fclose(fPtr);
    }
  }
}