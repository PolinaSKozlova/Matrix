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
  //   ASSERT_TRUE(B(0, 0) != nullptr);
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
  A.SumMatrix(B);
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(SumMatrix, test_2) {
  S21Matrix A(3, 5);
  S21Matrix B(3, 5);
  A.FillMatrix();
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, OK);
}

TEST(SumMatrix, test_3) {
  S21Matrix A(8, 5);
  S21Matrix B(8, 5);
  A.FillSimpleMatrix();
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, ERROR);
}

TEST(SumMatrix, test_4) {
  S21Matrix A(5, 5);
  S21Matrix B(1, 5);
  ASSERT_THROW();
}

TEST(SumMatrix, test_5) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  A.FillSimpleMatrix();
  int res = A.EqMatrix(B);
  ASSERT_EQ(res, ERROR);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}