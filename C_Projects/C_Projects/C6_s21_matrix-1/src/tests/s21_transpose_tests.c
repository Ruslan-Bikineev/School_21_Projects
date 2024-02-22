#include "s21_tests.h"

START_TEST(transpose_INCORRECT_COLUMS) {
  // Arrange
  int rows = 5;
  int cols = 0;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  matrix_t test_matrix_ptr_2 = {0};
  // Act
  int error = s21_transpose(&test_matrix_ptr_1, &test_matrix_ptr_2);
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

START_TEST(transpose_INCORRECT_ROWS) {
  // Arrange
  int rows = 0;
  int cols = 4;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  matrix_t test_matrix_ptr_2 = {0};
  // Act
  int error = s21_transpose(&test_matrix_ptr_1, &test_matrix_ptr_2);
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

START_TEST(transpose_INCORRECT_STRUCT_1) {
  // Arrange
  matrix_t *test_matrix_ptr_1 = NULL;
  matrix_t test_matrix_ptr_2 = {0};
  // Act
  int error = s21_transpose(test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(transpose_OK_1) {
  // Arrange
  int rows = 3;
  int cols = 2;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  matrix_t test_matrix_ptr_2 = {0};

  matrix_t result_matrix_ptr = {0};
  s21_create_matrix(2, 3, &result_matrix_ptr);
  double buffer[2][3] = {{1, 3, 5}, {2, 4, 6}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      result_matrix_ptr.matrix[i][j] = buffer[i][j];
    }
  }
  // Act
  int error = s21_transpose(&test_matrix_ptr_1, &test_matrix_ptr_2);
  int equal = s21_eq_matrix(&result_matrix_ptr, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&result_matrix_ptr);
}
END_TEST

Suite *transpose(void) {
  Suite *s = suite_create("transpose function suite");

  TCase *transpose = tcase_create("transpose function tests");
  tcase_add_test(transpose, transpose_INCORRECT_COLUMS);
  tcase_add_test(transpose, transpose_INCORRECT_ROWS);
  tcase_add_test(transpose, transpose_INCORRECT_STRUCT_1);
  tcase_add_test(transpose, transpose_OK_1);

  suite_add_tcase(s, transpose);

  return s;
}