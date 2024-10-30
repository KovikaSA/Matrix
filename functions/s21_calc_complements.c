#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!validate(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return ERROR_CALCULATE;

  matrix_t B = {0};
  s21_create_matrix(A->rows - 1, A->columns - 1, &B);

  int status = s21_create_matrix(A->rows, A->columns, result);

  if (status == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        minor(A, &B, i, j);

        double det = 0;
        s21_determinant(&B, &det);

        result->matrix[i][j] = pow(-1, i + j) * det;
      }
    }
  }

  s21_remove_matrix(&B);

  return status;
}