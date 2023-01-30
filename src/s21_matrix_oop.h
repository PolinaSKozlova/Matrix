#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <exception>
#include <iostream>

enum RETURN_STATUS { OK, ERROR };

class S21Matrix {
 public:
  constexpr static double kNumAccuracy = 1.0e-7L;

  S21Matrix();
  S21Matrix(int r, int c);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  S21Matrix& operator=(const S21Matrix& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double& num) noexcept;

  ~S21Matrix();

  int GetRows();
  int GetCols();
  void SetRows(const int& r);
  void SetCols(const int& c);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double& num) noexcept;
  bool operator==(const S21Matrix& other) noexcept;
  /* перегрузка оператора [] */
  double& operator()(const int& i, const int& j);
  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double& num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  /* вспомогательные функции для основных методов и операторов */
  void MemoryAllocate();
  void MemoryFree();
  int IsMatrixSquare();
  int IsSizeEqual(const S21Matrix& other);
  int SignForOne(const int& num);
  double CountDeterminant();
  double DefineDeterminant();
  S21Matrix& MinorMatrix(const int& rows, const int& cols,
                         const S21Matrix& other);
  friend double** PointerToMatrix(const S21Matrix& other);

  void FillMatrix();
  void FillSimpleMatrix();

 private:
  int rows_, cols_;
  double** matrix_;
};

S21Matrix operator*(const double& num, const S21Matrix& other) noexcept;

#endif  // SRC_S21_MATRIX_OOP_H_