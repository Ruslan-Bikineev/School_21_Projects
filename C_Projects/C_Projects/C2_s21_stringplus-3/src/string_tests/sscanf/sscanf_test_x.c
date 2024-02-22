#include "../s21_string_tests.h"

START_TEST(sscanf_test_hx_1) {
  char format[] = "%hx%hx%hx";
  char str[] = "123 198 87";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_hx_2) {
  char format[] = "%hx%hx%hx";
  char str[] = "12a3 156B4 17C23";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_hx_3) {
  char format[] = "%hx%hx";
  char str[] = "0 0x";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1);
  int res2 = sscanf(str, format, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_test_hx_4) {
  char format[] = "%hx%hx%hx";
  char str[] = "0 0XABC 0X";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_hx_5) {
  char format[] = "%hx%hx%hx";
  char str[] = "0abc4 0XABC 0x";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_hx_6) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a 04 3723";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_hx_7) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a 0x 3723";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_hx_8) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bc 0x 3723";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_hx_9) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bCc 0x 3723";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_hx_10) {
  char format[] = "%3hx %3hx %3hx";
  char str[] = "0x123 0X4 37x23";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_hx_11) {
  char format[] = "%*hx %*hx %hx";
  char str[] = "0x123 04 372f3";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_1) {
  char format[] = "%x%x%x";
  char str[] = "123 198 87";
  unsigned int a1, a2;
  unsigned int b1, b2;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_2) {
  char format[] = "%x%x%x";
  char str[] = "12a3 156B4 17C23";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_3) {
  char format[] = "%x%x";
  char str[] = "0 0x";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1);
  int res2 = sscanf(str, format, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_test_x_4) {
  char format[] = "%x%x%x";
  char str[] = "0 0XABC 0X";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_5) {
  char format[] = "%x%x%x";
  char str[] = "0abc4 0XABC 0x";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_6) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a 04 3723";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_7) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a 0x 3723";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_8) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a bc 0x 3723";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_9) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a bCc 0x 3723";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_10) {
  char format[] = "%3x %3x %3x";
  char str[] = "0x123 0X4 37x23";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_x_11) {
  char format[] = "%*x %*x %x";
  char str[] = "0x123 04 372f3";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_1) {
  char format[] = "%lx%lx%lx";
  char str[] = "123 198 87";
  unsigned long int a1, a2;
  unsigned long int b1, b2;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_2) {
  char format[] = "%lx%lx%lx";
  char str[] = "12a3 156B4 17C23";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_3) {
  char format[] = "%lx%lx";
  char str[] = "0 0x";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1);
  int res2 = sscanf(str, format, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_test_lx_4) {
  char format[] = "%lx%lx%lx";
  char str[] = "0 0XABC 0X";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_5) {
  char format[] = "%lx%lx%lx";
  char str[] = "0abc4 0XABC 0x";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_6) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1a 04 3723";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_7) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1a 0x 3723";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_8) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a bc 0x 3723";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_9) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a bCc 0x 3723";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_10) {
  char format[] = "%3lx %3lx %3lx";
  char str[] = "0x123 0X4 37x23";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_lx_11) {
  char format[] = "%*lx %*lx %lx";
  char str[] = "0x123 04 372f3";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
}
END_TEST

Suite *sscanf_test_x(void) {
  Suite *suite = suite_create("---SSCANF_X---");
  TCase *tcase = tcase_create("sscanf_tc");

  tcase_add_test(tcase, sscanf_test_hx_1);
  tcase_add_test(tcase, sscanf_test_hx_2);
  tcase_add_test(tcase, sscanf_test_hx_3);
  tcase_add_test(tcase, sscanf_test_hx_4);
  tcase_add_test(tcase, sscanf_test_hx_5);
  tcase_add_test(tcase, sscanf_test_hx_6);
  tcase_add_test(tcase, sscanf_test_hx_7);
  tcase_add_test(tcase, sscanf_test_hx_8);
  tcase_add_test(tcase, sscanf_test_hx_9);
  tcase_add_test(tcase, sscanf_test_hx_10);
  tcase_add_test(tcase, sscanf_test_hx_11);

  tcase_add_test(tcase, sscanf_test_x_1);
  tcase_add_test(tcase, sscanf_test_x_2);
  tcase_add_test(tcase, sscanf_test_x_3);
  tcase_add_test(tcase, sscanf_test_x_4);
  tcase_add_test(tcase, sscanf_test_x_5);
  tcase_add_test(tcase, sscanf_test_x_6);
  tcase_add_test(tcase, sscanf_test_x_7);
  tcase_add_test(tcase, sscanf_test_x_8);
  tcase_add_test(tcase, sscanf_test_x_9);
  tcase_add_test(tcase, sscanf_test_x_10);
  tcase_add_test(tcase, sscanf_test_x_11);

  tcase_add_test(tcase, sscanf_test_lx_1);
  tcase_add_test(tcase, sscanf_test_lx_2);
  tcase_add_test(tcase, sscanf_test_lx_3);
  tcase_add_test(tcase, sscanf_test_lx_4);
  tcase_add_test(tcase, sscanf_test_lx_5);
  tcase_add_test(tcase, sscanf_test_lx_6);
  tcase_add_test(tcase, sscanf_test_lx_7);
  tcase_add_test(tcase, sscanf_test_lx_8);
  tcase_add_test(tcase, sscanf_test_lx_9);
  tcase_add_test(tcase, sscanf_test_lx_10);
  tcase_add_test(tcase, sscanf_test_lx_11);

  suite_add_tcase(suite, tcase);
  return suite;
}