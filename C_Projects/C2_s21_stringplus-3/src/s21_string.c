#include "s21_string.h"

/*|1|Выполняет поиск первого вхождения символа c (беззнаковый тип)
в первых n байтах строки, на которую указывает аргумент str.*/
void *s21_memchr(const void *str, int c, s21_size_t n) {
  bool flag = true;
  const char *sPtr = str;
  for (s21_size_t i = 0; flag && i < n; i++) {
    if (*(sPtr)++ == c) {
      flag = false;
    }
  }
  return flag ? S21_NULL : (void *)(sPtr - 1);
}

/*|2|Сравнивает первые n байтов str1 и str2.*/
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  bool flag = true;
  const char *s1Ptr = str1;
  const char *s2Ptr = str2;
  int result = 0;
  for (s21_size_t i = 0; flag && i < n; i++) {
    if (s1Ptr[i] == s2Ptr[i]) {
      continue;
    } else {
      flag = false;
      result =
          (s1Ptr[i] > s2Ptr[i]) ? s1Ptr[i] - s2Ptr[i] : -(s2Ptr[i] - s1Ptr[i]);
    }
  }
  return result;
}

/*|3|Копирует n символов из src в dest.*/
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *destPtr = dest;
  const char *srcPtr = src;
  for (s21_size_t i = 0; i < n; i++) {
    destPtr[i] = srcPtr[i];
  }
  return destPtr;
}

/*|4|Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
 указывает аргумент str.*/
void *s21_memset(void *str, int c, s21_size_t n) {
  char *sPtr = str;
  for (s21_size_t i = 0; i < n; i++) {
    sPtr[i] = c;
  }
  return sPtr;
}

/*|5|Добавляет строку, на которую указывает src, в конец строки, на которую
 * указывает dest, длиной до n символов.*/
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *destPtr = dest + s21_strlen(dest);
  for (s21_size_t i = 0; i < n && *(src) != '\0'; i++, destPtr++, src++) {
    *destPtr = *src;
  }
  *destPtr++ = '\0';
  return dest;
}

/*|6|Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
 * которую указывает аргумент str.*/
char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  if (c == 0) {
    res = "";
  } else {
    for (bool flag = true; *str != '\0' && flag; str++) {
      if (*str == c) {
        flag = false;
        res = (char *)str;
      }
    }
  }
  return res;
}

/*|7|Сравнивает не более первых n байтов str1 и str2.*/
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  bool flag = true;
  int result = 0;
  for (s21_size_t i = 0; flag && i < n; i++) {
    if (str1[i] != str2[i]) {
      flag = false;
      result = (str1[i] > str2[i]) ? str1[i] - str2[i] : -(str2[i] - str1[i]);
    }
  }
  return result;
}

/*|8|Копирует до n символов из строки, на которую указывает src, в dest.*/
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  bool flag = false;
  for (s21_size_t i = 0; i < n; i++) {
    if (src[i] == '\0') {
      flag = true;
    }
    dest[i] = flag ? 0 : src[i];
  }
  return dest;
}

/*|9|Вычисляет длину начального сегмента str1, который полностью состоит из
 * символов, не входящих в str2.*/
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  char *temp = S21_NULL;
  s21_size_t s1Len = s21_strlen(str1), s2Len = s21_strlen(str2), result = 0;
  if (s1Len < s2Len) {
    temp = "t";
  } else {
    for (bool flag = true, stop = true; stop && *str2; str2++) {
      temp = s21_strchr(str1, *str2);
      if (flag && temp != S21_NULL) {
        result = temp - str1;
        flag = false;
      }
      if (result > (s21_size_t)(temp - str1)) {
        result = temp - str1;
      }
      if (result == 0) {
        stop = false;
      }
    }
  }
  return temp == S21_NULL && result == 0 ? s21_strlen(str1) : result;
}

/*|10|Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие
массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок
есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью
директив.*/
char *s21_strerror(int errnum) {
  static char resultError[60];
  if (errnum >= 0 && errnum < MAX_ERRORS_NUMBERS) {
    char allErrorsBuffer[MAX_ERRORS_NUMBERS][60] = ERRORS;
    s21_strcpy(resultError, allErrorsBuffer[errnum]);
  } else {
    s21_sprintf(resultError, "%s%d", UNKNOWN, errnum);
  }
  return resultError;
}

/*|11|Вычисляет длину строки str, не включая завершающий нулевой символ.*/
s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

/*|12|Находит первый символ в строке str1, который соответствует любому символу,
 * указанному в str2.*/
char *s21_strpbrk(const char *str1, const char *str2) {
  char *temp = S21_NULL, *result = S21_NULL;
  s21_size_t i = 0, s2Len = s21_strlen(str2);
  for (bool flag = true; i < s2Len; i++) {
    temp = s21_strchr(str1, str2[i]);
    if (flag && temp != S21_NULL) {
      flag = false;
      result = temp;
    }
    if (temp != S21_NULL && (temp - str1) < (result - str1)) {
      result = temp;
    }
  }
  return result;
}

/*|13|Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке,
 * на которую указывает аргумент str.*/
char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  if (c == 0) {
    result = "";
  } else {
    for (; *str != '\0'; str++) {
      if (*str == c) {
        result = (char *)str;
      }
    }
  }
  return result;
}

/*|14|Находит первое вхождение всей строки needle (не включая завершающий
 * нулевой символ), которая появляется в строке haystack.*/
char *s21_strstr(const char *haystack, const char *needle) {
  bool flag = true;
  const char *temp = haystack;
  if (s21_strlen(needle) != 0) {
    s21_size_t needleLen = s21_strlen(needle),
               haystackLen = s21_strlen(haystack);
    if (haystackLen == 0) {
      temp = S21_NULL;
    } else {
      for (s21_size_t i = 0; flag && i < haystackLen; i++) {
        if ((temp = s21_strchr(haystack, needle[0])) != S21_NULL) {
          if (s21_strncmp(temp, needle, needleLen) != 0) {
            haystack += temp - haystack + 1;
          } else {
            flag = false;
          }
        } else {
          flag = false;
        }
      }
    }
  }
  return (char *)temp;
}

/*|15|Разбивает строку str на ряд токенов, разделенных delim.*/
char *s21_strtok(char *str, const char *delim) {
  static char *move;
  char *temp = S21_NULL;
  str = (str == S21_NULL) ? move : str;
  if (str != S21_NULL && (temp = s21_strpbrk(str, delim)) != S21_NULL) {
    move = temp + 1 + s21_strspn(temp + 1, delim);
    *(temp) = '\0';
  } else {
    move = S21_NULL;
  }
  if (move != S21_NULL) {
    s21_size_t tempLen = s21_strlen(temp + 1);
    if (tempLen == 0) {
      move = S21_NULL;
    }
  }
  return str;
}

/*---------------------------------------------------------------------------------------*/

/*|16|Копирует строку, на которую указывает src, в dest.*/
char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  for (; src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

/*|17|Вычисляет длину начального сегмента str1, который полностью состоит из
 * символов str2.*/
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0, s1Len = s21_strlen(str1), s2Len = s21_strlen(str2);
  for (s21_size_t i = 0; i < s1Len && i < s2Len; i++) {
    if (s21_strchr(str2, str1[i]) != S21_NULL) {
      result++;
    }
  }
  return result;
}

/*|Part 5|Специальные функции обработки строк (вдохновленные классом String в
 * языке C#)*/
/*---------------------------------------------------------------------------------------*/

/*Возвращает копию строки (str), преобразованной в верхний регистр.
В случае какой-либо ошибки следует вернуть значение S21_NULL */
void *s21_to_upper(const char *str) {
  char *buffer = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t strLen = s21_strlen(str);
    char *temp = (char *)calloc(strLen + 1, sizeof(char));
    if (temp != S21_NULL) {
      buffer = temp;
      for (s21_size_t i = 0; i < strLen; i++) {
        if (str[i] > 96 && str[i] < 123) {
          buffer[i] = str[i] - 32;
        } else {
          buffer[i] = str[i];
        }
      }
    } else {
      printf("\nERROR s21_to_upper: realloc not memory avialable!\n");
      buffer = S21_NULL;
    }
  }
  return buffer;
}

/*Возвращает копию строки (str), преобразованной в нижний регистр.
В случае какой-либо ошибки следует вернуть значение S21_NULL*/
void *s21_to_lower(const char *str) {
  char *buffer = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t strLen = s21_strlen(str);
    char *temp = (char *)calloc(strLen + 1, sizeof(char));
    if (temp != S21_NULL) {
      buffer = temp;
      for (s21_size_t i = 0; i < strLen; i++) {
        if (str[i] > 64 && str[i] < 91) {
          buffer[i] = str[i] + 32;
        } else {
          buffer[i] = str[i];
        }
      }
    } else {
      printf("\nERROR s21_to_lower: realloc not memory avialable!\n");
      buffer = S21_NULL;
    }
  }
  return buffer;
}

/*Возвращает новую строку, в которой указанная строка (str) вставлена в
указанную позицию (start_index) в данной строке (src). В случае какой-либо
ошибки следует вернуть значение S21_NULL */
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *buffer = S21_NULL;
  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t strLen = s21_strlen(str), srcLen = s21_strlen(src),
               maxLen = strLen + srcLen, strOffset = strLen + start_index;
    if (!(start_index > srcLen)) {
      char *temp = (char *)calloc((maxLen + 1), sizeof(char));
      if (temp != S21_NULL) {
        buffer = temp;
        for (s21_size_t count = 0; count < maxLen; count++) {
          if (count < start_index) {
            *temp++ = *src++;
          } else if (count < strOffset) {
            *temp++ = *str++;
          } else {
            *temp++ = *src++;
          }
        }
      } else {
        printf("\nERROR s21_insert: realloc not memory avialable!\n");
        buffer = S21_NULL;
      }
    }
  }
  return buffer;
}

/*Возвращает новую строку, в которой удаляются все начальные и конечные
вхождения набора заданных символов (trim_chars) из данной строки (src). В случае
какой-либо ошибки следует вернуть значение S21_NULL */
void *s21_trim(const char *src, const char *trim_chars) {
  bool flag = true;
  char *buffer = S21_NULL, *sym;
  if (src != S21_NULL) {
    s21_size_t srcLen = s21_strlen(src);
    char *temp = (char *)calloc(srcLen + 1, sizeof(char));
    if (temp != S21_NULL) {
      buffer = temp;
      if (trim_chars == S21_NULL) {
        s21_memcpy(buffer, src, srcLen);
      } else {
        for (s21_size_t i = 0; flag && i < srcLen; i++, src += i) {
          if ((sym = s21_strpbrk(src, trim_chars)) != S21_NULL) {
            srcLen--;
            i = sym - src;
            s21_strncat(buffer, src, i);
          } else {
            s21_strncat(buffer, src, srcLen);
            flag = false;
          }
        }
      }
    } else {
      printf("\nERROR s21_trim: realloc not memory avialable!\n");
      buffer = S21_NULL;
    }
  }
  return buffer;
}