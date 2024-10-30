#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) return INCORRECT_MATRIX;

  result->rows = 0;
  result->columns = 0;
  result->matrix = NULL;

  double **matrix =
      malloc(rows * columns * sizeof(double) + rows * sizeof(double *));
  double *ptr = (double *)(matrix + rows);

  for (int i = 0; i < rows; i++) matrix[i] = ptr + columns * i;

  result->rows = rows;
  result->columns = columns;
  result->matrix = matrix;

  fill_matrix(result, 0);

  return OK;
}