#include "./s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int r, int c) {
  if (r > 0 && c > 0) {
    rows_ = r;
    cols_ = c;
    MemoryAllocate();
  } else {
    std::cout << "error" << std::endl;
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  MemoryAllocate();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  if (this != &other) {
    this->matrix_ = other.matrix_;
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    other.matrix_ = nullptr;
    other.cols_ = 0;
    other.rows_ = 0;
  }
}

S21Matrix::~S21Matrix() {
  std::cout << "destructor for " << this->matrix_ << std::endl;
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

int S21Matrix::GetRows() { return this->rows_; };

int S21Matrix::GetCols() { return this->cols_; }

void S21Matrix::SetRows(int r) { this->rows_ = r; }

void S21Matrix::SetCols(int c) { this->cols_ = c; }
