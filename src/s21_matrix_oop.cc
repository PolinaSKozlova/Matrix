#include "./s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
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

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int r) {
  //   if (rows_ < r) {
  //     rows_ = r;
  //   } else if (rows_ = r) {
  //   } else {
  //     rows_ = r;
  //   }
  rows_ = r;
}

void S21Matrix::SetCols(int c) {
  cols_ = c;
  //   if (cols_ < r) {
  //     cols_ = r;
  //   } else if (cols_ = r) {
  //   } else {
  //     cols_ = r;
  //   }
}
