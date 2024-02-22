#include <gtest/gtest.h>
#include <math.h>

#include "../mvc/controller.h"

TEST(IncorrectInput, IncorrectBracket_1) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "((1+3)+4*5*6^7";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectBracket_2) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "(1+3)+4*(5*6^7";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectBracket_3) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "(1+3)+4*(5*6))^7";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectBracket_4) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "(1+3)+4*(5*6)^7)";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectInput_1) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "7*8+0++cos(1)";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectInput_2) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "7*-8+0+cos(1)";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectInput_3) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "7*8+0.916^^";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectInput_4) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "-(7*8)(-0.916)";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectInput_5) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "-(-7*8)((-0.916)+2)";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectInput_6) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "7sin(1)";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectInput_7) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "-(-(3+6))*2(3)";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectFunction_1) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "7*8+0.916+cos5";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(IncorrectInput, IncorrectFunction_2) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "7*8+0.916+cos(sin5)";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(DivisionToNull, DivisionToNull_1) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "ln(sin(2)+1.13154547)/x";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(DivisionToNull, DivisionToNull_2) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0.00000001;
  char line[] = "2mod1.13154547/x";
  // Act
  // Assert
  ASSERT_THROW(controller.Calculator(line, x), std::invalid_argument);
}

TEST(ResultNan, ResultNan) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 2.2531;
  char line[] = "atan(1.2*34)-asin(5.67)-log(8.90)*x";
  double result = atan(1.2 * 34) - asin(5.67) - log10(8.9) * x;
  // Act
  // Assert
  ASSERT_EQ(std::isnan(result), std::isnan(controller.Calculator(line, x)));
}

TEST(CorrectInput, CorrectInput_1) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "acos(1)+1.26531+(3+4.56)/5.15635*6.213^7";
  double result = acos(1) + 1.26531 + (3 + 4.56) / 5.15635 * pow(6.213, 7);
  // Act
  // Assert
  ASSERT_EQ(result, controller.Calculator(line, x));
}

TEST(CorrectInput, CorrectInput_2) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "sqrt(2.3*2)+1.55-2*(2.65+3^2)";
  double result = sqrt(2.3 * 2) + 1.55 - 2 * (2.65 + pow(3, 2));
  // Act
  // Assert
  ASSERT_EQ(result, controller.Calculator(line, x));
}

TEST(CorrectInput, CorrectInput_3) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "cos(sin(2)+1.13154547)*x";
  double result = cos(sin(2) + 1.13154547) * x;
  // Act
  // Assert
  ASSERT_EQ(result, controller.Calculator(line, x));
}

TEST(CorrectInput, CorrectInput_4) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "-(15514.135mod35.15548)-tan(-1.15)";
  double result = -(fmod(15514.135, 35.15548)) - tan(-1.15);
  // Act
  // Assert
  ASSERT_EQ(result, controller.Calculator(line, x));
}

TEST(CorrectInput, CorrectInput_5) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 5.3546;
  char line[] = "-(-1.135)-(+3.55+(-(cos(x))*(-(-4))))*x*6.5415^7";
  double result =
      -(-1.135) - (+3.55 + (-(cos(x)) * (-(-4)))) * x * pow(6.5415, 7);
  // Act
  // Assert
  ASSERT_EQ(result, controller.Calculator(line, x));
}

TEST(CorrectInput, CorrectInput_6) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "-(tan(atan(0.5)))+acos(0.05-(+0.003))-cos(3^2)";
  double result = -(tan(atan(0.5))) + acos(+0.05 - +0.003) - cos(pow(3, 2));
  // Act
  // Assert
  ASSERT_EQ(result, controller.Calculator(line, x));
}

TEST(CorrectInput, CorrectInput_7) {
  // Arrange
  s21::Model model;
  s21::Controller controller(&model);
  double x = 0;
  char line[] = "-5^5";
  double result = pow(-5, 5);
  // Act
  // Assert
  ASSERT_EQ(result, controller.Calculator(line, x));
}