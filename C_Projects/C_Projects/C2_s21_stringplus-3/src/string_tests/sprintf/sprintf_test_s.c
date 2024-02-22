#include "../s21_string_tests.h"

START_TEST(sprintf_test_s_1) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%sasd", "asdfg");
  int res2 = sprintf(str2, "%sasd", "asdfg");
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_s_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%10sasd", "asdfg");
  int res2 = sprintf(str2, "%10sasd", "asdfg");
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_s_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-10sasd", "asdfg");
  int res2 = sprintf(str2, "%-10sasd", "asdfg");
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_s_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-10s", "");
  int res2 = sprintf(str2, "%-10s", "");
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_s_5) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%s", "%%%%%%");
  int res2 = sprintf(str2, "%s", "%%%%%%");
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

Suite *sprintf_test_s() {
  Suite *suite = suite_create("---SPRINTF_S---");
  TCase *tcase = tcase_create("sprintf_tc");
  tcase_add_test(tcase, sprintf_test_s_1);
  tcase_add_test(tcase, sprintf_test_s_2);
  tcase_add_test(tcase, sprintf_test_s_3);
  tcase_add_test(tcase, sprintf_test_s_4);
  tcase_add_test(tcase, sprintf_test_s_5);

  suite_add_tcase(suite, tcase);
  return suite;
}