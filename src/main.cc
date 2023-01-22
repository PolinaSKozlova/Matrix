#include <iostream>

#include "./s21_matrix_oop.h"

using namespace std;

int main() {
  S21Matrix m;
  //   S21Matrix m(4, 5);
  //   int r = m.GetRows();
  int r;
  m.GetRows(&r);
  int c = m.GetCols();
  cout << "r = " << r << "\n"
       << "c = " << c << endl;
  m.SetRows(8);
  m.SetCols(5);
  c = m.GetCols();
  cout << "r = " << r << "\n"
       << "c = " << c << endl;
  return 0;
}
