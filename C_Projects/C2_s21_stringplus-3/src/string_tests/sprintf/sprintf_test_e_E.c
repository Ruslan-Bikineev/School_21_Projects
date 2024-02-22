#include "../s21_string_tests.h"

START_TEST(sprintf_test_e_E_1) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%e", 100.1);
  int res2 = sprintf(str2, "%e", 100.1);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_2) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%E", 100.1);
  int res2 = sprintf(str2, "%E", 100.1);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_3) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%-10e", 100.1);
  int res2 = sprintf(str2, "%-10e", 100.1);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_4) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%e", 0.001);
  int res2 = sprintf(str2, "%e", 0.001);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_5) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%e", 1.0);
  int res2 = sprintf(str2, "%e", 1.0);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_6) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%e", -10.078);
  int res2 = sprintf(str2, "%e", -10.078);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_7) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%10e", -10.078);
  int res2 = sprintf(str2, "%10e", -10.078);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_8) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%+10e", 10798.078);
  int res2 = sprintf(str2, "%+10e", 10798.078);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_9) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "% 10e", 78542.07788);
  int res2 = sprintf(str2, "% 10e", 78542.07788);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_10) {
  char str1[1000];
  char str2[1000];

  int res1 = s21_sprintf(str1, "%#10e", 1.0);
  int res2 = sprintf(str2, "%#10e", 1.0);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_test_e_E_11) {
  char str1[1000];
  char str2[1000];

  int res1 =
      s21_sprintf(str1, "%e dscd %e %E dscd %E", NAN, INFINITY, NAN, INFINITY);
  int res2 =
      sprintf(str2, "%e dscd %e %E dscd %E", NAN, INFINITY, NAN, INFINITY);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_1_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e Test %5e Test %5.0e";
  double num = -764231539.;
  int res1 = sprintf(str1, str3, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e\n%0.0e\n%4e\n%4.0e\n%5.10e!";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%#e\n%#0.0e\n%#5.0e\n%#.0e\n%#0.0e!";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e Second test: %020.0e!";
  double num = -5921563224775967.;
  int res1 = sprintf(str1, str3, num, num);
  int res2 = s21_sprintf(str2, str3, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.0e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %0.0e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.0e!";
  double num =
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.e\nFifth test: %0.0e!";
  double num =
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %020.4e Forth test: %020.3e!";
  double num = -592156322477596.;
  int res1 = sprintf(str1, str3, num, num);
  int res2 = s21_sprintf(str2, str3, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %020.2e Sixth test: %020.1e!";
  double num = -592156322477596.;
  int res1 = sprintf(str1, str3, num, num);
  int res2 = s21_sprintf(str2, str3, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: %020.0e\n Eighth test: %020.0e!";
  double num = -592156322477596.;
  int res1 = sprintf(str1, str3, num, num);
  int res2 = s21_sprintf(str2, str3, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: % 20e Second test: % 20.5e!";
  double num = -592156322477596.;
  int res1 = sprintf(str1, str3, num, num);
  int res2 = s21_sprintf(str2, str3, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: % 20.4e\nForth test: % 20.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: % 20.2e\nSixth test: % 20.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: % 20.e\n Eighth test: % 20.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: % 31e\nSecond test: % 30.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: % 33.4e\nForth test: % 35.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: % 36.2e\nSixth test: % 45.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: % 64.e\n Eighth test: % 80.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_e) {
  char str1[300];
  char str2[300];
  double num1 = -89435776876.;
  double num2 = -894357768.76;
  char *str3 = "New test: %e\nSecond test: %e!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_e) {
  char str1[300];
  char str2[300];
  double num3 = -89435.776876;
  double num4 = -0.89435776876;
  char *str3 = "Third test: %e\nForth test: %e\n!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_e) {
  char str1[300];
  char str2[300];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  char *str3 = "New test: %e\nSecond test: %e!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_e) {
  char str1[300];
  char str2[300];
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "Third test: %e\nForth test: %e\n!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_e) {
  char str1[300];
  char str2[300];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "test: %0.0E! test: %#E! test: %#0.0E! test: %0.0E!";
  int res1 = sprintf(str1, str3, num1, num2, num3, num4);
  int res2 = s21_sprintf(str2, str3, num1, num2, num3, num4);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_e) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num2 = -.0003529373967;
  double num3 = -0.00000003529373967;
  char *str3 = "test: %013.0E\ntest: %#4.9E\ntest: % 16.2E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_e) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "test: %20.0E test: %-20.0E!";
  int res1 = sprintf(str1, str3, num4, num1);
  int res2 = s21_sprintf(str2, str3, num4, num1);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_e) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "test: % 30.1E\ntest: % 30.0E\ntest: %030.0E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_e) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num4 = 0000000000000.3529373967;
  char *str3 = "test: %066.0E\ntest: %-20.0E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_e) {
  char str1[300];
  char str2[300];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "test: %-17.1E\ntest: % 17.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_e) {
  char str1[300];
  char str2[300];
  double num2 = -53296575676899283734747273752737878257.;
  char *str3 = "test: %#10.2E\ntest: % 10.0E\ntest: %010.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_e) {
  char str1[600];
  char str2[600];
  double num1 = 1234567890000.0938217586;
  char *str3 = "test: % 67.1E\ntest: %-67.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_e) {
  char str1[600];
  char str2[600];
  double num2 = -.12345678900000938217586;
  char *str3 = "test: %#100.0E\ntest: % 100.0E\ntest: %0100.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_e) {
  char str1[1000];
  char str2[1000];
  double num1 = 1234567890000.0938217586;
  double num2 = -.12345678900000938217586;
  char *str3 = "test: %070.10E\ntest: %-67.10E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_e) {
  char str1[1000];
  char str2[1000];
  double num1 = -12345678900000938217586.;
  double num2 = .12345678900000938217586;
  char *str3 = "test: % 70.10E\ntest: % 67.10E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_e) {
  char str1[600];
  char str2[600];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "test: % 10.1E\ntest: %-10.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_e) {
  char str1[600];
  char str2[600];
  double num2 = 53296575676899283.734747273752737878257;
  char *str3 = "test: %-10.0E\ntest: % 10.0E\ntest: %-10.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_e) {
  char str1[600];
  char str2[600];
  double num1 = .000000005329657567689928373474727375273787825732159676631957;
  double num2 = 53296575676899283.73474727375273787825732159676631957;
  char *str3 = "test: % 20E\ntest: %-20E\ntest: %+20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num1),
                   s21_sprintf(str2, str3, num1, num2, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_e) {
  char str1[600];
  char str2[600];
  double num3 = 5329657567689928373474727375.273787825732159676631957;
  double num4 = 53296575676899283734747273752737878257.32159676631957;
  char *str3 = "test: %#20.0E\ntest: %-20E!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%.0e\n%.2e\n%.5E\n%.9E\n%.13E!";
  double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%.Le\n%.2Le\n%.5Le\n%.9Le\n%.13LE!";
  long double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%e %.0e %.5e %.9e %.15E!";
  double num = 0;
  int res1 = sprintf(str1, str3, num, num, num, num, num);
  int res2 = s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %20Le!\ntest: %Le!\ntest: %-10Le!";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623598263628236642932982362398.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %060Le!\ntest: %.14Le!";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623598263628236642932982362398.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *sprintf_test_e_E() {
  Suite *suite = suite_create("---SPRINTF_E---");
  TCase *tcase = tcase_create("sprintf_tc");
  tcase_add_test(tcase, sprintf_test_e_E_1);
  tcase_add_test(tcase, sprintf_test_e_E_2);
  tcase_add_test(tcase, sprintf_test_e_E_3);
  tcase_add_test(tcase, sprintf_test_e_E_4);
  tcase_add_test(tcase, sprintf_test_e_E_5);
  tcase_add_test(tcase, sprintf_test_e_E_6);
  tcase_add_test(tcase, sprintf_test_e_E_7);
  tcase_add_test(tcase, sprintf_test_e_E_8);
  tcase_add_test(tcase, sprintf_test_e_E_9);
  tcase_add_test(tcase, sprintf_test_e_E_10);
  tcase_add_test(tcase, sprintf_test_e_E_11);

  tcase_add_test(tcase, sprintf_1_e);
  tcase_add_test(tcase, sprintf_2_e);
  tcase_add_test(tcase, sprintf_3_e);
  tcase_add_test(tcase, sprintf_4_e);
  tcase_add_test(tcase, sprintf_5_e);
  tcase_add_test(tcase, sprintf_6_e);
  tcase_add_test(tcase, sprintf_7_e);
  tcase_add_test(tcase, sprintf_8_e);
  tcase_add_test(tcase, sprintf_9_e);
  tcase_add_test(tcase, sprintf_10_e);
  tcase_add_test(tcase, sprintf_11_e);
  tcase_add_test(tcase, sprintf_12_e);
  tcase_add_test(tcase, sprintf_13_e);
  tcase_add_test(tcase, sprintf_14_e);
  tcase_add_test(tcase, sprintf_15_e);
  tcase_add_test(tcase, sprintf_16_e);
  tcase_add_test(tcase, sprintf_17_e);
  tcase_add_test(tcase, sprintf_18_e);
  tcase_add_test(tcase, sprintf_19_e);
  tcase_add_test(tcase, sprintf_20_e);
  tcase_add_test(tcase, sprintf_21_e);
  tcase_add_test(tcase, sprintf_22_e);
  tcase_add_test(tcase, sprintf_23_e);
  tcase_add_test(tcase, sprintf_24_e);
  tcase_add_test(tcase, sprintf_25_e);
  tcase_add_test(tcase, sprintf_26_e);
  tcase_add_test(tcase, sprintf_27_e);
  tcase_add_test(tcase, sprintf_28_e);
  tcase_add_test(tcase, sprintf_29_e);
  tcase_add_test(tcase, sprintf_30_e);
  tcase_add_test(tcase, sprintf_31_e);
  tcase_add_test(tcase, sprintf_32_e);
  tcase_add_test(tcase, sprintf_33_e);
  tcase_add_test(tcase, sprintf_34_e);
  tcase_add_test(tcase, sprintf_35_e);
  tcase_add_test(tcase, sprintf_36_e);
  tcase_add_test(tcase, sprintf_37_e);
  tcase_add_test(tcase, sprintf_38_e);
  tcase_add_test(tcase, sprintf_39_e);
  tcase_add_test(tcase, sprintf_40_e);
  tcase_add_test(tcase, sprintf_41_e);
  tcase_add_test(tcase, sprintf_42_e);
  tcase_add_test(tcase, sprintf_43_e);
  tcase_add_test(tcase, sprintf_44_e);

  suite_add_tcase(suite, tcase);
  return suite;
}
