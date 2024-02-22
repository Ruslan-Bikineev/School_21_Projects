#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0, res_sign = s21_get_decimal_sign(value_1);
  s21_zeroing_decimal(result);
  // нормализуем к большему скейлу
  s21_normalize_decimals(&value_1, &value_2);
  if (s21_get_decimal_sign(value_1) !=
      s21_get_decimal_sign(value_2)) {  // знаки не равны
    res_sign =
        s21_max_significant_sign(value_1, value_2);  // берем знак максимального
    s21_set_decimal_sign(&value_1, 0);
    s21_set_decimal_sign(&value_2, 0);
    if (s21_significant_bits_count(value_1) >
        s21_significant_bits_count(value_2))
      error = s21_sub(value_1, value_2, result);
    else
      error = s21_sub(value_2, value_1, result);
    s21_set_decimal_sign(result, res_sign);
    s21_set_decimal_scale(result, s21_get_decimal_scale(value_1));
  } else {
    s21_set_decimal_sign(result, res_sign);
    s21_set_decimal_scale(result, s21_get_decimal_scale(value_1));
    s21_big_decimal big_1 = {{value_1.bits[0], value_1.bits[1], value_1.bits[2],
                              0, 0, 0, value_1.bits[3]}};
    s21_big_decimal big_2 = {{value_2.bits[0], value_2.bits[1], value_2.bits[2],
                              0, 0, 0, value_2.bits[3]}};
    s21_big_decimal big_res = {};
    // складываем в биг децимал и там считаем
    if (!s21_big_add(big_1, big_2, &big_res)) {
      big_res.bits[6] = result->bits[3];
      error = s21_big_to_small(big_res, result);
    }
  }
  return error;
}

// умножение децималов
// проверить сумму значимых битов | если больше 96 то переполнение
// степень не далжна быть больше чем 28, инаяе ей пизда
int s21_mul(s21_decimal number_1, s21_decimal number_2, s21_decimal *result) {
  int error = 0;
  s21_zeroing_decimal(result);
  s21_set_decimal_scale(result, s21_get_decimal_scale(number_1) +
                                    s21_get_decimal_scale(number_2));
  if (s21_get_decimal_sign(number_1) == s21_get_decimal_sign(number_2))
    s21_set_decimal_sign(result, 0);
  else
    s21_set_decimal_sign(result, 1);
  int significant_1 = s21_significant_bits_count(number_1);
  s21_big_decimal res = {{}};  // результат записанный в big decimal
  for (int i = 0; i <= significant_1; i++) {
    if (s21_get_bit_mantissa(number_1, i)) {
      s21_big_decimal temp = {{number_2.bits[0], number_2.bits[1],
                               number_2.bits[2], 0, 0, 0, number_2.bits[3]}};
      for (int j = 0; j < i; j++) {
        error = s21_shift_decimal(&temp);
      }
      s21_big_add(temp, res, &res);
    }
  }
  res.bits[6] = result->bits[3];
  if (res.bits[0] | res.bits[1] | res.bits[2] | res.bits[3] | res.bits[4] |
      res.bits[5])
    error = s21_big_to_small(res, result);
  else
    result->bits[3] = 0;
  return error;
}

/* Вычитание */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int mode, error = s21_check_error_sub(value_1, value_2);
  if (!error) {
    s21_set_all_decimal_0(result);
    s21_normalize_decimals(&value_1, &value_2);
    s21_set_decimal_scale(result, s21_get_decimal_scale(value_1));
    s21_big_decimal big_1 = {{value_1.bits[0], value_1.bits[1], value_1.bits[2],
                              0, 0, 0, value_1.bits[3]}};
    s21_big_decimal big_2 = {{value_2.bits[0], value_2.bits[1], value_2.bits[2],
                              0, 0, 0, value_2.bits[3]}};
    s21_big_decimal big_res = {};
    mode = s21_check_sub_mode(value_1, value_2, result);
    switch (mode) {
      case 1:
        error = s21_big_add(big_1, big_2, &big_res);
        break;
      case 2:
        s21_big_sub(big_1, big_2, &big_res);
        break;
      case 3:
        s21_big_sub(big_2, big_1, &big_res);
        break;
    }
    big_res.bits[6] = result->bits[3];
    error = s21_big_to_small(big_res, result);
  }
  return error;
}

/* Деление */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_set_all_decimal_0(result);
  s21_decimal one = {{1, 0, 0, 0}};
  int error = 0, init_negatif_sign = 0;
  bool init_max_scale = false;
  if (s21_check_null(value_2)) {
    error = 3;
  } else if (s21_is_equal(value_1, value_2)) {
    result->bits[0] = 1;
  } else if (s21_is_equal(value_2, one)) {
    s21_dec_1_transfer_to_dec_2(value_1, result);
  } else {
    s21_normalize_decimals(&value_1, &value_2);
    /*после нормализации степени должны быть одинаковыми, после чего зануляем
     * степени для правильного расчета*/
    if (s21_get_decimal_scale(value_1) > 0) {
      s21_set_decimal_scale(&value_1, 0);
      s21_set_decimal_scale(&value_2, 0);
    }
    if (!(s21_check_null(value_1))) {
      if (s21_check_null(value_2)) {
        error = s21_check_erorr_div(value_1, value_2);
      } else {
        int actual_scale = s21_get_decimal_scale(value_1);
        // check negative sign
        init_negatif_sign = s21_init_negatif_sign(&value_1, &value_2);
        actual_scale = s21_set_max_scale(&value_1, &value_2, &init_max_scale);
        error = s21_main_div_cicle(&value_1, &value_2, result, &actual_scale);
        if (!s21_check_null(*result)) {
          s21_set_decimal_scale(&value_1, actual_scale);
        }
      }
    }
    s21_proccesing_result(value_1, result, init_negatif_sign, init_max_scale);
  }
  return error;
}