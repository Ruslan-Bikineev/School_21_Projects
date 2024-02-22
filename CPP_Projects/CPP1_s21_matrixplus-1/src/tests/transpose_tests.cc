#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
TEST(TransposeTests, TransposeTest_1) {
  // Arrange
  S21Matrix A(2, 3);
  A.FillingMatrix(kModePosSequence);
  const double kResult[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  // Act
  A.Transpose();
  // Assert
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), kResult[i - 1][j - 1]);
    }
  }
}
