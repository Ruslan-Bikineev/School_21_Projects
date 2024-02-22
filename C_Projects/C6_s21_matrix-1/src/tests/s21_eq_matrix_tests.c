#include "s21_tests.h"

START_TEST(eq_matrix_INCORRECT_COLUMS) {
  // Arrange
  int rows_1 = 5;
  int cols_1 = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows_1, cols_1, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_REVERS_SEQUENCE);
  int rows_2 = 5;
  int cols_2 = 4;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows_2, cols_2, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);
  // Act
  int error = s21_eq_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, FAILURE);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(eq_matrix_INCORRECT_STRUCT_1) {
  // Arrange
  int rows = 5;
  int cols = 5;
  matrix_t *test_matrix_ptr_1 = NULL;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, test_matrix_ptr_1);
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);
  // Act
  int error = s21_eq_matrix(test_matrix_ptr_1, &test_matrix_ptr_2);
  // Assert
  ck_assert_int_eq(error, FAILURE);
  s21_remove_matrix(test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(eq_matrix_INCORRECT_STRUCT_2) {
  // Arrange
  int rows = 4;
  int cols = 4;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t *test_matrix_ptr_2 = NULL;
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_create_matrix(rows, cols, test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_REVERS_SEQUENCE);
  // Act
  int error = s21_eq_matrix(&test_matrix_ptr_1, test_matrix_ptr_2);
  // Assert
  ck_assert_int_eq(error, FAILURE);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(test_matrix_ptr_2);
}
END_TEST

START_TEST(eq_matrix_INCORRECT_ROWS) {
  // Arrange
  int rows = 0;
  int cols = 5;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_REVERS_SEQUENCE);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);
  // Act
  int error = s21_eq_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // Assert
  ck_assert_int_eq(error, FAILURE);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(eq_matrix_INCORRECT_NOT_EQUAL) {
  // Arrange
  int rows = 5;
  int cols = 5;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_REVERS_SEQUENCE);
  test_matrix_ptr_1.matrix[1][1] = 19.123457;
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);
  // Act
  int error = s21_eq_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // Assert
  ck_assert_int_eq(error, FAILURE);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(eq_matrix_OK_1) {
  // Arrange
  int rows = 5;
  int cols = 5;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_REVERS_SEQUENCE);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);
  // Act
  int error = s21_eq_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // Assert
  ck_assert_int_eq(error, SUCCESS);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

START_TEST(eq_matrix_OK_2) {
  // Arrange
  int rows = 5;
  int cols = 5;
  matrix_t test_matrix_ptr_1 = {0};
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_REVERS_SEQUENCE);
  test_matrix_ptr_1.matrix[1][1] = 19.12345671;
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);
  // Act
  int error = s21_eq_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2);
  // Assert
  ck_assert_int_eq(error, SUCCESS);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
}
END_TEST

Suite *eq_matrix(void) {
  Suite *s = suite_create("eq_matrix function suite");

  TCase *eq_matrix = tcase_create("eq_matrix function tests");
  tcase_add_test(eq_matrix, eq_matrix_INCORRECT_COLUMS);
  tcase_add_test(eq_matrix, eq_matrix_INCORRECT_STRUCT_1);
  tcase_add_test(eq_matrix, eq_matrix_INCORRECT_STRUCT_2);
  tcase_add_test(eq_matrix, eq_matrix_INCORRECT_ROWS);
  tcase_add_test(eq_matrix, eq_matrix_INCORRECT_NOT_EQUAL);
  tcase_add_test(eq_matrix, eq_matrix_OK_1);
  tcase_add_test(eq_matrix, eq_matrix_OK_2);

  suite_add_tcase(s, eq_matrix);

  return s;
}