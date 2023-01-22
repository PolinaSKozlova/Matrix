#include "./s21_matrix_oop.h"

using namespace std;

int main() {
  S21Matrix m(10, 15);
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

  m.ShowMatrix();

  return 0;
}
