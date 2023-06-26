#ifndef MATRIXPLUS_MATRIX_OOP_H_
#define MATRIXPLUS_MATRIX_OOP_H_

#include <exception>
#include <iostream>

constexpr static double kNumAccuracy = 1.0e-7L;

enum RETURN_STATUS { OK, ERROR };

class Matrix {
 public:
  Matrix();
  explicit Matrix(int r, int c);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other);

  Matrix& operator=(const Matrix& other) noexcept;
  Matrix& operator+=(const Matrix& other);
  Matrix& operator-=(const Matrix& other);
  Matrix& operator*=(const Matrix& other);
  Matrix& operator*=(const double& num) noexcept;
  Matrix operator+(const Matrix& other) const;
  Matrix operator-(const Matrix& other) const;
  Matrix operator*(const Matrix& other) const;
  Matrix operator*(const double& num) const noexcept;
  bool operator==(const Matrix& other) const noexcept;

  ~Matrix();

  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(const int& r);
  void SetCols(const int& c);
  /* перегрузка оператора [] */
  double& operator()(const int& i, const int& j);
  bool EqMatrix(const Matrix& other) const noexcept;
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulNumber(const double& num) noexcept;
  void MulMatrix(const Matrix& other);
  Matrix Transpose() const noexcept;
  Matrix CalcComplements() const;
  double Determinant() const;
  Matrix InverseMatrix() const;

  friend double** PointerToMatrix(const Matrix& other);
  void FillMatrix();
  void FillSimpleMatrix();

 private:
  void MemoryAllocate();
  void MemoryFree();
  int IsMatrixSquare() const noexcept;
  int IsSizeEqual(const Matrix& other) const noexcept;
  int SignForOne(const int& num) const noexcept;
  double CountDeterminant() const;
  double DefineDeterminant() const;
  Matrix& MinorMatrix(const int& rows, const int& cols, const Matrix& other);
  int rows_, cols_;
  double** matrix_;
};

Matrix operator*(const double& num, const Matrix& other) noexcept;

#endif  // MATRIXPLUS_S21_MATRIX_OOP_H_