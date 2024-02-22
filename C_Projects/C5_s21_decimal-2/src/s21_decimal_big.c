#include "s21_decimal.h"

// возвращаает первый бит int'a
int s21_big_get_bit_mantissa(s21_big_decimal value, unsigned index) {
  unsigned setMask = 1 << index;
  return (value.bits[index / 32] & setMask) >> index;
}

// сдвигет big decimal на 1
int s21_shift_decimal(s21_big_decimal *value) {
  int error = 0;
  if (s21_big_get_bit_mantissa(*value, 6 * 32 - 1)) {
    error = 1;
  }
  for (int i = 5; i >= 0 && !error; i--) {
    if (s21_big_get_bit_mantissa(*value, (i + 1) * 32 - 1)) {
      value->bits[i + 1] += 1;
    }
    value->bits[i] <<= 1;
  }
  return error;
}

void s21_big_set_bit_mantissa(s21_big_decimal *value, unsigned index) {
  unsigned setMask = 1 << (index % 32);
  value->bits[index / 32] |= setMask;
}

int s21_big_significant_bits_count(s21_big_decimal value) {
  int res = 0, flag = 1;
  for (int i = 6 * 32 - 1; i >= 0 && flag; i--) {
    if (s21_big_get_bit_mantissa(value, i)) {
      res = i;
      flag = 0;
    }
  }
  return res;
}

void s21_big_decimal_div_10(s21_big_decimal *value, int scale) {
  for (int s = 0; s < scale; s++) {
    unsigned long long overflow;
    overflow = value->bits[5];
    for (int i = 5; i > 0;) {
      int tmp = overflow % 10;
      value->bits[i] = overflow / 10;
      i--;
      overflow = tmp * (1l << 32) + value->bits[i];
      if (i == 0) value->bits[i] = overflow / 10;
    }
  }
  s21_set_big_decimal_scale(value, (s21_get_big_decimal_scale(*value) - scale));
}

// перевод из big decimal в decimal
int s21_big_to_small(s21_big_decimal big, s21_decimal *result) {
  int error = 0;
  s21_big_decimal plus1 = {{1, 0, 0, 0, 0, 0, big.bits[6]}};
  // если scale > 28 то его надо уменьшать и округлять decimal
  while (s21_get_big_decimal_scale(big) > 28 ||
         (s21_big_significant_bits_count(big) > 95 &&
          s21_get_big_decimal_scale(big) > 0)) {
    int last = s21_get_big_last_digit(big);
    s21_big_decimal_div_10(&big, 1);
    // округляем если больше 5 или 5 и пред число нечетное
    if ((last >= 5 && s21_get_big_last_digit(big) % 2 != 0) || (last > 5)) {
      error = s21_big_add(plus1, big, &big);
    }
  }
  if ((s21_big_significant_bits_count(big) > 95 &&
       s21_get_big_decimal_scale(big) == 0) ||
      (s21_get_big_decimal_scale(big) > 28))
    error = 1;
  result->bits[0] = big.bits[0];
  result->bits[1] = big.bits[1];
  result->bits[2] = big.bits[2];
  result->bits[3] = big.bits[6];
  return error;
}

// set new scale to big decimal
void s21_set_big_decimal_scale(s21_big_decimal *number, int scale) {
  number->bits[6] &= s21_get_big_decimal_sign(*number)
                     << 31;  // зануляем весь инт (кроме знака)
  number->bits[6] |= scale << 16;  // сетим новый скейл
}

// обнуление
void s21_zeroing_big_decimal(s21_big_decimal *number) {
  number->bits[0] = 0;
  number->bits[1] = 0;
  number->bits[2] = 0;
  number->bits[3] = 0;
  number->bits[4] = 0;
  number->bits[5] = 0;
}

void s21_zeroing_decimal(s21_decimal *number) {
  number->bits[0] = 0;
  number->bits[1] = 0;
  number->bits[2] = 0;
  number->bits[3] = 0;
}

int s21_get_big_decimal_scale(s21_big_decimal number) {
  return (number.bits[6] >> 16) & ((1 << 8) - 1);
}

int s21_get_big_decimal_sign(s21_big_decimal number) {
  return (number.bits[6] >> 31) & 1;
}

void s21_big_force_div(s21_big_decimal *value, int scale) {
  for (int i = 0; i < scale; i++) {
    unsigned long long overflow;
    overflow = value->bits[5];
    for (int i = 5; i > 0;) {
      int tmp = overflow % 10;
      value->bits[i] = overflow / 10;
      i--;
      overflow = tmp * (1l << 32) + value->bits[i];
      if (i == 0) value->bits[i] = overflow / 10;
    }
  }
}

void s21_big_force_mult(s21_big_decimal *value, int *scale) {
  for (int error = 0, i = 0; i < *scale && !error;) {
    s21_big_decimal temp_value = {};
    unsigned long long temp = value->bits[0] * 10l;
    unsigned long long mod = temp % (1l << 32);
    unsigned long long div = temp / (1l << 32);
    temp_value.bits[0] = mod;

    for (int j = 1; j < 5; j++) {
      temp = value->bits[j] * 10l + div;
      mod = temp % (1l << 32);
      temp_value.bits[j] = mod;
      div = temp / (1l << 32);
    }

    temp = value->bits[5] * 10l + div;
    error = temp + 1 > (1l << 32);  // вышел за пределы unsigned
    if (!error) {
      value->bits[0] = temp_value.bits[0];
      value->bits[1] = temp_value.bits[1];
      value->bits[2] = temp_value.bits[2];
      value->bits[3] = temp_value.bits[3];
      value->bits[4] = temp_value.bits[4];
      value->bits[5] = temp;
      i++;
    }
  }
}

void s21_big_set_bit_mantissa_0(s21_big_decimal *value, unsigned index) {
  unsigned setMask = ~(1 << (index % 32));
  value->bits[index / 32] &= setMask;
}

// возвращает последнюю цифру числа
int s21_get_big_last_digit(s21_big_decimal number) {
  s21_big_decimal temp = {{number.bits[0], number.bits[1], number.bits[2],
                           number.bits[3], number.bits[4], number.bits[5],
                           number.bits[6]}};
  s21_big_force_div(&number, 1);
  int a = 1;
  s21_big_force_mult(&number, &a);
  s21_big_decimal res = {{}};
  s21_big_sub(temp, number, &res);
  return res.bits[0];
}