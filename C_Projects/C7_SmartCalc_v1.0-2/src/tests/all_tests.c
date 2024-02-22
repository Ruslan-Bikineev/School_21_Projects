#include "tests.h"

START_TEST(test_incorrect_brackets_1) {
  // Arrange
  char str[] = {"((1+3)+4*5*6^7"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_1);
}
END_TEST

START_TEST(test_incorrect_brackets_2) {
  // Arrange
  char str[] = {"(1+3))+4*5*6^7"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_1);
}
END_TEST

START_TEST(test_incorrect_brackets_3) {
  // Arrange
  char str[] = {"(1+(3+4*5)*6^7"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_1);
}
END_TEST

START_TEST(test_incorrect_brackets_4) {
  // Arrange
  char str[] = {"1+(3+4)*5)*6^7"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_1);
}
END_TEST

START_TEST(test_incorrect_input_1) {
  // Arrange
  char str[] = {"1+(3+4)*/5*6^7"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_2);
}
END_TEST

START_TEST(test_incorrect_input_2) {
  // Arrange
  char str[] = {"sin(sin(/2)+1)"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_2);
}
END_TEST

START_TEST(test_incorrect_input_3) {
  // Arrange
  char str[] = {"sin(sin(2)++1)"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_2);
}
END_TEST

START_TEST(test_incorrect_input_4) {
  // Arrange
  char str[] = {"-(mod35)"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_2);
}
END_TEST

START_TEST(test_incorrect_input_5) {
  // Arrange
  char str[] = {"sin(.125+1.04)+1"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_2);
}
END_TEST

START_TEST(test_nan) {
  // Arrange
  char str[] = {"atan(1.2*34)-asin(5.67)-log(8.90)*x"};
  int error = 0;
  double x = 2.2531;
  double actual_result = 0;
  double expected_result = atan(1.2 * 34) - asin(5.67) - log10(8.9) * x;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_double_nan(actual_result);
  ck_assert_double_nan(expected_result);
}
END_TEST

START_TEST(test_div_null_1) {
  // Arrange
  char str[] = {"ln(sin(2)+1.13154547)/x"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_3);
}
END_TEST

START_TEST(test_div_null_2) {
  // Arrange
  char str[] = {"2mod1.13154547/x"};
  int error = 0;
  double x = 0.00000001;
  double actual_result = 0;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, ERROR_3);
}
END_TEST

START_TEST(test_div_null_3) {
  // Arrange
  char str[] = {"log(cos(2)+1.13154547)/x"};
  int error = 0;
  double x = 0.0000001;
  double actual_result = 0;
  double expected_result = log10(cos(2) + 1.13154547) / x;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(actual_result, expected_result, PRECISION);
}
END_TEST

START_TEST(test_OK_1) {
  // Arrange
  char str[] = {"acos(1)+1.26531+(3+4.56)/5.15635*6.213^7"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  double expected_result =
      acos(1) + 1.26531 + (3 + 4.56) / 5.15635 * pow(6.213, 7);
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(actual_result, expected_result, PRECISION);
}
END_TEST

START_TEST(test_OK_2) {
  // Arrange
  char str[] = {"sqrt(2.3*2)+1.55-2*(2.65+3^2)"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  double expected_result = sqrt(2.3 * 2) + 1.55 - 2 * (2.65 + pow(3, 2));
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(actual_result, expected_result, PRECISION);
}
END_TEST

START_TEST(test_OK_3) {
  // Arrange
  char str[] = {"cos(sin(2)+1.13154547)*x"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  double expected_result = cos(sin(2) + 1.13154547) * x;
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(actual_result, expected_result, PRECISION);
}
END_TEST

START_TEST(test_OK_4) {
  // Arrange
  char str[] = {"-(15514.135mod35.15548)-tan(-1.15)"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  double expected_result = -(fmod(15514.135, 35.15548)) - tan(-1.15);
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(actual_result, expected_result, PRECISION);
}
END_TEST

START_TEST(test_unarny_OK_5) {
  // Arrange
  char str[] = {"-(-1)+(+3+4)*5*6^7"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  double expected_result = -(-1) + (+3 + 4) * 5 * pow(6, 7);
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(actual_result, expected_result, PRECISION);
}
END_TEST

START_TEST(test_unarny_OK_6) {
  // Arrange
  char str[] = {"-(tan(atan(0.5)))+acos(0.05-(+0.003))-cos(3^2)"};
  int error = 0;
  double x = 0;
  double actual_result = 0;
  double expected_result =
      -(tan(atan(0.5))) + acos(+0.05 - +0.003) - cos(pow(3, 2));
  // Act
  smart_calc(str, &error, x, &actual_result);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(actual_result, expected_result, PRECISION);
}
END_TEST

Suite *all_tests(void) {
  Suite *s = suite_create("brackets function suite");

  TCase *all_tests = tcase_create("smart_calc function tests brackets");
  tcase_add_test(all_tests, test_incorrect_brackets_1);
  tcase_add_test(all_tests, test_incorrect_brackets_2);
  tcase_add_test(all_tests, test_incorrect_brackets_3);
  tcase_add_test(all_tests, test_incorrect_brackets_4);
  tcase_add_test(all_tests, test_incorrect_input_1);
  tcase_add_test(all_tests, test_incorrect_input_2);
  tcase_add_test(all_tests, test_incorrect_input_3);
  tcase_add_test(all_tests, test_incorrect_input_4);
  tcase_add_test(all_tests, test_incorrect_input_5);
  tcase_add_test(all_tests, test_nan);
  tcase_add_test(all_tests, test_div_null_1);
  tcase_add_test(all_tests, test_div_null_2);
  tcase_add_test(all_tests, test_div_null_3);
  tcase_add_test(all_tests, test_OK_1);
  tcase_add_test(all_tests, test_OK_2);
  tcase_add_test(all_tests, test_OK_3);
  tcase_add_test(all_tests, test_OK_4);
  tcase_add_test(all_tests, test_unarny_OK_5);
  tcase_add_test(all_tests, test_unarny_OK_6);
  suite_add_tcase(s, all_tests);

  return s;
}