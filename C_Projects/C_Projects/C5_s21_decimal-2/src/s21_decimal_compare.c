#include "s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return s21_compare_decimal(value_1, value_2) > 0;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_compare_decimal(value_1, value_2) >= 0;
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  return s21_compare_decimal(value_1, value_2) < 0;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_compare_decimal(value_1, value_2) <= 0;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_compare_decimal(value_1, value_2) == 0;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_compare_decimal(value_1, value_2) != 0;
}

int s21_compare_decimal(s21_decimal value_1, s21_decimal value_2) {
  if ((value_2.bits[0] | value_2.bits[1] | value_2.bits[2]) == 0) {
    return (value_1.bits[0] | value_1.bits[1] | value_1.bits[2]) != 0;
  }
  if ((value_1.bits[0] | value_1.bits[1] | value_1.bits[2]) == 0) {
    return -1;
  }
  int sign = (value_1.bits[3] >> 31) - (value_2.bits[3] >> 31);
  if (sign != 0) return -sign;
  return s21_bitwise_compare(value_1, value_2);
}

// битовое сравнение
int s21_bitwise_compare(s21_decimal value_1, s21_decimal value_2) {
  // нормализуем децималы
  s21_normalize_decimals(&value_1, &value_2);
  // берем знак первого
  int sign = 1, negative_cf = s21_get_decimal_sign(value_1) ? -1 : 1;
  long diff = (long)value_1.bits[2] - value_2.bits[2];
  // возвращаем для каждого инта 1, -1 (чей инт больше)
  if (diff != 0) {
    if (diff < 0) sign = -sign;
    return negative_cf * sign;
  }
  diff = (long)value_1.bits[1] - value_2.bits[1];
  if (diff != 0) {
    if (diff < 0) sign = -sign;
    return negative_cf * sign;
  }
  diff = (long)value_1.bits[0] - value_2.bits[0];
  if (diff == 0)
    sign = 0;
  else if (diff < 0)
    sign = -sign;
  return negative_cf * sign;
}

// знак максимального из двух децималов
int s21_max_significant_sign(s21_decimal value_1, s21_decimal value_2) {
  return s21_significant_bits_count(value_1) >
                 s21_significant_bits_count(value_2)
             ? s21_get_decimal_sign(value_1)
             : s21_get_decimal_sign(value_2);
}