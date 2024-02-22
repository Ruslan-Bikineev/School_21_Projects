#include "../s21_tests.h"

START_TEST(equal_test_1) {
  s21_decimal number1 = {{1 << 31, 1 << 31, 1 << 31, c1}};
  s21_decimal number2 = {{1 << 31, 1 << 31, 1 << 31, c1}};
  int res = s21_is_equal(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(equal_test_2) {
  s21_decimal number1 = {{1, 2, 3, c1}};
  s21_decimal number2 = {{1, 2, 3, 0}};
  int res = s21_is_equal(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_test_3) {
  s21_decimal number1 = {{1 << 5, 1 << 5, 1 << 5, 0}};
  s21_decimal number2 = {{1 << 5, 1 << 5, 1 << 5, 0}};
  int res = s21_is_equal(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(equal_test_4) {
  s21_decimal number1 = {{435, 234, 1232, 0}};
  s21_decimal number2 = {{34534, 23423, 1232, 0}};
  int res = s21_is_equal(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_test_5) {
  s21_decimal number1 = {{11232, 32132, 3, 0}};
  s21_decimal number2 = {{0, 0, 6, 0}};
  int res = s21_is_equal(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_test_6) {
  s21_decimal number1 = {{11232, 23232323, 0, 0}};
  s21_decimal number2 = {{11232, 23242323, 0, 0}};
  int res = s21_is_equal(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(equal_test_7) {
  s21_decimal number1 = {{0, 0, 0, c6}};
  s21_decimal number2 = {{0, 0, 0, m5}};
  int res = s21_is_equal(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(equal_test_8) {
  s21_decimal number1 = {{53454, 23423, 5345, c15}};
  s21_decimal number2 = {{234234, 53434435, 3453443, c19}};
  int res = s21_is_equal(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(not_equal_test_1) {
  s21_decimal number1 = {{11232, 32132, 3, 0}};
  s21_decimal number2 = {{0, 0, 6, 0}};
  int res = s21_is_not_equal(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(not_equal_test_2) {
  s21_decimal number1 = {{11232, 2, 0, 0}};
  s21_decimal number2 = {{3123, 3, 0, 0}};
  int res = s21_is_not_equal(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(not_equal_test_3) {
  s21_decimal number1 = {{0, 0, 0, c6}};
  s21_decimal number2 = {{0, 0, 0, m5}};
  int res = s21_is_not_equal(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(not_equal_test_4) {
  s21_decimal number1 = {{213, 213, 213, minus}};
  s21_decimal number2 = {{213, 213, 213, minus}};
  int res = s21_is_not_equal(number1, number2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(not_equal_test_5) {
  s21_decimal number1 = {{5345, 12313, 5435, m5}};
  s21_decimal number2 = {{12314, 23423, 645, m7}};
  int res = s21_is_not_equal(number1, number2);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *equal_tests() {
  Suite *suite = suite_create("---EQUAL---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, equal_test_1);
  tcase_add_test(tcase, equal_test_2);
  tcase_add_test(tcase, equal_test_3);
  tcase_add_test(tcase, equal_test_4);
  tcase_add_test(tcase, equal_test_5);
  tcase_add_test(tcase, equal_test_6);
  tcase_add_test(tcase, equal_test_7);
  tcase_add_test(tcase, equal_test_8);
  tcase_add_test(tcase, not_equal_test_1);
  tcase_add_test(tcase, not_equal_test_2);
  tcase_add_test(tcase, not_equal_test_3);
  tcase_add_test(tcase, not_equal_test_4);
  tcase_add_test(tcase, not_equal_test_5);

  suite_add_tcase(suite, tcase);
  return suite;
}