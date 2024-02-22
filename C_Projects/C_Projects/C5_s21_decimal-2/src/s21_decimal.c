#include "s21_decimal.h"

/* Устанавливает в указанный бит(index) 1 */
void s21_set_bit_mantissa(s21_decimal *value, unsigned index) {
  unsigned setMask = 1 << (index % 32);
  value->bits[index / 32] |= setMask;
}

/* Показывает указанный бит(index) 1 или 0 */
int s21_get_bit_mantissa(s21_decimal value, unsigned index) {
  unsigned setMask = 1 << (index % 32);
  return (value.bits[index / 32] & setMask) >> (index % 32);
}

/* Проверка числа на ноль, если вывод 1 то число ноль */
bool s21_check_null(s21_decimal value) {
  bool result = true;
  for (int i = 0; i < 3; i++) {
    if (value.bits[i] != 0) {
      result = false;
    }
  }
  return result;
}

// set new sign decimal
void s21_set_decimal_sign(s21_decimal *value, int sign) {
  value->bits[3] &= ~(1 << 31);  // зануляем текущий знак
  value->bits[3] |= sign << 31;  // сетим новый
}

// return 1 if negative, 0 if positive
int s21_get_decimal_sign(s21_decimal value) {
  return (value.bits[3] >> 31) & 1;
}

// return power of 10 (number scale)
int s21_get_decimal_scale(s21_decimal value) {
  return (value.bits[3] >> 16) & ((1 << 8) - 1);
}

// set new scale to decimal
void s21_set_decimal_scale(s21_decimal *value, int scale) {
  value->bits[3] &= s21_get_decimal_sign(*value)
                    << 31;  // зануляем весь инт (кроме знака)
  value->bits[3] |= scale << 16;  // сетим новый скейл
}

// умножение мантисы на 10 (return 1, если переполнение)
void s21_decimal_div_10(s21_decimal *value, int scale) {
  s21_force_div(value, scale);
  s21_set_decimal_scale(value, (s21_get_decimal_scale(*value) - scale));
}

void s21_force_div(s21_decimal *value, int scale) {
  for (int s = 0; s < scale; s++) {
    unsigned long long overflow;
    overflow = value->bits[2];
    for (int i = 2; i > 0;) {
      int tmp = overflow % 10;
      value->bits[i] = overflow / 10;
      i--;
      overflow = tmp * (1l << 32) + value->bits[i];
      if (i == 0) value->bits[i] = overflow / 10;
    }
  }
}

// умножение мантисы на 10 (return 1, если переполнение)
void s21_decimal_mult_10(s21_decimal *value, int *scale) {
  int old_scale = *scale;
  s21_force_mult(value, scale);
  s21_set_decimal_scale(value,
                        s21_get_decimal_scale(*value) + (old_scale - *scale));
}

void s21_force_mult(s21_decimal *value, int *scale) {
  int i = 0;
  for (int error = 0; i < *scale && !error;) {
    s21_decimal temp_value = {};
    unsigned long long temp = value->bits[0] * 10l;
    unsigned long long mod = temp % (1l << 32);
    unsigned long long div = temp / (1l << 32);
    temp_value.bits[0] = mod;

    temp = value->bits[1] * 10l + div;
    mod = temp % (1l << 32);
    temp_value.bits[1] = mod;
    div = temp / (1l << 32);
    temp = value->bits[2] * 10l + div;
    error = (temp + 1) > (1l << 32);  // вышел за пределы unsigned
    if (!error) {
      value->bits[0] = temp_value.bits[0];
      value->bits[1] = temp_value.bits[1];
      value->bits[2] = temp;
      i++;
    }
  }
  (*scale) -= i;
}

// нормализация decimals (умножает на 10 децимал с меньшим скейлом, пока не
// переполнен)
void s21_normalize_decimals(s21_decimal *value_1, s21_decimal *value_2) {
  int scale = s21_get_decimal_scale(*value_2) - s21_get_decimal_scale(*value_1);
  if (scale != 0) {
    s21_decimal *first = value_1;
    s21_decimal *second = value_2;
    if (scale < 0) {
      scale = -scale;
      first = value_2;
      second = value_1;
    }
    // умножаем дец. на 10, пока не переполнен
    s21_decimal_mult_10(first, &scale);
    s21_decimal_div_10(second, scale);
  }
}

// кол-во значимых битов
int s21_significant_bits_count(s21_decimal value) {
  int res = 0, flag = 1;
  for (int i = 95; i >= 0 && flag; i--) {
    if (s21_get_bit_mantissa(value, i)) {
      res = i;
      flag = 0;
    }
  }
  return res;
}

int s21_shift_left(s21_decimal *value) {
  int error = s21_get_bit_mantissa(*value, 95);
  if (!error) {
    value->bits[2] <<= 1;

    value->bits[2] += s21_get_bit_mantissa(*value, 63);
    value->bits[1] <<= 1;

    value->bits[1] += s21_get_bit_mantissa(*value, 31);
    value->bits[0] <<= 1;
  }
  return error;
}

// возвращает последнюю цифру числа
int s21_get_last_digit(s21_decimal number) {
  s21_decimal temp = {
      {number.bits[0], number.bits[1], number.bits[2], number.bits[3]}};
  s21_force_div(&number, 1);
  int a = 1;
  s21_force_mult(&number, &a);
  s21_decimal res = {{}};
  s21_sub(temp, number, &res);
  return res.bits[0];
}

/* Обнуляет полностью всё число s21_decimal*/
void s21_set_all_decimal_0(s21_decimal *number) {
  for (int i = 0; i <= 4; i++) {
    (*number).bits[i] = 0;
  }
}

/* return 1 if mantissa is max else return 0 */
int s21_check_max_decimal_mantissa(s21_decimal value) {
  int result = 1;
  for (int i = 0; i < 3 && result; i++) {
    if (value.bits[i] != MAXBYTE) {
      result = 0;
    }
  }
  return result;
}

/* Functions for sub, Don't touch! */
int s21_check_error_sub(s21_decimal value_1, s21_decimal value_2) {
  int error = 0;
  int val_1_sign = s21_get_decimal_sign(value_1);
  int val_2_sign = s21_get_decimal_sign(value_2);

  if ((val_1_sign && !val_2_sign && s21_check_max_decimal_mantissa(value_2)) ||
      (!val_1_sign && val_2_sign && s21_check_max_decimal_mantissa(value_1))) {
    error = 2;
  }
  return error;
}

int s21_check_sub_mode(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result) {
  int mode = 0, mode_two_minus = 0;
  int val_1_sign = s21_get_decimal_sign(value_1);
  int val_2_sign = s21_get_decimal_sign(value_2);

  if (val_1_sign && val_1_sign) {
    mode_two_minus = 1;
    s21_set_decimal_sign(&value_1, 0);
    s21_set_decimal_sign(&value_2, 0);
  }
  if ((val_1_sign && !val_2_sign) || (!val_1_sign && val_2_sign)) {
    mode = 1;
    if ((val_1_sign && !val_2_sign)) {
      s21_set_decimal_sign(result, 1);
    }
  } else if (s21_is_greater_or_equal(value_1, value_2)) {
    mode = 2;
    if (mode_two_minus) {
      s21_set_decimal_sign(result, 1);
    }
  } else if (s21_is_less_or_equal(value_1, value_2)) {
    mode = 3;
    if (!mode_two_minus) {
      s21_set_decimal_sign(result, 1);
    }
  }
  return mode;
}

void s21_big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int move = 0, count = 0, setBit = 0;
  s21_zeroing_big_decimal(result);
  // вычитаем побитово
  for (; move < 5 * 32; move++) {
    if (s21_big_get_bit_mantissa(value_1, move) == 0 &&
        s21_big_get_bit_mantissa(value_2, move) == 1) {
      bool flag = true;
      for (int j = move; j < 5 * 32 && flag; j++) {
        if (s21_big_get_bit_mantissa(value_1, j)) {
          s21_big_set_bit_mantissa_0(&value_1, j);
          count = --j;
          flag = false;
        }
      }
      for (; count >= move; count--) {
        s21_big_set_bit_mantissa(&value_1, count);
      }
      s21_big_set_bit_mantissa(result, move);
    } else {
      setBit = s21_big_get_bit_mantissa(value_1, move) -
               s21_big_get_bit_mantissa(value_2, move);
      if (setBit) {
        s21_big_set_bit_mantissa(result, move);
      } else {
        s21_big_set_bit_mantissa_0(result, move);
      }
    }
  }
}

void s21_dec_1_transfer_to_dec_2(s21_decimal value_1, s21_decimal *value_2) {
  for (int i = 0; i < 4; i++) {
    value_2->bits[i] = value_1.bits[i];
  }
}

/* Functions for add, Don't touch! */
int s21_big_add(s21_big_decimal number_1, s21_big_decimal number_2,
                s21_big_decimal *result) {
  int error = 0;
  int next_plus = 0;
  s21_zeroing_big_decimal(result);
  // складываем побитово
  for (int i = 0; i < 6 * 32; i++) {
    int bit1 = s21_big_get_bit_mantissa(number_1, i),
        bit2 = s21_big_get_bit_mantissa(number_2, i);
    int sum_bit = (bit1 + bit2 + next_plus) % 2;
    next_plus = (bit1 + bit2 + next_plus) / 2;
    if (sum_bit) s21_big_set_bit_mantissa(result, i);
  }
  // переполнение последнего бита
  if (next_plus) error = 1;
  return error;
}

/* Functions for div, Don't touch! */
int s21_main_div_cicle(s21_decimal *value_1, s21_decimal *value_2,
                       s21_decimal *result, int *actual_scale) {
  s21_decimal mask = {0};
  int error = 0, stop_cicle = 1, number = 0;
  do {
    number = s21_calculate_div_cicle_1(value_1, *value_2, &error);
    s21_set_all_decimal_0(&mask);
    s21_set_bit_mantissa(&mask, number - 1);
    error = s21_add(mask, *result, result);
    stop_cicle =
        s21_calculate_div_cicle_2(value_1, value_2, result, actual_scale);
  } while (s21_is_greater_or_equal(*value_1, *value_2) && !(error) &&
           stop_cicle);
  return error;
}

int s21_calculate_div_cicle_1(s21_decimal *value_1, s21_decimal value_2,
                              int *error) {
  unsigned move = 0, result = 0;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_decimal number_2 = {{1, 0, 0, 0}};
  s21_decimal number_3 = {0};
  for (; move < 96 && s21_is_less_or_equal(number_1, *value_1) && !(*error);
       move++) {
    result = move;
    *error = s21_mul(number_2, value_2, &number_1);
    if (s21_is_less_or_equal(number_1, *value_1)) {
      s21_dec_1_transfer_to_dec_2(number_1, &number_3);
    }
    s21_shift_left(&number_2);
  }
  *error = s21_sub(*value_1, number_3, value_1);
  return result;
}

int s21_calculate_div_cicle_2(s21_decimal *value_1, s21_decimal *value_2,
                              s21_decimal *result, int *actual_scale) {
  int stop_cicle = 1;
  float equal_value_1 = 0, equal_value_2 = 0;
  for (int mul_1 = 1, mul_2 = 1;
       s21_is_less(*value_1, *value_2) && (*actual_scale) < 28 &&
       !s21_check_null(*value_1) && stop_cicle;
       mul_1 = 1, mul_2 = 1) {
    s21_from_decimal_to_float(*result, &equal_value_1);
    s21_decimal_mult_10(value_1, &mul_1);
    /*это добавил тестово, если делимое число упирается в потолок по
     * х10, тогда понижаем делитель на х10*/
    s21_set_decimal_scale(value_2, mul_1);
    s21_decimal_div_10(value_2, mul_1);
    s21_set_decimal_scale(value_1, mul_1);
    s21_decimal_mult_10(result, &mul_2);
    /*зануляем степень для корректного сравнения*/
    s21_set_decimal_scale(value_1, 0);
    s21_set_decimal_scale(value_2, 0);
    s21_set_decimal_scale(result, 0);
    s21_from_decimal_to_float(*result, &equal_value_2);
    if (equal_value_1 == equal_value_2) {
      stop_cicle = 0;
    } else {
      (*actual_scale)++;
    }
  }
  return stop_cicle;
}

int s21_init_negatif_sign(s21_decimal *value_1, s21_decimal *value_2) {
  int init_negatif_sign = 0;
  int sign_val_1 = s21_get_decimal_sign(*value_1);
  int sign_val_2 = s21_get_decimal_sign(*value_2);
  if ((sign_val_1 && !(sign_val_2)) || (!(sign_val_1) && sign_val_2)) {
    s21_set_decimal_sign(value_1, 0);
    s21_set_decimal_sign(value_2, 0);
    init_negatif_sign = 1;
  } else if (sign_val_1 && sign_val_1) {
    s21_set_decimal_sign(value_1, 0);
    s21_set_decimal_sign(value_2, 0);
  }
  return init_negatif_sign;
}

int s21_check_erorr_div(s21_decimal value_1, s21_decimal value_2) {
  int error = 0;
  int sign_val_1 = s21_get_decimal_sign(value_1);
  int sign_val_2 = s21_get_decimal_sign(value_2);
  if ((!(sign_val_1) && !(sign_val_2)) || (sign_val_1 && sign_val_2)) {
    error = 1;
  } else {
    error = 2;
  }
  return error;
}

void s21_proccesing_result(s21_decimal value_1, s21_decimal *result,
                           int init_negatif_sign, bool init_max_scale) {
  if (init_negatif_sign) {
    s21_set_decimal_sign(result, 1);
  }
  if (init_max_scale && !s21_check_null(*result)) {
    s21_set_decimal_scale(result, 28);
  } else {
    s21_set_decimal_scale(result, s21_get_decimal_scale(value_1));
  }
}

int s21_set_max_scale(s21_decimal *value_1, s21_decimal *value_2,
                      bool *init_max_scale) {
  int max_scale = 28;
  if (s21_is_less(*value_1, *value_2)) {
    s21_decimal_mult_10(value_1, &max_scale);
    s21_set_decimal_scale(value_1, 0);
    s21_set_decimal_scale(value_2, 0);
    (*init_max_scale) = true;
  }
  return (28 - max_scale);
}