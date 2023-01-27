#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <exception>
#include <iostream>

enum STATUS { OK, ERROR };

class S21Matrix {
 public:
  const double NumAccuracy = 1e-7L;

  S21Matrix();
  S21Matrix(int r, int c);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double& num) noexcept;
  bool operator==(const S21Matrix& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double& num) noexcept;
  double& operator()(const int& i, const int& j);

  ~S21Matrix();

  int GetRows();
  int GetCols();
  void SetRows(const int& r);
  void SetCols(const int& c);

  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double& num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  void MemoryAllocate();
  void MemoryFree();
  int IsSquare();
  int SignForOne(const int& num);
  double CountDeterm();
  double DefineDeterminant();
  S21Matrix& MinorMatrix(const int& rows, const int& cols,
                         const S21Matrix& other);
  /************************************************/
  void ShowMatrix();
  void FillMatrix();
  void FillSimpleMatrix();
  /************************************************/
  friend double** PtrToMatrix(const S21Matrix& other);

 private:
  int rows_, cols_;
  double** matrix_;
};

S21Matrix operator*(const double& num, const S21Matrix& other) noexcept;

#endif  // SRC_S21_MATRIX_OOP_H_
