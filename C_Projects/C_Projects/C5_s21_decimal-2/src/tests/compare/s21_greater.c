#include "../s21_tests.h"

START_TEST(greater_test_1) {
  s21_decimal number1 = {{1 << 31, 1 << 31, 1 << 31, c1}};
  s21_decimal number2 = {{1 << 31, 1 << 31, 1 << 31, c1}};
  int res = s21_is_greater(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_test_2) {
  s21_decimal number1 = {{1 << 31, 1 << 31, 1 << 31, c1}};
  s21_decimal number2 = {{1 << 31, 1 << 31, 1 << 31, 0}};
  int res = s21_is_greater(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_test_3) {
  s21_decimal number1 = {{1 << 31, 1 << 31, 1 << 31, 0}};
  s21_decimal number2 = {{1 << 31, 1 << 31, 1 << 31, c1}};
  int res = s21_is_greater(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_test_4) {
  s21_decimal number1 = {{1, 2, 3, 0}};
  s21_decimal number2 = {{4, 5, 6, 0}};
  int res = s21_is_greater(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_test_5) {
  s21_decimal number1 = {{11232, 32132, 3, 0}};
  s21_decimal number2 = {{0, 0, 6, 0}};
  int res = s21_is_greater(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_test_6) {
  s21_decimal number1 = {{11232, 32132, 0, 0}};
  s21_decimal number2 = {{3123, 312312, 0, 0}};
  int res = s21_is_greater(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_test_7) {
  s21_decimal number1 = {{0, 0, 0, c6}};
  s21_decimal number2 = {{0, 0, 0, m5}};
  int res = s21_is_greater(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_test_8) {
  s21_decimal number1 = {{55, 2434, 213, c15}};
  s21_decimal number2 = {{345345, 1234, 1322, c19}};
  int res = s21_is_greater(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_equal_test_1) {
  s21_decimal number1 = {{1, 2, 3, 0}};
  s21_decimal number2 = {{4, 5, 6, 0}};
  int res = s21_is_greater_or_equal(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_equal_test_2) {
  s21_decimal number1 = {{11232, 32132, 3, 0}};
  s21_decimal number2 = {{0, 0, 6, 0}};
  int res = s21_is_greater_or_equal(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_equal_test_3) {
  s21_decimal number1 = {{11232, 12312, 0, 0}};
  s21_decimal number2 = {{3123, 12312, 0, 0}};
  int res = s21_is_greater_or_equal(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_equal_test_4) {
  s21_decimal number1 = {{0, 0, 0, c6}};
  s21_decimal number2 = {{0, 0, 0, m5}};
  int res = s21_is_greater_or_equal(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_equal_test_5) {
  s21_decimal number1 = {{55, 2434, 213, c15}};
  s21_decimal number2 = {{345345, 1234, 1322, c19}};
  int res = s21_is_greater_or_equal(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *greater_tests() {
  Suite *suite = suite_create("---GREATER---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, greater_test_1);
  tcase_add_test(tcase, greater_test_2);
  tcase_add_test(tcase, greater_test_3);
  tcase_add_test(tcase, greater_test_4);
  tcase_add_test(tcase, greater_test_5);
  tcase_add_test(tcase, greater_test_6);
  tcase_add_test(tcase, greater_test_7);
  tcase_add_test(tcase, greater_test_8);
  tcase_add_test(tcase, greater_equal_test_1);
  tcase_add_test(tcase, greater_equal_test_2);
  tcase_add_test(tcase, greater_equal_test_3);
  tcase_add_test(tcase, greater_equal_test_4);
  tcase_add_test(tcase, greater_equal_test_5);

  suite_add_tcase(suite, tcase);
  return suite;
}