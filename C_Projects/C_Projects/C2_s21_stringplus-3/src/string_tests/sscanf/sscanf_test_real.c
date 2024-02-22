#include "../s21_string_tests.h"

START_TEST(sscanf_test_real_1) {
  char format[] = "%f %f %f";
  char str[] = "123 +198 -87";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  float c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_real_2) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_real_3) {
  char format[] = "%f %fx %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.x 1.1 2.x 1.1 2.x";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  float c1 = 0, c2 = 0;
  float d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_real_4) {
  char format[] = "%Lf %Lf %Lf %Lf";
  char str[] = "34.56e3 83.3e-4 .43e+1 +2.43e3";
  long double a1, a2;
  long double b1, b2;
  long double c1, c2;
  long double d1, d2;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_real_5) {
  char format[] = "%1f %1f %2f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  float c1 = 0, c2 = 0;
  float d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_real_6) {
  char format[] = "%*f %7f %*f %*f";
  char str[] = "34.5 +6e3 83.2e-4 +43e+1 +2.43e3";
  float a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, format, &a1);
  int res2 = sscanf(str, format, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_test_real_7) {
  char format[] = "%fr %7f p";
  char str[] = "34.5r 83.2ep4";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1);
  int res2 = sscanf(str, format, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_test_real_8) {
  char format[] = "%1f %1f %1f %1f";
  char str[] = "34 32. +45.e +23E3 -0.3e4";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  float c1 = 0, c2 = 0;
  float d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_real_9) {
  char format[] = "%2Lf %2Lf %2Lf %2Lf";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  long double a1 = 0, a2 = 0;
  long double b1 = 0, b2 = 0;
  long double c1 = 0, c2 = 0;
  long double d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_real_10) {
  char format[] = "%3f %3f %4f %3f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  float c1 = 0, c2 = 0;
  float d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_real_11) {
  char format[] = "%Lf %4Lf %5Lfq %6Lf %*Lf q%*Lf";
  char str[] = "1.3e1 1.4eb2 1.3e1q 1.4 1.3eq 1.4e2";
  long double a1 = 0, a2 = 0;
  long double b1 = 0, b2 = 0;
  long double c1 = 0, c2 = 0;
  long double d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

Suite *sscanf_test_real() {
  Suite *suite = suite_create("---SSCANF_REAL---");
  TCase *tcase = tcase_create("sscanf_tc");

  tcase_add_test(tcase, sscanf_test_real_1);
  tcase_add_test(tcase, sscanf_test_real_2);
  tcase_add_test(tcase, sscanf_test_real_3);
  tcase_add_test(tcase, sscanf_test_real_4);
  tcase_add_test(tcase, sscanf_test_real_5);
  tcase_add_test(tcase, sscanf_test_real_6);
  tcase_add_test(tcase, sscanf_test_real_7);
  tcase_add_test(tcase, sscanf_test_real_8);
  tcase_add_test(tcase, sscanf_test_real_9);
  tcase_add_test(tcase, sscanf_test_real_10);
  tcase_add_test(tcase, sscanf_test_real_11);

  suite_add_tcase(suite, tcase);
  return suite;
}