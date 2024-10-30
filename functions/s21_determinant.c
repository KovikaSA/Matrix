#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!validate(A) || !result) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return ERROR_CALCULATE;

  *result = calc_determinant(A, A->rows);

  return OK;
}