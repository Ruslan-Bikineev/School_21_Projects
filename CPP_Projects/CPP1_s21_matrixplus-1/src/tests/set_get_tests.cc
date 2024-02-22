#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
TEST(SetGetTests, SetGetTest_1) {
  // Arrange
  S21Matrix A(2, 2);
  A.FillingMatrix(kModePosSequence);
  const double kResult[3][2] = {{1, 2}, {3, 4}, {0, 0}};
  // Act
  A.SetSize(3, A.GetCols());
  // Assert
  ASSERT_EQ(A.GetRows(), 3);
  ASSERT_EQ(A.GetCols(), 2);
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), kResult[i - 1][j - 1]);
    }
  }
}

TEST(SetGetTests, SetGetTest_2) {
  // Arrange
  S21Matrix A(3, 3);
  A.FillingMatrix(kModePosSequence);
  S21Matrix B(1, 3);
  B.FillingMatrix(kModePosSequence);
  // Act
  A.SetSize(1, A.GetCols());
  // Assert
  ASSERT_EQ(A.GetRows(), B.GetRows());
  ASSERT_EQ(A.GetCols(), B.GetCols());
  ASSERT_TRUE(A == B);
}

TEST(SetGetTests, SetGetTest_3) {
  // Arrange
  S21Matrix A(2, 2);
  A.FillingMatrix(kModePosSequence);
  const double kResult[2][3] = {{1, 2, 0}, {3, 4, 0}};
  // Act
  A.SetSize(A.GetRows(), 3);
  // Assert
  ASSERT_EQ(A.GetRows(), 2);
  ASSERT_EQ(A.GetCols(), 3);
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), kResult[i - 1][j - 1]);
    }
  }
}

TEST(SetGetTests, SetGetTest_4) {
  // Arrange
  S21Matrix A(3, 3);
  A.FillingMatrix(kModePosSequence);
  const double kResult[3][2] = {{1, 2}, {4, 5}, {7, 8}};
  // Act
  A.SetSize(A.GetRows(), 2);
  // Assert
  ASSERT_EQ(A.GetRows(), 3);
  ASSERT_EQ(A.GetCols(), 2);
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), kResult[i - 1][j - 1]);
    }
  }
}

TEST(SetGetTests, SetGetTest_5) {
  // Arrange
  const S21Matrix A(3, 3);
  // Act
  double number = A(1, 1);
  // Assert
  ASSERT_EQ(number, A(1, 1));
}

TEST(SetGetTests, SetGetTest_6) {
  // Arrange
  S21Matrix A(3, 3);
  A.FillingMatrix(kModePosSequence);
  // Act
  A(1, 1) = 400;
  // Assert
  ASSERT_EQ(400, A(1, 1));
}
/*------------------------NEGATIVE_TESTS--------------------------*/
TEST(SetGetTests, SetGetTest_7) {
  // Arrange
  S21Matrix A(4, 4);
  // Accert
  ASSERT_THROW(A.SetSize(0, A.GetCols()), std::invalid_argument);
}

TEST(SetGetTests, SetGetTest_8) {
  // Arrange
  S21Matrix A(4, 4);
  // Accert
  ASSERT_THROW(A.SetSize(A.GetRows(), -1), std::invalid_argument);
}

TEST(SetGetTests, SetGetTest_9) {
  // Arrange
  S21Matrix A(4, 4);
  // Accert
  ASSERT_THROW(A(4, 5), std::out_of_range);
}

TEST(SetGetTests, SetGetTest_10) {
  // Arrange
  S21Matrix A(4, 4);
  // Accert
  ASSERT_THROW(A(0, 5), std::out_of_range);
}

TEST(SetGetTests, SetGetTest_11) {
  // Arrange
  const S21Matrix A(3, 5);
  // Accert
  ASSERT_THROW(A(0, 5), std::out_of_range);
}