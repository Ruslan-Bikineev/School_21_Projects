#include "../s21_string_tests.h"

START_TEST(sprintf_test_c_1) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%casd", '=');
  int res2 = sprintf(str2, "%casd", '=');
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_c_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%casd%c", '=', '+');
  int res2 = sprintf(str2, "%casd%c", '=', '+');
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_c_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%casd%10c", '=', '+');
  int res2 = sprintf(str2, "%casd%10c", '=', '+');
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_c_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%1casd%10c", '=', '+');
  int res2 = sprintf(str2, "%1casd%10c", '=', '+');
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_c_5) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%1casd%-10c", '=', '+');
  int res2 = sprintf(str2, "%1casd%-10c", '=', '+');
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_c_6) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%%asd");
  int res2 = sprintf(str2, "%%asd");
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprintf_test_c() {
  Suite *suite = suite_create("---SPRINTF_C---");
  TCase *tcase = tcase_create("sprintf_tc");

  tcase_add_test(tcase, sprintf_test_c_1);
  tcase_add_test(tcase, sprintf_test_c_2);
  tcase_add_test(tcase, sprintf_test_c_3);
  tcase_add_test(tcase, sprintf_test_c_4);
  tcase_add_test(tcase, sprintf_test_c_5);
  tcase_add_test(tcase, sprintf_test_c_6);

  suite_add_tcase(suite, tcase);
  return suite;
}
