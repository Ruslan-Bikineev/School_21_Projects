#include "s21_string.h"

/* При успешном завершении вывода возвращается количество выведенных символов.
   При ошибке возвращается отрицательное число.
   %[флаги][ширина][.точность][длина]спецификатор. */
int s21_sprintf(char *str, const char *format, ...) {
  bool flag = true;
  va_list argp;
  va_start(argp, format);
  char *result = str;
  while (*format && flag) {
    if (*format == '%') {
      format++;
      if (*format == '%') {
        *str = *format;
        str++;
      }
      PARAMETRS *newPtr = calloc(1, sizeof(PARAMETRS));
      if (newPtr == S21_NULL) {
        printf("\nERROR: Calloc not be avialable!\n");
        flag = false;
      } else {
        readFormat(&newPtr, &format, &argp);
        processingSpecificators(newPtr, &argp, &str);
        free(newPtr);
      }
    } else {
      *str = *format;
      str++;
    }
    format++;
  }
  va_end(argp);
  *str = '\0';
  return s21_strlen(result);
}

/*%[флаги][ширина][.точность][длина]спецификатор.*/
void readFormat(PARAMETRS **newPtr, const char **format, va_list *ap) {
  const char s21_spec[] = "cdfsuxXeEgGop";
  int flag = 0;
  (*newPtr)->flag = checkFlags(format);  // flags
  if (s21_is_digit(**format)) {
    (*newPtr)->width = (int)strToUnsigned(format);
  } else if (*(*format) == '*') {
    (*newPtr)->width = va_arg(*ap, unsigned);
    (*format)++;
  }
  if (*(*format) == 46) {  // check precision
    flag = 1;
    (*format)++;
    if (*(*format) == '*') {
      (*newPtr)->precision = va_arg(*ap, unsigned);
      (*format)++;
    } else {
      (*newPtr)->precision = strToUnsigned(format);
    }
  } else {
    (*newPtr)->precision = 6;
  }
  (*newPtr)->length = checkLength(format);  // check length
  // check specificator
  char *specificator = s21_strchr(s21_spec, *(*format));
  if (specificator != S21_NULL) {
    (*newPtr)->specificator = s21_spec[specificator - s21_spec];
  } else {
    (*newPtr)->specError = true;
  }
  // edit precision if specificator is o x X d u
  if (flag == 0)
    if ((*newPtr)->specificator == 'o' || (*newPtr)->specificator == 'x' ||
        (*newPtr)->specificator == 'X' || (*newPtr)->specificator == 'd' ||
        (*newPtr)->specificator == 'u') {
      (*newPtr)->precision = 1;
    }
}

void integer_specifiers(PARAMETRS *newPtr, va_list *ap, char **str) {
  long long int number;
  char *uns = s21_strchr("ouxX", newPtr->specificator);
  if (uns != S21_NULL) {
    if (newPtr->length == 'l')
      number = va_arg(*ap, long unsigned);
    else
      number = va_arg(*ap, unsigned);
  } else {
    if (newPtr->length == 'l')
      number = va_arg(*ap, long int);
    else
      number = va_arg(*ap, int);
  }
  if (newPtr->specificator == 'd' || newPtr->specificator == 'u') {
    printInt(str, newPtr, number);
  } else if (newPtr->specificator == 'x' || newPtr->specificator == 'X') {
    printHex(str, newPtr, number);
  } else if (newPtr->specificator == 'o') {
    printOct(str, newPtr, number);
  }
}

void double_specifiers(PARAMETRS *newPtr, va_list *ap, char **str) {
  long double number;
  if (newPtr->length == 'L') {
    number = va_arg(*ap, long double);
  } else {
    number = va_arg(*ap, double);
  }
  if (isnan(number) || isinf(number) || number == INFINITY ||
      number == -INFINITY || number == NAN || number == -NAN) {
    printNanAndInf(str, newPtr, number);
  } else if (newPtr->specificator == 'f') {
    printDouble(str, newPtr, number);
  } else if (newPtr->specificator == 'e' || newPtr->specificator == 'E') {
    printExp(str, newPtr, number);
  } else if (newPtr->specificator == 'G' || newPtr->specificator == 'g') {
    printG(str, newPtr, number);
  }
}

/*Обработка флагов*/
void processingSpecificators(PARAMETRS *newPtr, va_list *ap, char **str) {
  if (newPtr->specificator == 'c') {
    char c = va_arg(*ap, int);
    printChar(str, newPtr, c);
  } else if (newPtr->specificator == 's') {
    char *s = va_arg(*ap, char *);
    printString(str, newPtr, s);
  } else if (newPtr->specificator == 'p') {
    printPointer(str, newPtr, va_arg(*ap, void *));
  } else {
    char int_specs[] = "douxX";
    if ((s21_strchr(int_specs, newPtr->specificator)) != S21_NULL) {
      integer_specifiers(newPtr, ap, str);
    } else {
      char double_specs[] = "eEfgG";
      if ((s21_strchr(double_specs, newPtr->specificator)) != S21_NULL) {
        double_specifiers(newPtr, ap, str);
      }
    }
  }
}

//  For width and precision
unsigned strToUnsigned(const char **format) {
  unsigned result = 0;
  for (s21_size_t temp = 1; isdigit((**format)); (*format)++, temp = 10) {
    result = (**format - 48) + (result * temp);
  }
  return result;
}

// For check flags
char checkFlags(const char **format) {
  char result = '\0';
  if ((**format) == '+' || (**format) == '-' || (**format) == ' ' ||
      (**format) == '#' || (**format) == '0') {
    result = (**format);
    (*format)++;
    if (result == '0' && **format == '.') {
      result = '\0';
      (*format)--;
    }
  }
  return result;
}

// For check length
char checkLength(const char **format) {
  char result = '\0';
  if (**format == 'h' || **format == 'l' || **format == 'L') {
    result = **format;
    (*format)++;
  }
  return result;
}

int numberLen(long double x) {
  if (x < 0.0) x *= -1;
  long long unsigned temp = (long long unsigned)x;
  int len = 0;
  while (temp > 0) {
    len += 1;
    temp /= 10;
  }
  return len;
}

void number_to_string(char **str, long double number, PARAMETRS *newPtr) {
  if (number < 0) {
    if (newPtr->flag != '0') {
      **str = '-';
      (*str)++;
    }
    number *= -1;
  } else if (newPtr->flag == '+') {
    **str = '+';
    (*str)++;
  } else if (newPtr->flag == ' ') {
    **str = ' ';
    (*str)++;
  }
  int len = numberLen(number);
  if (len == 0) {
    **str = '0';
    (*str)++;
  }
  char *buffer = calloc(len + 10, sizeof(char));
  if (buffer != S21_NULL) {
    int buf_index = 0;
    while (number > 0.1) {
      buffer[buf_index] = (long long unsigned)fmodl(number, 10.0) + '0';
      buf_index++;
      number /= 10;
    }
    for (int i = len - 1; i >= 0; i--) {
      **str = buffer[i];
      (*str)++;
    }
    free(buffer);
  }
}

void f_specifier(char **str, long double number, PARAMETRS *newPtr) {
  if (number < 0 &&
      ((newPtr->flag != ' ' && newPtr->flag != '\0' && newPtr->flag != '-') ||
       newPtr->precision != 0)) {
    if (newPtr->width > 0) (*newPtr).width--;
  }
  if (newPtr->precision == 0) {
    number = roundl(number);
    number_to_string(str, number, newPtr);
    if (newPtr->flag == '#') {
      **str = '.';
      (*str)++;
    }
  } else {
    s21_round(str, number, newPtr);
  }
}

// ATTENTION!!!!!!!!!!!
// могут быть ошибки если что исправить!
void s21_round(char **str, long double num, PARAMETRS *newPtr) {
  // целая часть
  s21_integer_part_round(str, &num, newPtr);
  // дробная часть
  s21_fractional_part_round(str, num, newPtr);
}

void s21_integer_part_round(char **str, long double *num, PARAMETRS *newPtr) {
  long long unsigned prec = 1;
  int t = newPtr->precision;
  while (t > 0) {
    prec *= 10;
    t--;
  }
  *num = roundl(*num * (prec)) / (prec);
  number_to_string(str, *num, newPtr);
  if (newPtr->precision != 0 || newPtr->flag == '#') {
    **str = '.';
    (*str)++;
  }
  **str = '\0';
}

void s21_fractional_part_round(char **str, long double num, PARAMETRS *newPtr) {
  long long unsigned temp;
  long double double_temp;
  long double c;
  double_temp = fabsl(modfl(num, &c));
  for (int i = 0; i < newPtr->precision; i++) {
    double_temp *= 10;
    temp = (long long unsigned)fmodl(double_temp, 10);
    **str = temp + '0';
    (*str)++;
    double_temp = double_temp - (long long unsigned)double_temp;
  }
  temp = (long long unsigned)(double_temp * 10) % 10;
  if (temp >= 5) {
    int flag = 1;
    char *p = *str - 1;
    while (temp == 9 && flag) {
      flag = (*p == '9');  // округлили или нет
      *p = (*p - '0' + 1) % 10 + '0';
      p--;
      temp = *p - '0';
    }
    if (flag && *p != '.') {  // если округлили предыдущий то округляем этот
      *p = (*p - '0' + 1) % 10 + '0';
      if (*p == '0') {
        p--;
        *p = (*p - '0' + 1) % 10 + '0';
      }
    }
  }
}

void printInt(char **str, PARAMETRS *newPtr, long int number) {
  int sign = 0;
  if (number < 0) sign++;
  if (newPtr->flag == '+') sign++;
  if (sign == 2) sign = 0;
  if (newPtr->width > numberLen(number) + sign) {
    if (newPtr->flag == '-') {
      number_to_string(str, number, newPtr);
      width(str, newPtr->width - numberLen(number) - sign, newPtr);
    } else {
      width(str, newPtr->width - numberLen(number) - sign, newPtr);
      number_to_string(str, number, newPtr);
    }
  } else
    number_to_string(str, number, newPtr);
}

void printDouble(char **str, PARAMETRS *newPtr, long double number) {
  if (newPtr->precision == 0)
    if (number > 0) (*newPtr).width++;
  if (newPtr->width == 0) (*newPtr).width = 1;
  if (number < 0 && newPtr->precision != 0 && (newPtr->flag != '-'))
    (*newPtr).width--;
  if (newPtr->flag == '#') (*newPtr).width--;
  if (newPtr->flag == ' ' || newPtr->flag == '+')
    if (number < 0) (*newPtr).width++;
  if (number < 0.0 && newPtr->flag == '0') {
    **str = '-';
    (*str)++;
  }
  if (newPtr->width > numberLen(number) + 1 + newPtr->precision) {
    if (newPtr->flag == '-') {
      f_specifier(str, number, newPtr);
      width(str, newPtr->width - (numberLen(number) + 1 + newPtr->precision),
            newPtr);
    } else {
      // длина целой части + точка + точность
      width(str, newPtr->width - (numberLen(number) + 1 + newPtr->precision),
            newPtr);
      f_specifier(str, number, newPtr);
    }
  } else
    f_specifier(str, number, newPtr);
}

void printString(char **str, PARAMETRS *newPtr, char *s) {
  if (newPtr->width > (int)s21_strlen(s)) {
    if (newPtr->flag == '-') {
      printStr(str, s);
      width(str, newPtr->width - (int)s21_strlen(s), newPtr);
    } else {
      width(str, newPtr->width - (int)s21_strlen(s), newPtr);
      printStr(str, s);
    }
  } else {
    printStr(str, s);
  }
}

void printChar(char **str, PARAMETRS *newPtr, char c) {
  if (newPtr->width > 1) {
    if (newPtr->flag == '-') {
      **str = c;
      (*str)++;
      width(str, newPtr->width - 1, newPtr);
    } else {
      width(str, newPtr->width - 1, newPtr);
      **str = c;
      (*str)++;
    }
  } else {
    **str = c;
    (*str)++;
  }
}

char *o_specifier(long unsigned number, PARAMETRS *newPtr) {
  if (newPtr->flag == '+' || newPtr->flag == ' ') {
    (*newPtr).width++;
  }
  if (newPtr->length == 'h') {
    number = (short unsigned)number;
  } else if (newPtr->length == 'l') {
    number = (long unsigned)number;
  } else {
    number = (unsigned)number;
  }
  char *s = (char *)calloc(numberLen(number) + 100, sizeof(char));
  char *res = s;
  if (s != S21_NULL) {
    long int *bufferPtr = (long int *)calloc(100, sizeof(long int));
    if (bufferPtr == S21_NULL) {
      printf("ERROR o_specifier: calloc not be avialable!");
    } else {
      if (newPtr->flag == '#' && number != 0) {
        flag_trellis(&s, 'o');
      }
      int k = 0;
      do {
        *bufferPtr = (number % 8);
        bufferPtr++;
        number = number / 8;
        k++;
      } while (number != 0);
      bufferPtr -= k;
      if (newPtr->precision > k) {
        if (newPtr->flag == '#')
          precisionPointer(&s, newPtr->precision - k - 1);
        else
          precisionPointer(&s, newPtr->precision - k);
      }
      for (int i = k - 1; i >= 0; i--, (s)++) {
        *s = bufferPtr[i] + 48;
      }
      free(bufferPtr);
    }
  }
  return res;
}

void printOct(char **str, PARAMETRS *newPtr, long unsigned number) {
  char *s = o_specifier(number, newPtr);
  printString(str, newPtr, s);
  free(s);
}

void printPointer(char **str, PARAMETRS *newPtr, void *pointer) {
  char *s = p_specifier(pointer, newPtr);
  printString(str, newPtr, s);
  free(s);
}

char *p_specifier(void *pointer, PARAMETRS *newPtr) {
  unsigned long addr = (unsigned long)(pointer);
  char *s = (char *)calloc(5000, sizeof(char));
  char *res = s;
  char *bufferPtr = (char *)calloc(1000, sizeof(char));
  if (bufferPtr == S21_NULL || s == S21_NULL) {
    printf("ERROR p_specifier: calloc not be avialable!\n");
  } else if (pointer != S21_NULL) {
    int i = 0;
    while (addr != 0) {
      unsigned long digit = addr % 16;
      bufferPtr[i] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
      addr /= 16;
      i++;
    }
    if (newPtr->flag == '+') {
      (*s++) = '+';
    } else if (newPtr->flag == ' ') {
      (*s++) = ' ';
    }
    (*s++) = '0';
    (*s++) = 'x';
    if (newPtr->precision > 12) {
      precisionPointer(&s, newPtr->precision - (int)s21_strlen(bufferPtr));
    }
    for (int k = i - 1; k >= 0; k--, s++) {
      *s = bufferPtr[k];
    }
    free(bufferPtr);
  } else {
    s21_strncat(s, "(nil)", s21_strlen("(nil)"));
    free(bufferPtr);
  }
  return res;
}

void precisionPointer(char **str, int precision) {
  for (int i = 0; i < precision; i++) {
    **str = '0';
    (*str)++;
  }
}

char *g_G_specifier(PARAMETRS *newPtr, long double number) {
  char *s = calloc(400, sizeof(char));
  char *res = s;
  if (s != S21_NULL) {
    int exp = 0;
    long double t = number;
    if (t == 0) {
      *s = '0';
    } else {
      while (fabsl(t) > 1 && t != 0.0) {
        t = t / 10;
        exp++;
      }
      while (fabsl(t) < 1 && t != 0.0) {
        t = t * 10;
        exp--;
      }
      if (exp < -4 || exp >= newPtr->precision) {
        e_from_g(&s, newPtr, number);
      } else {
        f_from_g(&s, newPtr, number);
      }
    }
  }
  return res;
}

void e_from_g(char **s, PARAMETRS *newPtr, long double number) {
  if (newPtr->precision > 0) (*newPtr).precision -= 1;
  if (newPtr->specificator == 'g') {
    (*newPtr).specificator = 'e';
  } else {
    (*newPtr).specificator = 'E';
  }
  char *temp = *s;
  printExp(s, newPtr, number);
  temp = s21_strchr(temp, 'e');
  char *e = temp;
  if (temp != S21_NULL && *(temp - 1) == '0') {
    temp--;
    if (newPtr->flag != '#') {
      while (*temp == '0') {
        (temp)--;
      }
      if (*temp == '.' && newPtr->flag != '#') {
        *temp = '\0';
        (temp)--;
      }
      temp++;
      while (*e != '\0') {
        *temp = *e;
        temp++;
        e++;
      }
      *temp = '\0';
      temp--;
    }
    if (*temp == '.' && newPtr->flag != '#') {
      *temp = '\0';
    }
  }
}

void f_from_g(char **s, PARAMETRS *newPtr, long double number) {
  if (newPtr->flag == '+' || newPtr->flag == ' ') {
    (*newPtr).width++;
  }
  (*newPtr).precision -= numberLen(number);
  char *temp = *s;
  if (newPtr->precision == 0) {
    number = roundl(number);
    number_to_string(s, number, newPtr);
    if (newPtr->flag == '#') {
      **s = '.';
      (*s)++;
    }
  } else {
    s21_round(s, number, newPtr);
  }
  if ((s21_strchr(temp, '.')) != S21_NULL) {
    do {
      (*s)--;
    } while (**s == ' ');
    deleteZero(s, newPtr);
  }
}

void deleteZero(char **str, PARAMETRS *newPtr) {
  if (newPtr->flag != '#')
    while (**str == '0') {
      **str = '\0';
      (*str)--;
    }
  if (**str == '.' && newPtr->flag != '#') {
    **str = '\0';
    (*str)--;
  }
}

void printG(char **str, PARAMETRS *newPtr, long double number) {
  char *s = g_G_specifier(newPtr, number);
  if (newPtr->specificator == 'g' || newPtr->specificator == 'G')
    if (number < 0.0 && newPtr->flag == '0') {
      **str = '-';
      (*str)++;
      (*newPtr).width--;
    }

  printString(str, newPtr, s);
  free(s);
}

char *e_E_specifier(PARAMETRS *newPtr, long double number) {
  int exp = 0;
  char *str = (char *)calloc(100, sizeof(char));
  char *res = str;
  if (str != S21_NULL) {
    while (fabsl(number) > 1 && number != 0.0) {
      number = number / 10;
      exp++;
    }
    while (fabsl(number) < 1 && number != 0.0) {
      number = number * 10;
      exp--;
    }
    if (fmodl(roundl(number), 10) == 0 && number != 0) {
      exp++;
      number = number / 10;
    }
    if (newPtr->precision == 0 && number != 0) {
      number = roundl(number);
      number_to_string(&str, number, newPtr);
      if (newPtr->flag == '#') {
        *str = '.';
        (str)++;
      }
    } else {
      s21_round(&str, number, newPtr);
    }
    *str = newPtr->specificator;
    (str)++;
    expSign(&str, exp);
  }
  return res;
}

void expSign(char **str, long int exp) {
  if (exp < 0.0) {
    **str = '-';
    exp = -exp;
  } else {
    **str = '+';
  }
  (*str)++;
  if (exp < 10) {
    **str = '0';
    (*str)++;
  }
  if (exp != 0) {
    expToString(str, exp);
  } else {
    **str = '0';
    (*str)++;
  }
}

void expToString(char **str, long int number) {
  int len = numberLen(number);
  char *buffer = calloc(len, sizeof(char));
  if (buffer != S21_NULL) {
    int buf_index = 0;
    while (number > 0) {
      buffer[buf_index] = (number % 10) + '0';
      buf_index++;
      number /= 10;
    }
    for (int i = len - 1; i >= 0; i--) {
      **str = buffer[i];
      (*str)++;
    }
    free(buffer);
  }
}

char *x_X_specifier(long unsigned number, PARAMETRS *newPtr) {
  if (newPtr->length == 'h') {
    number = (short unsigned)number;
  } else if (newPtr->length != 'l') {
    number = (unsigned)number;
  }
  if (newPtr->flag == '+' || newPtr->flag == ' ') {
    (*newPtr).width++;
  }
  char *s = (char *)calloc(numberLen(number) + 100, sizeof(char));
  char *res = s;
  long unsigned *bufferPtr =
      (long unsigned *)calloc(numberLen(number) + 100, sizeof(long unsigned));
  long unsigned *buf = bufferPtr;
  if (bufferPtr == S21_NULL || s == S21_NULL) {
    printf("ERROR x_specifier: calloc not be avialable!");
  } else {
    if (newPtr->flag == '#' && number != 0) {
      flag_trellis(&s, newPtr->specificator);
    }
    int k = 0;
    do {
      *bufferPtr = (number % 16);
      bufferPtr++;
      number = number / 16;
      k++;
    } while (number != 0);
    bufferPtr--;
    char *temp = calloc(k * 2, sizeof(char));
    for (int i = 0; i < k; i++, bufferPtr--) {
      temp[i] = number_to_hex(*bufferPtr, newPtr->specificator);
    }
    if ((s21_size_t)newPtr->precision > s21_strlen(temp)) {
      precisionPointer(&s, newPtr->precision - s21_strlen(temp));
    }
    s21_strncat(s, temp, s21_strlen(temp));
    free(temp);
    free(buf);
  }
  return res;
}

void flag_trellis(char **str, char specificator) {
  if (specificator == 'x' || specificator == 'X') {
    **str = '0';
    (*str)++;
    **str = specificator;
    (*str)++;
  } else if (specificator == 'o') {
    **str = '0';
    (*str)++;
  }
}

char number_to_hex(unsigned number, char specificator) {
  char res;
  if (number <= 9) {
    res = number + 48;
  } else {
    switch (number) {
      case 10:
        res = 'a';
        break;
      case 11:
        res = 'b';
        break;
      case 12:
        res = 'c';
        break;
      case 13:
        res = 'd';
        break;
      case 14:
        res = 'e';
        break;
      case 15:
        res = 'f';
        break;
    }
    if (specificator == 'X') res = res - 32;
  }
  return res;
}

void width(char **str, int width, PARAMETRS *newPtr) {
  if (newPtr->specificator != 'e' && newPtr->specificator != 'E')
    if (newPtr->flag == '+' || newPtr->flag == ' ') width--;
  char symbol = ' ';
  if (newPtr->flag == '0') {
    symbol = '0';
  }
  for (int i = 0; i < width; i++) {
    **str = symbol;
    (*str)++;
  }
}

void printHex(char **str, PARAMETRS *newPtr, long unsigned number) {
  char *s = x_X_specifier(number, newPtr);
  printString(str, newPtr, s);
  free(s);
}

void printStr(char **str, char *s) {
  for (s21_size_t i = 0; i < s21_strlen(s); i++) {
    **str = s[i];
    (*str)++;
  }
}

void printExp(char **str, PARAMETRS *newPtr, long double number) {
  char *s = e_E_specifier(newPtr, number);
  if (number < 0.0 && newPtr->flag == '0') {
    **str = '-';
    (*str)++;
    (*newPtr).width--;
  }
  printString(str, newPtr, s);
  free(s);
}

void printNanAndInf(char **str, PARAMETRS *newPtr, long double number) {
  char *s = calloc(400, sizeof(char));
  if (isnan(number) && newPtr->specificator != 'E' &&
      newPtr->specificator != 'G') {
    s21_strncat(s, "nan", s21_strlen("nan"));
  } else if (isinf(number) && newPtr->specificator != 'E' &&
             newPtr->specificator != 'G') {
    s21_strncat(s, "inf", s21_strlen("inf"));
  } else if (isnan(number) &&
             (newPtr->specificator == 'E' || newPtr->specificator == 'G')) {
    s21_strncat(s, "NAN", s21_strlen("NAN"));
  } else if (isinf(number) &&
             (newPtr->specificator == 'E' || newPtr->specificator == 'G')) {
    s21_strncat(s, "INF", s21_strlen("INF"));
  }
  printString(str, newPtr, s);
  free(s);
}
