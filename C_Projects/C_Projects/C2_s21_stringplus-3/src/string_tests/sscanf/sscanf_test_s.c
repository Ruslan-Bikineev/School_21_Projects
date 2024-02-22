#include "../s21_string_tests.h"

START_TEST(sscanf_test_s_1) {
  char format[] = "this is %s";
  char str[] = "this is string";
  char string1[BF_SIZE], string2[BF_SIZE];

  int res1 = s21_sscanf(str, format, &string1);
  int res2 = sscanf(str, format, &string2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(string1, string2);
}

END_TEST

START_TEST(sscanf_test_s_2) {
  char format[] = "oh %*s";
  char str[] = "oh god";
  char string1[BF_SIZE], string2[BF_SIZE];

  int res1 = s21_sscanf(str, format, &string1);
  int res2 = sscanf(str, format, &string2);
  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_test_s_3) {
  char format[] = "%7s";
  char str[] = "refrigerator";
  char string1[BF_SIZE], string2[BF_SIZE];

  int res1 = s21_sscanf(str, format, &string1);
  int res2 = sscanf(str, format, &string2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(string1, string2);
}

END_TEST

START_TEST(sscanf_test_s_4) {
  char format[] = "%s %3s %*s %11s";
  char str[] = "i have some snacks";
  char string11[BF_SIZE], string12[BF_SIZE], string13[BF_SIZE];
  char string21[BF_SIZE], string22[BF_SIZE], string23[BF_SIZE];

  int res1 = s21_sscanf(str, format, &string11, &string12, &string13);
  int res2 = sscanf(str, format, &string21, &string22, &string23);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(string11, string21);
  ck_assert_pstr_eq(string12, string22);
  ck_assert_pstr_eq(string13, string23);
}

END_TEST

Suite *sscanf_test_s() {
  Suite *suite = suite_create("---SSCANF_S---");
  TCase *tcase = tcase_create("sscanf_tc");

  tcase_add_test(tcase, sscanf_test_s_1);
  tcase_add_test(tcase, sscanf_test_s_2);
  tcase_add_test(tcase, sscanf_test_s_3);
  tcase_add_test(tcase, sscanf_test_s_4);

  suite_add_tcase(suite, tcase);
  return suite;
}