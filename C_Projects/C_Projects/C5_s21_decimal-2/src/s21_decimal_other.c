#include "s21_decimal.h"

/* Возвращает целые цифры указанного Decimal числа; любые дробные цифры
 * отбрасываются, включая конечные нули. */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int scale = s21_get_decimal_scale(value), error = 0;
  if (scale > 28 || result == NULL) {
    error = 1;
  } else {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = value.bits[3];

    s21_decimal_div_10(result, scale);
  }
  return error;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int scale = s21_get_decimal_scale(value), error = 0;
  if (scale > 28 || result == NULL) {
    error = 1;
  } else {
    int sign = s21_get_decimal_sign(value);
    if (!sign) {  // положительное - отбрасываем дробную
      error = s21_truncate(value, result);
    } else {  // отрицательное - если дробная не 0, делаем -1
      int is_fraction = 0;
      s21_set_decimal_sign(&value, 0);
      for (int i = 0; i < scale; i++) {
        is_fraction = is_fraction || s21_get_last_digit(value);
        s21_decimal_div_10(&value, 1);
      }
      s21_decimal plus_one = {{1, 0, 0, value.bits[3]}};
      if (is_fraction) s21_add(value, plus_one, &value);
      result->bits[0] = value.bits[0];
      result->bits[1] = value.bits[1];
      result->bits[2] = value.bits[2];
      s21_set_decimal_sign(result, sign);
    }
  }
  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int scale = s21_get_decimal_scale(value), error = 0;
  if (scale > 28 || result == NULL) {
    error = 1;
  } else {
    int sign = s21_get_decimal_sign(value);
    if (!sign) {  // положительное - отбрасываем дробную
      error = s21_truncate(value, result);
    } else {  // отрицательное - если дробная не 0, делаем -1
      s21_set_decimal_sign(&value, 0);
      int last_digit;
      for (int i = 0; i < scale; i++) {
        last_digit = s21_get_last_digit(value);
        s21_decimal_div_10(&value, 1);
      }
      s21_decimal plus_one = {{1, 0, 0, value.bits[3]}};
      if (last_digit >= 5) s21_add(value, plus_one, &value);
      result->bits[0] = value.bits[0];
      result->bits[1] = value.bits[1];
      result->bits[2] = value.bits[2];
      s21_set_decimal_sign(result, sign);
    }
  }
  return error;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int scale = s21_get_decimal_scale(value), error = 0;
  if (scale > 28 || result == NULL) {
    error = 1;
  } else {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = value.bits[3];

    s21_set_decimal_sign(result, 1 - s21_get_decimal_sign(*result));
  }
  return error;
}