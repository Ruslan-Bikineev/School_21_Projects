#include "s21_tests.h"

START_TEST(inverse_matrix_INCORRECT_COLUMS) {
  // Arrange
  int rows = 3;
  int cols = 0;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_inverse_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(inverse_matrix_INCORRECT_ROWS) {
  // Arrange
  int rows = 0;
  int cols = 3;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);

  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_inverse_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(inverse_matrix_INCORRECT_STRUCT) {
  // Arrange
  matrix_t *test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};

  // Act
  int error = s21_inverse_matrix(test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(inverse_matrix_INCORRECT_SIZE) {
  // Arrange
  int rows = 2;
  int cols = 3;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);

  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_inverse_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(inverse_matrix_DETERMINANT_NULL) {
  // Arrange
  int rows = 3;
  int cols = 3;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  // Act
  int error = s21_inverse_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(inverse_matrix_OK_1) {
  // Arrange
  int rows = 1;
  int cols = 1;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);

  s21_create_matrix(rows, cols, &result);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  s21_fill_matrix(&result, MODE_POS_SEQUENCE);
  // Act
  int error = s21_inverse_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  s21_eq_matrix(&test_matrix_ptr_2, &result);
  ck_assert_int_eq(error, OK);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_OK_2) {
  // Arrange
  int rows = 2;
  int cols = 2;
  double buffer[2][2] = {{-2, 1}, {1.5, -0.5}};
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);

  s21_create_matrix(rows, cols, &result);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result.matrix[i][j] = buffer[i][j];
    }
  }
  // Act
  int error = s21_inverse_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  s21_eq_matrix(&test_matrix_ptr_2, &result);
  ck_assert_int_eq(error, OK);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_OK_3) {
  // Arrange
  int rows = 3;
  int cols = 3;
  double buffer_det[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double buffer_res[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);

  s21_create_matrix(rows, cols, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      test_matrix_ptr_1.matrix[i][j] = buffer_det[i][j];
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result.matrix[i][j] = buffer_res[i][j];
    }
  }
  // Act
  int error = s21_inverse_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  s21_eq_matrix(&test_matrix_ptr_2, &result);
  ck_assert_int_eq(error, OK);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&result);
}
END_TEST

Suite *inverse_matrix(void) {
  Suite *s = suite_create("inverse_matrix function suite");

  TCase *inverse_matrix = tcase_create("inverse_matrix function tests");
  tcase_add_test(inverse_matrix, inverse_matrix_INCORRECT_COLUMS);
  tcase_add_test(inverse_matrix, inverse_matrix_INCORRECT_ROWS);
  tcase_add_test(inverse_matrix, inverse_matrix_INCORRECT_STRUCT);
  tcase_add_test(inverse_matrix, inverse_matrix_INCORRECT_SIZE);
  tcase_add_test(inverse_matrix, inverse_matrix_DETERMINANT_NULL);
  tcase_add_test(inverse_matrix, inverse_matrix_OK_1);
  tcase_add_test(inverse_matrix, inverse_matrix_OK_2);
  tcase_add_test(inverse_matrix, inverse_matrix_OK_3);

  suite_add_tcase(s, inverse_matrix);

  return s;
}