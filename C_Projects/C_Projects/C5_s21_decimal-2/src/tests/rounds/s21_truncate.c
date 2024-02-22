#include "../s21_tests.h"

START_TEST(truncate_test_1) {
  s21_decimal number = {{123, 456, 789, 0}};
  s21_decimal number_res = {{}};
  int res = s21_truncate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], number.bits[0]);
  ck_assert_int_eq(number_res.bits[1], number.bits[1]);
  ck_assert_int_eq(number_res.bits[2], number.bits[2]);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(truncate_test_2) {
  s21_decimal number = {{123, 456, 234, c1}};
  s21_decimal number_res = {{}};
  int res = s21_truncate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b1100);
  ck_assert_int_eq(number_res.bits[1], 0b1100110011001100110011010010100);
  ck_assert_int_eq(number_res.bits[2], 0b10111);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(truncate_test_3) {
  s21_decimal number = {{1 << 31, 0, 989789, m5}};
  s21_decimal number_res = {{}};
  int res = s21_truncate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b1100111110010110011111001010111);
  ck_assert_int_eq(number_res.bits[1], 0b11100101110111000001111001111001);
  ck_assert_int_eq(number_res.bits[2], 0b1001);
  ck_assert_int_eq(number_res.bits[3], minus);
}
END_TEST

START_TEST(truncate_test_4) {
  s21_decimal number = {{132, 34534553, 123512632, m5}};
  s21_decimal number_res = {{}};
  int res = s21_truncate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b101101000111101011100001010001);
  ck_assert_int_eq(number_res.bits[1], 0b100000010101101000001101000110);
  ck_assert_int_eq(number_res.bits[2], 0b10011010011);
  ck_assert_int_eq(number_res.bits[3], minus);
}
END_TEST

START_TEST(truncate_test_5) {
  s21_decimal number = {{1, 2, 3, c30}};
  s21_decimal number_res = {{}};
  int res = s21_truncate(number, &number_res);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(truncate_test_6) {
  s21_decimal number = {{0, 0, 0, c15}};
  s21_decimal number_res = {{}};
  int res = s21_truncate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0);
  ck_assert_int_eq(number_res.bits[1], 0);
  ck_assert_int_eq(number_res.bits[2], 0);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(truncate_test_7) {
  s21_decimal number = {{1, 1, 0, m1}};
  s21_decimal number_res = {{}};
  int res = s21_truncate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b11001100110011001100110011001);
  ck_assert_int_eq(number_res.bits[1], 0);
  ck_assert_int_eq(number_res.bits[2], 0);
  ck_assert_int_eq(number_res.bits[3], minus);
}
END_TEST

START_TEST(truncate_test_8) {
  s21_decimal number = {{123, 123, 123, 0}};
  int res = s21_truncate(number, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *truncate_tests() {
  Suite *suite = suite_create("---TRUNCATE---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, truncate_test_1);
  tcase_add_test(tcase, truncate_test_2);
  tcase_add_test(tcase, truncate_test_3);
  tcase_add_test(tcase, truncate_test_4);
  tcase_add_test(tcase, truncate_test_5);
  tcase_add_test(tcase, truncate_test_6);
  tcase_add_test(tcase, truncate_test_7);
  tcase_add_test(tcase, truncate_test_8);

  suite_add_tcase(suite, tcase);
  return suite;
}