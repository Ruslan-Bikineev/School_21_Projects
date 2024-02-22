#ifndef S21_STRING_TESTS_H
#define S21_STRING_TESTS_H

#include <check.h>
#include <limits.h>
#include <string.h>
#include "../s21_string.h"

Suite *sscanf_test_c();
Suite *sscanf_test_n();
Suite *sscanf_test_d();
Suite *sscanf_test_u();
Suite *sscanf_test_o();
Suite *sscanf_test_x();
Suite *sscanf_test_p();
Suite *sscanf_test_real();
Suite *sscanf_test_i();
Suite *sscanf_test_s();
////////////////////////
Suite *string_funcs();
////////////////////////
Suite *sprintf_test_c();
Suite *sprintf_test_d();
Suite *sprintf_test_f();
Suite *sprintf_test_s();
Suite *sprintf_test_x_X();
Suite *sprintf_test_p();
Suite *sprintf_test_o();
Suite *sprintf_test_e_E();
Suite *sprintf_test_g_G();
Suite *sprintf_test_u();

#endif  // S21_STRING_TESTS_H
