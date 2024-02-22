#ifndef S21_DECIMAL_TESTS_H
#define S21_DECIMAL_TESTS_H

#include <check.h>

#include "../s21_decimal.h"

#define c30 0b00000000000111100000000000000000    // scale 30
#define c28 0b00000000000111000000000000000000    // scale 28
#define c15 0b00000000000011110000000000000000    // scale 15
#define c19 0b00000000000100110000000000000000    // scale 19
#define m7 0b10000000000001110000000000000000     // minus scale 7
#define m6 0b10000000000001100000000000000000     // minus scale 6
#define m5 0b10000000000001010000000000000000     // minus scale 5
#define c6 0b00000000000001100000000000000000     // scale 6
#define c1 0b00000000000000010000000000000000     // scale 1
#define m1 0b10000000000000010000000000000000     // minus scale 1
#define minus 0b10000000000000000000000000000000  // minus scale 0

Suite *addition_tests();
Suite *sub_tests();
Suite *mul_tests();
Suite *div_tests();
////////////////////////
Suite *greater_tests();
Suite *less_tests();
Suite *equal_tests();
////////////////////////
Suite *round_tests();
Suite *truncate_tests();
Suite *floor_tests();
Suite *negate_tests();
////////////////////////
Suite *dec_to_float_tests();
///////////////////////
Suite *int_to_dec_tests();
Suite *dec_to_int_tests();
Suite *float_to_dec_tests();

#endif  // S21_DECIMAL_TESTS_H
