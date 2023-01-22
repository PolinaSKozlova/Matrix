#include "./s21_matrix_oop.h"

void S21Matrix::ShowMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << this->matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void S21Matrix::FillMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = i + j;
    }
  }
}

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int r, int c) {
  if (r > 0 || c > 0) {
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
  if (r > 0) {
    //   if (rows_ < r) {
    //     rows_ = r;
    //     MemoryAllocate();
    //   } else if (rows_ = r) {
    //   } else {
    //     rows_ = r;
    //     MemoryAllocate();
    //   }
    rows_ = r;
  } else {
  }
}

void S21Matrix::SetCols(int c) {
  if (c > 0) {
    cols_ = c;
    //   if (cols_ < r) {
    //     cols_ = r;
    //   } else if (cols_ = r) {
    //   } else {
    //     cols_ = r;
    //   }
  } else {
  }
}
