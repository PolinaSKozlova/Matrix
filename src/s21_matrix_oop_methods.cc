#include "./s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
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

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->CheckMatrix() || CheckMatrix(other)) {
  } else {
    if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
          this->matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
        }
      }
    } else {
    }
  }
}
