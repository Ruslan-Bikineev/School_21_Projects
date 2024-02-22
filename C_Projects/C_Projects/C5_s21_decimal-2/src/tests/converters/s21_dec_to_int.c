#include "../s21_tests.h"

START_TEST(dec_to_int_1) {
  int number, res = 0;
  s21_decimal src = {{0, 0, 0, 0}};
  int out = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, res);
  ck_assert_int_eq(out, 0);
}
END_TEST

START_TEST(dec_to_int_2) {
  int number, res = 123456;
  s21_decimal src = {{123456, 0, 0, 0}};
  int out = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, res);
  ck_assert_int_eq(out, 0);
}
END_TEST

START_TEST(dec_to_int_3) {
  int number, res = -123456;
  s21_decimal src = {{123456, 0, 0, 0x80000000}};
  int out = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, res);
  ck_assert_int_eq(out, 0);
}
END_TEST

START_TEST(dec_to_int_4) {
  int number, res = INT_MIN;
  s21_decimal src = {{abs(INT_MIN), 0, 0, 0x80000000}};
  int out = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, res);
  ck_assert_int_eq(out, 0);
}
END_TEST

START_TEST(dec_to_int_5) {
  int number, res = INT_MAX;
  s21_decimal src = {{INT_MAX, 0, 0, 0}};
  int out = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, res);
  ck_assert_int_eq(out, 0);
}
END_TEST

START_TEST(dec_to_int_6) {
  int number, res = 10;
  s21_decimal src = {{10, 0, 0, 0}};
  int out = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, res);
  ck_assert_int_eq(out, 0);
}
END_TEST

START_TEST(dec_to_int_7) {
  int number, res = -10;
  s21_decimal src = {{10, 0, 0, 0x80000000}};
  int out = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, res);
  ck_assert_int_eq(out, 0);
}
END_TEST

START_TEST(dec_to_int_8) {
  int number, res = -1;
  s21_decimal src = {{1, 0, 0, 0x80000000}};
  int out = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, res);
  ck_assert_int_eq(out, 0);
}
END_TEST
START_TEST(dec_to_int_9) {
  s21_decimal src;
  int out = s21_from_decimal_to_int(src, NULL);
  ck_assert_int_eq(out, 1);
}
END_TEST

Suite *dec_to_int_tests() {
  Suite *suite = suite_create("---DEC_TO_INT---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, dec_to_int_1);
  tcase_add_test(tcase, dec_to_int_2);
  tcase_add_test(tcase, dec_to_int_3);
  tcase_add_test(tcase, dec_to_int_4);
  tcase_add_test(tcase, dec_to_int_5);
  tcase_add_test(tcase, dec_to_int_6);
  tcase_add_test(tcase, dec_to_int_7);
  tcase_add_test(tcase, dec_to_int_8);
  tcase_add_test(tcase, dec_to_int_9);

  suite_add_tcase(suite, tcase);
  return suite;
}
