#include "./s21_matrix_oop.h"

using namespace std;

int main() {
  S21Matrix m(2, 5);
  // S21Matrix m1(5, 8);
  // m1.ShowMatrix();
  m.FillMatrix();
  // m1.FillMatrix();
  // m1.FillMatrix1();
  // cout << "m1" << endl;
  // m1.ShowMatrix();
  cout << "m" << endl;
  // m.ShowMatrix();
  // m1 = m;
  // S21Matrix m1(m);
  // m.SumMatrix(m1);
  // S21Matrix m1(std::move(m));
  m.ShowMatrix();
  // m.SumMatrix(m1);

  m.Transpose();
  cout << "результат Transpose" << endl;
  m.ShowMatrix();
  cout << endl;
  // int res = (m == m1);
  // S21Matrix sum(3, 5);
  // sum = m + m1;
  // sum.ShowMatrix();
  // cout << "res " << res << endl;
  return 0;
}
