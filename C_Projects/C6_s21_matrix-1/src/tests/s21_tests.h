#ifndef S21_DECIMAL_TESTS_H
#define S21_DECIMAL_TESTS_H

#include <check.h>
#include <limits.h>

#include "../s21_matrix.h"

Suite *create_matrix();
Suite *remove_matrix();
Suite *eq_matrix();
Suite *sum_matrix();
Suite *sub_matrix();
Suite *mult_number();
Suite *mult_matrix();
Suite *transpose();
Suite *determinant();
Suite *calc_complements();
Suite *inverse_matrix();

#endif  // S21_DECIMAL_TESTS_H
