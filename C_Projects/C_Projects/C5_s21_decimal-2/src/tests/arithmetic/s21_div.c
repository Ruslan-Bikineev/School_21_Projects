#include "../s21_tests.h"

START_TEST(div_test_1) {
  s21_decimal number1 = {{19, 0, 0, 0}};
  s21_decimal number2 = {{2, 0, 0, 0}};
  s21_decimal result = {};
  int add_res = s21_div(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 95);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 65536);
}
END_TEST

START_TEST(div_test_2) {
  s21_decimal number1 = {{180, 0, 0, 0}};
  s21_decimal number2 = {{3, 0, 0, 0}};
  s21_decimal result = {};
  int add_res = s21_div(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 60);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], number1.bits[3]);
}
END_TEST

START_TEST(div_test_3) {
  s21_decimal number1 = {{12000, 0, 0, 0}};
  s21_decimal number2 = {{2000, 0, 0, 0}};
  s21_decimal result = {};
  int add_res = s21_div(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 6);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], number1.bits[3]);
}
END_TEST

START_TEST(div_test_4) {
  s21_decimal number1 = {{123456, 0, 0, 0}};
  s21_decimal number2 = {{123456, 0, 0, 0}};
  s21_decimal result = {};
  int add_res = s21_div(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], number1.bits[3]);
}
END_TEST

START_TEST(div_test_5) {
  s21_decimal number1 = {{123456, 0, 0, 0}};
  s21_decimal number2 = {{0, 0, 0, 0}};
  s21_decimal result = {};
  int add_res = s21_div(number1, number2, &result);
  ck_assert_int_eq(add_res, 3);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
}
END_TEST

START_TEST(div_test_6) {
  s21_decimal number1 = {{19, 0, 0, 2147483648}};
  s21_decimal number2 = {{3, 0, 0, 0}};
  s21_decimal result = {};
  int add_res = s21_div(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 1700091221);
  ck_assert_int_eq(result.bits[1], 2308247313);
  ck_assert_int_eq(result.bits[2], 3433306879);
  ck_assert_int_eq(result.bits[3], 2149318656);
}
END_TEST

START_TEST(div_test_7) {
  s21_decimal number1 = {{12356, 0, 0, 0}};
  s21_decimal number2 = {{5, 0, 0, 2147483648}};
  s21_decimal result = {};
  int add_res = s21_div(number1, number2, &result);
  ck_assert_int_eq(add_res, 0);
  ck_assert_int_eq(result.bits[0], 24712);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147549184);
}
END_TEST

static s21_decimal num1[] = {
    {{0x0000000A, 0x00000000, 0x00000000, 0x00000000}},  // 0 10
    {{0x0000000A, 0x00000000, 0x00000000, 0x00000000}},  // 1 10
    {{0x000000B6, 0x00000000, 0x00000000, 0x00000000}},  // 2 182
    {{0x0001F0F1, 0x00000000, 0x00000000, 0x00000000}},  // 3 127217
    {{0x000000D4, 0x00000000, 0x00000000, 0x80000000}},  // 4 -212
    {{0x014CF9BF, 0x00000000, 0x00000000, 0x80020000}},  // 5 -218218.87
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 6 0
    {{0x0001DC88, 0x00000000, 0x00000000, 0x00020000}},  // 7 1219.92
    {{0x001D537F, 0x00000000, 0x00000000, 0x80020000}},  // 8 -19219.19
    {{0x7D17C946, 0x00000BA8, 0x00000000, 0x00040000}},  // 9 1281828112.2118
    {{0x7D17C946, 0x00000BA8, 0x00000000, 0x00040000}},  // 10 1281828112.2118
    {{0x00000369, 0x00000000, 0x00000000, 0x00000000}},  // 11 873
    {{0x0001DD09, 0x00000000, 0x00000000,
      0x00110000}},  // 12 0.00000000000122121
    {{0x00140263, 0x00000000, 0x00000000,
      0x00120000}},  // 13 0.000000000001311331
    {{0x0098967F, 0x00000000, 0x00000000, 0x00070000}},  // 14 0.9999999
    {{0x0098967F, 0x00000000, 0x00000000, 0x00070000}},  // 15 0.9999999
    {{0x0098967F, 0x00000000, 0x00000000, 0x80070000}},  // 16 -0.9999999
    {{0xE17A7F9D, 0x0DAED47B, 0x00000000,
      0x000C0000}},  // 17 985958.996969684893
    {{0x000186A0, 0x00000000, 0x00000000, 0x00030000}},  // 18 100.000
    {{0x007FEBFE, 0x00000000, 0x00000000, 0x00020000}},  // 19 83834.86
    {{0x15C0748C, 0x00000000, 0x00000000, 0x00000000}},  // 20 364934284
    {{0x15C0748C, 0x00000000, 0x00000000, 0x80000000}},  // 21 -364934284
};

static s21_decimal num2[] = {
    {{0x00000005, 0x00000000, 0x00000000, 0x00000000}},  // 0 5
    {{0x00004E2A, 0x00000000, 0x00000000, 0x00000000}},  // 1 20010
    {{0x00000065, 0x00000000, 0x00000000, 0x00000000}},  // 2 101
    {{0x04FDBA54, 0x00000000, 0x00000000, 0x00000000}},  // 3 83737172
    {{0x00000011, 0x00000000, 0x00000000, 0x80000000}},  // 4 -17
    {{0x9336DD9D, 0x00000032, 0x00000000, 0x80020000}},  // 5 -2172182112.29
    {{0x0000000A, 0x00000000, 0x00000000, 0x00000000}},  // 6 10
    {{0x0116F341, 0x00000000, 0x00000000, 0x80030000}},  // 7 -18281.281
    {{0x00007208, 0x00000000, 0x00000000, 0x00000000}},  // 8 29192
    {{0xCED1C28B, 0x00000032, 0x00000000, 0x00030000}},  // 9 218218218.123
    {{0x7EE8E7D9, 0x00000000, 0x00000000, 0x00050000}},  // 10 21291.92921
    {{0x000D9987, 0x00000000, 0x00000000, 0x00000000}},  // 11 891271
    {{0x000E1209, 0x00000000, 0x00000000,
      0x001B0000}},  // 12 0.000000000000000000000922121
    {{0xEFB25CB0, 0x00000008, 0x00000000, 0x00060000}},  // 13 38381.182128
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 14 1
    {{0x3B9AC60D, 0x00000000, 0x00000000, 0x80090000}},  // 15 -0.999998989
    {{0xD4B49FE1, 0x000000E8, 0x00000000, 0x000C0000}},  // 16 1.000001019873
    {{0x00004706, 0x00000000, 0x00000000, 0x00030000}},  // 17 18.182
    {{0x00000005, 0x00000000, 0x00000000, 0x00000000}},  // 18 5
    {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},  // 19 2
    {{0x0000D8B6, 0x00000000, 0x00000000, 0x00000000}},  // 20 55478
    {{0x000019B2, 0x00000000, 0x00000000, 0x80000000}},  // 21 -6578
};

static s21_decimal result[] = {
    {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},  // 0: 2
    {{0x9BD58675, 0x15E87A6F, 0x00042243,
      0x001C0000}},  // 1: 0.0004997501249375312343828086
    {{2482363523, 3154500539, 976855422,
      1835008}},  // 2: 1.801980198019801980198019802
    {{0x32BBC140, 0x8D8AFA58, 0x000C911E,
      0x001C0000}},  // 3: 0.0015192416576953422788149569
    {{0x89696969, 0xD80A02F7, 0x284B6DC6,
      0x001B0000}},  // 4: 12.470588235294117647058823529
    {{0xADCFD4F0, 0xD696F916, 0x0000D4BB,
      0x001C0000}},  // 5: 0.0001004606698330394895308016
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 6: 0
    {{0x9C29AC02, 0x8B157841, 0x0227FB71,
      0x801C0000}},  // 7: -0.0667305535098990054362164227
    {{0xEF1E9F89, 0xA0889681, 0x1545EC8B,
      0x801C0000}},  // 8: -0.6583718141956700465881063305
    {{0xD2206F18, 0x481D7320, 0xBDCD2196,
      0x001C0000}},  // 9: 5.8740655259557198854380089113
    {{0xF563AF1D, 0x924473AA, 0xC2865EA6,
      0x00180000}},  // 10: 60202.534940317885830506196766
    {{0x39A7B007, 0x0C3825D8, 0x00081A2C,
      0x001C0000}},  // 11: 0.0009795000622706225154863111
    {{0x74CC4BF6, 0x387BB251, 0x2ACAC209,
      0x00130000}},  // 12: 1324348973.7247064105469889526
    {{0x8C840218, 0x0000004F, 0x00000000,
      0x001C0000}},  // 13: 0.0000000000000000341659877913
    {{0x0098967F, 0x00000000, 0x00000000, 0x00070000}},  // 14: 0.9999999
    {{0x1AF606CB, 0x18EB582D, 0x204FD04C,
      0x801C0000}},  // 15: -1.0000009110009210219311531724
    {{0xF97B0D96, 0x28B45460, 0x204FCBFF,
      0x801C0000}},  // 16: -0.9999988801281421270713044374
    {{0xA658CE14, 0x3D31233A, 0xAF37B0CD,
      0x00180000}},  // 17: 54227.202561307056044439555604
    {{0x00000014, 0x00000000, 0x00000000, 0x00000000}},  // 18: 20.000
    {{0x003FF5FF, 0x00000000, 0x00000000, 0x00020000}},  // 19: 41917.43
    {{0x000019B2, 0x00000000, 0x00000000, 0x00000000}},  // 20: 6578
    {{0x0000D8B6, 0x00000000, 0x00000000, 0x00000000}},  // 21: 55478
};

static s21_decimal err_num1[] = {
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 0 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 1 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // 2 -79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // 3 -79228162514264337593543950335
    {{0x204479BE, 0x0000006F, 0x00000000, 0x00040000}},  // 4 47728272.8382
    {{0xFA01F028, 0x00000001, 0x00000000, 0x80020000}},  // 5 -84893983.12
    {{0x00000000, 0x00000000, 0x00000000, 0x00040000}},  // 6 0.0000
};

static s21_decimal err_num2[] = {
    {{0x00000312, 0x00000000, 0x00000000, 0x00090000}},  // 0 0.000000786
    {{0x00000002, 0x00000000, 0x00000000, 0x80020000}},  // 1 -0.02
    {{0x000026A1, 0x00000000, 0x00000000, 0x00060000}},  // 2 0.009889
    {{0x000002FD, 0x00000000, 0x00000000, 0x80050000}},  // 3 -0.00765
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 4 0
    {{0x00000000, 0x00000000, 0x00000000, 0x80080000}},  // 5 0.00000000
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 6 0
};

static int err_result[] = {
    1, 2, 2, 1, 3, 3, 3,
};

START_TEST(div_test_8) {
  for (size_t i = 0; i < sizeof(num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;
    int ret = s21_div(num1[i], num2[i], &tmp);
    ck_assert_int_eq(tmp.bits[0], result[i].bits[0]);
    ck_assert_int_eq(tmp.bits[1], result[i].bits[1]);
    ck_assert_int_eq(tmp.bits[2], result[i].bits[2]);
    ck_assert_int_eq(tmp.bits[3], result[i].bits[3]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

START_TEST(div_test_9) {
  for (size_t i = 0; i < sizeof(err_num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;
    int ret = s21_div(err_num1[i], err_num2[i], &tmp);
    if (tmp.bits[0] == 0) {
      tmp.bits[0] = 1;
    }
    ck_assert_int_eq(ret, err_result[i]);
  }
}
END_TEST

Suite *div_tests() {
  Suite *suite = suite_create("---div---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, div_test_1);
  tcase_add_test(tcase, div_test_2);
  tcase_add_test(tcase, div_test_3);
  tcase_add_test(tcase, div_test_4);
  tcase_add_test(tcase, div_test_5);
  tcase_add_test(tcase, div_test_6);
  tcase_add_test(tcase, div_test_7);
  tcase_add_test(tcase, div_test_8);
  tcase_add_test(tcase, div_test_9);

  suite_add_tcase(suite, tcase);
  return suite;
}