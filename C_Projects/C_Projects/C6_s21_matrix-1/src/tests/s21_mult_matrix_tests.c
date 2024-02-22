#include "s21_tests.h"

START_TEST(mult_matrix_INCORRECT_COLUMS) {
  // Arrange
  int rows_1 = 5;
  int cols_1 = 0;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows_1, cols_1, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  int rows_2 = 5;
  int cols_2 = 5;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows_2, cols_2, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);

  matrix_t test_matrix_ptr_3 = {0};
  // Act
  int error = s21_mult_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
                              &test_matrix_ptr_3);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&test_matrix_ptr_3);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_ROWS) {
  // Arrange
  int rows_1 = 5;
  int cols_1 = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows_1, cols_1, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  int rows_2 = 0;
  int cols_2 = 5;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows_2, cols_2, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);

  matrix_t test_matrix_ptr_3 = {0};
  // Act
  int error = s21_mult_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
                              &test_matrix_ptr_3);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&test_matrix_ptr_3);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_STRUCT_1) {
  // Arrange
  matrix_t *test_matrix_ptr_1 = NULL;
  int rows_2 = 5;
  int cols_2 = 5;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows_2, cols_2, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);
  matrix_t test_matrix_ptr_3 = {0};
  // Act
  int error = s21_mult_matrix(test_matrix_ptr_1, &test_matrix_ptr_2,
                              &test_matrix_ptr_3);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&test_matrix_ptr_3);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_STRUCT_2) {
  // Arrange
  int rows_1 = 5;
  int cols_1 = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows_1, cols_1, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  matrix_t *test_matrix_ptr_2 = NULL;

  matrix_t test_matrix_ptr_3 = {0};
  // Act
  int error = s21_mult_matrix(&test_matrix_ptr_1, test_matrix_ptr_2,
                              &test_matrix_ptr_3);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_3);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_STRUCT_3) {
  // Arrange
  int rows_1 = 5;
  int cols_1 = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows_1, cols_1, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  int rows_2 = 4;
  int cols_2 = 5;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows_2, cols_2, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  matrix_t test_matrix_ptr_3 = {0};
  // Act
  int error = s21_mult_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
                              &test_matrix_ptr_3);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&test_matrix_ptr_3);
}
END_TEST

START_TEST(mult_matrix_OK_1) {
  // Arrange
  int rows_1 = 2;
  int cols_1 = 3;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows_1, cols_1, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  int rows_2 = 3;
  int cols_2 = 2;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows_2, cols_2, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_NEG_SEQUENCE);

  matrix_t test_matrix_ptr_3 = {0};

  matrix_t result_matrix_ptr = {0};
  s21_create_matrix(2, 2, &result_matrix_ptr);
  double buffer[2][2] = {{-22, -28}, {-49, -64}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      result_matrix_ptr.matrix[i][j] = buffer[i][j];
    }
  }
  // Act
  int error = s21_mult_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
                              &test_matrix_ptr_3);
  int equal = s21_eq_matrix(&result_matrix_ptr, &test_matrix_ptr_3);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&test_matrix_ptr_3);
  s21_remove_matrix(&result_matrix_ptr);
}
END_TEST

START_TEST(mult_matrix_OK_2) {
  // Arrange
  int rows_1 = 3;
  int cols_1 = 2;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows_1, cols_1, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  int rows_2 = 2;
  int cols_2 = 3;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows_2, cols_2, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_NEG_SEQUENCE);

  matrix_t test_matrix_ptr_3 = {0};

  matrix_t result_matrix_ptr = {0};
  s21_create_matrix(3, 3, &result_matrix_ptr);
  double buffer[3][3] = {{-9, -12, -15}, {-19, -26, -33}, {-29, -40, -51}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result_matrix_ptr.matrix[i][j] = buffer[i][j];
    }
  }
  // Act
  int error = s21_mult_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
                              &test_matrix_ptr_3);
  int equal = s21_eq_matrix(&result_matrix_ptr, &test_matrix_ptr_3);
  // s21_display_matrix(&test_matrix_ptr_1);
  // printf("\n");
  // s21_display_matrix(&test_matrix_ptr_2);
  // printf("\n%d\n", error);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&test_matrix_ptr_1);
  s21_remove_matrix(&test_matrix_ptr_2);
  s21_remove_matrix(&test_matrix_ptr_3);
  s21_remove_matrix(&result_matrix_ptr);
}
END_TEST

Suite *mult_matrix(void) {
  Suite *s = suite_create("mult_matrix function suite");

  TCase *mult_matrix = tcase_create("mult_matrix function tests");
  tcase_add_test(mult_matrix, mult_matrix_INCORRECT_COLUMS);
  tcase_add_test(mult_matrix, mult_matrix_INCORRECT_ROWS);
  tcase_add_test(mult_matrix, mult_matrix_INCORRECT_STRUCT_1);
  tcase_add_test(mult_matrix, mult_matrix_INCORRECT_STRUCT_2);
  tcase_add_test(mult_matrix, mult_matrix_INCORRECT_STRUCT_3);
  tcase_add_test(mult_matrix, mult_matrix_OK_1);
  tcase_add_test(mult_matrix, mult_matrix_OK_2);

  suite_add_tcase(s, mult_matrix);

  return s;
}