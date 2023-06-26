#include "matrix_oop.h"

static double FABS(double num) { return (num < 0 ? -num : num); }

Matrix Matrix::operator+(const Matrix& other) const {
  if (!(IsSizeEqual(other))) {
    Matrix result_matrix(rows_, cols_);
    for (int i = 0; i < result_matrix.rows_; ++i) {
      for (int j = 0; j < result_matrix.cols_; ++j) {
        result_matrix.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
      }
    }
    return result_matrix;
  } else {
    throw std::runtime_error("Different size of matrices");
  }
}

Matrix Matrix::operator-(const Matrix& other) const {
  if (!(IsSizeEqual(other))) {
    Matrix result_matrix(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        result_matrix.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
      }
    }
    return result_matrix;
  } else {
    throw std::runtime_error("Different size of matrices");
  }
}

Matrix Matrix::operator*(const Matrix& other) const {
  if (cols_ == other.rows_) {
    Matrix result_matrix(rows_, other.cols_);
    for (int i = 0; i < result_matrix.rows_; ++i) {
      for (int j = 0; j < result_matrix.cols_; ++j) {
        for (int k = 0; k < cols_; ++k) {
          result_matrix.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    return result_matrix;
  } else {
    throw std::runtime_error(
        "The rows of first matrix are not equal to the cols of second matrix");
  }
}

Matrix Matrix::operator*(const double& num) const noexcept {
  Matrix result_matrix(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result_matrix.matrix_[i][j] = matrix_[i][j] * num;
    }
  }
  return result_matrix;
}

Matrix operator*(const double& num, const Matrix& other) noexcept {
  Matrix result_matrix(other);
  result_matrix *= num;
  return result_matrix;
}

bool Matrix::operator==(const Matrix& other) const noexcept {
  int status_code = OK;
  if (!(IsSizeEqual(other))) {
    for (int i = 0; i < rows_ && !status_code; ++i) {
      for (int j = 0; j < cols_ && !status_code; ++j) {
        if (FABS(matrix_[i][j] - other.matrix_[i][j]) > kNumAccuracy) {
          status_code = ERROR;
        }
      }
    }
  } else {
    status_code = ERROR;
  }
  return status_code;
}

Matrix& Matrix::operator=(const Matrix& other) noexcept {
  if (matrix_ != nullptr) {
    MemoryFree();
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  MemoryAllocate();
  for (int i = 0; i < other.rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
  return (*this = *this + other);
}

Matrix& Matrix::operator-=(const Matrix& other) {
  return (*this = *this - other);
}

Matrix& Matrix::operator*=(const Matrix& other) {
  return (*this = *this * other);
}

Matrix& Matrix::operator*=(const double& num) noexcept {
  return (*this = *this * num);
}

double& Matrix::operator()(const int& i, const int& j) {
  if (i > rows_ || i < 0 || j > cols_ || j < 0) {
    throw std::runtime_error("Out of range");
  } else {
    return matrix_[i][j];
  }
}
