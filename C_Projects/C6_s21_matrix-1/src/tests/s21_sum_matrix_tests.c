#include "s21_tests.h"

START_TEST(sum_matrix_INCORRECT_COLUMS_1) {
  // Arrange
  int rows_1 = 5;
  int cols_1 = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows_1, cols_1, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  int rows_2 = 5;
  int cols_2 = 4;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows_2, cols_2, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);
  matrix_t test_matrix_ptr_3 = {0};
  // Act
  int error = s21_sum_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
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

START_TEST(sum_matrix_INCORRECT_COLUMS_2) {
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
  int error = s21_sum_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
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

START_TEST(sum_matrix_INCORRECT_ROWS_1) {
  // Arrange
  int rows_1 = 9;
  int cols_1 = 5;
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
  int error = s21_sum_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
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

START_TEST(sum_matrix_INCORRECT_ROWS_2) {
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
  int error = s21_sum_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
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

START_TEST(sum_matrix_INCORRECT_STRUCT_1) {
  // Arrange
  matrix_t *test_matrix_ptr_1 = NULL;
  int rows_2 = 5;
  int cols_2 = 5;
  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows_2, cols_2, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);
  matrix_t test_matrix_ptr_3 = {0};
  // Act
  int error =
      s21_sum_matrix(test_matrix_ptr_1, &test_matrix_ptr_2, &test_matrix_ptr_3);
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

START_TEST(sum_matrix_INCORRECT_STRUCT_2) {
  // Arrange
  int rows_1 = 5;
  int cols_1 = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows_1, cols_1, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);
  matrix_t *test_matrix_ptr_2 = NULL;
  matrix_t test_matrix_ptr_3 = {0};
  // Act
  int error =
      s21_sum_matrix(&test_matrix_ptr_1, test_matrix_ptr_2, &test_matrix_ptr_3);
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

START_TEST(sum_matrix_OK_1) {
  // Arrange
  int rows = 5;
  int cols = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);

  matrix_t test_matrix_ptr_3 = {0};

  matrix_t result_matrix_ptr = {0};
  s21_create_matrix(rows, cols, &result_matrix_ptr);
  s21_fill_matrix(&result_matrix_ptr, MODE_FOR_RESULT_POS);

  // Act
  int error = s21_sum_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
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

START_TEST(sum_matrix_OK_2) {
  // Arrange
  int rows = 5;
  int cols = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);

  matrix_t test_matrix_ptr_3 = {0};

  matrix_t result_matrix_ptr = {0};
  s21_create_matrix(rows, cols, &result_matrix_ptr);
  s21_fill_matrix(&result_matrix_ptr, MODE_FOR_RESULT_POS);

  // Act
  int error = s21_sum_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
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

START_TEST(sum_matrix_OK_3) {
  // Arrange
  int rows = 5;
  int cols = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_POS_SEQUENCE);

  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_POS_REVERS_SEQUENCE);

  matrix_t test_matrix_ptr_3 = {0};

  matrix_t result_matrix_ptr = {0};
  s21_create_matrix(rows, cols, &result_matrix_ptr);
  s21_fill_matrix(&result_matrix_ptr, MODE_FOR_RESULT_POS);

  // Act
  int error = s21_sum_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
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

START_TEST(sum_matrix_OK_4) {
  // Arrange
  int rows = 5;
  int cols = 5;
  matrix_t test_matrix_ptr_1 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_1);
  s21_fill_matrix(&test_matrix_ptr_1, MODE_NEG_SEQUENCE);

  matrix_t test_matrix_ptr_2 = {0};
  s21_create_matrix(rows, cols, &test_matrix_ptr_2);
  s21_fill_matrix(&test_matrix_ptr_2, MODE_NEG_REVERS_SEQUENCE);

  matrix_t test_matrix_ptr_3 = {0};

  matrix_t result_matrix_ptr = {0};
  s21_create_matrix(rows, cols, &result_matrix_ptr);
  s21_fill_matrix(&result_matrix_ptr, MODE_FOR_RESULT_NEG);

  // Act
  int error = s21_sum_matrix(&test_matrix_ptr_1, &test_matrix_ptr_2,
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

Suite *sum_matrix(void) {
  Suite *s = suite_create("sum_matrix function suite");

  TCase *sum_matrix = tcase_create("sum_matrix function tests");
  tcase_add_test(sum_matrix, sum_matrix_INCORRECT_COLUMS_1);
  tcase_add_test(sum_matrix, sum_matrix_INCORRECT_COLUMS_2);
  tcase_add_test(sum_matrix, sum_matrix_INCORRECT_ROWS_1);
  tcase_add_test(sum_matrix, sum_matrix_INCORRECT_ROWS_2);
  tcase_add_test(sum_matrix, sum_matrix_INCORRECT_STRUCT_1);
  tcase_add_test(sum_matrix, sum_matrix_INCORRECT_STRUCT_2);
  tcase_add_test(sum_matrix, sum_matrix_OK_1);
  tcase_add_test(sum_matrix, sum_matrix_OK_2);
  tcase_add_test(sum_matrix, sum_matrix_OK_3);
  tcase_add_test(sum_matrix, sum_matrix_OK_4);

  suite_add_tcase(s, sum_matrix);

  return s;
}