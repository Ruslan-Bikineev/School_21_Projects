#include "../s21_string_tests.h"

START_TEST(sscanf_test_n_1) {
  char format[] = "%n";
  char str[] = "School";
  int n1 = 0, n2 = 0;

  int res1 = s21_sscanf(str, format, &n1);
  int res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_test_n_2) {
  char format[] = "%d %n School";
  char str[] = "21 School";
  int d1 = 0, d2 = 0;
  int n1 = 0, n2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &n1);
  int res2 = sscanf(str, format, &d2, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_test_n_3) {
  char format[] = "%d %d %n %d";
  char str[] = "12 23 45";
  int d11 = 0, d12 = 0, d13 = 0;
  int d21 = 0, d22 = 0, d23 = 0;
  int n1 = 0, n2 = 0;

  int res1 = s21_sscanf(str, format, &d11, &d12, &n1, &d13);
  int res2 = sscanf(str, format, &d21, &d22, &n2, &d23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(d12, d22);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(d13, d23);
}
END_TEST

START_TEST(sscanf_test_n_4) {
  char format[] = "Hello%n!";
  char str[] = "Hello!";
  int n1 = 0, n2 = 0;

  int res1 = s21_sscanf(str, format, &n1);
  int res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_test_n_5) {
  char format[] = "%d %n %d %d %n";
  char str[] = "80 50 70 371 327";
  int d11 = 0, d12 = 0, d13 = 0;
  int d21 = 0, d22 = 0, d23 = 0;
  int n11 = 0, n12 = 0;
  int n21 = 0, n22 = 0;

  int res1 = s21_sscanf(str, format, &d11, &n11, &d12, &d13, &n12);
  int res2 = sscanf(str, format, &d21, &n21, &d22, &d23, &n22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(n11, n21);
  ck_assert_int_eq(d12, d22);
  ck_assert_int_eq(d13, d23);
  ck_assert_int_eq(n12, n22);
}
END_TEST

START_TEST(sscanf_test_n_6) {
  char format[] = "%d %n %n %hd";
  char str[] = "3263 225 724 38 482";

  int d11 = 0, d12 = 0;
  /*short*/ int d21 = 0, d22 = 0;
  int n11 = 0, n12 = 0;
  int n21 = 0, n22 = 0;

  int res1 = s21_sscanf(str, format, &d11, &n11, &n12, &d12);
  int res2 = sscanf(str, format, &d21, &n21, &n22, &d22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(n11, n21);
  ck_assert_int_eq(n12, n22);
  ck_assert_int_eq(d12, d22);
}
END_TEST

START_TEST(sscanf_test_n_7) {
  char format[] = "%s %n %d %n %s";
  char str[] = "Hello, 21 School";
  char s11[30], s12[30], s21[30], s22[30];
  int d1 = 0, d2 = 0;
  int n11 = 0, n12 = 0, n21 = 0, n22 = 0;

  int res1 = s21_sscanf(str, format, &s11, &n11, &d1, &n12, &s12);
  int res2 = sscanf(str, format, &s21, &n21, &d2, &n22, &s22);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s11, s21);
  ck_assert_int_eq(n11, n21);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n12, n22);
  ck_assert_pstr_eq(s12, s22);
}
END_TEST

Suite *sscanf_test_n() {
  Suite *suite = suite_create("---SSCANF_N---");
  TCase *tcase = tcase_create("sscanf_tc");

  tcase_add_test(tcase, sscanf_test_n_1);
  tcase_add_test(tcase, sscanf_test_n_2);
  tcase_add_test(tcase, sscanf_test_n_3);
  tcase_add_test(tcase, sscanf_test_n_4);
  tcase_add_test(tcase, sscanf_test_n_5);
  tcase_add_test(tcase, sscanf_test_n_6);
  tcase_add_test(tcase, sscanf_test_n_7);

  suite_add_tcase(suite, tcase);
  return suite;
}