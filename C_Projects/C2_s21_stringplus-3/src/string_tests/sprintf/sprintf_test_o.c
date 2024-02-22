#include "../s21_string_tests.h"

START_TEST(sprintf_test_o_1) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%o", 100);
  int res2 = sprintf(str2, "%o", 100);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_o_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#o", 100);
  int res2 = sprintf(str2, "%#o", 100);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_o_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#*o", 10, 100);
  int res2 = sprintf(str2, "%#*o", 10, 100);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_o_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-*o", 10, 100);
  int res2 = sprintf(str2, "%-*o", 10, 100);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_o_5) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%*o", 10, 100);
  int res2 = sprintf(str2, "%*o", 10, 100);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

// One parameter octal
START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three octal parameters
START_TEST(sprintf_2_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  int res1 = sprintf(str1, str3, val, val2, val3, val4);
  int res2 = s21_sprintf(str2, str3, val, val2, val3, val4);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different prec and width
START_TEST(sprintf_6_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  int res1 = sprintf(str1, str3, val, val2, val3, val4);
  int res2 = s21_sprintf(str2, str3, val, val2, val3, val4);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3o Test %5.7o TEST %10o %#o %-o %+o %.9o % o";
  int val = 0;
  int res1 = sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  int res2 =
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3o Test % 5.7o TEST % 10o GOD %0.0o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.0o Test %+5.7o TEST %+10o GOD %+0.0o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#0.0o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  int res1 = sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.0o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Test %-*o Test %*.*o TEST %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Simple extra test
START_TEST(sprintf_16_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-o Test %-15o sdasda %-15o sdsad %-o";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  int res1 = sprintf(str1, str3, val, val2, val3, val4);
  int res2 = s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lo";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *sprintf_test_o() {
  Suite *suite = suite_create("---SPRINTF_O---");
  TCase *tcase = tcase_create("sprintf_tc");
  tcase_add_test(tcase, sprintf_test_o_1);
  tcase_add_test(tcase, sprintf_test_o_2);
  tcase_add_test(tcase, sprintf_test_o_3);
  tcase_add_test(tcase, sprintf_test_o_4);
  tcase_add_test(tcase, sprintf_test_o_5);

  tcase_add_test(tcase, sprintf_1_octal);
  tcase_add_test(tcase, sprintf_2_octal);
  tcase_add_test(tcase, sprintf_3_octal);
  tcase_add_test(tcase, sprintf_4_octal);
  tcase_add_test(tcase, sprintf_5_octal);
  tcase_add_test(tcase, sprintf_6_octal);
  tcase_add_test(tcase, sprintf_7_octal);
  tcase_add_test(tcase, sprintf_8_octal);
  tcase_add_test(tcase, sprintf_9_octal);
  tcase_add_test(tcase, sprintf_10_octal);
  tcase_add_test(tcase, sprintf_11_octal);
  tcase_add_test(tcase, sprintf_12_octal);
  tcase_add_test(tcase, sprintf_13_octal);
  tcase_add_test(tcase, sprintf_14_octal);
  tcase_add_test(tcase, sprintf_15_octal);
  tcase_add_test(tcase, sprintf_16_octal);
  tcase_add_test(tcase, sprintf_17_octal);
  tcase_add_test(tcase, sprintf_18_octal);

  suite_add_tcase(suite, tcase);
  return suite;
}