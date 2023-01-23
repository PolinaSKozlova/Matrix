#include "./s21_matrix_oop.h"

void S21Matrix::MemoryAllocate() {
  this->matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[cols_];
  }
}

int S21Matrix::CheckMatrix() {
  return (this->rows_ <= 0 || this->cols_ <= 0 || this->matrix_ == nullptr)
             ? ERROR
             : OK;
}

int S21Matrix::CheckMatrix(const S21Matrix& other) {
  return (other.rows_ <= 0 || other.cols_ <= 0 || other.matrix_ == nullptr)
             ? ERROR
             : OK;
}
