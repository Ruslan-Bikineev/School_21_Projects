#include "s21_matrix.h"

/* Создание матриц (create_matrix) */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 1 || columns < 1 || result == NULL) {
    return INCORRECT_MATRIX;
  }
  int error = OK;
  long double buffer_size =
      rows * columns * sizeof(double) + rows * sizeof(double *);
  result->matrix = calloc(buffer_size, sizeof(double));
  if (result->matrix == NULL) {
    error = CALCULATION_ERROR;
  } else {
    double *ptr = (double *)(result->matrix + rows);
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = ptr + columns * i;
    }
    result->rows = rows;
    result->columns = columns;
  }
  return error;
}

/* Очистка матриц (remove_matrix) */
int s21_remove_matrix(matrix_t *A) {
  int error = INCORRECT_MATRIX;
  if (s21_validation_matrix(A)) {
    A->rows = 0;
    A->columns = 0;
    free(A->matrix);
    error = OK;
  }
  return error;
}

/* Сравнение матриц (eq_matrix) */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_validation_matrix(A) || !s21_validation_matrix(B) ||
      !s21_check_eq_size_matrix(A, B)) {
    return FAILURE;
  } else {
    int error = SUCCESS;
    int i = A->rows * A->columns;
    while (i--) {
      if (fabs(A->matrix[0][i] - B->matrix[0][i]) > PRECISION) {
        error = FAILURE;
      }
    }
    return error;
  }
}

/* Сложение матриц (sum_matrix) */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sum_or_sub(A, B, result, SUM_MODE);
}

/* Вычитание матриц (sub_matrix) */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sum_or_sub(A, B, result, SUB_MODE);
}

/* Умножение матрицы на число (mult_number) */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  s21_init_matrix(result);
  if (!s21_validation_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    error = CALCULATION_ERROR;
  } else {
    int i = A->rows * A->columns;
    while (i--) {
      result->matrix[0][i] = A->matrix[0][i] * number;
    }
  }
  return error;
}

/* Умножение двух матриц (mult_matrix) */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  s21_init_matrix(result);
  if (!s21_validation_matrix(A) || !s21_validation_matrix(B)) {
    error = INCORRECT_MATRIX;
  } else if ((A->columns != B->rows) ||
             s21_create_matrix(A->rows, B->columns, result)) {
    error = CALCULATION_ERROR;
  } else {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return error;
}

/* Транспонирование матрицы (transpose) */
int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;
  s21_init_matrix(result);
  if (!s21_validation_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (s21_create_matrix(A->columns, A->rows, result)) {
    error = CALCULATION_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return error;
}

/* Определитель матрицы (determinant) */
int s21_determinant(matrix_t *A, double *result) {
  double det = 0;
  int error = OK;
  if (!s21_validation_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  } else {
    if (A->rows == 1) {
      det = A->matrix[0][0];
    } else if (A->rows == 2) {
      det = s21_determinant_2x2(A);
    } else {
      for (int i = 0; i < A->rows && !error; i++) {
        matrix_t B = {0};
        error = s21_create_matrix(A->rows - 1, A->columns - 1, &B);
        for (int j = 1, k = 0; j < A->rows && !error; j++, k = 0) {
          for (int l = 0; l < A->rows && !error; l++) {
            if (l == i) continue;
            B.matrix[j - 1][k] = A->matrix[j][l];
            k++;
          }
        }
        error = s21_determinant(&B, result);
        det += A->matrix[0][i] * (i % 2 == 0 ? 1 : -1) * *result;
        error = s21_remove_matrix(&B);
      }
    }
  }
  *result = det;
  return error;
}

/* Минор матрицы и матрица алгебраических дополнений (calc_complements) */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  double det = 0;
  int error = OK;
  s21_init_matrix(result);
  if (!s21_validation_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != A->columns ||
             s21_create_matrix(A->rows, A->columns, result)) {
    error = CALCULATION_ERROR;
  } else {
    **result->matrix = **A->matrix;
    if (A->rows > 1) {
      for (int i = 0; i < A->rows && !error; i++) {
        for (int j = 0; j < A->columns && !error; j++) {
          matrix_t B = {0};
          error = s21_create_matrix(A->rows - 1, A->columns - 1, &B);
          int r = 0, y = 0;
          for (int row = 0; row < A->rows && !error; row++) {
            for (int col = 0; col < A->columns && !error; col++) {
              if (row != i && col != j) {
                B.matrix[r][y++] = A->matrix[row][col];
                if (y == A->rows - 1) {
                  y = 0;
                  r++;
                }
              }
            }
          }
          error = s21_determinant(&B, &det);
          s21_remove_matrix(&B);
          result->matrix[i][j] = det * pow(-1, i + j);
        }
      }
    }
  }
  return error;
}

/* Обратная матрица (inverse_matrix) */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det = 0;
  int error = OK;
  s21_init_matrix(result);
  if (!s21_validation_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != A->columns || s21_determinant(A, &det) || det == 0) {
    error = CALCULATION_ERROR;
  } else {
    s21_calc_complements(A, result);
    matrix_t temp = {0};
    s21_transpose(result, &temp);
    int i = A->rows * A->columns;
    while (i--) {
      result->matrix[0][i] = 1 / det * temp.matrix[0][i];
    }
    s21_remove_matrix(&temp);
  }
  return error;
}

/*-----------------------------HELP_FUNCTIONS-----------------------------*/
double s21_determinant_2x2(matrix_t *A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

int s21_sum_or_sub(matrix_t *A, matrix_t *B, matrix_t *result, int mode) {
  int error = OK;
  s21_init_matrix(result);
  if (!s21_validation_matrix(A) || !s21_validation_matrix(B)) {
    error = INCORRECT_MATRIX;
  } else if (!s21_check_eq_size_matrix(A, B) ||
             s21_create_matrix(A->rows, A->columns, result)) {
    error = CALCULATION_ERROR;
  } else {
    int i = A->rows * A->columns;
    while (i--) {
      if (mode) {
        result->matrix[0][i] = A->matrix[0][i] - B->matrix[0][i];
      } else {
        result->matrix[0][i] = A->matrix[0][i] + B->matrix[0][i];
      }
    }
  }
  return error;
}

void s21_init_matrix(matrix_t *value) {
  value->matrix = NULL;
  value->rows = 0;
  value->columns = 0;
}

/* check validation matrix, return 1 if OK else 0 */
int s21_validation_matrix(matrix_t *value_1) {
  int error = SUCCESS;
  if (!(value_1) || value_1->matrix == NULL || value_1->rows < 1 ||
      value_1->columns < 1) {
    error = FAILURE;
  }
  return error;
}

/* check eq row and collumns matrix, return 1 if OK else 0 */
int s21_check_eq_size_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    error = FAILURE;
  }
  return error;
}

void s21_fill_matrix(matrix_t *A, int mode) {
  int i = A->rows * A->columns;
  double count = 1.123456789;
  if (mode == MODE_POS_SEQUENCE) {
    while (i--) {
      A->matrix[0][i] = i + 1;
    }
  } else if (mode == MODE_POS_REVERS_SEQUENCE) {
    while (i--) {
      A->matrix[0][i] = count++;
    }
  } else if (mode == MODE_FOR_RESULT_POS) {
    while (i--) {
      A->matrix[0][i] = 26.1234567890;
    }
  } else if (mode == MODE_NEG_SEQUENCE) {
    while (i--) {
      A->matrix[0][i] = -i - 1;
    }
  } else if (mode == MODE_NEG_REVERS_SEQUENCE) {
    while (i--) {
      A->matrix[0][i] = -count++;
    }
  } else if (mode == MODE_FOR_RESULT_NEG) {
    while (i--) {
      A->matrix[0][i] = -26.1234567890;
    }
  }
}
