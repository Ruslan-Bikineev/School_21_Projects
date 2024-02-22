#include "../s21_tests.h"

START_TEST(float_to_dec_1) {
  s21_decimal number;
  float num = 123456;
  s21_decimal res = {{123456, 0, 0, 0}};
  int out = s21_from_float_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_to_dec_2) {
  s21_decimal number;
  float num = -1.0;
  s21_decimal res = {{1, 0, 0, 0x80000000}};
  int out = s21_from_float_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_to_dec_3) {
  s21_decimal number;
  float num = 0.00011;
  s21_decimal res = {{0x0000000B, 0x00000000, 0x00000000, 0x00050000}};
  int out = s21_from_float_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_to_dec_4) {
  s21_decimal number;
  float num = 0.022137;
  s21_decimal res = {
      {0x00005679, 0x00000000, 0x00000000, 0x00060000}};  // 0.022137;
  int out = s21_from_float_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_to_dec_5) {
  s21_decimal number;
  float num = 2.38183;
  s21_decimal res = {
      {0x0003A267, 0x00000000, 0x00000000, 0x00050000}};  // 2.38183
  int out = s21_from_float_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_to_dec_6) {
  s21_decimal number;
  float num = -32860;
  s21_decimal res = {{0x0000805C, 0x00000000, 0x00000000, 0x80000000}};
  int out = s21_from_float_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_to_dec_7) {
  s21_decimal number;
  float num = 65535;
  s21_decimal res = {{0x0000FFFF, 0x00000000, 0x00000000, 0x00000000}};
  int out = s21_from_float_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_to_dec_8) {
  int out = s21_from_float_to_decimal(0, NULL);
  ck_assert_int_eq(out, 1);
}
END_TEST

Suite *float_to_dec_tests() {
  Suite *suite = suite_create("---FLOAT_TO_DEC---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, float_to_dec_1);
  tcase_add_test(tcase, float_to_dec_2);
  tcase_add_test(tcase, float_to_dec_3);
  tcase_add_test(tcase, float_to_dec_4);
  tcase_add_test(tcase, float_to_dec_5);
  tcase_add_test(tcase, float_to_dec_6);
  tcase_add_test(tcase, float_to_dec_7);
  tcase_add_test(tcase, float_to_dec_8);

  suite_add_tcase(suite, tcase);
  return suite;
}