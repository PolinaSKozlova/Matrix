#include "./s21_matrix_oop.h"

using namespace std;

int main() {
  S21Matrix m(4, 7);
  S21Matrix m1(0, 0);
  int r = m.GetRows();
  int c = m.GetCols();
  //   cout << "r = " << r << "\n"
  //        << "c = " << c << endl;
  //   m.SetRows(8);
  //   m.SetCols(5);
  //   r = m.GetRows();
  //   c = m.GetCols();
  //   m.MemoryAllocate();
  cout << "r = " << r << "\n"
       << "c = " << c << endl;
  //   m.ShowMatrix();
  //   r = m2.GetRows();
  //   c = m2.GetCols();
  //   cout << "r = " << r << "\n"
  //        << "c = " << c << endl;
  //   m2.MemoryAllocate();
  m.FillMatrix();
  m.ShowMatrix();
  S21Matrix m2(m);
  cout << endl;
  m2.ShowMatrix();
  return 0;
}
