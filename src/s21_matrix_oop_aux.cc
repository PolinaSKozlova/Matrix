#include "s21_matrix_oop.h"

void S21Matrix::MemoryAllocate() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
}

void S21Matrix::MemoryFree() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

int S21Matrix::IsSquare() { return (rows_ == cols_) ? OK : ERROR; }

int S21Matrix::SignForOne(const int& num) { return (num % 2 == 0) ? 1 : -1; }

S21Matrix& S21Matrix::MinorMatrix(const int& rows, const int& cols,
                                  const S21Matrix& other) {
  for (int i_other = 0, i_minor = 0; i_other < other.rows_ && i_minor < rows_;
       i_other++, i_minor++) {
    if (i_other == rows && i_other < rows_) {
      i_other++;
    }
    for (int j_other = 0, j_minor = 0; j_other < other.cols_ && j_minor < cols_;
         j_other++, j_minor++) {
      if (j_other == cols && j_other < cols_) {
        j_other++;
      }
      matrix_[i_minor][j_minor] = other.matrix_[i_other][j_other];
    }
  }
  return *this;
}

double S21Matrix::CountDeterm() {
  double dtrm = 0;
  if (rows_ == 2) {
    dtrm = DefineDeterminant();
  } else {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor(rows_ - 1, cols_ - 1);
      dtrm += SignForOne(j) * matrix_[0][j] *
              minor.MinorMatrix(0, j, *this).CountDeterm();
    }
  }
  return dtrm;
}

double S21Matrix::DefineDeterminant() {
  return (matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0]);
}

void S21Matrix::FillMatrix() {
  double k = 0.34;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++, k += 0.25) {
      matrix_[i][j] = i % (j + 1) + (i + j + k);
    }
  }
}

void S21Matrix::FillSimpleMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = i + j;
    }
  }
}

double** PtrToMatrix(const S21Matrix& other) {
  double** ptr = other.matrix_;
  return ptr;
}

/************************************************/

/*void S21Matrix::ShowMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
  // std::cout << "call function ShowMatrix " << this->matrix_ << std::endl;
}*/

/************************************************/
