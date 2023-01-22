#include "./s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 1;
  cols_ = 1;
}

S21Matrix::S21Matrix(int r, int c) {
  rows_ = r;
  cols_ = c;
}

S21Matrix::S21Matrix(const S21Matrix& other) {}

S21Matrix::S21Matrix(S21Matrix&& other) {}

S21Matrix::~S21Matrix() {
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

int S21Matrix::GetRows() { return rows_; };

int S21Matrix::GetCols() { return cols_; };
