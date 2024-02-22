#include "../s21_string_tests.h"

START_TEST(sprintf_test_hd_1) {
  char str1[1000];
  char str2[1000];
  short int num = 1234;

  int res1 = s21_sprintf(str1, "%hdasd", num);
  int res2 = sprintf(str2, "%hdasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_hd_2) {
  char str1[1000];
  char str2[1000];
  short int num = 1234;

  int res1 = s21_sprintf(str1, "%10hdasd", num);
  int res2 = sprintf(str2, "%10hdasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_hd_3) {
  char str1[1000];
  char str2[1000];
  short int num = 1234;

  int res1 = s21_sprintf(str1, "% hdasd", num);
  int res2 = sprintf(str2, "% hdasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_hd_4) {
  char str1[1000];
  char str2[1000];
  short int num = 1234;

  int res1 = s21_sprintf(str1, "%+hdasd", num);
  int res2 = sprintf(str2, "%+hdasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_d_1) {
  char str1[1000];
  char str2[1000];
  short int num = -1234;

  int res1 = s21_sprintf(str1, "%dasd", num);
  int res2 = sprintf(str2, "%dasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_d_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-12dasd", -1234);
  int res2 = sprintf(str2, "%-12dasd", -1234);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_d_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%+12dasd", -1234);
  int res2 = sprintf(str2, "%+12dasd", -1234);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_d_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%*dasd", 10, -1234);
  int res2 = sprintf(str2, "%*dasd", 10, -1234);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_ld_1) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%ldasd", -123456789678);
  int res2 = sprintf(str2, "%ldasd", -123456789678);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_ld_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%ldasd", 123456789012345);
  int res2 = sprintf(str2, "%ldasd", 123456789012345);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_ld_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%+ldasd", 123456789012345);
  int res2 = sprintf(str2, "%+ldasd", 123456789012345);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_ld_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-10ldasd", 123456789012345);
  int res2 = sprintf(str2, "%-10ldasd", 123456789012345);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_ld_5) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-*ldasd", 20, 123456789012345);
  int res2 = sprintf(str2, "%-*ldasd", 20, 123456789012345);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

Suite *sprintf_test_d() {
  Suite *suite = suite_create("---SPRINTF_D---");
  TCase *tcase = tcase_create("sprintf_tc");

  tcase_add_test(tcase, sprintf_test_hd_1);
  tcase_add_test(tcase, sprintf_test_hd_2);
  tcase_add_test(tcase, sprintf_test_hd_3);
  tcase_add_test(tcase, sprintf_test_hd_4);

  tcase_add_test(tcase, sprintf_test_d_1);
  tcase_add_test(tcase, sprintf_test_d_2);
  tcase_add_test(tcase, sprintf_test_d_3);
  tcase_add_test(tcase, sprintf_test_d_4);

  tcase_add_test(tcase, sprintf_test_ld_1);
  tcase_add_test(tcase, sprintf_test_ld_2);
  tcase_add_test(tcase, sprintf_test_ld_3);
  tcase_add_test(tcase, sprintf_test_ld_4);
  tcase_add_test(tcase, sprintf_test_ld_5);

  suite_add_tcase(suite, tcase);
  return suite;
}
