#include "controller.h"

double s21::Controller::Calculator(char *line, double x) {
  model_->CheckBrackets(line);
  s21::Stack stack = model_->Parser(line, &x);
  model_->ReversePolishNotation(stack);
  model_->Calculate(stack);
  return model_->GetResult();
}