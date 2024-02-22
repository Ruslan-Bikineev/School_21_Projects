#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
TEST(DeterminantTests, DeterminantTest_1) {
  // Arrange
  double result = 1, det = 0;
  S21Matrix A(1, 1);
  A.FillingMatrix(kModePosSequence);
  // Act
  det = A.Determinant();
  // Assert
  ASSERT_DOUBLE_EQ(det, result);
}

TEST(DeterminantTests, DeterminantTest_2) {
  // Arrange
  double result = -2, det = 0;
  S21Matrix A(2, 2);
  A.FillingMatrix(kModePosSequence);
  // Act
  det = A.Determinant();
  // Assert
  ASSERT_DOUBLE_EQ(det, result);
}

TEST(DeterminantTests, DeterminantTest_3) {
  // Arrange
  double result = -1, det = 0;
  S21Matrix A(3, 3);
  A.FillingMatrix(kModeInverseMatrix);
  // Act
  det = A.Determinant();
  // Assert
  ASSERT_DOUBLE_EQ(det, result);
}
/*------------------------NEGATIVE_TESTS--------------------------*/
TEST(DeterminantTests, DeterminantTest_4) {
  // Arrange
  S21Matrix A(4, 5);
  // Accert
  ASSERT_THROW(A.Determinant(), std::domain_error);
}