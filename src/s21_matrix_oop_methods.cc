#include "./s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  return !(*this == other) ? OK : ERROR;
}

void S21Matrix::SumMatrix(const S21Matrix& other) { *this += other; }

void S21Matrix::SubMatrix(const S21Matrix& other) { *this -= other; }

void S21Matrix::MulNumber(const double& num) noexcept { *this *= num; }

void S21Matrix::MulMatrix(const S21Matrix& other) { *this *= other; }

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix tmp(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      tmp.matrix_[i][j] = matrix_[j][i];
    }
  }
  return tmp;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!(IsSquare())) {
    S21Matrix tmp(rows_, cols_);
    if (rows_ == 1) {
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
  if (!(IsSquare())) {
    double dtrm = 0;
    if (rows_ == 1) {
      dtrm = matrix_[0][0];
    } else {
      dtrm = CountDeterm();
    }
    return dtrm;
  } else {
    throw std::runtime_error("Matrix is not square");
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  double dtrm = Determinant();
  if (!IsSquare() && dtrm != 0) {
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
