#include "../s21_tests.h"

START_TEST(addition_test_1) {
  s21_decimal number1 = {{1 << 31, 1 << 31, 1 << 31, c1}};
  s21_decimal number2 = {{1 << 31, 1 << 31, 1 << 31}};
  s21_decimal result = {};
  int add_res = s21_add(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 0b100110011001100110011001100110);
  ck_assert_int_eq(result.bits[1], 0b1011001100110011001100110011010);
  ck_assert_int_eq(result.bits[2], 0b10001100110011001100110011001101);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(addition_test_2) {
  s21_decimal number1 = {{1 << 31, 1 << 30, 1 << 30, 0}};
  s21_decimal number2 = {{1 << 31, 1 << 30, 1 << 30, 0}};
  s21_decimal result = {};
  int add_res = s21_add(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0b10000000000000000000000000000001);
  ck_assert_int_eq(result.bits[2], 0b10000000000000000000000000000000);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(addition_test_3) {
  s21_decimal number1 = {{123, 15324, 348573429, c6}};
  s21_decimal number2 = {{56345634, 45645645, 1074285609, m5}};
  s21_decimal result = {};
  int add_res = s21_add(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 0b110110100011101111011101001001);
  ck_assert_int_eq(result.bits[1], 0b11100010100100001001011101010);
  ck_assert_int_eq(result.bits[2], 0b111101111101000110101010101010);
  ck_assert_int_eq(result.bits[3], number2.bits[3]);
}
END_TEST

START_TEST(addition_test_4) {
  s21_decimal number1 = {{576348763, 129384323, 471823912, 0}};
  s21_decimal number2 = {{1 << 31, 1 << 31, (1 << 31) + (1 << 30), 0}};
  s21_decimal result = {};
  int add_res = s21_add(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 0b10100010010110100110001001011011);
  ck_assert_int_eq(result.bits[1], 0b10000111101101100011111110000011);
  ck_assert_int_eq(result.bits[2], 0b11011100000111110111011000101000);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(addition_test_5) {
  s21_decimal number1 = {{576348763, 129384323, 1 << 31, 0}};
  s21_decimal number2 = {{1 << 31, 1 << 31, 1 << 31, 0}};
  s21_decimal result = {};
  int add_res = s21_add(number1, number2, &result);
  ck_assert_int_eq(add_res, 1);
}
END_TEST

START_TEST(addition_test_6) {
  s21_decimal number1 = {{576348763, 129384323, 1471823912, 0}};
  s21_decimal number2 = {{1 << 31, 1 << 31, 2129384323, c1}};
  s21_decimal result = {};
  int add_res = s21_add(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 0b11001000110000001100100011000001);
  ck_assert_int_eq(result.bits[1], 0b1100001010011111101100100011100);
  ck_assert_int_eq(result.bits[2], 0b1100100011010110110111011101000);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(addition_test_7) {
  s21_decimal number1 = {{576348763, 129384323, 1471823912, c19}};
  s21_decimal number2 = {{73823, 1656584323, 2129384323, c15}};
  s21_decimal result = {};
  int add_res = s21_add(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 0b10100000101001011101100010001100);
  ck_assert_int_eq(result.bits[1], 0b11000110111000110101100111110011);
  ck_assert_int_eq(result.bits[2], 0b1111110111011100001001001110001);
  ck_assert_int_eq(result.bits[3], number2.bits[3]);
}
END_TEST

START_TEST(addition_test_8) {
  s21_decimal number1 = {{123, 321, 4123123, c1}};
  s21_decimal number2 = {{123, 321, 4123123, m1}};
  s21_decimal result = {};
  int add_res = s21_add(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], number2.bits[3]);
}
END_TEST

START_TEST(addition_test_9) {
  s21_decimal number1 = {{0, 0, 0, c6}};
  s21_decimal number2 = {{0, 0, 0, m7}};
  s21_decimal result = {};
  int add_res = s21_add(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], number2.bits[3]);
}
END_TEST

Suite *addition_tests() {
  Suite *suite = suite_create("---ADDITION---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, addition_test_1);
  tcase_add_test(tcase, addition_test_2);
  tcase_add_test(tcase, addition_test_3);
  tcase_add_test(tcase, addition_test_4);
  tcase_add_test(tcase, addition_test_5);
  tcase_add_test(tcase, addition_test_6);
  tcase_add_test(tcase, addition_test_7);
  tcase_add_test(tcase, addition_test_8);
  tcase_add_test(tcase, addition_test_9);

  suite_add_tcase(suite, tcase);
  return suite;
}
