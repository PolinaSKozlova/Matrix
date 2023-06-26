#include "s21_matrix_oop.h"

void Matrix::MemoryAllocate() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]{};
  }
}

void Matrix::MemoryFree() {
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

int Matrix::IsMatrixSquare() const noexcept {
  return (rows_ == cols_) ? OK : ERROR;
}

int Matrix::IsSizeEqual(const Matrix& other) const noexcept {
  return (rows_ == other.rows_ && cols_ == other.cols_) ? OK : ERROR;
}

int Matrix::SignForOne(const int& num) const noexcept {
  return (num % 2 == 0) ? 1 : -1;
}

Matrix& Matrix::MinorMatrix(const int& rows, const int& cols,
                            const Matrix& other) {
  for (int i_other = 0, i_minor = 0; i_other < other.rows_ && i_minor < rows_;
       ++i_other, ++i_minor) {
    if (i_other == rows && i_other < rows_) {
      ++i_other;
    }
    for (int j_other = 0, j_minor = 0; j_other < other.cols_ && j_minor < cols_;
         ++j_other, ++j_minor) {
      if (j_other == cols && j_other < cols_) {
        ++j_other;
      }
      matrix_[i_minor][j_minor] = other.matrix_[i_other][j_other];
    }
  }
  return *this;
}

double Matrix::CountDeterminant() const {
  double determinant = 0;
  if (rows_ == 2) {
    determinant = DefineDeterminant();
  } else {
    for (int j = 0; j < cols_; ++j) {
      Matrix minor(rows_ - 1, cols_ - 1);
      determinant += SignForOne(j) * matrix_[0][j] *
                     minor.MinorMatrix(0, j, *this).CountDeterminant();
    }
  }
  return determinant;
}

double Matrix::DefineDeterminant() const {
  return (matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0]);
}

void Matrix::FillMatrix() {
  double k = 0.34;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++, k += 0.25) {
      matrix_[i][j] = i % (j + 1) + (i + j + k);
    }
  }
}

void Matrix::FillSimpleMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = i + j;
    }
  }
}

double** PointerToMatrix(const Matrix& other) {
  double** pointer_to_matrix = other.matrix_;
  return pointer_to_matrix;
}
