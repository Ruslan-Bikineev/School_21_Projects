#include "../s21_string_tests.h"

START_TEST(sscanf_test_c_1) {
  char format[] = "%c";
  char str[] = "string";
  char c1, c2;

  int res1 = s21_sscanf(str, format, &c1);
  int res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_c_2) {
  char format[] = "%c";
  char str[] = "\t\n   \n  \ta";
  char c1, c2;

  int res1 = s21_sscanf(str, format, &c1);
  int res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_c_3) {
  char format[] = "%c %c %c";
  char str[] = "7 1 3";
  char c11, c12, c13, c21, c22, c23;

  int res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_test_c_4) {
  char format[] = "%c \n%c %c";
  char str[] = "1 \n2 3";
  char c11, c12, c13, c21, c22, c23;

  int res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_test_c_5) {
  char format[] = "%%%c";
  char str[] = "%p";
  char c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &c1);
  int res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

Suite *sscanf_test_c() {
  Suite *suite = suite_create("---SSCANF_C---");
  TCase *tcase = tcase_create("sscanf_tc");

  tcase_add_test(tcase, sscanf_test_c_1);
  tcase_add_test(tcase, sscanf_test_c_2);
  tcase_add_test(tcase, sscanf_test_c_3);
  tcase_add_test(tcase, sscanf_test_c_4);
  tcase_add_test(tcase, sscanf_test_c_5);

  suite_add_tcase(suite, tcase);
  return suite;
}