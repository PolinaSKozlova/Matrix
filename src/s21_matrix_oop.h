#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <iostream>

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
  void SetRows(int r);
  void SetCols(int c);

  /* Проверяет матрицы на равенство между собой */
  bool EqMatrix(const S21Matrix& other);
  /* Прибавляет вторую матрицы к текущей */
  void SumMatrix(const S21Matrix& other);
  /* Вычитает из текущей матрицы другую */
  void SubMatrix(const S21Matrix& other);
  /* Умножает текущую матрицу на число */
  void MulNumber(const double num);
  /* Умножает текущую матрицу на вторую */
  void MulMatrix(const S21Matrix& other);
  /* Создает новую транспонированную матрицу из текущей и возвращает ее */
  S21Matrix Transpose();
  /* Вычисляет матрицу алгебраических дополнений текущей матрицы
  и возвращает ее */
  S21Matrix CalcComplements();
  /* Вычисляет и возвращает определитель текущей матрицы */
  double Determinant();
  /* Вычисляет и возвращает обратную матрицу */
  S21Matrix InverseMatrix();
  void MemoryAllocate();
  /************************************************/
  void ShowMatrix();
  void FillMatrix();
  void FillMatrix1();
  /************************************************/

  S21Matrix& operator=(const S21Matrix& other);

 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
};

#endif  // SRC_S21_MATRIX_OOP_H_
