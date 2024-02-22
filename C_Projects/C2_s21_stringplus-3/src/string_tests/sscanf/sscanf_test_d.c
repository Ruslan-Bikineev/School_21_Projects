#include "../s21_string_tests.h"

START_TEST(sscanf_test_hd_1) {
  char format[] = "%hd";
  char str[] = "123";
  short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_2) {
  char format[] = "%5hd";
  char str[] = "123";
  short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_3) {
  char format[] = "%hd";
  char str[] = "-123";
  short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_4) {
  char format[] = "%hd";
  char str[] = "+123";
  short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_5) {
  char format[] = "%3hd";
  char str[] = "-123";
  short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_6) {
  char format[] = "%3hd";
  char str[] = "+123";
  short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_7) {
  char format[] = "%10hd";
  char str[] = "-123";
  short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_8) {
  char format[] = "%1hd";
  char str[] = "-123";
  short int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_9) {
  char format[] = "%*1hd";
  char str[] = "+123";
  short int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_10) {
  char format[] = "%*hd";
  char str[] = "123";
  short int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_11) {
  char format[] = "%hd";
  char str[] = "2147483647";
  short int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hd_12) {
  char format[] = "%hd";
  char str[] = "-2147483648";
  short int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_1) {
  char format[] = "%d";
  char str[] = "123";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_2) {
  char format[] = "%d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_3) {
  char format[] = "%d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_4) {
  char format[] = "%3d %3d";
  char str[] = "-123 123";
  int d11 = 0, d12 = 0;
  int d21 = 0, d22 = 0;

  int res1 = s21_sscanf(str, format, &d11, &d12);
  int res2 = sscanf(str, format, &d21, &d22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(d12, d22);
}

END_TEST

START_TEST(sscanf_test_d_5) {
  char format[] = "%10d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_6) {
  char format[] = "%1d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_7) {
  char format[] = "%1d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_8) {
  char format[] = "%*1d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_9) {
  char format[] = "%*d";
  char str[] = "123";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_10) {
  char format[] = "%d";
  char str[] = "2147483647";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_d_11) {
  char format[] = "%d";
  char str[] = "-2147483648";
  int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_1) {
  char format[] = "%ld";
  char str[] = "123";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_2) {
  char format[] = "%ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_3) {
  char format[] = "%ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_4) {
  char format[] = "%3ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_5) {
  char format[] = "%10ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_6) {
  char format[] = "%1ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_7) {
  char format[] = "%10ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_8) {
  char format[] = "%*1ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_9) {
  char format[] = "%*ld";
  char str[] = "123";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_10) {
  char format[] = "%ld";
  char str[] = "2147483647";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_11) {
  char format[] = "%ld";
  char str[] = "214743483648";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_12) {
  char format[] = "%ld";
  char str[] = "-2147483648";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_13) {
  char format[] = "%ld";
  char str[] = "-2147483649";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_14) {
  char format[] = "%ld";
  char str[] = "-214748364239";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_ld_15) {
  char format[] = "%ld";
  char str[] = "9223372036854775807";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

Suite *sscanf_test_d() {
  Suite *suite = suite_create("---SSCANF_D---");
  TCase *tcase = tcase_create("sscanf_tc");

  tcase_add_test(tcase, sscanf_test_hd_1);
  tcase_add_test(tcase, sscanf_test_hd_2);
  tcase_add_test(tcase, sscanf_test_hd_3);
  tcase_add_test(tcase, sscanf_test_hd_4);
  tcase_add_test(tcase, sscanf_test_hd_5);
  tcase_add_test(tcase, sscanf_test_hd_6);
  tcase_add_test(tcase, sscanf_test_hd_7);
  tcase_add_test(tcase, sscanf_test_hd_8);
  tcase_add_test(tcase, sscanf_test_hd_9);
  tcase_add_test(tcase, sscanf_test_hd_10);
  tcase_add_test(tcase, sscanf_test_hd_11);
  tcase_add_test(tcase, sscanf_test_hd_12);

  tcase_add_test(tcase, sscanf_test_d_1);
  tcase_add_test(tcase, sscanf_test_d_2);
  tcase_add_test(tcase, sscanf_test_d_3);
  tcase_add_test(tcase, sscanf_test_d_4);
  tcase_add_test(tcase, sscanf_test_d_5);
  tcase_add_test(tcase, sscanf_test_d_6);
  tcase_add_test(tcase, sscanf_test_d_7);
  tcase_add_test(tcase, sscanf_test_d_8);
  tcase_add_test(tcase, sscanf_test_d_9);
  tcase_add_test(tcase, sscanf_test_d_10);
  tcase_add_test(tcase, sscanf_test_d_11);

  tcase_add_test(tcase, sscanf_test_ld_1);
  tcase_add_test(tcase, sscanf_test_ld_2);
  tcase_add_test(tcase, sscanf_test_ld_3);
  tcase_add_test(tcase, sscanf_test_ld_4);
  tcase_add_test(tcase, sscanf_test_ld_5);
  tcase_add_test(tcase, sscanf_test_ld_6);
  tcase_add_test(tcase, sscanf_test_ld_7);
  tcase_add_test(tcase, sscanf_test_ld_8);
  tcase_add_test(tcase, sscanf_test_ld_9);
  tcase_add_test(tcase, sscanf_test_ld_10);
  tcase_add_test(tcase, sscanf_test_ld_11);
  tcase_add_test(tcase, sscanf_test_ld_12);
  tcase_add_test(tcase, sscanf_test_ld_13);
  tcase_add_test(tcase, sscanf_test_ld_14);
  tcase_add_test(tcase, sscanf_test_ld_15);

  suite_add_tcase(suite, tcase);
  return suite;
}
