#include "../s21_tests.h"

START_TEST(dec_to_float_test_1) {
  s21_decimal number = {{123, 456, 789, 0}};
  float f, fres = 14554481074156836225024.0;
  int res = s21_from_decimal_to_float(number, &f);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(f, fres);
}
END_TEST

START_TEST(dec_to_float_test_2) {
  s21_decimal number = {{123, 456, 234, m1}};
  float f, fres = -4.316538E+20;
  int res = s21_from_decimal_to_float(number, &f);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(f, fres);
}
END_TEST

START_TEST(dec_to_float_test_3) {
  s21_decimal number = {{1 << 31, 0, 989789, 0}};
  float f, fres = 18258384369972903384449024.0;
  int res = s21_from_decimal_to_float(number, &f);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(f, fres);
}
END_TEST

START_TEST(dec_to_float_test_4) {
  s21_decimal number = {{132, 34534553, 0, c19}};
  float f, fres = 0.0148324780;
  int res = s21_from_decimal_to_float(number, &f);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(f, fres);
}
END_TEST

START_TEST(dec_to_float_test_5) {
  s21_decimal number = {{11232, 0, 0, m7}};
  float f, fres = -0.0011232;
  int res = s21_from_decimal_to_float(number, &f);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(f, fres);
}
END_TEST

START_TEST(dec_to_float_test_6) {
  s21_decimal number = {{0, 0, 0, c30}};
  float f, fres = 0;
  int res = s21_from_decimal_to_float(number, &f);
  ck_assert_int_eq(res, 1);
  ck_assert_float_eq(f, fres);
}
END_TEST

START_TEST(dec_to_float_test_7) {
  s21_decimal number = {{123, 123, 123, 0}};
  int res = s21_negate(number, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *dec_to_float_tests() {
  Suite *suite = suite_create("---DEC_TO_FLOAT---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, dec_to_float_test_1);
  tcase_add_test(tcase, dec_to_float_test_2);
  tcase_add_test(tcase, dec_to_float_test_3);
  tcase_add_test(tcase, dec_to_float_test_4);
  tcase_add_test(tcase, dec_to_float_test_5);
  tcase_add_test(tcase, dec_to_float_test_6);
  tcase_add_test(tcase, dec_to_float_test_7);

  suite_add_tcase(suite, tcase);
  return suite;
}