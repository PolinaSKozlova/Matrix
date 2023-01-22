#include "./s21_matrix_oop.h"

#include <iostream>
using namespace std;

int main() {
  S21Matrix m;
  //   S21Matrix m(4, 5);
  int r = m.GetRows();
  int c = m.GetCols();
  cout << "r = " << r << "c = " << c << endl;
  return 0;
}
