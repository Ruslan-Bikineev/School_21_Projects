#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
/* Copy function for matrix */
TEST(MoveCopyTests, MoveCopyTest_1) {
  // Arrange
  S21Matrix A(3, 3);
  A.FillingMatrix(kModePosSequence);
  S21Matrix B;
  // Act
  B = A;
  // Assert
  ASSERT_TRUE(A == B);
}

/* Move function for matrix */
TEST(MoveCopyTests, MoveCopyTest_2) {
  // Arrange
  S21Matrix A(4, 3);
  A.FillingMatrix(kModePosSequence);
  S21Matrix Result(4, 3);
  Result.FillingMatrix(kModePosSequence);
  S21Matrix B;
  // Act
  B = std::move(A);
  // Assert
  ASSERT_TRUE(B == Result);
}