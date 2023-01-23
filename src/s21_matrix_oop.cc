#include "./s21_matrix_oop.h"

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

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int r, int c) {
  if (r > 0 || c > 0) {
    rows_ = r;
    cols_ = c;
    MemoryAllocate();
  } else {
    std::cout << "error" << std::endl;
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  MemoryAllocate();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  if (this != &other) {
    this->matrix_ = other.matrix_;
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    other.matrix_ = nullptr;
    other.cols_ = 0;
    other.rows_ = 0;
  }
}

S21Matrix::~S21Matrix() {
  std::cout << "destructor for " << this->matrix_ << std::endl;
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

void S21Matrix::MemoryAllocate() {
  this->matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[cols_];
  }
}

int S21Matrix::CheckMatrix() {
  return (this->rows_ <= 0 || this->cols_ <= 0 || this->matrix_ == nullptr)
             ? ERROR
             : OK;
}

int S21Matrix::CheckMatrix(const S21Matrix& other) {
  return (other.rows_ <= 0 || other.cols_ <= 0 || other.matrix_ == nullptr)
             ? ERROR
             : OK;
}

int S21Matrix::GetRows() { return this->rows_; };

int S21Matrix::GetCols() { return this->cols_; }

void S21Matrix::SetRows(int r) { this->rows_ = r; }

void S21Matrix::SetCols(int c) { this->cols_ = c; }

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
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

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->CheckMatrix() || CheckMatrix(other)) {
  } else {
    if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
          this->matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
        }
      }
    } else {
    }
  }
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

bool S21Matrix::operator!=(const S21Matrix& other) noexcept {
  int status_code = OK;
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int i = 0; i < this->rows_ && !status_code; i++) {
      for (int j = 0; j < this->cols_ && !status_code; j++) {
        if (this->matrix_[i][j] == other.matrix_[i][j]) {
          status_code = ERROR;
        }
      }
    }
  } else {
    status_code = ERROR;
  }
  return status_code;
}
