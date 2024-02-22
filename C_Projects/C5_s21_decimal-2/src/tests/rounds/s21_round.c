#include "../s21_tests.h"

START_TEST(round_test_1) {
  s21_decimal number = {{123, 456, 789, 0}};
  s21_decimal number_res = {{}};
  int res = s21_round(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], number.bits[0]);
  ck_assert_int_eq(number_res.bits[1], number.bits[1]);
  ck_assert_int_eq(number_res.bits[2], number.bits[2]);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(round_test_2) {
  s21_decimal number = {{123, 0, 0, c1}};
  s21_decimal number_res = {{}};
  int res = s21_round(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b1100);
  ck_assert_int_eq(number_res.bits[1], 0);
  ck_assert_int_eq(number_res.bits[2], 0);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(round_test_3) {
  s21_decimal number = {{0, 0, 989789, c6}};
  s21_decimal number_res = {{}};
  int res = s21_round(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b11110000110001110111110111011000);
  ck_assert_int_eq(number_res.bits[1], 0b11111101011000101100111111011000);
  ck_assert_int_eq(number_res.bits[2], 0);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(round_test_4) {
  s21_decimal number = {{423674234, 23467234, 123512632, m5}};
  s21_decimal number_res = {{}};
  int res = s21_round(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b10000000110010001001101011010101);
  ck_assert_int_eq(number_res.bits[1], 0b100000010101101000001011010111);
  ck_assert_int_eq(number_res.bits[2], 0b10011010011);
  ck_assert_int_eq(number_res.bits[3], minus);
}
END_TEST

START_TEST(round_test_5) {
  s21_decimal number = {{0, 0, 0, 0}};
  s21_decimal number_res = {{}};
  int res = s21_round(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0);
  ck_assert_int_eq(number_res.bits[1], 0);
  ck_assert_int_eq(number_res.bits[2], 0);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(round_test_6) {
  s21_decimal number = {{0, 0, 0, c15}};
  s21_decimal number_res = {{}};
  int res = s21_round(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0);
  ck_assert_int_eq(number_res.bits[1], 0);
  ck_assert_int_eq(number_res.bits[2], 0);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(round_test_7) {
  s21_decimal number = {{1, 1, 1, m1}};
  s21_decimal number_res = {{}};
  int res = s21_round(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b10110011001100110011001100110011);
  ck_assert_int_eq(number_res.bits[1], 0b11001100110011001100110011001);
  ck_assert_int_eq(number_res.bits[2], 0);
  ck_assert_int_eq(number_res.bits[3], minus);
}
END_TEST

START_TEST(round_test_8) {
  s21_decimal number = {{123, 123, 123, 0}};
  int res = s21_round(number, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *round_tests() {
  Suite *suite = suite_create("---ROUND---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, round_test_1);
  tcase_add_test(tcase, round_test_2);
  tcase_add_test(tcase, round_test_3);
  tcase_add_test(tcase, round_test_4);
  tcase_add_test(tcase, round_test_5);
  tcase_add_test(tcase, round_test_6);
  tcase_add_test(tcase, round_test_7);
  tcase_add_test(tcase, round_test_8);

  suite_add_tcase(suite, tcase);
  return suite;
}