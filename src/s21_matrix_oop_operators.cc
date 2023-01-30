#include "s21_matrix_oop.h"

static double FABS(double num) { return (num < 0 ? -num : num); }

int S21Matrix::IsSizeEqual(const S21Matrix& other) {
  return (rows_ == other.rows_ && cols_ == other.cols_) ? OK : ERROR;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  if (!(IsSizeEqual(other))) {
    S21Matrix result_matrix(rows_, cols_);
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

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  if (!(IsSizeEqual(other))) {
    S21Matrix result_matrix(rows_, cols_);
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

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  if (cols_ == other.rows_) {
    S21Matrix result_matrix(rows_, other.cols_);
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

S21Matrix S21Matrix::operator*(const double& num) noexcept {
  S21Matrix result_matrix(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result_matrix.matrix_[i][j] = matrix_[i][j] * num;
    }
  }
  return result_matrix;
}

S21Matrix operator*(const double& num, const S21Matrix& other) noexcept {
  S21Matrix result_matrix(other);
  result_matrix *= num;
  return result_matrix;
}

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
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

S21Matrix& S21Matrix::operator=(const S21Matrix& other) noexcept {
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

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  return (*this = *this + other);
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  return (*this = *this - other);
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  return (*this = *this * other);
}

S21Matrix& S21Matrix::operator*=(const double& num) noexcept {
  return (*this = *this * num);
}

double& S21Matrix::operator()(const int& i, const int& j) {
  if (i > rows_ || i < 0 || j > cols_ || j < 0) {
    throw std::runtime_error("Out of range");
  } else {
    return matrix_[i][j];
  }
}
