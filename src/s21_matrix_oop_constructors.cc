#include <cassert>

#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int r, int c) : rows_(r), cols_(c) {
  assert(rows_ > 0 || cols_ > 0);
  MemoryAllocate();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  MemoryAllocate();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) : rows_(0), cols_(0), matrix_(nullptr) {
  std::swap(matrix_, other.matrix_);
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    MemoryFree();
  }
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

int S21Matrix::GetRows() { return rows_; };

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(const int& new_rows) {
  assert(new_rows > 0);
  S21Matrix temporary_matrix(new_rows, cols_);
  for (int i = 0; i < std::min(rows_, new_rows); ++i) {
    for (int j = 0; j < temporary_matrix.cols_; ++j) {
      temporary_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = temporary_matrix;
  rows_ = new_rows;
}

void S21Matrix::SetCols(const int& new_cols) {
  assert(new_cols > 0);
  S21Matrix temporary_matrix(rows_, new_cols);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < std::min(cols_, new_cols); ++j) {
      if (j < cols_) {
        temporary_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = temporary_matrix;
  cols_ = new_cols;
}
