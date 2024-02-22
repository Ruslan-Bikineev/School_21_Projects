#include "../s21_tests.h"

START_TEST(int_to_dec_1) {
  s21_decimal number;
  int num = 1455448;
  s21_decimal res = {{num, 0, 0, 0}};
  int out = s21_from_int_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(int_to_dec_2) {
  s21_decimal number;
  int num = INT_MIN;
  s21_decimal res = {{0x80000000, 0, 0, 0x80000000}};
  int out = s21_from_int_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(int_to_dec_3) {
  s21_decimal number;
  int num = INT_MAX;
  s21_decimal res = {{num, 0, 0, 0}};
  int out = s21_from_int_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(int_to_dec_4) {
  s21_decimal number;
  int num = 0;
  s21_decimal res = {{num, 0, 0, 0}};

  int out = s21_from_int_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(int_to_dec_5) {
  s21_decimal number;
  int num = 10;
  s21_decimal res = {{num, 0, 0, 0}};

  int out = s21_from_int_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST
START_TEST(int_to_dec_6) {
  s21_decimal number;
  int num = -10;
  s21_decimal res = {{10, 0, 0, 0x80000000}};
  int out = s21_from_int_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST
START_TEST(int_to_dec_7) {
  s21_decimal number;
  int num = 123456;
  s21_decimal res = {{num, 0, 0, 0}};
  int out = s21_from_int_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(int_to_dec_8) {
  s21_decimal number;
  int num = -123456;
  s21_decimal res = {{123456, 0, 0, 0x80000000}};
  int out = s21_from_int_to_decimal(num, &number);
  ck_assert_int_eq(out, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(number.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(int_to_dec_9) {
  int num = -123456;
  int out = s21_from_int_to_decimal(num, NULL);
  ck_assert_int_eq(out, 1);
}
END_TEST

Suite *int_to_dec_tests() {
  Suite *suite = suite_create("---INT_TO_DEC---");
  TCase *tcase = tcase_create("decimal_tc");

  tcase_add_test(tcase, int_to_dec_1);
  tcase_add_test(tcase, int_to_dec_2);
  tcase_add_test(tcase, int_to_dec_3);
  tcase_add_test(tcase, int_to_dec_4);
  tcase_add_test(tcase, int_to_dec_5);
  tcase_add_test(tcase, int_to_dec_6);
  tcase_add_test(tcase, int_to_dec_7);
  tcase_add_test(tcase, int_to_dec_8);
  tcase_add_test(tcase, int_to_dec_9);

  suite_add_tcase(suite, tcase);
  return suite;
}
