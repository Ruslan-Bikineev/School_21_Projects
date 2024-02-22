#include "../s21_string_tests.h"

START_TEST(sscanf_test_hu_1) {
  char format[] = "%hu";
  char str[] = "123";
  unsigned short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hu_2) {
  char format[] = "%5hu";
  char str[] = "123";
  unsigned short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hu_3) {
  char format[] = "%hu";
  char str[] = "-123";
  unsigned short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hu_4) {
  char format[] = "%hu";
  char str[] = "+123";
  unsigned short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hu_5) {
  char format[] = "%3hu";
  char str[] = "+123";
  unsigned short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hu_6) {
  char format[] = "%10hu";
  char str[] = "123";
  unsigned short int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hu_7) {
  char format[] = "%*1hu";
  char str[] = "+123";
  unsigned short int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hu_8) {
  char format[] = "%*hu";
  char str[] = "123";
  unsigned short int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_hu_9) {
  char format[] = "%hu";
  char str[] = "2147483647";
  unsigned short int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_u_1) {
  char format[] = "%u";
  char str[] = "123";
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_u_2) {
  char format[] = "%u";
  char str[] = "-123";
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_u_3) {
  char format[] = "%u";
  char str[] = "+123";
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_u_4) {
  char format[] = "%3u %3u";
  char str[] = "23 +123";
  unsigned int d11 = 0, d12 = 0;
  unsigned int d21 = 0, d22 = 0;

  int res1 = s21_sscanf(str, format, &d11, &d12);
  int res2 = sscanf(str, format, &d21, &d22);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d11, d21);
  ck_assert_uint_eq(d12, d22);
}

END_TEST

START_TEST(sscanf_test_u_5) {
  char format[] = "%10u";
  char str[] = "123";
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_u_6) {
  char format[] = "%2u";
  char str[] = "+123";
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_u_7) {
  char format[] = "%1u";
  char str[] = "123";
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_u_8) {
  char format[] = "%*1u";
  char str[] = "+123";
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_u_9) {
  char format[] = "%*u";
  char str[] = "123";
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_u_10) {
  char format[] = "%u";
  char str[] = "2147483647";
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_1) {
  char format[] = "%lu";
  char str[] = "123";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_2) {
  char format[] = "%lu";
  char str[] = "-123";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_3) {
  char format[] = "%lu";
  char str[] = "+123";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_4) {
  char format[] = "%3lu";
  char str[] = "123";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_5) {
  char format[] = "%10lu";
  char str[] = "+123";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_6) {
  char format[] = "%1lu";
  char str[] = "123";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_7) {
  char format[] = "%*1lu";
  char str[] = "+123";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_8) {
  char format[] = "%*lu";
  char str[] = "123";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_9) {
  char format[] = "%lu";
  char str[] = "2147483647";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_10) {
  char format[] = "%lu";
  char str[] = "214741413648";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_test_lu_11) {
  char format[] = "%lu";
  char str[] = "9223372036854775807";
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

Suite *sscanf_test_u() {
  Suite *suite = suite_create("---SSCANF_U---");
  TCase *tcase = tcase_create("sscanf_tc");

  tcase_add_test(tcase, sscanf_test_hu_1);
  tcase_add_test(tcase, sscanf_test_hu_2);
  tcase_add_test(tcase, sscanf_test_hu_3);
  tcase_add_test(tcase, sscanf_test_hu_4);
  tcase_add_test(tcase, sscanf_test_hu_5);
  tcase_add_test(tcase, sscanf_test_hu_6);
  tcase_add_test(tcase, sscanf_test_hu_7);
  tcase_add_test(tcase, sscanf_test_hu_8);
  tcase_add_test(tcase, sscanf_test_hu_9);

  tcase_add_test(tcase, sscanf_test_u_1);
  tcase_add_test(tcase, sscanf_test_u_2);
  tcase_add_test(tcase, sscanf_test_u_3);
  tcase_add_test(tcase, sscanf_test_u_4);
  tcase_add_test(tcase, sscanf_test_u_5);
  tcase_add_test(tcase, sscanf_test_u_6);
  tcase_add_test(tcase, sscanf_test_u_7);
  tcase_add_test(tcase, sscanf_test_u_8);
  tcase_add_test(tcase, sscanf_test_u_9);
  tcase_add_test(tcase, sscanf_test_u_10);

  tcase_add_test(tcase, sscanf_test_lu_1);
  tcase_add_test(tcase, sscanf_test_lu_2);
  tcase_add_test(tcase, sscanf_test_lu_3);
  tcase_add_test(tcase, sscanf_test_lu_4);
  tcase_add_test(tcase, sscanf_test_lu_5);
  tcase_add_test(tcase, sscanf_test_lu_6);
  tcase_add_test(tcase, sscanf_test_lu_7);
  tcase_add_test(tcase, sscanf_test_lu_8);
  tcase_add_test(tcase, sscanf_test_lu_9);
  tcase_add_test(tcase, sscanf_test_lu_10);
  tcase_add_test(tcase, sscanf_test_lu_11);

  suite_add_tcase(suite, tcase);
  return suite;
}
