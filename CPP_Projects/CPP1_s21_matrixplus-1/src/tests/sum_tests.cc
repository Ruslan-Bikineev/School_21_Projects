#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
/* Based sum function for matrix */
TEST(SumTests, SumTest_1) {
  // Arrange
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix Result(5, 5);
  A.FillingMatrix(kModePosSequence);
  B.FillingMatrix(kModePosReversSequence);
  Result.FillingMatrix(kModeForResultPos);
  // Act
  A.SumMatrix(B);
  // Assert
  ASSERT_TRUE(A.EqMatrix(Result));
}

/* Overload function += for matrix */
TEST(SumTests, SumTest_2) {
  // Arrange
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix Result(5, 5);
  A.FillingMatrix(kModeNegSequence);
  B.FillingMatrix(kModeNegReversSequence);
  Result.FillingMatrix(kModeForResultNeg);
  // Act
  A += B;
  // Assert
  ASSERT_TRUE(A.EqMatrix(Result));
}

/* Overload function + for matrix */
TEST(SumTests, SumTest_3) {
  // Arrange
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix Result(5, 5);
  A.FillingMatrix(kModeNegSequence);
  B.FillingMatrix(kModeNegReversSequence);
  Result.FillingMatrix(kModeForResultNeg);
  // Act
  S21Matrix D = A + B;
  // Assert
  ASSERT_TRUE(D.EqMatrix(Result));
}
/*------------------------NEGATIVE_TESTS--------------------------*/
TEST(SumTests, SumTest_4) {
  // Arrange
  S21Matrix A(4, 5);
  S21Matrix B(4, 4);
  // Accert
  ASSERT_THROW(A.SumMatrix(B), std::domain_error);
}

TEST(SumTests, SumTest_5) {
  // Arrange
  S21Matrix A(4, 8);
  S21Matrix B(1, 4);
  // Accert
  ASSERT_THROW(A += B, std::domain_error);
}

TEST(SumTests, SumTest_6) {
  // Arrange
  S21Matrix A(4, 4);
  S21Matrix B(1, 4);
  // Accert
  ASSERT_THROW(S21Matrix Result = A + B, std::domain_error);
}