#include <cassert>

#include "./s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int r, int c) : rows_(r), cols_(c) {
  assert(rows_ > 0 || cols_ > 0);
  MemoryAllocate();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  MemoryAllocate();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) : rows_(0), cols_(0), matrix_(nullptr) {
  std::swap(matrix_, other.matrix_);
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
}

S21Matrix::~S21Matrix() {
  std::cout << "Destruct " << matrix_ << std::endl;
  if (matrix_) {
    MemoryFree();
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

int S21Matrix::GetRows() { return rows_; };

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(const int& r) {
  if (r > 0) {
    S21Matrix tmp(r, this->cols_);
    for (int i = 0; i < std::min(this->rows_, r); i++) {
      for (int j = 0; j < tmp.cols_; j++) {
        tmp.matrix_[i][j] = this->matrix_[i][j];
      }
    }
    *this = tmp;
    this->rows_ = r;
  } else {
    throw std::runtime_error(
        "The rows of matrix are less than or equal to zero");
  }
}

void S21Matrix::SetCols(const int& c) {
  if (c > 0) {
    S21Matrix tmp(this->rows_, c);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < std::min(this->cols_, c); j++) {
        if (j < this->cols_) {
          tmp.matrix_[i][j] = this->matrix_[i][j];
        }
      }
    }
    *this = tmp;
    this->cols_ = c;
  } else {
    throw std::runtime_error(
        "The cols of matrix are less than or equal to zero");
  }
}
