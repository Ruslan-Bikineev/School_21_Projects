#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXBYTE 4294967295

typedef struct {
  unsigned bits[4];
} s21_decimal;

typedef struct {
  unsigned bits[7];
} s21_big_decimal;

/*-------------------------GENERAL-------------------------*/
int s21_get_decimal_sign(s21_decimal value);
int s21_get_decimal_scale(s21_decimal value);
void s21_set_decimal_sign(s21_decimal *value, int sign);
void s21_set_decimal_scale(s21_decimal *value, int scale);
void s21_set_bit_mantissa(s21_decimal *value, unsigned index);
int s21_get_bit_mantissa(s21_decimal value, unsigned index);
void s21_decimal_mult_10(s21_decimal *value, int *scale);
void s21_decimal_div_10(s21_decimal *value, int scale);
int s21_significant_bits_count(s21_decimal value);
int s21_shift_left(s21_decimal *value);
void s21_normalize_decimals(s21_decimal *value_1, s21_decimal *value_2);
bool s21_check_null(s21_decimal value);
int s21_calculate_div_cicle_1(s21_decimal *value_1, s21_decimal value_2,
                              int *error);
int s21_get_last_digit(s21_decimal number);
void s21_set_all_decimal_0(s21_decimal *number);
int s21_check_error_sub(s21_decimal value_1, s21_decimal value_2);
int s21_check_max_decimal_mantissa(s21_decimal value);
void s21_dec_1_transfer_to_dec_2(s21_decimal value_1, s21_decimal *value_2);
int s21_init_negatif_sign(s21_decimal *value_1, s21_decimal *value_2);
int s21_check_erorr_div(s21_decimal value_1, s21_decimal value_2);
void s21_proccesing_result(s21_decimal value_1, s21_decimal *result,
                           int init_negatif_sign, bool init_max_scale);
int s21_calculate_div_cicle_2(s21_decimal *value_1, s21_decimal *value_2,
                              s21_decimal *result, int *actual_scale);
int s21_set_max_scale(s21_decimal *value_1, s21_decimal *value_2,
                      bool *init_max_scale);
int s21_main_div_cicle(s21_decimal *value_1, s21_decimal *value_2,
                       s21_decimal *result, int *actual_scale);

/*-------------------------ARITHMETIC------------------------*/
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_big_add(s21_big_decimal number_1, s21_big_decimal number_2,
                s21_big_decimal *result);
void s21_big_sub(s21_big_decimal number_1, s21_big_decimal number_2,
                 s21_big_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal number_1, s21_decimal number_2, s21_decimal *result);
void s21_force_div(s21_decimal *value, int scale);
void s21_force_mult(s21_decimal *value, int *scale);
int s21_check_sub_mode(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result);
/*-------------------------BIG------------------------*/
int s21_big_get_bit_mantissa(s21_big_decimal value, unsigned index);
void s21_big_set_bit_mantissa(s21_big_decimal *value, unsigned index);
void s21_zeroing_decimal(s21_decimal *number);
void s21_zeroing_big_decimal(s21_big_decimal *number);
void s21_set_big_decimal_scale(s21_big_decimal *number, int scale);
int s21_get_big_decimal_sign(s21_big_decimal number);
int s21_get_big_decimal_scale(s21_big_decimal number);
int s21_big_to_small(s21_big_decimal big, s21_decimal *res);
int s21_significant_bits_count(s21_decimal value);
int s21_shift_decimal(s21_big_decimal *value);
void s21_big_decimal_div_10(s21_big_decimal *value, int scale);
int s21_get_big_last_digit(s21_big_decimal number);
void s21_big_force_div(s21_big_decimal *value, int scale);
void s21_big_force_mult(s21_big_decimal *value, int *scale);
void s21_big_set_bit_mantissa_0(s21_big_decimal *value, unsigned index);
int s21_big_significant_bits_count(s21_big_decimal value);
/*-------------------------COMPARING-------------------------*/
int s21_max_significant_sign(s21_decimal value_1, s21_decimal value_2);
int s21_compare_decimal(s21_decimal value_1, s21_decimal value_2);
int s21_bitwise_compare(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
/*--------------------------OTHER--------------------------*/
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
/*------------------------CONVERTERS-----------------------*/
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
unsigned *s21_to_binary(long long unsigned src);
void s21_write_to_decimal(s21_decimal *dst, const unsigned *binary);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_write_to_int(s21_decimal src);
int s21_from_float_to_decimal(float src, s21_decimal *dst);

#endif