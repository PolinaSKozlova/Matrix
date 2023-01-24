#include "./s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  return (*this == other) ? OK : ERROR;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  try {
    *this += other;
  } catch (std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  try {
    *this -= other;
  } catch (std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
}

void S21Matrix::MulNumber(const double& num) noexcept { *this *= num; }

void S21Matrix::MulMatrix(const S21Matrix& other) {
  try {
    *this *= other;
  } catch (std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
}

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix tmp(this->cols_, this->rows_);
  for (int i = 0; i < this->cols_; i++) {
    for (int j = 0; j < this->rows_; j++) {
      tmp.matrix_[i][j] = this->matrix_[j][i];
    }
  }
  *this = tmp;
  return *this;
}

// S21Matrix S21Matrix::CalcComplements() {}

double S21Matrix::Determinant() {
  double dtrm = 0;
  if (!(this->IsSquare())) {
    if (this->rows_ == 1) {
      dtrm = this->matrix_[0][0];
    } else {
      dtrm = this->CountDeterm();
    }
  } else {
    throw std::runtime_error("Matrix is not square");
  }
  return dtrm;
}

double S21Matrix::CountDeterm() {
  double dtrm = 0;
  return dtrm;
}

double S21Matrix::DefineDeterminant() {
  return (this->matrix_[0][0] * this->matrix_[1][1] -
          this->matrix_[0][1] * this->matrix_[1][0]);
}

// S21Matrix S21Matrix::InverseMatrix() {
//   S21Matrix tmp(this->rows_, this->cols_);
//   if (!(this->CheckMatrix())) {
//     double dtrm = 0;
//     dtrm = this->Determinant();
//     if (this->rows_ == this->cols_ && dtrm != 0) {
//       if (this->rows_ == 1) {
//         tmp.matrix_[0][0] = 1. / dtrm;
//       } else {
//         this->CalcComplements();
//         this->Transpose();
//         this->MulNumber(1. / dtrm);
//       }
//     } else {
//       throw std::bad_exception();
//     }
//   } else {
//     throw std::bad_exception();
//   }
//   return tmp;
// }
