#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
/* Based sub function for matrix */
TEST(SubTests, SubTest_1) {
  // Arrange
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix Result(5, 5);
  A.FillingMatrix(kModeNegReversSequence);
  B.FillingMatrix(kModePosSequence);
  Result.FillingMatrix(kModeForResultNeg);
  // Act
  A.SubMatrix(B);
  // Assert
  ASSERT_TRUE(A.EqMatrix(Result));
}

/* Overload function -= for matrix */
TEST(SubTests, SubTest_2) {
  // Arrange
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix Result(5, 5);
  A.FillingMatrix(kModePosReversSequence);
  B.FillingMatrix(kModeNegSequence);
  Result.FillingMatrix(kModeForResultPos);
  // Act
  A -= B;
  // Assert
  ASSERT_TRUE(A.EqMatrix(Result));
}

/* Overload function - for matrix */
TEST(SubTests, SubTest_3) {
  // Arrange
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix Result(5, 5);
  A.FillingMatrix(kModePosReversSequence);
  B.FillingMatrix(kModeNegSequence);
  Result.FillingMatrix(kModeForResultPos);
  // Act
  S21Matrix D = A - B;
  // Assert
  ASSERT_TRUE(D.EqMatrix(Result));
}
/*------------------------NEGATIVE_TESTS--------------------------*/
TEST(SubTests, SubTest_4) {
  // Arrange
  S21Matrix A(4, 5);
  S21Matrix B(4, 4);
  // Accert
  ASSERT_THROW(A.SubMatrix(B), std::domain_error);
}

TEST(SubTests, SubTest_5) {
  // Arrange
  S21Matrix A(4, 8);
  S21Matrix B(1, 4);
  // Accert
  ASSERT_THROW(A -= B, std::domain_error);
}

TEST(SubTests, SubTest_6) {
  // Arrange
  S21Matrix A(4, 4);
  S21Matrix B(1, 4);
  // Accert
  ASSERT_THROW(S21Matrix Result = A - B, std::domain_error);
}