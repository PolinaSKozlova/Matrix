#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <math.h>

#include <cstdlib>
#include <exception>
#include <iostream>

enum STATUS { OK, ERROR };

class S21Matrix {
 public:
  /* Базовый конструктор, инициализирующий матрицу некоторой
   * заранее заданной размерностью */
  S21Matrix();  // = delete;
  /* Параметризированный конструктор с количеством строк и столбцов */
  S21Matrix(int r, int c);
  /* Конструктор копирования */
  S21Matrix(const S21Matrix& other);
  /* Конструктор переноса */
  S21Matrix(S21Matrix&& other);
  /* Деструктор */
  ~S21Matrix();

  /* геттеры для получения столбцов и колонок */
  int GetRows();
  int GetCols();
  void SetRows(const int& r);
  void SetCols(const int& c);

  /* Проверяет матрицы на равенство между собой */
  bool EqMatrix(const S21Matrix& other) noexcept;
  /* Прибавляет вторую матрицы к текущей */
  void SumMatrix(const S21Matrix& other);
  /* Вычитает из текущей матрицы другую */
  void SubMatrix(const S21Matrix& other);
  /* Умножает текущую матрицу на число */
  void MulNumber(const double& num) noexcept;
  /* Умножает текущую матрицу на вторую */
  void MulMatrix(const S21Matrix& other);
  /* Создает новую транспонированную матрицу из текущей и возвращает ее */
  S21Matrix Transpose() noexcept;
  /* Вычисляет матрицу алгебраических дополнений текущей матрицы
  и возвращает ее */
  S21Matrix CalcComplements();
  /* Вычисляет и возвращает определитель текущей матрицы */
  double Determinant();
  /* Вычисляет и возвращает обратную матрицу */
  S21Matrix InverseMatrix();
  void MemoryAllocate();
  int IsSquare();
  int SignForOne(const int& num);
  double CountDeterm();
  double DefineDeterminant();
  S21Matrix& MinorMatrix(const int& rows, const int& cols,
                         const S21Matrix& other);
  double RandomDouble(double min, double max);
  /************************************************/
  void ShowMatrix();
  void FillMatrix();
  void FillMatrix1();
  /************************************************/

  /*noexcept  Этот спецификатор указывает, что наша функция не генерирует (не
    выбрасывает) исключение или аварийно завершает свою работу. */
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

 private:
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
};

#endif  // SRC_S21_MATRIX_OOP_H_
