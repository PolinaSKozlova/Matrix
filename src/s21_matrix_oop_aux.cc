#include "./s21_matrix_oop.h"

/************************************************/

void S21Matrix::ShowMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << this->matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "call function ShowMatrix " << this->matrix_ << std::endl;
}

void S21Matrix::FillMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = 1 + i * j;
    }
  }
}

void S21Matrix::FillMatrix1() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = i + j;
    }
  }
}
/************************************************/
