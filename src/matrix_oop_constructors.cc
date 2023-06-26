#include "matrix_oop.h"

Matrix::Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

Matrix::Matrix(int r, int c) : rows_(r), cols_(c) {
  if (rows_ <= 0 || cols_ <= 0)
    throw std::invalid_argument("Rows or cols can't be 0");
  MemoryAllocate();
}

Matrix::Matrix(const Matrix& other) : rows_(other.rows_), cols_(other.cols_) {
  MemoryAllocate();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

Matrix::Matrix(Matrix&& other) : rows_(0), cols_(0), matrix_(nullptr) {
  std::swap(matrix_, other.matrix_);
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
}

Matrix::~Matrix() {
  if (matrix_) {
    MemoryFree();
  }
  matrix_ = nullptr;
  rows_ = cols_ = 0;
}

int Matrix::GetRows() const noexcept { return rows_; };

int Matrix::GetCols() const noexcept { return cols_; }

void Matrix::SetRows(const int& new_rows) {
  if (new_rows <= 0)
    throw std::invalid_argument("Rows should be greater than 0");
  Matrix temporary_matrix(new_rows, cols_);
  for (int i = 0; i < std::min(rows_, new_rows); ++i) {
    for (int j = 0; j < temporary_matrix.cols_; ++j) {
      temporary_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = temporary_matrix;
}

void Matrix::SetCols(const int& new_cols) {
  if (new_cols <= 0)
    throw std::invalid_argument("Cols should be greater than 0");
  Matrix temporary_matrix(rows_, new_cols);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < std::min(cols_, new_cols); ++j) {
      if (j < cols_) {
        temporary_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = temporary_matrix;
}
