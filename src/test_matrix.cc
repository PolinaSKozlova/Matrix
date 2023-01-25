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
  // EXPECT_ANY_THROW(A.SumMatrix(B));
  //   EXPECT_THROW(A.SumMatrix(B), std::runtime_error *);
}

TEST(SumMatrix, test_5) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
  //   EXPECT_ANY_THROW(A.SumMatrix(B));
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
  // EXPECT_ANY_THROW(A.SubMatrix(B));
}

TEST(SubMatrix, test_5) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
  //   EXPECT_ANY_THROW(A.SubMatrix(B));
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
  A.ShowMatrix();
  std::cout << std::endl;
  C.ShowMatrix();
  int res = A.EqMatrix(C);
  std::cout << std::endl;
  ASSERT_EQ(res, OK);
}

TEST(MulNumber, test_2) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
}

TEST(MulNumber, test_3) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
}

TEST(MulNumber, test_4) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
}

TEST(MulNumber, test_5) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
}

TEST(MulMatrix, test_1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
}

TEST(MulMatrix, test_2) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
}

TEST(MulMatrix, test_3) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
}

TEST(MulMatrix, test_4) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
}

TEST(MulMatrix, test_5) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 0);
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}