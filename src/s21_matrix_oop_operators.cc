#include "./s21_matrix_oop.h"

S21Matrix& S21Matrix::operator=(const S21Matrix& other) noexcept {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  if (this->matrix_ != nullptr) {
    delete[] this->matrix_;
  }
  MemoryAllocate();
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  int status_code = OK;
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int i = 0; i < this->rows_ && !status_code; i++) {
      for (int j = 0; j < this->cols_ && !status_code; j++) {
        if (this->matrix_[i][j] != other.matrix_[i][j]) {
          status_code = ERROR;
        }
      }
    }
  } else {
    status_code = ERROR;
  }
  return status_code;
}

S21Matrix& S21Matrix::operator+(const S21Matrix& other) {
  if (this->CheckMatrix() || CheckMatrix(other)) {
    if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
          this->matrix_[i][j] += other.matrix_[i][j];
        }
      }

    } else {
    }
  } else {
  }

  return *this;
}
