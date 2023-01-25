#include "./s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  return !(*this == other) ? OK : ERROR;
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
  return tmp;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!(this->IsSquare())) {
    S21Matrix tmp(this->rows_, this->cols_);
    if (this->rows_ == 1) {
      tmp.matrix_[0][0] = this->matrix_[0][0];
    } else {
      double dtrm = 0;
      S21Matrix minor(tmp.rows_ - 1, tmp.cols_ - 1);
      for (int i = 0; i < tmp.rows_; i++) {
        for (int j = 0; j < tmp.cols_; j++) {
          dtrm = minor.MinorMatrix(i, j, *this).Determinant();
          tmp.matrix_[i][j] = SignForOne(i + j) * dtrm;
        }
      }
    }
    return tmp;
  } else {
    throw std::runtime_error("Matrix is not square");
  }
}

double S21Matrix::Determinant() {
  if (!(this->IsSquare())) {
    double dtrm = 0;
    if (this->rows_ == 1) {
      dtrm = this->matrix_[0][0];
    } else {
      dtrm = this->CountDeterm();
    }
    return dtrm;
  } else {
    throw std::runtime_error("Matrix is not square");
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  double dtrm = 0;
  dtrm = this->Determinant();
  int res = this->IsSquare();
  if (!res && dtrm != 0) {
    S21Matrix tmp(*this);
    if (tmp.rows_ == 1) {
      tmp.matrix_[0][0] = 1. / dtrm;
    } else {
      tmp = tmp.CalcComplements().Transpose();
      tmp.MulNumber(1. / dtrm);
    }
    return tmp;
  } else {
    throw std::runtime_error(
        "Matrix is not square or determinant is equal to zero");
  }
}
