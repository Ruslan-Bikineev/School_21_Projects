#include "../s21_string_tests.h"
START_TEST(sprintf_test_hu_1) {
  char str1[1000];
  char str2[1000];
  short unsigned int num = 1234;

  int res1 = s21_sprintf(str1, "%huasd", num);

  int res2 = sprintf(str2, "%huasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_hu_2) {
  char str1[1000];
  char str2[1000];
  short unsigned int num = 1234;

  int res1 = s21_sprintf(str1, "%10huasd", num);
  int res2 = sprintf(str2, "%10huasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_hu_3) {
  char str1[1000];
  char str2[1000];
  short unsigned int num = 1234;

  int res1 = s21_sprintf(str1, "%huasd", num);
  int res2 = sprintf(str2, "%huasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_hu_4) {
  char str1[1000];
  char str2[1000];
  short unsigned int num = 1234;

  int res1 = s21_sprintf(str1, "%-huasd", num);
  int res2 = sprintf(str2, "%-huasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_u_1) {
  char str1[1000];
  char str2[1000];
  unsigned int num = 1234;

  int res1 = s21_sprintf(str1, "%uasd", num);
  int res2 = sprintf(str2, "%uasd", num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_u_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-12uasd", 91234);
  int res2 = sprintf(str2, "%-12uasd", 91234);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_u_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%12uasd", 13234);
  int res2 = sprintf(str2, "%12uasd", 13234);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_u_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%*uasd", 10, 4321);
  int res2 = sprintf(str2, "%*uasd", 10, 4321);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_lu_1) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%luasd", 123456789678);
  int res2 = sprintf(str2, "%luasd", 123456789678);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_lu_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%luasd", 123456789012345);
  int res2 = sprintf(str2, "%luasd", 123456789012345);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_lu_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-luasd", 123456789012345);
  int res2 = sprintf(str2, "%-luasd", 123456789012345);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_lu_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%luasd", 123456789012345);
  int res2 = sprintf(str2, "%luasd", 123456789012345);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_lu_5) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-*luasd", 20, 123456789012345);
  int res2 = sprintf(str2, "%-*luasd", 20, 123456789012345);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

Suite *sprintf_test_u() {
  Suite *suite = suite_create("---SPRINTF_U---");
  TCase *tcase = tcase_create("sprintf_tc");

  tcase_add_test(tcase, sprintf_test_hu_1);
  tcase_add_test(tcase, sprintf_test_hu_2);
  tcase_add_test(tcase, sprintf_test_hu_3);
  tcase_add_test(tcase, sprintf_test_hu_4);

  tcase_add_test(tcase, sprintf_test_u_1);
  tcase_add_test(tcase, sprintf_test_u_2);
  tcase_add_test(tcase, sprintf_test_u_3);
  tcase_add_test(tcase, sprintf_test_u_4);

  tcase_add_test(tcase, sprintf_test_lu_1);
  tcase_add_test(tcase, sprintf_test_lu_2);
  tcase_add_test(tcase, sprintf_test_lu_3);
  tcase_add_test(tcase, sprintf_test_lu_4);
  tcase_add_test(tcase, sprintf_test_lu_5);

  suite_add_tcase(suite, tcase);
  return suite;
}