#include "./s21_matrix_oop.h"

void S21Matrix::ShowMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  //   MemoryAllocate();
}

S21Matrix::S21Matrix(int r, int c) {
  rows_ = r;
  cols_ = c;
  MemoryAllocate();
}

S21Matrix::S21Matrix(const S21Matrix& other) {}

S21Matrix::S21Matrix(S21Matrix&& other) {}

S21Matrix::~S21Matrix() {
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

void S21Matrix::MemoryAllocate() {
  this->matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[cols_];
  }
}

int S21Matrix::GetRows() { return rows_; };

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int r) {
  //   if (rows_ < r) {
  //     rows_ = r;
  //   } else if (rows_ = r) {
  //   } else {
  //     rows_ = r;
  //   }
  rows_ = r;
}

void S21Matrix::SetCols(int c) {
  cols_ = c;
  //   if (cols_ < r) {
  //     cols_ = r;
  //   } else if (cols_ = r) {
  //   } else {
  //     cols_ = r;
  //   }
}
