#include "../s21_string_tests.h"

START_TEST(sprintf_test_x_X_1) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%x", 10);
  int res2 = sprintf(str2, "%x", 10);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#x", 10);
  int res2 = sprintf(str2, "%#x", 10);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#X", 10);
  int res2 = sprintf(str2, "%#X", 10);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#X", 9);
  int res2 = sprintf(str2, "%#X", 9);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_5) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#x", 11);
  int res2 = sprintf(str2, "%#x", 11);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_6) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#x", 12);
  int res2 = sprintf(str2, "%#x", 12);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_7) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#x", 13);
  int res2 = sprintf(str2, "%#x", 13);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_8) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#x", 14);
  int res2 = sprintf(str2, "%#x", 14);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_9) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#x", 15);
  int res2 = sprintf(str2, "%#x", 15);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_10) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-10x", 15);
  int res2 = sprintf(str2, "%-10x", 15);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_11) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%x", 150);
  int res2 = sprintf(str2, "%x", 150);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_12) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#10x", 150);
  int res2 = sprintf(str2, "%#10x", 150);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_x_X_13) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%10x", 150);
  int res2 = sprintf(str2, "%10x", 150);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_1_hex) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %x Test";
  int val = 0x32;
  int res1 = sprintf(str1, str3, val);
  int res2 = s21_sprintf(str2, str3, val);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three hex parameters
START_TEST(sprintf_2_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %lx Test %x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  int res1 = sprintf(str1, str3, val, val2, val3);
  int res2 = s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx Test %lx Test %hx GOD %hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x Test %5x Test %10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x Test %.23x Test %3x TEST %x";
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
START_TEST(sprintf_7_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Test %-8x Test %-7x TEST %-x";
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
START_TEST(sprintf_8_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %0x Test %0.0x TEST %.0x GOD %x";
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
START_TEST(sprintf_9_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3x Test %+5.7x TEST %+10x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int res1 = sprintf(str1, str3, val, val2, val3, val4);
  int res2 = s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %.3x Test %5.7x TEST %10x %#x %-x %+x %x % x";
  int val = 0;
  int res1 = sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  int res2 =
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% x Test % 3x Test % 5.7x TEST % 10x GOD %x";
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
START_TEST(sprintf_12_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3x Test %+5.7x TEST %+10x GOD %+x";
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
START_TEST(sprintf_13_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x Test %#3x Test %#5.7x TEST %#.7x Oof %#.3x";
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

// ZERO flag
START_TEST(sprintf_14_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %06x Test %05.7x TEST %0.7x Oof %0x";
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
START_TEST(sprintf_15_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%*x Test %-*x Test %*.*x TEST %.*x";
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

START_TEST(sprintf_16_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-x Test %-.15x sdasda % 15x sdsad %-x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  int res1 = sprintf(str1, str3, val, val2, val3, val4);
  int res2 = s21_sprintf(str2, str3, val, val2, val3, val4);
  //  printf("1: %s\n", str1);
  //  printf("2: %s\n", str2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter HEX
START_TEST(sprintf_1_HEX) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %X Test";
  int val = 0X32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three HEX parameters
START_TEST(sprintf_2_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X3015;
  int val2 = 0X712;
  int val3 = 0X99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX Test %lX Test %hX GOD %hX";
  unsigned long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%3X Test %5X Test %10X";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5X Test %.23X Test %3.X TEST %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5X Test %-.8X Test %-7X TEST %-.X";
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
START_TEST(sprintf_8_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %0.X Test %0.0X TEST %0X GOD %.X";
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
START_TEST(sprintf_9_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X";
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
START_TEST(sprintf_10_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Test %3X Test %5.7X TEST %.10X %#X %-X %+X %X % X";
  int val = 0;
  int res1 = sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  int res2 =
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% X Test % 3X Test % 5.7X TEST % .10X GOD %X";
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
START_TEST(sprintf_12_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+.3X Test %+5.7X TEST %+.10X GOD %+10X";
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
START_TEST(sprintf_13_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%#X Test %#3X Test %#5.7X TEST %#.7X Oof %#X";
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

// ZERO flag
START_TEST(sprintf_14_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %06X Test %05.7X TEST %0.7X Oof %0X";
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
START_TEST(sprintf_15_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%*X Test %-*X Test %*.*X TEST %.*X";
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

START_TEST(sprintf_16_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-X Test %-15X sdasda %-15X sdsad % X";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *sprintf_test_x_X() {
  Suite *suite = suite_create("---SPRINTF_X---");
  TCase *tcase = tcase_create("sprintf_tc");
  tcase_add_test(tcase, sprintf_test_x_X_1);
  tcase_add_test(tcase, sprintf_test_x_X_2);
  tcase_add_test(tcase, sprintf_test_x_X_3);
  tcase_add_test(tcase, sprintf_test_x_X_4);
  tcase_add_test(tcase, sprintf_test_x_X_5);
  tcase_add_test(tcase, sprintf_test_x_X_6);
  tcase_add_test(tcase, sprintf_test_x_X_7);
  tcase_add_test(tcase, sprintf_test_x_X_8);
  tcase_add_test(tcase, sprintf_test_x_X_9);
  tcase_add_test(tcase, sprintf_test_x_X_10);
  tcase_add_test(tcase, sprintf_test_x_X_11);
  tcase_add_test(tcase, sprintf_test_x_X_12);
  tcase_add_test(tcase, sprintf_test_x_X_13);

  tcase_add_test(tcase, sprintf_1_hex);
  tcase_add_test(tcase, sprintf_2_hex);
  tcase_add_test(tcase, sprintf_3_hex);
  tcase_add_test(tcase, sprintf_4_hex);
  tcase_add_test(tcase, sprintf_5_hex);
  tcase_add_test(tcase, sprintf_6_hex);
  tcase_add_test(tcase, sprintf_7_hex);
  tcase_add_test(tcase, sprintf_8_hex);
  tcase_add_test(tcase, sprintf_9_hex);
  tcase_add_test(tcase, sprintf_10_hex);
  tcase_add_test(tcase, sprintf_11_hex);
  tcase_add_test(tcase, sprintf_12_hex);
  tcase_add_test(tcase, sprintf_13_hex);
  tcase_add_test(tcase, sprintf_14_hex);
  tcase_add_test(tcase, sprintf_15_hex);
  tcase_add_test(tcase, sprintf_16_hex);

  tcase_add_test(tcase, sprintf_1_HEX);
  tcase_add_test(tcase, sprintf_2_HEX);
  tcase_add_test(tcase, sprintf_3_HEX);
  tcase_add_test(tcase, sprintf_4_HEX);
  tcase_add_test(tcase, sprintf_5_HEX);
  tcase_add_test(tcase, sprintf_6_HEX);
  tcase_add_test(tcase, sprintf_7_HEX);
  tcase_add_test(tcase, sprintf_8_HEX);
  tcase_add_test(tcase, sprintf_9_HEX);
  tcase_add_test(tcase, sprintf_10_HEX);
  tcase_add_test(tcase, sprintf_11_HEX);
  tcase_add_test(tcase, sprintf_12_HEX);
  tcase_add_test(tcase, sprintf_13_HEX);
  tcase_add_test(tcase, sprintf_14_HEX);
  tcase_add_test(tcase, sprintf_15_HEX);
  tcase_add_test(tcase, sprintf_16_HEX);
  suite_add_tcase(suite, tcase);
  return suite;
}