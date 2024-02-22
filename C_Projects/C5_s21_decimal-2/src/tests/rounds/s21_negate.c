#include "../s21_tests.h"

START_TEST(negate_test_1) {
  s21_decimal number = {{123, 456, 789, 0}};
  s21_decimal number_res = {{}};
  int res = s21_negate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], number.bits[0]);
  ck_assert_int_eq(number_res.bits[1], number.bits[1]);
  ck_assert_int_eq(number_res.bits[2], number.bits[2]);
  ck_assert_int_eq(s21_get_decimal_sign(number_res), 1);
  ck_assert_int_eq(s21_get_decimal_scale(number_res), 0);
}
END_TEST

START_TEST(negate_test_2) {
  s21_decimal number = {{123, 456, 234, m1}};
  s21_decimal number_res = {{}};
  int res = s21_negate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], number.bits[0]);
  ck_assert_int_eq(number_res.bits[1], number.bits[1]);
  ck_assert_int_eq(number_res.bits[2], number.bits[2]);
  ck_assert_int_eq(s21_get_decimal_sign(number_res), 0);
  ck_assert_int_eq(s21_get_decimal_scale(number_res), 1);
}
END_TEST

START_TEST(negate_test_3) {
  s21_decimal number = {{1 << 31, 0, 989789, 0}};
  s21_decimal number_res = {{}};
  int res = s21_negate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], number.bits[0]);
  ck_assert_int_eq(number_res.bits[1], number.bits[1]);
  ck_assert_int_eq(number_res.bits[2], number.bits[2]);
  ck_assert_int_eq(s21_get_decimal_sign(number_res), 1);
  ck_assert_int_eq(s21_get_decimal_scale(number_res), 0);
}
END_TEST

START_TEST(negate_test_4) {
  s21_decimal number = {{132, 34534553, 123512632, c19}};
  s21_decimal number_res = {{}};
  int res = s21_negate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], number.bits[0]);
  ck_assert_int_eq(number_res.bits[1], number.bits[1]);
  ck_assert_int_eq(number_res.bits[2], number.bits[2]);
  ck_assert_int_eq(s21_get_decimal_sign(number_res), 1);
  ck_assert_int_eq(s21_get_decimal_scale(number_res), 19);
}
END_TEST

START_TEST(negate_test_5) {
  s21_decimal number = {{1, 2, 3, m7}};
  s21_decimal number_res = {{}};
  int res = s21_negate(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], number.bits[0]);
  ck_assert_int_eq(number_res.bits[1], number.bits[1]);
  ck_assert_int_eq(number_res.bits[2], number.bits[2]);
  ck_assert_int_eq(s21_get_decimal_sign(number_res), 0);
  ck_assert_int_eq(s21_get_decimal_scale(number_res), 7);
}
END_TEST

START_TEST(negate_test_6) {
  s21_decimal number = {{0, 0, 0, c30}};
  s21_decimal number_res = {{}};
  int res = s21_negate(number, &number_res);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(negate_test_7) {
  s21_decimal number = {{123, 123, 123, 0}};
  int res = s21_negate(number, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *negate_tests() {
  Suite *suite = suite_create("---NEGATE---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, negate_test_1);
  tcase_add_test(tcase, negate_test_2);
  tcase_add_test(tcase, negate_test_3);
  tcase_add_test(tcase, negate_test_4);
  tcase_add_test(tcase, negate_test_5);
  tcase_add_test(tcase, negate_test_6);
  tcase_add_test(tcase, negate_test_7);

  suite_add_tcase(suite, tcase);
  return suite;
}