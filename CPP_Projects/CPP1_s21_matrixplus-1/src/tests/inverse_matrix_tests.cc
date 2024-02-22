#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
TEST(InverseMatrixTests, InverseMatrixTest_1) {
  // Arrange
  S21Matrix A(3, 3);
  A.FillingMatrix(kModeInverseMatrix);
  const double kResult[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  // Act
  A.InverseMatrix();
  // Assert
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), kResult[i - 1][j - 1]);
    }
  }
}

TEST(InverseMatrixTests, InverseMatrixTest_2) {
  // Arrange
  S21Matrix A(2, 2);
  A.FillingMatrix(kModePosSequence);
  const double kResult[2][2] = {{-2, 1}, {1.5, -0.5}};
  // Act
  A.InverseMatrix();
  // Assert
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), kResult[i - 1][j - 1]);
    }
  }
}
/*------------------------NEGATIVE_TESTS--------------------------*/
TEST(InverseMatrixTests, InverseMatrixTest_3) {
  // Arrange
  S21Matrix A(3, 3);
  A.FillingMatrix(kModePosSequence);
  // Accert
  ASSERT_THROW(A.InverseMatrix(), std::domain_error);
}