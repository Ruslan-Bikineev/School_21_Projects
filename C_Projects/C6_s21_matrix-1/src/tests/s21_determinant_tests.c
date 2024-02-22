#include "s21_tests.h"

START_TEST(determinant_INCORRECT_COLUMS) {
  // Arrange
  int rows = 3;
  int cols = 0;
  double det = 0, result = 0;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_determinant(&test_matrix_ptr_1, &det);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_double_eq(det, result);
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_1);
}
END_TEST

START_TEST(determinant_INCORRECT_ROWS) {
  // Arrange
  int rows = 0;
  int cols = 3;
  double det = 0, result = 0;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_determinant(&test_matrix_ptr_1, &det);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_double_eq(det, result);
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_1);
}
END_TEST

START_TEST(determinant_INCORRECT_STRUCT) {
  // Arrange
  double det = 0, result = 0;
  matrix_t *test_matrix_ptr_1 = NULL;
  // Act
  int error = s21_determinant(test_matrix_ptr_1, &det);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_double_eq(det, result);
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_INCORRECT_SIZE) {
  // Arrange
  int rows = 2;
  int cols = 3;
  double det = 0, result = 0;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_determinant(&test_matrix_ptr_1, &det);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_double_eq(det, result);
  ck_assert_int_eq(error, CALCULATION_ERROR);
  s21_remove_matrix(&test_matrix_ptr_1);
}
END_TEST

START_TEST(determinant_OK_1) {
  // Arrange
  int rows = 1;
  int cols = 1;
  double det = 0, result = 1;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_determinant(&test_matrix_ptr_1, &det);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_double_eq(det, result);
  ck_assert_int_eq(error, OK);
  s21_remove_matrix(&test_matrix_ptr_1);
}
END_TEST

START_TEST(determinant_OK_2) {
  // Arrange
  int rows = 2;
  int cols = 2;
  double det = 0, result = -2;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_determinant(&test_matrix_ptr_1, &det);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_double_eq(det, result);
  ck_assert_int_eq(error, OK);
  s21_remove_matrix(&test_matrix_ptr_1);
}
END_TEST

START_TEST(determinant_OK_3) {
  // Arrange
  int rows = 3;
  int cols = 3;
  double det = 0, result = 0;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_determinant(&test_matrix_ptr_1, &det);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_double_eq(det, result);
  ck_assert_int_eq(error, OK);
  s21_remove_matrix(&test_matrix_ptr_1);
}
END_TEST

START_TEST(determinant_OK_4) {
  // Arrange
  int rows = 3;
  int cols = 3;
  double det = 0, result = -1;
  double buffer[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix_ptr_1.matrix[i][j] = buffer[i][j];
    }
  }
  // Act
  int error = s21_determinant(&test_matrix_ptr_1, &det);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_double_eq(det, result);
  ck_assert_int_eq(error, OK);
  s21_remove_matrix(&test_matrix_ptr_1);
}
END_TEST

Suite *determinant(void) {
  Suite *s = suite_create("determinant function suite");

  TCase *determinant = tcase_create("determinant function tests");
  tcase_add_test(determinant, determinant_INCORRECT_COLUMS);
  tcase_add_test(determinant, determinant_INCORRECT_ROWS);
  tcase_add_test(determinant, determinant_INCORRECT_STRUCT);
  tcase_add_test(determinant, determinant_INCORRECT_SIZE);
  tcase_add_test(determinant, determinant_OK_1);
  tcase_add_test(determinant, determinant_OK_2);
  tcase_add_test(determinant, determinant_OK_3);
  tcase_add_test(determinant, determinant_OK_4);

  suite_add_tcase(s, determinant);

  return s;
}