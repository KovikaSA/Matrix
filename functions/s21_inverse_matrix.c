#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!validate(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return ERROR_CALCULATE;
  double det = 0;
  int det_ret = 0;
  det_ret = s21_determinant(A, &det);
  if (!det || det_ret == ERROR_CALCULATE) return ERROR_CALCULATE;

  int status = s21_create_matrix(A->rows, A->columns, result);

  if (status == OK) {
    if (A->rows != 1) {
      matrix_t B = {0};
      matrix_t C = {0};
      matrix_t D = {0};

      s21_calc_complements(A, &B);

      s21_transpose(&B, &C);

      s21_mult_number(&C, 1.0 / det, &D);

      for (int i = 0; i < D.rows; i++)
        for (int j = 0; j < D.columns; j++)
          result->matrix[i][j] = D.matrix[i][j];

      s21_remove_matrix(&B);
      s21_remove_matrix(&C);
      s21_remove_matrix(&D);
    } else {
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    }
  }

  return status;
}