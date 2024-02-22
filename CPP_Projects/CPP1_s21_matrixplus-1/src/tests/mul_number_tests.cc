#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
/* Based MulNumber function for matrix */
TEST(MulNumberTests, MulNumberTest_1) {
  // Arrange
  S21Matrix A(5, 5);
  A.FillingMatrix(kModePosSequence);
  // Act
  A.MulNumber(0.0);
  // Assert
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), 0.0);
    }
  }
}

/* Overload function *= for matrix */
TEST(MulNumberTests, MulNumberTest_2) {
  // Arrange
  S21Matrix A(5, 5);
  A.FillingMatrix(kModePosSequence);
  S21Matrix Result(5, 5);
  Result.FillingMatrix(kModeNegSequence);
  // Act
  A *= -1;
  // Assert
  ASSERT_TRUE(A.EqMatrix(Result));
}

/* Overload function * for matrix */
TEST(MulNumberTests, MulNumberTest_3) {
  // Arrange
  S21Matrix A(5, 5);
  A.FillingMatrix(kModeNegSequence);
  S21Matrix Result(5, 5);
  Result.FillingMatrix(kModePosSequence);
  // Act
  S21Matrix B = A * -1;
  // Assert
  ASSERT_TRUE(B.EqMatrix(Result));
}