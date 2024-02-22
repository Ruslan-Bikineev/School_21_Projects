#ifndef S21_MATRIX_H
#define S21_MATRIX_H

// INCLUDES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// MACROS
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2
#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0
#define PRECISION 1e-7
#define SUB_MODE 1
#define SUM_MODE 0

// MODE FOR FILLING MATRIX
#define MODE_POS_SEQUENCE 1
#define MODE_POS_REVERS_SEQUENCE 2
#define MODE_FOR_RESULT_POS 3
#define MODE_NEG_SEQUENCE 4
#define MODE_NEG_REVERS_SEQUENCE 5
#define MODE_FOR_RESULT_NEG 6

/*----------------------------MATRIX----------------------------*/
int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
/*----------------------------GENERAL----------------------------*/
void s21_fill_matrix(matrix_t *A, int mode);
int s21_sum_or_sub(matrix_t *A, matrix_t *B, matrix_t *result, int mode);
void s21_init_matrix(matrix_t *value);
int s21_validation_matrix(matrix_t *value_1);
int s21_check_eq_size_matrix(matrix_t *A, matrix_t *B);
double s21_determinant_2x2(matrix_t *A);

#endif