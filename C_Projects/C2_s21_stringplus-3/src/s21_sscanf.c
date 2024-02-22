#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *start = str;
  SSCANF_PARAMS param;
  s21_init_struct(&param, 0);
  int accepted_vars = 0;
  if (*str == '\0' && *format != '\0') param.error = 1;
  while (*str != '\0' && *format != '\0' && !param.error) {
    if (*format == '%') {
      while (*str == ' ') str++;
      s21_init_struct(&param, str - start);
      s21_read_format(&param, &format);
      if (!param.error) accepted_vars += process_specifier(&str, &args, &param);
      if (!param.error) skip_spaces(&str, &format);
    } else {
      if (*format >= 32 && *str >= 32) {
        param.error = *str != *format;
        format++;
        str++;
      }
      if (*format < 32 && *format != '\0') format++;
      if (*str < 32 && *format != '\0') str++;
    }
  }
  va_end(args);
  if (param.error && accepted_vars == 0) accepted_vars = -1;
  return accepted_vars;
}

/* Инициализация структуры */
void s21_init_struct(SSCANF_PARAMS *param, int quantity) {
  param->specifier = ' ';
  param->accepted = 1;
  param->error = 0;
  param->width = 0;
  param->length = ' ';
  param->sign = 0;
  param->n_quantity = quantity;
}

/* %[*][ширина][длина]спецификатор */
void s21_read_format(SSCANF_PARAMS *param, const char **format) {
  const char s21_spec[] = "cdieEfgGosuxXpn%";
  (*format)++;
  // check *
  if (**format == '*') {
    param->accepted = 0;
    (*format)++;
  }
  // check width
  if (s21_is_digit(**format) || **format == '-' || **format == '+')
    s21_select_width(format, param);
  if (param->error == 0)
    // check length
    if (is_len_specifier(**format)) param->length = *((*format)++);

  // check specifier
  char *specifier = s21_strchr(s21_spec, **format);
  if (specifier != S21_NULL) {
    param->specifier = s21_spec[specifier - s21_spec];
    (*format)++;
  } else {
    param->error = 1;
  }
}

int process_specifier(const char **str, va_list *args, SSCANF_PARAMS *param) {
  if (param->specifier == 'c')
    c_spec_process(str, args, param);
  else if (param->specifier == 'd')
    d_spec_process(str, args, param);
  else if (param->specifier == 'i')
    i_spec_process(str, args, param);
  else if (param->specifier == 'e' || param->specifier == 'E' ||
           param->specifier == 'f' || param->specifier == 'g' ||
           param->specifier == 'G')
    real_spec_process(str, args, param);
  else if (param->specifier == 'u')
    u_spec_process(str, args, param);
  else if (param->specifier == 'o')
    o_spec_process(str, args, param);
  else if (param->specifier == 's')
    s_spec_process(str, args, param);
  else if (param->specifier == 'x' || param->specifier == 'X')
    x_spec_process(str, args, param);
  else if (param->specifier == 'p')
    p_spec_process(str, args, param);
  else if (param->specifier == 'n')
    n_spec_process(args, param);
  else if (param->specifier == '%')
    percent_spec_process(str, param);
  else
    param->error = 1;
  return param->accepted;
}

void skip_spaces(const char **str, const char **format) {
  int format_pushed = 0;
  while (**format != '\0' && **format <= 32) {
    (*format)++;
    format_pushed = 1;
  }
  while (**str != '\0' && **str <= 32 && format_pushed) (*str)++;
}

int is_len_specifier(char c) { return c == 'h' || c == 'l' || c == 'L'; }

int s21_is_digit(char c) { return '0' <= c && c <= '9'; }

int s21_is_hex_letter(char c) { return 'a' <= c && c <= 'f'; }

void s21_select_width(const char **format, SSCANF_PARAMS *param) {
  int sign = 0;
  s21_set_sign(format, &sign);
  for (int mult = 1; s21_is_digit(**format); (*format)++, mult = 10)
    param->width = param->width * mult + (**format - '0');
  if (sign != 0) param->width = -1;
}

long int select_number_from_str(const char **str, SSCANF_PARAMS *param) {
  int inf_width = (param->width == 0);
  long int num = 0;
  int len = 0;
  const char *start = *str;
  if (param->sign == 0)
    param->sign = 1;
  else
    start--;

  for (; s21_is_digit(**str) && ((*str - start) < param->width || inf_width);
       (*str)++) {
    num = num * 10 + (**str - '0');
    len++;
  }

  if (*str - start <= 0) param->error = 1;
  if (len == 0) param->accepted = 0;
  return param->sign * num;
}

long double select_real_from_str(const char **str, SSCANF_PARAMS *param) {
  s21_set_sign(str, &(param->sign));
  int inf_width = (param->width == 0);
  long double num = 0;
  int ex = 0, ex_sign = 1, len = 0;
  const char *start = *str;
  if (param->sign == 0)
    param->sign = 1;
  else
    start--;
  for (; s21_is_digit(**str) && ((*str - start) < param->width || inf_width);
       (*str)++) {
    num = num * 10 + (**str - '0');
    len++;
  }
  if (**str == '.' && ((*str - start) < param->width || inf_width)) {
    (*str)++;
    len++;
    long double fl = 10L;
    for (; s21_is_digit(**str) && ((*str - start) < param->width || inf_width);
         (*str)++) {
      num = num + (**str - '0') / fl;
      fl *= 10;
      len++;
    }
  }
  if (**str == 'e' && len > 0 && ((*str - start) < param->width || inf_width)) {
    (*str)++;
    len++;
    if (**str == '-' || **str == '+') {
      if (**str == '-') ex_sign = -1;
      (*str)++;
    }
    for (; s21_is_digit(**str) && ((*str - start) < param->width || inf_width);
         (*str)++) {
      ex = ex * 10 + (**str - '0');
      len++;
    }
  }
  if (*str - start <= 0) param->error = 1;
  if (len == 0) param->accepted = 0;
  return param->sign * num * pow(10, ex * ex_sign);
}

long int select_hex_from_string(const char **str, SSCANF_PARAMS *param) {
  int inf_width = (param->width == 0);
  long int num = 0;
  int len = 0;
  const char *start = *str;
  if (param->sign == 0)
    param->sign = 1;
  else
    start--;
  // check hex prefix
  if (**str == '0' && ((*str - start) < param->width || inf_width)) {
    (*str)++;
    len++;
  }
  if (s21_lower(**str) == 'x' && ((*str - start) < param->width || inf_width)) {
    (*str)++;
    len++;
  }
  int slag;
  // create low = lower of cur symbol, if (digit or a-e letter) -> process
  // letter to digit, num = num + new
  for (char low = s21_lower(**str);
       (s21_is_digit(low) || s21_is_hex_letter(low)) &&
       ((*str - start) < param->width || inf_width);
       ++(*str), low = s21_lower(**str)) {
    if (s21_is_hex_letter(low))
      slag = 10 + (low - 'a');
    else
      slag = low - '0';

    if (num * 16 + slag < 0)
      num = INT64_MAX;
    else
      num = num * 16 + slag;
    len++;
  }
  if (*str - start <= 0) param->error = 1;
  if (len == 0) param->accepted = 0;
  return param->sign * num;
}

long int select_oct_from_string(const char **str, SSCANF_PARAMS *param) {
  int inf_width = (param->width == 0);
  long int num = 0;
  int len = 0;
  const char *start = *str;
  if (param->sign == 0)
    param->sign = 1;
  else
    start--;
  // check octal prefix
  if (**str == '0' && ((*str - start) < param->width || inf_width)) {
    len++;
    (*str)++;
  }
  for (; s21_is_digit(**str) && (**str - '0') < 8 &&
         ((*str - start) < param->width || inf_width);
       (*str)++) {
    num = num * 8 + (**str - '0');
    len++;
  }
  if (*str - start <= 0 || (len == 0 && (*str - start == 1))) param->error = 1;
  if (len == 0) param->accepted = 0;
  return param->sign * num;
}

int get_substr_len(const char *str) {
  int len = 0;
  while (*str > 32) {
    len++;
    str++;
  }
  return len;
}

void c_spec_process(const char **str, va_list *args, SSCANF_PARAMS *param) {
  if (param->accepted) {
    char *c = va_arg(*args, char *);
    *c = **str;
  }
  (*str)++;
}

void d_spec_process(const char **str, va_list *args, SSCANF_PARAMS *param) {
  s21_set_sign(str, &(param->sign));
  long int res = select_number_from_str(str, param);
  if (param->error) param->accepted = 0;
  if (param->accepted) {
    if (param->length == 'h') {
      short int *num = va_arg(*args, short int *);
      *num = res;
    } else if (param->length == 'l') {
      long int *num = va_arg(*args, long int *);
      *num = res;
    } else {
      int *num = va_arg(*args, int *);
      *num = res;
    }
  }
}

void i_spec_process(const char **str, va_list *args, SSCANF_PARAMS *param) {
  s21_set_sign(str, &(param->sign));
  if (**str == '0' && s21_is_digit(*(*str + 1)))
    o_spec_process(str, args, param);
  else if (**str == '0' && s21_lower(*(*str + 1)) == 'x')
    x_spec_process(str, args, param);
  else
    d_spec_process(str, args, param);
}

void u_spec_process(const char **str, va_list *args, SSCANF_PARAMS *param) {
  s21_set_sign(str, &(param->sign));
  long int res = select_number_from_str(str, param);
  if (param->error) param->accepted = 0;
  if (param->accepted) {
    if (param->length == 'h') {
      unsigned short int *num = va_arg(*args, unsigned short int *);
      *num = res;
    } else if (param->length == 'l') {
      unsigned long int *num = va_arg(*args, unsigned long int *);
      *num = res;
    } else {
      unsigned int *num = va_arg(*args, unsigned int *);
      *num = res;
    }
  }
}

void o_spec_process(const char **str, va_list *args, SSCANF_PARAMS *param) {
  s21_set_sign(str, &(param->sign));
  long int oct = select_oct_from_string(str, param);
  if (param->error) param->accepted = 0;
  if (param->accepted) {
    if (param->length == 'h') {
      unsigned short int *num = va_arg(*args, unsigned short int *);
      *num = oct;
    } else if (param->length == 'l') {
      unsigned long int *num = va_arg(*args, unsigned long int *);
      *num = oct;
    } else {
      unsigned int *num = va_arg(*args, unsigned int *);
      *num = oct;
    }
  }
}

void x_spec_process(const char **str, va_list *args, SSCANF_PARAMS *param) {
  s21_set_sign(str, &(param->sign));
  long int hex = select_hex_from_string(str, param);
  if (param->error) param->accepted = 0;
  if (param->accepted) {
    if (param->length == 'h') {
      unsigned short int *num = va_arg(*args, unsigned short int *);
      *num = hex;
    } else if (param->length == 'l') {
      unsigned long int *num = va_arg(*args, unsigned long int *);
      *num = hex;
    } else {
      unsigned int *num = va_arg(*args, unsigned int *);
      *num = hex;
    }
  }
}

void s_spec_process(const char **str, va_list *args, SSCANF_PARAMS *param) {
  int len = get_substr_len(*str);
  if (len == 0) param->accepted = 0;
  if (param->accepted) {
    char *s = va_arg(*args, char *);
    if (param->width > 0 && len > param->width) len = param->width;
    s21_strncpy(s, *str, len);
    s[len] = '\0';
  }
  *str = *str + len;
}

void p_spec_process(const char **str, va_list *args, SSCANF_PARAMS *param) {
  long int hex = select_hex_from_string(str, param);
  if (param->error) param->accepted = 0;
  if (param->accepted) {
    void **num = va_arg(*args, void **);
    *num = (void *)(s21_size_t)hex;
  }
}

void real_spec_process(const char **str, va_list *args, SSCANF_PARAMS *param) {
  long double res = select_real_from_str(str, param);
  if (param->accepted) {
    if (param->length == 'L') {
      long double *num = va_arg(*args, long double *);
      *num = res;
    } else {
      float *num = va_arg(*args, float *);
      *num = res;
    }
  }
}

void n_spec_process(va_list *args, SSCANF_PARAMS *param) {
  if (param->accepted) {
    int *quantity_var = va_arg(*args, int *);
    *quantity_var = param->n_quantity;
    param->accepted = 0;
  }
}

void percent_spec_process(const char **str, SSCANF_PARAMS *param) {
  if (**str == '%')
    (*str)++;
  else
    param->error = 1;
  param->accepted = 0;
}

void s21_set_sign(const char **str, int *sign) {
  if (**str == '-' || **str == '+') {
    if (**str == '+')
      *sign = 1;
    else
      *sign = -1;
    (*str)++;
  }
}

char s21_lower(char c) {
  if ('A' <= c && c <= 'Z') c += 32;
  return c;
}
