#include "./s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix tmp(this->rows_, this->cols_);
  if (!(this->CheckMatrix()) || !CheckMatrix(other)) {
    if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
          tmp.matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
        }
      }
    } else {
    }
  } else {
  }
  return tmp;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix tmp(this->rows_, this->cols_);
  if (!(this->CheckMatrix()) || !CheckMatrix(other)) {
    if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
          tmp.matrix_[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
        }
      }
    } else {
    }
  } else {
  }
  return tmp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix tmp(this->rows_, other.cols_);
  if (!(this->CheckMatrix()) || !CheckMatrix(other)) {
    if (this->cols_ == other.rows_) {
      for (int i = 0; i < tmp.rows_; i++) {
        for (int j = 0; j < tmp.cols_; j++) {
          for (int k = 0; k < this->cols_; k++) {
            tmp.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
          }
        }
      }
    } else {
    }
  } else {
  }
  return tmp;
}

S21Matrix S21Matrix::operator*(const double& num) {
  S21Matrix tmp(this->rows_, this->cols_);
  if (!(this->CheckMatrix())) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        tmp.matrix_[i][j] = this->matrix_[i][j] * num;
      }
    }

  } else {
  }

  return tmp;
}

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  int status_code = OK;
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int i = 0; i < this->rows_ && !status_code; i++) {
      for (int j = 0; j < this->cols_ && !status_code; j++) {
        if (this->matrix_[i][j] != other.matrix_[i][j]) {
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
    delete[] this->matrix_;
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
  if (!(this->CheckMatrix()) || !CheckMatrix(other)) {
    if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
          this->matrix_[i][j] += other.matrix_[i][j];
        }
      }

    } else {
    }
  } else {
  }
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  if (!(this->CheckMatrix()) || !CheckMatrix(other)) {
    if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
          this->matrix_[i][j] -= other.matrix_[i][j];
        }
      }

    } else {
    }
  } else {
  }

  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  if (!(this->CheckMatrix()) || !CheckMatrix(other)) {
    S21Matrix tmp(this->rows_, other.cols_);
    if (this->cols_ == other.rows_) {
      for (int i = 0; i < tmp.rows_; i++) {
        for (int j = 0; j < tmp.cols_; j++) {
          for (int k = 0; k < this->cols_; k++) {
            tmp.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
          }
        }
      }
      *this = tmp;
    } else {
    }
  } else {
  }
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double& num) {
  if (!(this->CheckMatrix())) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] *= num;
      }
    }
  } else {
  }
  return *this;
}

double& S21Matrix::operator()(const int i, const int j) {
  return this->matrix_[i][j];
}
