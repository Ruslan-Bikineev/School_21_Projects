#include "s21_tests.h"

START_TEST(mult_number_INCORRECT_COLUMS) {
  // Arrange
  int rows = 5;
  int cols = 0;
  double mult = 10;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  matrix_t result_matrix_ptr = {0};
  // Act
  int error = s21_mult_number(&test_matrix_ptr_1, mult, &result_matrix_ptr);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&result_matrix_ptr);
}
END_TEST

START_TEST(mult_number_INCORRECT_ROW) {
  // Arrange
  int rows = 0;
  int cols = 5;
  double mult = 10;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  matrix_t result_matrix_ptr = {0};
  // Act
  int error = s21_mult_number(&test_matrix_ptr_1, mult, &result_matrix_ptr);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&result_matrix_ptr);
}
END_TEST

START_TEST(mult_number_INCORRECT_STRUCT) {
  // Arrange
  double mult = 10;
  matrix_t *test_matrix_ptr_1 = NULL;
  matrix_t result_matrix_ptr = {0};
  // Act
  int error = s21_mult_number(test_matrix_ptr_1, mult, &result_matrix_ptr);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&result_matrix_ptr);
}
END_TEST

START_TEST(mult_number_OK_1) {
  // Arrange
  int rows = 5;
  int cols = 5;
  double mult = 0;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);

  matrix_t result_matrix_ptr = {0};
  // Act
  int error = s21_mult_number(&test_matrix_ptr_1, mult, &result_matrix_ptr);
  int equal = s21_eq_matrix(&result_matrix_ptr, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n");
  // s21_display_matrix(&result_matrix_ptr);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&result_matrix_ptr);
}
END_TEST

START_TEST(mult_number_OK_2) {
  // Arrange
  int rows = 5;
  int cols = 5;
  double mult = -1;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_FOR_RESULT_POS);

  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_FOR_RESULT_NEG);

  matrix_t result_matrix_ptr = {0};
  // Act
  int error = s21_mult_number(&test_matrix_ptr_1, mult, &result_matrix_ptr);
  int equal = s21_eq_matrix(&result_matrix_ptr, &test_matrix_ptr_2);
  // printf("test_matrix_ptr_1\n");
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("test_matrix_ptr_2\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("result_matrix_ptr\n");
  // s21_display_matrix(&result_matrix_ptr);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&result_matrix_ptr);
}
END_TEST

Suite *mult_number(void) {
  Suite *s = suite_create("mult_number function suite");

  TCase *mult_number = tcase_create("mult_number function tests");
  tcase_add_test(mult_number, mult_number_INCORRECT_COLUMS);
  tcase_add_test(mult_number, mult_number_INCORRECT_ROW);
  tcase_add_test(mult_number, mult_number_INCORRECT_STRUCT);
  tcase_add_test(mult_number, mult_number_OK_1);
  tcase_add_test(mult_number, mult_number_OK_2);

  suite_add_tcase(s, mult_number);

  return s;
}