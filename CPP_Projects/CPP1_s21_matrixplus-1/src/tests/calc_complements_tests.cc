#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/*------------------------POSITIVE_TESTS--------------------------*/
TEST(CalcComplementsTests, CalcComplementsTests_1) {
  // Arrange
  S21Matrix A(3, 3);
  A.FillingMatrix(kModeCalcComplements);
  const double kResult[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  // Act
  A.CalcComplements();
  // Assert
  for (int i = 1; i < A.GetRows(); i++) {
    for (int j = 1; j < A.GetCols(); j++) {
      ASSERT_EQ(A(i, j), kResult[i - 1][j - 1]);
    }
  }
}
/*------------------------NEGATIVE_TESTS--------------------------*/
TEST(CalcComplementsTests, CalcComplementsTests_2) {
  // Arrange
  S21Matrix A(4, 5);
  // Accert
  ASSERT_THROW(A.CalcComplements(), std::domain_error);
}