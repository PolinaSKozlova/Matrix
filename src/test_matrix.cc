#include <gtest/gtest.h>

#include "./s21_matrix_oop.h"

TEST(constuctors, test_1) {
  S21Matrix A(4, 7);
  A.FillSimpleMatrix();
  S21Matrix B(A);
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(constuctors, test_2) {
  S21Matrix A(10, 10);
  A.FillMatrix();
  S21Matrix B(A);
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(constuctors, test_3) {
  S21Matrix A(6, 6);
  S21Matrix B(A);
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(constuctors, test_4) {
  S21Matrix A(4, 7);
  S21Matrix B(std::move(A));
  double **ptr = PtrToMatrix(A);
  EXPECT_EQ(ptr, nullptr);
}

TEST(constuctors, test_5) {
  S21Matrix A(4, 7);
  S21Matrix B(std::move(A));
  double **ptr = PtrToMatrix(A);
  EXPECT_EQ(ptr, nullptr);
}

TEST(eqMatrix, test_1) {
  S21Matrix A(4, 7);
  S21Matrix B(4, 7);
  A.FillSimpleMatrix();
  B.FillSimpleMatrix();
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(eqMatrix, test_2) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  A.FillSimpleMatrix();
  B.FillSimpleMatrix();
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(eqMatrix, test_3) {
  S21Matrix A(5, 8);
  S21Matrix B(5, 5);
  A.FillSimpleMatrix();
  B.FillSimpleMatrix();
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, ERROR);
}

TEST(eqMatrix, test_4) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  A.FillSimpleMatrix();
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, ERROR);
}

TEST(eqMatrix, test_5) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  A.FillSimpleMatrix();
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, ERROR);
}

TEST(SumMatrix, test_1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  A.FillSimpleMatrix();
  B.FillSimpleMatrix();
  S21Matrix C(5, 5);
  C = A + B;
  A.SumMatrix(B);
  int res = A.EqMatrix(C);
  ASSERT_EQ(res, OK);
}

TEST(SumMatrix, test_2) {
  S21Matrix A(3, 5);
  S21Matrix B(3, 5);
  B.FillMatrix();
  A.SumMatrix(B);
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(SumMatrix, test_3) {
  S21Matrix A(8, 5);
  S21Matrix B(8, 5);
  B.FillSimpleMatrix();
  A.SumMatrix(B);
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(SumMatrix, test_4) {
  S21Matrix A(5, 5);
  S21Matrix B(1, 5);
  EXPECT_THROW(A.SumMatrix(B), std::exception);
}

TEST(SumMatrix, test_5) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
  EXPECT_THROW(A.SumMatrix(B), std::exception);
}

TEST(SubMatrix, test_1) {
  S21Matrix A(5, 4);
  S21Matrix B(5, 4);
  A.FillSimpleMatrix();
  S21Matrix C(A);
  A.SubMatrix(B);
  int res = A.EqMatrix(C);
  ASSERT_EQ(res, OK);
}

TEST(SubMatrix, test_2) {
  S21Matrix A(6, 3);
  S21Matrix B(6, 3);
  S21Matrix C(6, 3);
  A.FillMatrix();
  B.FillMatrix();
  A.SubMatrix(B);
  int res = A.EqMatrix(C);
  ASSERT_EQ(res, OK);
}

TEST(SubMatrix, test_3) {
  S21Matrix A(4, 6);
  S21Matrix B(4, 6);
  B.FillMatrix();
  S21Matrix C(B);
  C *= -1;
  A.SubMatrix(B);
  int res = A.EqMatrix(C);
  ASSERT_EQ(res, OK);
}

TEST(SubMatrix, test_4) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
  EXPECT_THROW(A.SubMatrix(B), std::exception);
}

TEST(SubMatrix, test_5) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
  EXPECT_THROW(A.SubMatrix(B), std::exception);
}

TEST(MulNumber, test_1) {
  S21Matrix A(5, 3);
  A.FillMatrix();
  A.MulNumber(23.5);
  S21Matrix C(5, 3);
  C(0, 0) = 7.99;
  C(0, 1) = 37.365;
  C(0, 2) = 66.74;
  C(1, 0) = 49.115;
  C(1, 1) = 101.99;
  C(1, 2) = 131.365;
  C(2, 0) = 90.24;
  C(2, 1) = 119.615;
  C(2, 2) = 195.99;
  C(3, 0) = 131.365;
  C(3, 1) = 184.24;
  C(3, 2) = 190.115;
  C(4, 0) = 172.49;
  C(4, 1) = 201.865;
  C(4, 2) = 254.74;
  int res = A.EqMatrix(C);
  ASSERT_EQ(res, OK);
}

TEST(MulNumber, test_2) {
  S21Matrix A(5, 5);
  A.FillSimpleMatrix();
  S21Matrix B(A);
  A.MulNumber(-45.32);
  B *= -45.32;
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(MulNumber, test_3) {
  S21Matrix A(7, 4);
  A.FillMatrix();
  S21Matrix B(A);
  A.MulNumber(324.001);
  B *= 324.001;
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(MulMatrix, test_1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);
  A.FillMatrix();
  B.FillSimpleMatrix();
  C = A * B;
  A.MulMatrix(B);
  int res = A.EqMatrix(C);
  EXPECT_EQ(res, OK);
}

TEST(MulMatrix, test_2) {
  S21Matrix A(4, 5);
  S21Matrix B(5, 4);
  S21Matrix C(4, 4);
  A.FillMatrix();
  B.FillMatrix();
  C = A * B;
  A.MulMatrix(B);
  int res = A.EqMatrix(C);
  EXPECT_EQ(res, OK);
}

TEST(MulMatrix, test_3) {
  S21Matrix A(2, 5);
  S21Matrix B(4, 2);
  EXPECT_THROW(A.MulMatrix(B), std::exception);
}

TEST(MulMatrix, test_4) {
  S21Matrix A(5, 1);
  S21Matrix B(2, 1);
  EXPECT_THROW(A.MulMatrix(B), std::exception);
}

TEST(MulMatrix, test_5) {
  S21Matrix A(5, 5);
  S21Matrix B(1, 5);
  EXPECT_THROW(A.MulMatrix(B), std::exception);
}

TEST(Transpose, test_1) {
  S21Matrix A(7, 2);
  S21Matrix B(1, 1);
  S21Matrix C(2, 7);
  C(0, 0) = 0.34;
  C(1, 0) = 1.59;
  C(0, 1) = 1.84;
  C(1, 1) = 4.09;
  C(0, 2) = 3.34;
  C(1, 2) = 4.59;
  C(0, 3) = 4.84;
  C(1, 3) = 7.09;
  C(0, 4) = 6.34;
  C(1, 4) = 7.59;
  C(0, 5) = 7.84;
  C(1, 5) = 10.09;
  C(0, 6) = 9.34;
  C(1, 6) = 10.59;
  A.FillMatrix();
  B = A.Transpose();
  int res = B.EqMatrix(C);
  EXPECT_EQ(res, OK);
}

TEST(Transpose, test_2) {
  S21Matrix A(4, 4);
  S21Matrix B(1, 1);
  S21Matrix C(4, 4);
  A.FillMatrix();
  B = A.Transpose();
  C(0, 0) = 0.34;
  C(0, 1) = 2.34;
  C(0, 2) = 4.34;
  C(0, 3) = 6.34;
  C(1, 0) = 1.59;
  C(1, 1) = 4.59;
  C(1, 2) = 5.59;
  C(1, 3) = 8.59;
  C(2, 0) = 2.84;
  C(2, 1) = 5.84;
  C(2, 2) = 8.84;
  C(2, 3) = 8.84;
  C(3, 0) = 4.09;
  C(3, 1) = 7.09;
  C(3, 2) = 10.09;
  C(3, 3) = 13.09;
  int res = B.EqMatrix(C);
  EXPECT_EQ(res, OK);
}

TEST(CalcComplements, test_1) {
  S21Matrix A(4, 4);
  S21Matrix B(1, 1);
  S21Matrix C(4, 4);
  C(0, 0) = 12.54;
  C(0, 1) = 21.48;
  C(0, 2) = 14.32;
  C(0, 3) = -29.84;
  C(1, 0) = 27.96;
  C(1, 1) = -42.96;
  C(1, 2) = -14.32;
  C(1, 3) = 24.32;
  C(2, 0) = -15;
  C(2, 1) = 21.48;
  C(2, 2) = -14.32;
  C(2, 3) = 2.84;
  C(3, 0) = -7.5;
  C(3, 1) = 0;
  C(3, 2) = 14.32;
  C(3, 3) = -9.32;
  A.FillMatrix();
  B = A.CalcComplements();
  int res = B.EqMatrix(C);
  EXPECT_EQ(res, OK);
}

TEST(CalcComplements, test_2) {
  S21Matrix A(5, 5);
  S21Matrix B(1, 1);
  S21Matrix C(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A(i, j) = i ^ j;
    }
  }
  C(0, 0) = -224;
  C(0, 1) = 224;
  C(0, 2) = 224;
  C(0, 3) = -224;
  C(0, 4) = 0;
  C(1, 0) = 224;
  C(1, 1) = -224;
  C(1, 2) = -224;
  C(1, 3) = 224;
  C(1, 4) = 0;
  C(2, 0) = 224;
  C(2, 1) = -224;
  C(2, 2) = -224;
  C(2, 3) = 224;
  C(2, 4) = 0;
  C(3, 0) = -224;
  C(3, 1) = 224;
  C(3, 2) = 224;
  C(3, 3) = -224;
  C(3, 4) = 0;
  C(4, 0) = 0;
  C(4, 1) = 0;
  C(4, 2) = 0;
  C(4, 3) = 0;
  C(4, 4) = 0;
  B = A.CalcComplements();
  int res = B.EqMatrix(C);
  EXPECT_EQ(res, OK);
}

TEST(CalcComplements, test_3) {
  S21Matrix A(5, 5);
  S21Matrix B(1, 1);
  S21Matrix C(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A(i, j) = 1;
    }
  }
  B = A.CalcComplements();
  int res = B.EqMatrix(C);
  EXPECT_EQ(res, OK);
}
TEST(CalcComplements, test_4) {
  S21Matrix A(3, 4);
  S21Matrix B(1, 1);
  EXPECT_THROW((B = A.CalcComplements()), std::exception);
}

TEST(CalcComplements, test_5) {
  S21Matrix A(7, 4);
  S21Matrix B(1, 1);
  EXPECT_THROW((B = A.CalcComplements()), std::exception);
}

TEST(Determinant, test_1) {
  S21Matrix A(7, 7);
  A.FillMatrix();
  double d = A.Determinant();
  EXPECT_NEAR(d, -14605.2, 1e-7L);
}

TEST(Determinant, test_2) {
  S21Matrix A(5, 5);
  A.FillSimpleMatrix();
  double d = A.Determinant();
  EXPECT_NEAR(d, 0, 1e-7L);
}

TEST(Determinant, test_3) {
  S21Matrix A(6, 6);
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      A(i, j) = i ^ j;
    }
  }
  double d = A.Determinant();
  EXPECT_NEAR(d, 0, 1e-7L);
}

TEST(Determinant, test_4) {
  S21Matrix A(6, 6);
  A.FillMatrix();
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      A(i, j) += i + j;
    }
  }
  double d = A.Determinant();
  EXPECT_NEAR(d, -4684.2, 1e-7L);
}

TEST(Determinant, test_5) {
  S21Matrix A(7, 3);
  EXPECT_THROW((A.Determinant()), std::exception);
}

TEST(InverseMatrix, test_1) {
  S21Matrix A(4, 4);
  S21Matrix B(1, 1);
  S21Matrix C(A);
  C(0, 0) = -0.333333;
  C(0, 1) = 0.333333;
  C(0, 2) = -0.666667;
  C(0, 3) = 0.666667;
  C(1, 0) = -0.166667;
  C(1, 1) = -0.333333;
  C(1, 2) = 1.16667;
  C(1, 3) = -0.666667;
  C(2, 0) = -0.333333;
  C(2, 1) = 0.333333;
  C(2, 2) = 0.333333;
  C(2, 3) = -0.333333;
  C(3, 0) = 0.611111;
  C(3, 1) = -0.111111;
  C(3, 2) = -0.611111;
  C(3, 3) = 0.444444;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A(i, j) = (i ^ j) + (i % (j + 1));
    }
  }
  B = A.InverseMatrix();
  int res = B.EqMatrix(C);
  EXPECT_EQ(res, ERROR);
}

TEST(InverseMatrix, test_2) {
  // S21Matrix A(4, 4);
  // S21Matrix B(1, 1);
}

TEST(InverseMatrix, test_3) {
  // S21Matrix A(7, 4);
  // S21Matrix B(1, 1);
}

TEST(InverseMatrix, test_4) {
  // S21Matrix A(7, 4);
  // S21Matrix B(1, 1);
}

TEST(InverseMatrix, test_5) {
  // S21Matrix A(7, 4);
  // S21Matrix B(1, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}