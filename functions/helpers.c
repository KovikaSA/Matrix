#include "../s21_matrix.h"

int validate(matrix_t *A) {
  return (A == NULL || A->rows <= 0 || A->columns <= 0 || !A->matrix) ? 0 : 1;
};

int operate_matrix(matrix_t *A, matrix_t *B, matrix_t *result, int sign) {
  if (!A || !B || !result) return INCORRECT_MATRIX;
  if (!A->matrix || !B->matrix) return INCORRECT_MATRIX;
  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0)
    return INCORRECT_MATRIX;
  if (A->columns != B->columns || A->rows != B->rows){
    return ERROR_CALCULATE;
  }

  int ret_result = s21_create_matrix(A->rows, A->columns, result);

  if (ret_result == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = sign ? A->matrix[i][j] - B->matrix[i][j]
                                    : A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return ret_result;
}

void minor(matrix_t *A, matrix_t *B, int row_size, int col_size) {
  int i = 0, j = 0;
  for (int row = 0; row < A->rows; row++)
    for (int col = 0; col < A->columns; col++)
      if (row != row_size && col != col_size) {
        B->matrix[i][j] = A->matrix[row][col];
        j++;
        if (j == A->rows - 1) {
          j = 0;
          i++;
        }
      }
}

double calc_determinant(matrix_t *A, int n) {
  double determinant = 0;

  if (n == 1) return A->matrix[0][0];

  matrix_t B = {0};
  s21_create_matrix(A->rows, A->columns, &B);

  int sign = 1;

  for (int f = 0; f < n; f++) {
    minor(A, &B, 0, f);
    determinant += sign * A->matrix[0][f] * calc_determinant(&B, n - 1);
    sign = -sign;
  }

  s21_remove_matrix(&B);

  return determinant;
}

void fill_matrix(matrix_t *A, double number) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) A->matrix[i][j] = number;
  }
}