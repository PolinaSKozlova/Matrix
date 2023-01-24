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
    throw std::bad_exception();
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
  for (int i = 0; i < this->rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

int S21Matrix::GetRows() { return this->rows_; };

int S21Matrix::GetCols() { return this->cols_; }

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
    throw std::bad_exception();
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
    throw std::bad_exception();
  }
}

void S21Matrix::MemoryAllocate() {
  this->matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[cols_]{};
  }
}

int S21Matrix::IsSquare() { return (this->rows_ == this->cols_) ? OK : ERROR; }
