#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
/* Based MulMatrix function for matrix */
TEST(MulMatrixTests, MulMatrixTest_1) {
  // Arrange
  S21Matrix A(2, 3);
  A.FillingMatrix(kModePosSequence);
  S21Matrix B(3, 2);
  B.FillingMatrix(kModeNegSequence);
  const double kResult[2][2] = {{-22, -28}, {-49, -64}};
  // Act
  A.MulMatrix(B);
  // Assert
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), kResult[i - 1][j - 1]);
    }
  }
}

/* Overload function *= for matrix */
TEST(MulMatrixTests, MulMatrixTest_2) {
  // Arrange
  S21Matrix A(3, 2);
  A.FillingMatrix(kModePosSequence);
  S21Matrix B(2, 3);
  B.FillingMatrix(kModeNegSequence);
  const double kResult[3][3] = {
      {-9, -12, -15}, {-19, -26, -33}, {-29, -40, -51}};
  // Act
  A *= B;
  // Assert
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), kResult[i - 1][j - 1]);
    }
  }
}

/* Overload function * for matrix */
TEST(MulMatrixTests, MulMatrixTest_3) {
  // Arrange
  S21Matrix A(3, 2);
  A.FillingMatrix(kModePosSequence);
  S21Matrix B(2, 3);
  B.FillingMatrix(kModeNegSequence);
  const double kResult[3][3] = {
      {-9, -12, -15}, {-19, -26, -33}, {-29, -40, -51}};
  // Act
  S21Matrix C = A * B;
  // Assert
  for (int i = 1; i < C.GetRows(); i++) {
    for (int j = 1; j < C.GetCols(); j++) {
      ASSERT_EQ(C(i, j), kResult[i - 1][j - 1]);
    }
  }
}
/*------------------------NEGATIVE_TESTS--------------------------*/
TEST(MulMatrixTests, MulMatrixTest_4) {
  // Arrange
  S21Matrix A(4, 4);
  S21Matrix B(3, 4);
  // Accert
  ASSERT_THROW(A.MulMatrix(B), std::domain_error);
}

TEST(MulMatrixTests, MulMatrixTest_5) {
  // Arrange
  S21Matrix A(4, 2);
  S21Matrix B(1, 3);
  // Accert
  ASSERT_THROW(A *= B, std::domain_error);
}

TEST(MulMatrixTests, MulMatrixTest_6) {
  // Arrange
  S21Matrix A(1, 2);
  S21Matrix B(4, 3);
  // Accert
  ASSERT_THROW(S21Matrix Result = A * B, std::domain_error);
}