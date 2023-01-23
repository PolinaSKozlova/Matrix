#include "./s21_matrix_oop.h"

using namespace std;

int main() {
  S21Matrix m(3, 5);
  S21Matrix m1(5, 8);
  // m1.ShowMatrix();
  m.FillMatrix();
  // m1.FillMatrix();
  m1.FillMatrix1();
  cout << "m1" << endl;
  m1.ShowMatrix();
  cout << "m" << endl;
  m.ShowMatrix();
  m1 = m;
  // S21Matrix m1(std::move(m));
  cout << "m1 = m" << endl;
  m1.ShowMatrix();
  // cout << "m" << endl;
  // m.ShowMatrix();
  return 0;
}
