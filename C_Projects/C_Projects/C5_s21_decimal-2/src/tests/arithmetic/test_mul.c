#include "../s21_tests.h"

START_TEST(mul_test_1) {
  s21_decimal number1 = {{245, 13235, 0, c1}};
  s21_decimal number2 = {{3452235, 355, 0, c1}};
  s21_decimal result = {};
  int mul_res = s21_mul(number1, number2, &result);
  ck_assert_int_eq(mul_res, 0);
  ck_assert_int_eq(result.bits[0], 0b00110010011010011101100011000111);
  ck_assert_int_eq(result.bits[1], 0b10100011010111000111000000110000);
  ck_assert_int_eq(result.bits[2], 0b00000000010001111011000101000011);
  ck_assert_int_eq(result.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(mul_test_2) {
  s21_decimal number1 = {{245, 13235, 0, c1}};
  s21_decimal number2 = {{0, 0, 0, c1}};
  s21_decimal result = {};
  int mul_res = s21_mul(number1, number2, &result);
  ck_assert_int_eq(mul_res, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(mul_test_3) {
  s21_decimal number1 = {{0, 0, 0, c19}};
  s21_decimal number2 = {{0, 0, 0, c19}};
  s21_decimal result = {};
  int mul_res = s21_mul(number1, number2, &result);
  ck_assert_int_eq(mul_res, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(mul_test_4) {
  s21_decimal number1 = {{2324, 234, 0, m7}};
  s21_decimal number2 = {{0, 325, 0, c19}};
  s21_decimal result = {};
  int mul_res = s21_mul(number1, number2, &result);
  ck_assert_int_eq(mul_res, 0);
  ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
  ck_assert_int_eq(result.bits[1], 0b00000000000010111000011001100100);
  ck_assert_int_eq(result.bits[2], 0b00000000000000010010100100010010);
  ck_assert_int_eq(result.bits[3], 0b10000000000110100000000000000000);
}
END_TEST

START_TEST(mul_test_5) {
  s21_decimal number1 = {{2324, 234, 0, m7}};
  s21_decimal number2 = {{0, 325, 0, m6}};
  s21_decimal result = {};
  int mul_res = s21_mul(number1, number2, &result);
  ck_assert_int_eq(mul_res, 0);
  ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
  ck_assert_int_eq(result.bits[1], 0b00000000000010111000011001100100);
  ck_assert_int_eq(result.bits[2], 0b00000000000000010010100100010010);
  ck_assert_int_eq(result.bits[3], 0b00000000000011010000000000000000);
}
END_TEST

START_TEST(mul_test_6) {
  s21_decimal number1 = {{2324, 234, 0, m7}};
  s21_decimal number2 = {{0, 325, 5, m6}};
  s21_decimal result = {};
  int mul_res = s21_mul(number1, number2, &result);
  ck_assert_int_eq(mul_res, 0);
  ck_assert_int_eq(result.bits[0], 0b10100010010011011101001011110010);
  ck_assert_int_eq(result.bits[1], 0b01100110001001001101110101111010);
  ck_assert_int_eq(result.bits[2], 0b00011101111100111011011001001110);
  ck_assert_int_eq(result.bits[3], 0b00000000000010010000000000000000);
}
END_TEST

START_TEST(mul_test_7) {
  s21_decimal number1 = {{2324, 234, 2, m7}};
  s21_decimal number2 = {{0, 325, 5, m6}};
  s21_decimal result = {};
  int mul_res = s21_mul(number1, number2, &result);
  ck_assert_int_eq(mul_res, 0);
  ck_assert_int_eq(result.bits[0], 0b01000100000111010011000010010111);
  ck_assert_int_eq(result.bits[1], 0b10001010000100111000110100010010);
  ck_assert_int_eq(result.bits[2], 0b01101101111100110111111110110101);
  ck_assert_int_eq(result.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(mul_test_8) {
  s21_decimal number1 = {{2324, 234, 0, c28}};
  s21_decimal number2 = {{0, 325, 0, c6}};
  s21_decimal result = {};
  int mul_res = s21_mul(number1, number2, &result);
  ck_assert_int_eq(mul_res, 0);
  ck_assert_int_eq(result.bits[0], 0b10011101101110001011101011000111);
  ck_assert_int_eq(result.bits[1], 0b00010011011110000000001101000111);
  ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(result.bits[3], 0b00000000000111000000000000000000);
}
END_TEST

START_TEST(mul_test_9) {
  s21_decimal number1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal number2 = {{5, 0, 0, c1}};
  s21_decimal result = {};
  int mul_res = s21_mul(number1, number2, &result);
  ck_assert_int_eq(mul_res, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0x80000000);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

Suite *mul_tests() {
  Suite *suite = suite_create("---MUL---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, mul_test_1);
  tcase_add_test(tcase, mul_test_2);
  tcase_add_test(tcase, mul_test_3);
  tcase_add_test(tcase, mul_test_4);
  tcase_add_test(tcase, mul_test_5);
  tcase_add_test(tcase, mul_test_6);
  tcase_add_test(tcase, mul_test_7);
  tcase_add_test(tcase, mul_test_8);
  tcase_add_test(tcase, mul_test_9);

  suite_add_tcase(suite, tcase);
  return suite;
}