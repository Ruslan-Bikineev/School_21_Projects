#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
/* Based constructor, initialized matrix 1x1 */
TEST(ConstructorTests, ConstructorTest_1) {
  // Act
  S21Matrix A;
  // Assert
  ASSERT_EQ(A.GetRows(), 1);
  ASSERT_EQ(A.GetCols(), 1);
  ASSERT_DOUBLE_EQ(A(1, 1), 0.0);
}

/* Contructor with numbers of rows and cols */
TEST(ConstructorTests, ConstructorTest_2) {
  // Act
  S21Matrix A(4, 5);
  // Assert
  ASSERT_EQ(A.GetRows(), 4);
  ASSERT_EQ(A.GetCols(), 5);
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(A(i, j), 0.0);
    }
  }
}

/* Constructor copy */
TEST(ConstructorTests, ConstructorTest_3) {
  // Arrange
  S21Matrix A(3, 3);
  A.FillingMatrix(kModePosSequence);
  // Act
  S21Matrix B(A);
  // Assert
  ASSERT_EQ(B.GetRows(), 3);
  ASSERT_EQ(B.GetCols(), 3);
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(A(i, j), B(i, j));
    }
  }
}

/* Constructor move */
TEST(ConstructorTests, ConstructorTest_4) {
  // Arrange
  S21Matrix A(3, 3);
  A.FillingMatrix(kModePosSequence);
  // Act
  S21Matrix B(std::move(A));
  // Assert
  ASSERT_EQ(B.GetRows(), 3);
  ASSERT_EQ(B.GetCols(), 3);
  for (int i = 1, count = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(B(i, j), count++);
    }
  }
}
/*------------------------NEGATIVE_TESTS--------------------------*/
TEST(ConstructorTests, ConstructorTest_5) {
  // Assert
  ASSERT_THROW(S21Matrix A(-4, 1), std::bad_array_new_length);
}