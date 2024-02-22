#include "../s21_string_tests.h"

START_TEST(sprintf_test_g_G_1) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%g", 123.123);
  int res2 = sprintf(str2, "%g", 123.123);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%g", 1234567.123);
  int res2 = sprintf(str2, "%g", 1234567.123);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%G", 123.123);
  int res2 = sprintf(str2, "%G", 123.123);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%10g", 123.123);
  int res2 = sprintf(str2, "%10g", 123.123);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_5) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%g", 123.00001);
  int res2 = sprintf(str2, "%g", 123.00001);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_6) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%g", 123.01001010101);
  int res2 = sprintf(str2, "%g", 123.01001010101);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_7) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#g", 123.01001010101);
  int res2 = sprintf(str2, "%#g", 123.01001010101);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_8) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#g", 123.00000);
  int res2 = sprintf(str2, "%#g", 123.00000);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_9) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-*.*g", 20, 8, 1823.789456);
  int res2 = sprintf(str2, "%-*.*g", 20, 8, 1823.789456);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_10) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%0*.*G", 20, 8, 1823.789456);
  int res2 = sprintf(str2, "%0*.*G", 20, 8, 1823.789456);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_11) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#.*G", 8, 1823.789456);
  int res2 = sprintf(str2, "%#.*G", 8, 1823.789456);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_12) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%+.*G", 8, 1823.789456);
  int res2 = sprintf(str2, "%+.*G", 8, 1823.789456);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_13) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%+.*G", 8, 1823.789456);
  int res2 = sprintf(str2, "%+.*G", 8, 1823.789456);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_14) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#*.0g", 6, 123456.0);
  int res2 = sprintf(str2, "%#*.0g", 6, 123456.0);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_g_G_15) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%g 651661 %g %G dvdsvd %G", NAN, INFINITY, NAN,
                         INFINITY);
  int res2 =
      sprintf(str2, "%g 651661 %g %G dvdsvd %G", NAN, INFINITY, NAN, INFINITY);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %0.0g TEST %4g TEST %4.0g TEST %5.10g!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %0.0g TEST %4g TEST %4.0g TEST %5.10g!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2g TEST\n%.3g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %0.0g TEST %4g TEST %4.0g TEST %#5.10g!";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %0.g TEST %4g TEST %4.0g TEST %#5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %0.0g TEST %4g TEST %4.0g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %0.0g TEST %4.2g TEST %4.0g TEST %5.10g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %15.1g\ntest: %16.2g\ntest: %18.3g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %10.4g\ntest: %25.5g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#15.0g\ntest: %-26.1g\ntest: %-18.0g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#10.0g\ntest: %-25.0g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%6g TEST %.2g TEST %4.5g TEST %4.3g TEST %5.10g!";
  double num = -0.0000756589367;
  int res1 = sprintf(str1, str3, num, num, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num, num, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %0.0g TEST %4g TEST %4.0g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%0.0Lg!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10g %20.15g %-20.5g!";
  double num = -76.756589;

  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%0.0Lg\n%#Lg\n%+.Lg\n%-.Lg!";
  long double num = 76.756589;
  int res1 = sprintf(str1, str3, num, num, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num, num, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g! test: %26.15g!";
  double num = -365289.34628654873789362746834;
  int res1 = sprintf(str1, str3, num, num);
  int res2 = s21_sprintf(str2, str3, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g! test: %020g! test: %+25g!";
  double num = -837564.4753366;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 25.5g!\ntest: %-20.4g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-20g!\ntest: %+25g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %025.5g! test: % 20.4g!";
  double num = -837564.4753366;
  int res1 = sprintf(str1, str3, num, num);
  int res2 = s21_sprintf(str2, str3, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015g!\ntest: %-26g!\ntest: %+18g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 0.2g!\ntest: %-25.7g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg! test: %-26.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-30.15Lg! test: %+50.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+40.15Lg test: % 25.15Lg!";
  long double num = 278.723786;
  int res1 = sprintf(str1, str3, num, num);
  int res2 = s21_sprintf(str2, str3, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: %-26.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-30.13Lg!\ntest: %+50.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+40.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %0.1Lg! test: %0.2Lg! test: %0.3Lg!";
  long double num = 9999.999999;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %0.6Lg!\ntest: %0.0Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %0.0g! test: %.2g! test: %.3g!";
  double num = 0;

  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10g!\ntest: %.6g!\ntest: %0.0g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-20.13g!\ntest: %-25.7g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+20.13g!\ntest: %+25.7g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+.15g!\ntest: %+16g!\ntest: %+13.5g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %0.0Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.12Lg!\ntest: %.6Lg!\ntest: %.9Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\n";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *sprintf_test_g_G() {
  Suite *suite = suite_create("---SPRINTF_G---");
  TCase *tcase = tcase_create("sprintf_tc");
  tcase_add_test(tcase, sprintf_test_g_G_1);
  tcase_add_test(tcase, sprintf_test_g_G_2);
  tcase_add_test(tcase, sprintf_test_g_G_3);
  tcase_add_test(tcase, sprintf_test_g_G_4);
  tcase_add_test(tcase, sprintf_test_g_G_5);
  tcase_add_test(tcase, sprintf_test_g_G_6);
  tcase_add_test(tcase, sprintf_test_g_G_7);
  tcase_add_test(tcase, sprintf_test_g_G_8);
  tcase_add_test(tcase, sprintf_test_g_G_9);
  tcase_add_test(tcase, sprintf_test_g_G_10);
  tcase_add_test(tcase, sprintf_test_g_G_11);
  tcase_add_test(tcase, sprintf_test_g_G_12);
  tcase_add_test(tcase, sprintf_test_g_G_13);
  tcase_add_test(tcase, sprintf_test_g_G_14);
  tcase_add_test(tcase, sprintf_test_g_G_15);

  tcase_add_test(tcase, sprintf_1_g);
  tcase_add_test(tcase, sprintf_2_g);
  tcase_add_test(tcase, sprintf_4_g);
  tcase_add_test(tcase, sprintf_5_g);
  tcase_add_test(tcase, sprintf_6_g);
  tcase_add_test(tcase, sprintf_7_g);
  tcase_add_test(tcase, sprintf_8_g);
  tcase_add_test(tcase, sprintf_9_g);
  tcase_add_test(tcase, sprintf_10_g);
  tcase_add_test(tcase, sprintf_11_g);
  tcase_add_test(tcase, sprintf_12_g);
  tcase_add_test(tcase, sprintf_13_g);
  tcase_add_test(tcase, sprintf_14_g);
  tcase_add_test(tcase, sprintf_15_g);
  tcase_add_test(tcase, sprintf_16_g);
  tcase_add_test(tcase, sprintf_17_g);
  tcase_add_test(tcase, sprintf_18_g);
  tcase_add_test(tcase, sprintf_19_g);
  tcase_add_test(tcase, sprintf_20_g);
  tcase_add_test(tcase, sprintf_21_g);
  tcase_add_test(tcase, sprintf_22_g);
  tcase_add_test(tcase, sprintf_23_g);
  tcase_add_test(tcase, sprintf_24_g);
  tcase_add_test(tcase, sprintf_25_g);
  tcase_add_test(tcase, sprintf_26_g);
  tcase_add_test(tcase, sprintf_27_g);
  tcase_add_test(tcase, sprintf_28_g);
  tcase_add_test(tcase, sprintf_29_g);
  tcase_add_test(tcase, sprintf_30_g);
  tcase_add_test(tcase, sprintf_31_g);
  tcase_add_test(tcase, sprintf_32_g);
  tcase_add_test(tcase, sprintf_33_g);
  tcase_add_test(tcase, sprintf_34_g);
  tcase_add_test(tcase, sprintf_35_g);
  tcase_add_test(tcase, sprintf_36_g);
  tcase_add_test(tcase, sprintf_37_g);
  tcase_add_test(tcase, sprintf_38_g);
  tcase_add_test(tcase, sprintf_39_g);
  tcase_add_test(tcase, sprintf_40_g);
  tcase_add_test(tcase, sprintf_41_g);
  tcase_add_test(tcase, sprintf_42_g);
  tcase_add_test(tcase, sprintf_43_g);
  suite_add_tcase(suite, tcase);
  return suite;
}
