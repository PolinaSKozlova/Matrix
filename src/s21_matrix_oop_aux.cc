#include "./s21_matrix_oop.h"

void S21Matrix::MemoryAllocate() {
  this->matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[cols_]{};
  }
}

int S21Matrix::IsSquare() { return (this->rows_ == this->cols_) ? OK : ERROR; }

int S21Matrix::SignForDeterminant(const int& num) {
  return (num % 2 == 0) ? 1 : -1;
}

S21Matrix& S21Matrix::MinorMatrix(const int& rows, const int& cols,
                                  const S21Matrix& other) {
  for (int i_other = 0, i_minor = 0;
       i_other < other.rows_ && i_minor < this->rows_; i_other++, i_minor++) {
    if (i_other == rows && i_other < this->rows_) {
      i_other++;
    }
    for (int j_other = 0, j_minor = 0;
         j_other < other.cols_ && j_minor < this->cols_; j_other++, j_minor++) {
      if (j_other == cols && j_other < this->cols_) {
        j_other++;
      }
      this->matrix_[i_minor][j_minor] = other.matrix_[i_other][j_other];
    }
  }
  return *this;
}

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
