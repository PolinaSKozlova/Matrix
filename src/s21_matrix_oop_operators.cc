#include "./s21_matrix_oop.h"

static double FABS(double num) { return (num < 0 ? -num : num); }

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    S21Matrix tmp(rows_, cols_);
    for (int i = 0; i < tmp.rows_; i++) {
      for (int j = 0; j < tmp.cols_; j++) {
        tmp.matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
      }
    }
    return tmp;
  } else {
    throw std::runtime_error("Different size of matrices");
  }
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix tmp(this->rows_, this->cols_);
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        tmp.matrix_[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
      }
    }
  } else {
    throw std::runtime_error("Different size of matrices");
  }
  return tmp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix tmp(this->rows_, other.cols_);
  if (this->cols_ == other.rows_) {
    for (int i = 0; i < tmp.rows_; i++) {
      for (int j = 0; j < tmp.cols_; j++) {
        for (int k = 0; k < this->cols_; k++) {
          tmp.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
  } else {
    throw std::runtime_error(
        "The rows of first matrix are not equal to the cols of second matrix");
  }
  return tmp;
}

S21Matrix S21Matrix::operator*(const double& num) noexcept {
  S21Matrix tmp(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      tmp.matrix_[i][j] = this->matrix_[i][j] * num;
    }
  }
  return tmp;
}

S21Matrix operator*(const double& num, const S21Matrix& other) noexcept {
  S21Matrix tmp(other);
  tmp *= num;
  return tmp;
}

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  int status_code = OK;
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int i = 0; i < this->rows_ && !status_code; i++) {
      for (int j = 0; j < this->cols_ && !status_code; j++) {
        if (FABS(this->matrix_[i][j] - other.matrix_[i][j]) > 1e-7L) {
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
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  if (this->matrix_ != nullptr) {
    MemoryFree();
  }
  MemoryAllocate();
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] += other.matrix_[i][j];
      }
    }
    double** p_to_this = PtrToMatrix(*this);
    double** p_to_other = PtrToMatrix(other);
    std::cout << "SumMatrix A " << p_to_this << " B " << p_to_other
              << std::endl;
    return *this;
  } else {
    throw std::runtime_error("Different size of matrices");
  }
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  } else {
    throw std::runtime_error("Different size of matrices");
  }
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  if (this->cols_ == other.rows_) {
    S21Matrix tmp(this->rows_, other.cols_);
    for (int i = 0; i < tmp.rows_; i++) {
      for (int j = 0; j < tmp.cols_; j++) {
        for (int k = 0; k < this->cols_; k++) {
          tmp.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    *this = tmp;
  } else {
    throw std::runtime_error(
        "The rows of first matrix are not equal to the cols of second matrix");
  }
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double& num) noexcept {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] *= num;
    }
  }
  return *this;
}

double& S21Matrix::operator()(const int& i, const int& j) {
  if (i > this->rows_ || i < 0 || j > this->cols_ || j < 0) {
    throw std::runtime_error("Out of range");
  } else {
    return this->matrix_[i][j];
  }
}
