#include "./s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  return (*this == other) ? OK : ERROR;
}

void S21Matrix::SumMatrix(const S21Matrix& other) { *this += other; }

void S21Matrix::SubMatrix(const S21Matrix& other) { *this -= other; }

// void S21Matrix::MulNumber(const double num) {}

void S21Matrix::MulMatrix(const S21Matrix& other) { *this *= other; }

S21Matrix S21Matrix::Transpose() {
  if (!(this->CheckMatrix())) {
    S21Matrix tmp(this->cols_, this->rows_);
    for (int i = 0; i < this->cols_; i++) {
      for (int j = 0; j < this->rows_; j++) {
        tmp.matrix_[i][j] = this->matrix_[j][i];
      }
    }
    *this = tmp;
  }
  return *this;
}

// S21Matrix S21Matrix::CalcComplements() {}

// S21Matrix S21Matrix::InverseMatrix() {}
