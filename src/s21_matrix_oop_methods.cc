#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  return !(*this == other) ? OK : ERROR;
}

void S21Matrix::SumMatrix(const S21Matrix& other) { *this += other; }

void S21Matrix::SubMatrix(const S21Matrix& other) { *this -= other; }

void S21Matrix::MulNumber(const double& num) noexcept { *this *= num; }

void S21Matrix::MulMatrix(const S21Matrix& other) { *this *= other; }

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix result_matrix(cols_, rows_);
  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      result_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result_matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!(IsMatrixSquare())) {
    S21Matrix result_matrix(rows_, cols_);
    if (rows_ == 1) {
      result_matrix.matrix_[0][0] = matrix_[0][0];
    } else {
      double determinant = 0.0;
      S21Matrix submatrix(result_matrix.rows_ - 1, result_matrix.cols_ - 1);
      for (int i = 0; i < result_matrix.rows_; ++i) {
        for (int j = 0; j < result_matrix.cols_; ++j) {
          determinant = submatrix.MinorMatrix(i, j, *this).Determinant();
          result_matrix.matrix_[i][j] = SignForOne(i + j) * determinant;
        }
      }
    }
    return result_matrix;
  } else {
    throw std::runtime_error("Matrix is not square");
  }
}

double S21Matrix::Determinant() {
  if (!(IsMatrixSquare())) {
    double determinant = 0.0;
    if (rows_ == 1) {
      determinant = matrix_[0][0];
    } else {
      determinant = CountDeterminant();
    }
    return determinant;
  } else {
    throw std::runtime_error("Matrix is not square");
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  if (!IsMatrixSquare() && determinant != 0) {
    S21Matrix result_matrix(*this);
    if (rows_ == 1) {
      result_matrix.matrix_[0][0] = 1.0 / determinant;
    } else {
      result_matrix = result_matrix.CalcComplements().Transpose();
      result_matrix.MulNumber(1.0 / determinant);
    }
    return result_matrix;
  } else {
    throw std::runtime_error(
        "Matrix is not square or determinant is equal to zero");
  }
}
