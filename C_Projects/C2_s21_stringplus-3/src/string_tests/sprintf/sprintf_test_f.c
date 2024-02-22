#include "../s21_string_tests.h"

START_TEST(sprintf_test_f_1) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%fasd", 12345.234567);
  int res2 = sprintf(str2, "%fasd", 12345.234567);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%10fasd", 12345.234567);
  int res2 = sprintf(str2, "%10fasd", 12345.234567);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%10.12fasd", 12345.234567f);
  int res2 = sprintf(str2, "%10.12fasd", 12345.234567f);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%10.*fasd", 12, 12345.234567f);
  int res2 = sprintf(str2, "%10.*fasd", 12, 12345.234567f);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_5) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%*fasd", 12, 12345.234f);
  int res2 = sprintf(str2, "%*fasd", 12, 12345.234f);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_6) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%fasd", 1.8888888889f);
  int res2 = sprintf(str2, "%fasd", 1.8888888889f);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_7) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-5.1fasd", 1.8888888889f);
  int res2 = sprintf(str2, "%-5.1fasd", 1.8888888889f);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_8) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%10fasd", 1.8888f);
  int res2 = sprintf(str2, "%10fasd", 1.8888f);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_9) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%Lfasd", 1.8888L);
  int res2 = sprintf(str2, "%Lfasd", 1.8888L);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_10) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%*.*Lfasd", 10, 2, 1.8888L);
  int res2 = sprintf(str2, "%*.*Lfasd", 10, 2, 1.8888L);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_11) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%+*.*Lfasd", 10, 2, 1.8888L);
  int res2 = sprintf(str2, "%+*.*Lfasd", 10, 2, 1.8888L);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_12) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "% *.*Lfasd", 10, 2, 1.8888L);
  int res2 = sprintf(str2, "% *.*Lfasd", 10, 2, 1.8888L);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_f_13) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#fasd", 1.0);
  int res2 = sprintf(str2, "%#fasd", 1.0);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

START_TEST(sprintf_test_f_14) {
  char str1[1000];
  char str2[1000];
  int res1 = s21_sprintf(str1, "%f dvsdv %f", NAN, INFINITY);
  int res2 = sprintf(str2, "%f dvsdv %f", NAN, INFINITY);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_1_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %0.0f TEST %4f TEST %4.0f TEST %5.10f!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %0.0f TEST %3f TEST %4.0f TEST %5.10f!";
  double num = -76.756589367;

  int res1 = sprintf(str1, str3, num, num, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%0.0Lf!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10f %20.15f %-20.5f!";
  double num = -76.756589;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf %0.0Lf %+Lf %+0.0Lf %#0.0Lf!";
  long double num = 76.756589;
  int res1 = sprintf(str1, str3, num, num, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %5f\ntest: %6.1f\ntest: %8.2f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.5f\ntest: %12.4f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.1f\ntest: %16.2f\ntest: %18.3f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.4f\ntest: %25.5f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+15.0f\ntest: %#16.0f\ntest: %+18.0f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+18.0f\ntest: %+10.0f\ntest: %+25.0f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-26.1f\ntest: %-18.0f\ntest: %#10.0f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#15.0f\ntest: %+25.0f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-15.4f!\ntest: %-26.1f!\ntest: %18.0f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#10.9f!\ntest: %-25.15f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13f!\ntest: %26.15f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!\ntest: %25.15f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13f!\ntest: %26.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-23.14f!\ntest: %+25.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15f!\ntest: %-26f!\ntest: %-18f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+14f!\ntest: %+10f!\ntest: % 25f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_f) {
  char *str1 = malloc(100 * sizeof(char));
  char *str2 = malloc(100 * sizeof(char));
  char *str3 = "%14f a %-27f a % 19f!";
  double num = 365789.34;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(sprintf_24_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 16f!\ntest: %+44f!\ntest: % 35f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %26Lf!\ntest: %18Lf!\ntest: %60Lf!";
  long double num = -3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15Lf!test: %100Lf!";
  long double num = -3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-26Lf!\ntest: % 18Lf!\ntest: %60Lf!";
  long double num = 3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+15Lf!test: %100Lf!";
  long double num = 3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020f!\ntest: %-20f!\ntest: %+25f!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %025.5f!\ntest: %020.4f\ntest: %016.6f!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015f!\ntest: %-26f!\ntest: %+18f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+10.2f!\ntest: %025.7f\ntest: %+18.4f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % 26.15Lf!\ntest: %-30.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+50.15Lf!\ntest: % 40.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % 26.13Lf!\ntest: %-30.8Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 50.14Lf!\ntest: %+40.14Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %0.10Lf!\ntest: %0.6Lf!\ntest: %0.0Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lf!\ntest: %0.0Lf\ntest: %0Lf!!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -635293201236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %0Lf! test: %.6Lf! test: %.15Lf!";
  long double num = -635293201236310753.6495633;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf! test: %.2Lf! test: %.3Lf!";
  long double num = -236310753.6495633;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_45_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_46_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf! test: %.2Lf! test: %.3Lf!";
  long double num = -9325781235683689988.;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_47_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_48_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %25.5Lf!\ntest: %Lf!\ntest: %-50Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_49_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 0Lf!\ntest: %060Lf!\ntest: %.15Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_50_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-.1Lf! test: %-.2Lf! test: %-0.3Lf!";
  long double num = -0.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_51_f) {
  char str1[400];
  char str2[400];
  char *str3 = "fshgkaljck% 10.12f hgsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

END_TEST

Suite *sprintf_test_f() {
  Suite *suite = suite_create("---SPRINTF_F---");
  TCase *tcase = tcase_create("sprintf_tc");
  tcase_add_test(tcase, sprintf_test_f_1);
  tcase_add_test(tcase, sprintf_test_f_2);
  tcase_add_test(tcase, sprintf_test_f_3);
  tcase_add_test(tcase, sprintf_test_f_4);
  tcase_add_test(tcase, sprintf_test_f_5);
  tcase_add_test(tcase, sprintf_test_f_6);
  tcase_add_test(tcase, sprintf_test_f_7);
  tcase_add_test(tcase, sprintf_test_f_8);
  tcase_add_test(tcase, sprintf_test_f_9);
  tcase_add_test(tcase, sprintf_test_f_10);
  tcase_add_test(tcase, sprintf_test_f_11);
  tcase_add_test(tcase, sprintf_test_f_12);
  tcase_add_test(tcase, sprintf_test_f_13);
  tcase_add_test(tcase, sprintf_test_f_14);

  tcase_add_test(tcase, sprintf_1_f);
  tcase_add_test(tcase, sprintf_2_f);
  tcase_add_test(tcase, sprintf_3_f);
  tcase_add_test(tcase, sprintf_4_f);
  tcase_add_test(tcase, sprintf_5_f);
  tcase_add_test(tcase, sprintf_6_f);
  tcase_add_test(tcase, sprintf_7_f);
  tcase_add_test(tcase, sprintf_8_f);
  tcase_add_test(tcase, sprintf_9_f);
  tcase_add_test(tcase, sprintf_10_f);
  tcase_add_test(tcase, sprintf_11_f);
  tcase_add_test(tcase, sprintf_12_f);
  tcase_add_test(tcase, sprintf_13_f);
  tcase_add_test(tcase, sprintf_14_f);
  tcase_add_test(tcase, sprintf_15_f);
  tcase_add_test(tcase, sprintf_16_f);
  tcase_add_test(tcase, sprintf_17_f);
  tcase_add_test(tcase, sprintf_18_f);
  tcase_add_test(tcase, sprintf_19_f);
  tcase_add_test(tcase, sprintf_20_f);
  tcase_add_test(tcase, sprintf_21_f);
  tcase_add_test(tcase, sprintf_22_f);
  tcase_add_test(tcase, sprintf_23_f);
  tcase_add_test(tcase, sprintf_24_f);
  tcase_add_test(tcase, sprintf_25_f);
  tcase_add_test(tcase, sprintf_26_f);
  tcase_add_test(tcase, sprintf_27_f);
  tcase_add_test(tcase, sprintf_28_f);
  tcase_add_test(tcase, sprintf_30_f);
  tcase_add_test(tcase, sprintf_31_f);
  tcase_add_test(tcase, sprintf_32_f);
  tcase_add_test(tcase, sprintf_33_f);
  tcase_add_test(tcase, sprintf_34_f);
  tcase_add_test(tcase, sprintf_35_f);
  tcase_add_test(tcase, sprintf_36_f);
  tcase_add_test(tcase, sprintf_37_f);
  tcase_add_test(tcase, sprintf_38_f);
  tcase_add_test(tcase, sprintf_39_f);
  tcase_add_test(tcase, sprintf_40_f);
  tcase_add_test(tcase, sprintf_41_f);
  tcase_add_test(tcase, sprintf_42_f);
  tcase_add_test(tcase, sprintf_43_f);
  tcase_add_test(tcase, sprintf_44_f);
  tcase_add_test(tcase, sprintf_45_f);
  tcase_add_test(tcase, sprintf_46_f);
  tcase_add_test(tcase, sprintf_47_f);
  tcase_add_test(tcase, sprintf_48_f);
  tcase_add_test(tcase, sprintf_49_f);
  tcase_add_test(tcase, sprintf_50_f);
  tcase_add_test(tcase, sprintf_51_f);
  suite_add_tcase(suite, tcase);
  return suite;
}
