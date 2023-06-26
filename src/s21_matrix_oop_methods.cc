#include "s21_matrix_oop.h"

bool Matrix::EqMatrix(const Matrix& other) const noexcept {
  return !(*this == other) ? OK : ERROR;
}

void Matrix::SumMatrix(const Matrix& other) { *this += other; }

void Matrix::SubMatrix(const Matrix& other) { *this -= other; }

void Matrix::MulNumber(const double& num) noexcept { *this *= num; }

void Matrix::MulMatrix(const Matrix& other) { *this *= other; }

Matrix Matrix::Transpose() const noexcept {
  Matrix result_matrix(cols_, rows_);
  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      result_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result_matrix;
}

Matrix Matrix::CalcComplements() const {
  if (!(IsMatrixSquare())) {
    Matrix result_matrix(rows_, cols_);
    if (rows_ == 1) {
      result_matrix.matrix_[0][0] = matrix_[0][0];
    } else {
      Matrix submatrix(result_matrix.rows_ - 1, result_matrix.cols_ - 1);
      for (int i = 0; i < result_matrix.rows_; ++i) {
        for (int j = 0; j < result_matrix.cols_; ++j) {
          double determinant = submatrix.MinorMatrix(i, j, *this).Determinant();
          result_matrix.matrix_[i][j] = SignForOne(i + j) * determinant;
        }
      }
    }
    return result_matrix;
  } else {
    throw std::runtime_error("Matrix is not square");
  }
}

double Matrix::Determinant() const {
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

Matrix Matrix::InverseMatrix() const {
  double determinant = Determinant();
  if (!IsMatrixSquare() && determinant != 0) {
    Matrix result_matrix(*this);
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
