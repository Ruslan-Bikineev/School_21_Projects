#include "../s21_string_tests.h"

START_TEST(sscanf_test_hi_dec_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "123 +198 -87";
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

START_TEST(sscanf_test_hi_dec_2) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "13 +137 -8";
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

START_TEST(sscanf_test_hi_dec_3) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "13 +137 -8";
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

START_TEST(sscanf_test_hi_dec_4) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "13 +137 -8";
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

START_TEST(sscanf_test_hi_dec_5) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;
  unsigned short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_hi_oct_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0123 +0198 -087";
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

START_TEST(sscanf_test_hi_oct_2) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "013 +0137 -08";
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

START_TEST(sscanf_test_hi_oct_3) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "013 +0137 -08";
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

START_TEST(sscanf_test_hi_oct_4) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "013 +0137 -08";
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

START_TEST(sscanf_test_hi_oct_5) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;
  unsigned short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_hi_hex_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0x123 +0X198 -0x87";
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

START_TEST(sscanf_test_hi_hex_2) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "0X13 +0x137 -0x8";
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

START_TEST(sscanf_test_hi_hex_3) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "0x13 +0x137 -0x8";
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

START_TEST(sscanf_test_hi_hex_4) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "0x13 +0x1a -0x8";
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

START_TEST(sscanf_test_hi_hex_5) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned short a1 = 0, a2 = 0;
  unsigned short b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0;
  unsigned short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_i_dec_1) {
  char format[] = "%i%i%i";
  char str[] = "123 +198 -87";
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

START_TEST(sscanf_test_i_dec_2) {
  char format[] = "%1i %1i %1i";
  char str[] = "13 +137 -8";
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

START_TEST(sscanf_test_i_dec_3) {
  char format[] = "%2i %2i %2i";
  char str[] = "13 +137 -8";
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

START_TEST(sscanf_test_i_dec_4) {
  char format[] = "%30i %24i %21i";
  char str[] = "13 +137 -8";
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

START_TEST(sscanf_test_i_dec_5) {
  char format[] = "%i %i %i %i";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_i_oct_1) {
  char format[] = "%i%i%i";
  char str[] = "0123 +0198 -087";
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

START_TEST(sscanf_test_i_oct_2) {
  char format[] = "%1i %1i %1i";
  char str[] = "013 +0137 -08";
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

START_TEST(sscanf_test_i_oct_3) {
  char format[] = "%2i %2i %2i";
  char str[] = "013 +0137 -08";
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

START_TEST(sscanf_test_i_oct_4) {
  char format[] = "%30i %24i %21i";
  char str[] = "013 +0137 -08";
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

START_TEST(sscanf_test_i_oct_5) {
  char format[] = "%i %i %i %i";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_i_hex_1) {
  char format[] = "%i%i%i";
  char str[] = "0x123 +0X198 -0x87";
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

START_TEST(sscanf_test_i_hex_2) {
  char format[] = "%1i %1i %1i";
  char str[] = "0X13 +0x137 -0x8";
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

START_TEST(sscanf_test_i_hex_3) {
  char format[] = "%3i %3i %3i";
  char str[] = "0x13 +0x137 -0x8";
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

START_TEST(sscanf_test_i_hex_4) {
  char format[] = "%30i %24i %21i";
  char str[] = "0x13 +0x1a -0x8";
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

START_TEST(sscanf_test_i_hex_5) {
  char format[] = "%i %i %i %i";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned int c1 = 0, c2 = 0;
  unsigned int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_li_dec_1) {
  char format[] = "%li%li%li";
  char str[] = "123 +198 -87";
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

START_TEST(sscanf_test_li_dec_2) {
  char format[] = "%1li %1li %1li";
  char str[] = "13 +137 -8";
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

START_TEST(sscanf_test_li_dec_3) {
  char format[] = "%2li %2li %2li";
  char str[] = "13 +137 -8";
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

START_TEST(sscanf_test_li_dec_4) {
  char format[] = "%30li %24li %21li";
  char str[] = "13 +137 -8";
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

START_TEST(sscanf_test_li_dec_5) {
  char format[] = "%li %li %li %li";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_li_oct_1) {
  char format[] = "%li%li%li";
  char str[] = "0123 +0198 -087";
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

START_TEST(sscanf_test_li_oct_2) {
  char format[] = "%1li %1li %1li";
  char str[] = "013 +0137 -08";
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

START_TEST(sscanf_test_li_oct_3) {
  char format[] = "%2li %2li %2li";
  char str[] = "013 +0137 -08";
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

START_TEST(sscanf_test_li_oct_4) {
  char format[] = "%30li %24li %21li";
  char str[] = "013 +0137 -08";
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

START_TEST(sscanf_test_li_oct_5) {
  char format[] = "%li %li %li %li";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_li_hex_1) {
  char format[] = "%li%li%li";
  char str[] = "0x123 +0X198 -0x87";
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

START_TEST(sscanf_test_li_hex_2) {
  char format[] = "%1li %1li %1li";
  char str[] = "0X13 +0x137 -0x8";
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

START_TEST(sscanf_test_li_hex_3) {
  char format[] = "%3li %3li %3li";
  char str[] = "0x13 +0x137 -0x8";
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

START_TEST(sscanf_test_li_hex_4) {
  char format[] = "%30li %24li %21li";
  char str[] = "0x13 +0x1a -0x8";
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

START_TEST(sscanf_test_li_hex_5) {
  char format[] = "%li %li %li %li";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned long int a1 = 0, a2 = 0;
  unsigned long int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;
  unsigned long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

Suite *sscanf_test_i() {
  Suite *suite = suite_create("---SSCANF_I---");
  TCase *tcase = tcase_create("sscanf_tc");

  tcase_add_test(tcase, sscanf_test_hi_dec_1);
  tcase_add_test(tcase, sscanf_test_hi_dec_2);
  tcase_add_test(tcase, sscanf_test_hi_dec_3);
  tcase_add_test(tcase, sscanf_test_hi_dec_4);
  tcase_add_test(tcase, sscanf_test_hi_dec_5);

  tcase_add_test(tcase, sscanf_test_hi_oct_1);
  tcase_add_test(tcase, sscanf_test_hi_oct_2);
  tcase_add_test(tcase, sscanf_test_hi_oct_3);
  tcase_add_test(tcase, sscanf_test_hi_oct_4);
  tcase_add_test(tcase, sscanf_test_hi_oct_5);

  tcase_add_test(tcase, sscanf_test_hi_hex_1);
  tcase_add_test(tcase, sscanf_test_hi_hex_2);
  tcase_add_test(tcase, sscanf_test_hi_hex_3);
  tcase_add_test(tcase, sscanf_test_hi_hex_4);
  tcase_add_test(tcase, sscanf_test_hi_hex_5);

  tcase_add_test(tcase, sscanf_test_i_dec_1);
  tcase_add_test(tcase, sscanf_test_i_dec_2);
  tcase_add_test(tcase, sscanf_test_i_dec_3);
  tcase_add_test(tcase, sscanf_test_i_dec_4);
  tcase_add_test(tcase, sscanf_test_i_dec_5);

  tcase_add_test(tcase, sscanf_test_i_oct_1);
  tcase_add_test(tcase, sscanf_test_i_oct_2);
  tcase_add_test(tcase, sscanf_test_i_oct_3);
  tcase_add_test(tcase, sscanf_test_i_oct_4);
  tcase_add_test(tcase, sscanf_test_i_oct_5);

  tcase_add_test(tcase, sscanf_test_i_hex_1);
  tcase_add_test(tcase, sscanf_test_i_hex_2);
  tcase_add_test(tcase, sscanf_test_i_hex_3);
  tcase_add_test(tcase, sscanf_test_i_hex_4);
  tcase_add_test(tcase, sscanf_test_i_hex_5);

  tcase_add_test(tcase, sscanf_test_li_dec_1);
  tcase_add_test(tcase, sscanf_test_li_dec_2);
  tcase_add_test(tcase, sscanf_test_li_dec_3);
  tcase_add_test(tcase, sscanf_test_li_dec_4);
  tcase_add_test(tcase, sscanf_test_li_dec_5);

  tcase_add_test(tcase, sscanf_test_li_oct_1);
  tcase_add_test(tcase, sscanf_test_li_oct_2);
  tcase_add_test(tcase, sscanf_test_li_oct_3);
  tcase_add_test(tcase, sscanf_test_li_oct_4);
  tcase_add_test(tcase, sscanf_test_li_oct_5);

  tcase_add_test(tcase, sscanf_test_li_hex_1);
  tcase_add_test(tcase, sscanf_test_li_hex_2);
  tcase_add_test(tcase, sscanf_test_li_hex_3);
  tcase_add_test(tcase, sscanf_test_li_hex_4);
  tcase_add_test(tcase, sscanf_test_li_hex_5);

  suite_add_tcase(suite, tcase);
  return suite;
}