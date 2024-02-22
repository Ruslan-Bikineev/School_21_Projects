#include "s21_decimal.h"
/*
 * long int для того, чтобы установить знак и использовать положительное число
 * для случая, когда src = INT_MIN
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error_code = 0;
  long int temp = src;
  if (temp > INT_MAX || temp < INT_MIN || dst == NULL) {
    error_code = 1;
  } else {
    s21_zeroing_decimal(dst);
    if (temp < 0) {
      s21_set_decimal_sign(dst, 1);
      temp = -temp;
    }
    unsigned *binary = s21_to_binary(temp);
    s21_write_to_decimal(dst, binary);
    free(binary);
  }
  return error_code;
}

void s21_write_to_decimal(s21_decimal *dst, const unsigned *binary) {
  for (int i = 95; i >= 0; i--) {
    if (binary[i] == 1) {
      s21_set_bit_mantissa(dst, i);
    }
  }
}
/*
 * перевод числа int в двоичный вид
 */
unsigned *s21_to_binary(long long unsigned src) {
  unsigned *res = calloc(96, sizeof(unsigned));
  if (res != NULL) {
    unsigned i = 0;
    while (src != 0) {
      unsigned t = src % 2;
      res[i] = t;
      src = src / 2;
      i++;
    }
  }
  return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error_code = 0;
  if (dst == NULL) {
    error_code = 1;
  } else {
    int sign = s21_get_decimal_sign(src);
    if (sign == 0) {
      sign = 1;
    } else {
      sign = -1;
    }
    int res = s21_write_to_int(src);
    if (res == 0 && sign == -1) {
      res = INT_MIN;
      sign = 1;
    }
    *dst = sign * res;
  }
  return error_code;  // TODO
}
int s21_write_to_int(s21_decimal src) {
  int res = 0;
  int power_of_2 = 1;
  for (int i = 0; i < 32; i++, power_of_2 *= 2) {
    res += s21_get_bit_mantissa(src, i) * power_of_2;
  }
  return res;
}
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error_code = 0;
  if (dst == NULL) {  //какие еще граничные случаи?
    error_code = 1;
  } else {
    s21_zeroing_decimal(dst);
    if (src < 0) {
      src = -src;
      s21_set_decimal_sign(dst, 1);
    }
    float copy = src;
    int scale = 0;
    while (copy - (long long unsigned)copy > 1e-6 && scale < 6) {
      copy = copy * 10;
      scale++;
    }
    unsigned *binary = s21_to_binary((long long unsigned)copy);
    s21_write_to_decimal(dst, binary);
    s21_set_decimal_scale(dst, scale);
    free(binary);
  }
  return error_code;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int sign = s21_get_decimal_sign(src), scale = s21_get_decimal_scale(src);
  if (dst == NULL) return 1;
  *dst = 0;
  if (scale > 28) return 1;

  long double tmp = 0;
  for (int i = 0; i < 96; i++) tmp += pow(2, i) * s21_get_bit_mantissa(src, i);

  while (scale--) tmp /= 10.0;
  if (sign) tmp *= -1.0;
  *dst = tmp;

  return 0;
}
