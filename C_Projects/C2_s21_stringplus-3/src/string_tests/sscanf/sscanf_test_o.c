#include "../s21_string_tests.h"

START_TEST(sscanf_test_ho_1) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 183 77";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_ho_2) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 1564 1723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_ho_3) {
  char format[] = "%1ho %1ho %1ho";
  char str[] = "1 04 3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_ho_4) {
  char format[] = "%2ho %2ho %2ho";
  char str[] = "0123 04 3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_ho_5) {
  char format[] = "%3ho %3ho %3ho";
  char str[] = "0123 04 3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_ho_6) {
  char format[] = "%*ho %*ho %*ho";
  char str[] = "0123 04 3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_o_1) {
  char format[] = "%o%o%o";
  char str[] = "123 198 87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_o_2) {
  char format[] = "%o%o%o";
  char str[] = "123 1564 1723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_o_3) {
  char format[] = "%1o %1o %1o";
  char str[] = "1 04 3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_o_4) {
  char format[] = "%2o %2o %2o";
  char str[] = "0123 04 3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_o_5) {
  char format[] = "%3o %3o %3o";
  char str[] = "0123 04 3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_o_6) {
  char format[] = "%*o %*o %*o";
  char str[] = "0123 04 3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_lo_1) {
  char format[] = "%lo%lo%lo";
  char str[] = "123 198 87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_lo_2) {
  char format[] = "%lo%lo%lo";
  char str[] = "123 1564 1723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_lo_3) {
  char format[] = "%1lo %1lo %1lo";
  char str[] = "1 04 3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_lo_4) {
  char format[] = "%2lo %2lo %2lo";
  char str[] = "0123 04 3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_lo_5) {
  char format[] = "%3lo %3lo %3lo";
  char str[] = "0123 04 3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_lo_6) {
  char format[] = "%*lo %*lo %*lo";
  char str[] = "0123 04 3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

Suite *sscanf_test_o() {
  Suite *suite = suite_create("---SSCANF_O---");
  TCase *tcase = tcase_create("sscanf_tc");

  tcase_add_test(tcase, sscanf_test_ho_1);
  tcase_add_test(tcase, sscanf_test_ho_2);
  tcase_add_test(tcase, sscanf_test_ho_3);
  tcase_add_test(tcase, sscanf_test_ho_4);
  tcase_add_test(tcase, sscanf_test_ho_5);
  tcase_add_test(tcase, sscanf_test_ho_6);
  tcase_add_test(tcase, sscanf_test_o_1);
  tcase_add_test(tcase, sscanf_test_o_2);
  tcase_add_test(tcase, sscanf_test_o_3);
  tcase_add_test(tcase, sscanf_test_o_4);
  tcase_add_test(tcase, sscanf_test_o_5);
  tcase_add_test(tcase, sscanf_test_o_6);
  tcase_add_test(tcase, sscanf_test_lo_1);
  tcase_add_test(tcase, sscanf_test_lo_2);
  tcase_add_test(tcase, sscanf_test_lo_3);
  tcase_add_test(tcase, sscanf_test_lo_4);
  tcase_add_test(tcase, sscanf_test_lo_5);
  tcase_add_test(tcase, sscanf_test_lo_6);

  suite_add_tcase(suite, tcase);
  return suite;
}