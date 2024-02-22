#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
TEST(EqTests, EqTest_1) {
  // Arrange
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.FillingMatrix(kModePosSequence);
  B.FillingMatrix(kModePosSequence);
  // Assert
  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(EqTests, EqTest_2) {
  // Arrange
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.FillingMatrix(kModePosSequence);
  // Assert
  ASSERT_FALSE(A == B);
}

TEST(EqTests, EqTest_3) {
  // Arrange
  S21Matrix A(3, 3);
  S21Matrix B(3, 2);
  // Assert
  ASSERT_FALSE(A.EqMatrix(B));
}