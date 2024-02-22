#include "model.h"

#include <math.h>

#include <cctype>
#include <cstring>
#include <iostream>

/* Check brackets */
void s21::Model::CheckBrackets(char *line) {
  Stack stack;
  while (*line != '\0') {
    if (*line == '(') {
      stack.Push(0, s21::Stack::Priority::kBracket, s21::Stack::Type::kOpBr);
    } else if (*line == ')') {
      if (stack.Empty()) {
        throw std::invalid_argument("CheckBrackets(): Brackets error!");
      } else {
        stack.Pop();
      }
    }
    line++;
  }
  if (!stack.Empty()) {
    throw std::invalid_argument("CheckBrackets(): Brackets error!");
  }
}

/* Parser line to stack */
s21::Stack s21::Model::Parser(char *line, double *X) {
  Stack stack;
  while (*line) {
    if (isdigit(*line) ||
        (strchr("+-", *line) && isdigit(*(line + 1)) &&
         (stack.Empty() || stack.GetType() == s21::Stack::Type::kOpBr))) {
      stack.Push(strtod(line, &line), s21::Stack::Priority::kNum,
                 s21::Stack::Type::kNum);
    } else if ((*line == '-') && (*(line + 1) == '(' || isdigit(*(line + 1))) &&
               (stack.Empty() ||
                (stack.GetType() == s21::Stack::Type::kOpBr))) {
      stack.Push(0, s21::Stack::Priority::kUnMin, s21::Stack::Type::kUnMin);
      line++;
    } else if (*line == '(' &&
               (stack.Empty() || IsArifmetic(&stack) || IsFunction(&stack) ||
                stack.GetType() == s21::Stack::Type::kOpBr)) {
      stack.Push(0, s21::Stack::Priority::kBracket, s21::Stack::Type::kOpBr);
      line++;
    } else if (strchr("cstal", *line) &&
               (stack.Empty() || IsArifmetic(&stack) ||
                stack.GetType() == s21::Stack::Type::kOpBr)) {
      CheckFunctions(stack, *&line);
    } else if ((strchr("-+/*^m", *line)) &&
               (stack.Empty() || (stack.GetType() == s21::Stack::Type::kNum) ||
                stack.GetType() == s21::Stack::Type::kClBr)) {
      CheckArifmeticOperations(stack, *&line);
    } else if (*line == 'x') {
      stack.Push(*X, s21::Stack::Priority::kNum, s21::Stack::Type::kNum);
      line++;
    } else if (*line == ')') {
      stack.Push(0, s21::Stack::Priority::kBracket, s21::Stack::Type::kClBr);
      line++;
    } else {
      throw std::invalid_argument("Parser(): Input error!");
    }
  }
  stack.TurnOver();
  return stack;
}

/* Translation to reverse polish notation */
void s21::Model::ReversePolishNotation(Stack &stack) {
  Stack support_stack, main_stack;
  while (!stack.Empty()) {
    if (stack.GetType() == s21::Stack::Type::kNum) {
      main_stack.Push(stack.Top());
    } else if (stack.GetType() > s21::Stack::Type::kNum &&
               stack.GetType() < s21::Stack::Type::kClBr) {
      if (!support_stack.Empty() &&
          support_stack.GetType() != s21::Stack::Type::kOpBr &&
          support_stack.GetPrority() >= stack.GetPrority()) {
        main_stack.Push(support_stack.Top());
        support_stack.Pop();
        support_stack.Push(stack.Top());
      } else {
        support_stack.Push(stack.Top());
      }
    } else if (stack.GetType() == s21::Stack::Type::kClBr) {
      while (support_stack.GetType() != s21::Stack::Type::kOpBr) {
        main_stack.Push(support_stack.Top());
        support_stack.Pop();
      }
      support_stack.Pop();  // delete open bracket
    }
    stack.Pop();
  }
  while (!support_stack.Empty()) {
    main_stack.Push(support_stack.Top());
    support_stack.Pop();
  }
  main_stack.TurnOver();
  stack = std::move(main_stack);
}

/* Calculate revers polish notation expression */
void s21::Model::Calculate(Stack &stack) {
  Stack support_stack;
  while (!stack.Empty()) {
    if (stack.GetType() == s21::Stack::Type::kNum) {
      support_stack.Push(stack.Top());
      stack.Pop();
    } else if (IsArifmetic(&stack)) {
      ComputeArifmeticOperations(stack, support_stack);
    } else if (IsFunction(&stack)) {
      ComputeFunctions(stack, support_stack);
    }
  }
  stack = std::move(support_stack);
  result_ = stack.GetValue();
}

/* Check functions */
void s21::Model::CheckFunctions(Stack &stack, char *&line) {
  size_t len = strlen(line);
  if (len >= 4 && !strncmp(line, "sin(", 4)) {
    stack.Push(0, s21::Stack::Priority::kFunction, s21::Stack::Type::kSin);
    line += 3;
  } else if (len >= 4 && !strncmp(line, "cos(", 4)) {
    stack.Push(0, s21::Stack::Priority::kFunction, s21::Stack::Type::kCos);
    line += 3;
  } else if (len >= 4 && !strncmp(line, "tan(", 4)) {
    stack.Push(0, s21::Stack::Priority::kFunction, s21::Stack::Type::kTan);
    line += 3;
  } else if (len >= 5 && !strncmp(line, "acos(", 5)) {
    stack.Push(0, s21::Stack::Priority::kFunction, s21::Stack::Type::kAcos);
    line += 4;
  } else if (len >= 5 && !strncmp(line, "asin(", 5)) {
    stack.Push(0, s21::Stack::Priority::kFunction, s21::Stack::Type::kAsin);
    line += 4;
  } else if (len >= 5 && !strncmp(line, "atan(", 5)) {
    stack.Push(0, s21::Stack::Priority::kFunction, s21::Stack::Type::kAtan);
    line += 4;
  } else if (len >= 5 && !strncmp(line, "sqrt(", 5)) {
    stack.Push(0, s21::Stack::Priority::kFunction, s21::Stack::Type::kSqrt);
    line += 4;
  } else if (len >= 3 && !strncmp(line, "ln(", 3)) {
    stack.Push(0, s21::Stack::Priority::kFunction, s21::Stack::Type::kLn);
    line += 2;
  } else if (len >= 4 && !strncmp(line, "log(", 4)) {
    stack.Push(0, s21::Stack::Priority::kFunction, s21::Stack::Type::kLog);
    line += 3;
  } else {
    throw std::invalid_argument("Undefine function!");
  }
}

/* Check arifmetic operations */
void s21::Model::CheckArifmeticOperations(Stack &stack, char *&line) {
  if (*line == '-') {
    stack.Push(0, s21::Stack::Priority::kSumSub, s21::Stack::Type::kSub);
  } else if (*line == '+') {
    stack.Push(0, s21::Stack::Priority::kSumSub, s21::Stack::Type::kSum);
  } else if (*line == '/') {
    stack.Push(0, s21::Stack::Priority::kMultDivMod, s21::Stack::Type::kDiv);
  } else if (*line == '*') {
    stack.Push(0, s21::Stack::Priority::kMultDivMod, s21::Stack::Type::kMult);
  } else if (*line == '^') {
    stack.Push(0, s21::Stack::Priority::kPow, s21::Stack::Type::kPow);
  } else if (strlen(line) >= 3 && !strncmp(line, "mod", 3)) {
    stack.Push(0, s21::Stack::Priority::kMultDivMod, s21::Stack::Type::kMod);
    line += 2;
  }
  line++;
}

/* Compute arifmetic operations */
void s21::Model::ComputeArifmeticOperations(Stack &stack,
                                            Stack &support_stack) {
  double value_2 = support_stack.GetValue();
  support_stack.Pop();
  double value_1 = support_stack.GetValue();
  support_stack.Pop();
  if (stack.GetType() == s21::Stack::Type::kSum) {
    value_1 = value_1 + value_2;
  } else if (stack.GetType() == s21::Stack::Type::kSub) {
    value_1 = value_1 - value_2;
  } else if (stack.GetType() == s21::Stack::Type::kMult) {
    value_1 = value_1 * value_2;
  } else if (stack.GetType() == s21::Stack::Type::kDiv) {
    if (fabs(value_2 - 0) < 1e-7) {
      throw std::invalid_argument(
          "ComputeArifmeticOperations(): Divizion by zero!");
    } else {
      value_1 = value_1 / value_2;
    }
  } else if (stack.GetType() == s21::Stack::Type::kPow) {
    value_1 = pow(value_1, value_2);
  } else if (stack.GetType() == s21::Stack::Type::kMod) {
    value_1 = fmod(value_1, value_2);
  }
  support_stack.Push(value_1, s21::Stack::Priority::kNum,
                     s21::Stack::Type::kNum);
  stack.Pop();
}

/* Check arifmetic */
bool s21::Model::IsArifmetic(Stack *stack) const {
  bool result = false;
  if (stack->GetType() > s21::Stack::Type::kNum &&
      stack->GetType() < s21::Stack::Type::kCos) {
    result = true;
  }
  return result;
}

/* Check function */
bool s21::Model::IsFunction(Stack *stack) const {
  bool result = false;
  if (stack->GetType() > s21::Stack::Type::kMod &&
      stack->GetType() < s21::Stack::Type::kOpBr) {
    result = true;
  }
  return result;
}

/* Compute functions */
void s21::Model::ComputeFunctions(Stack &stack, Stack &support_stack) {
  double value = support_stack.GetValue();
  support_stack.Pop();
  if (stack.GetType() == s21::Stack::Type::kCos) {
    value = cos(value);
  } else if (stack.GetType() == s21::Stack::Type::kSin) {
    value = sin(value);
  } else if (stack.GetType() == s21::Stack::Type::kTan) {
    value = tan(value);
  } else if (stack.GetType() == s21::Stack::Type::kAcos) {
    value = acos(value);
  } else if (stack.GetType() == s21::Stack::Type::kAsin) {
    value = asin(value);
  } else if (stack.GetType() == s21::Stack::Type::kAtan) {
    value = atan(value);
  } else if (stack.GetType() == s21::Stack::Type::kSqrt) {
    value = sqrt(value);
  } else if (stack.GetType() == s21::Stack::Type::kLn) {
    value = log(value);
  } else if (stack.GetType() == s21::Stack::Type::kLog) {
    value = log10(value);
  } else if (stack.GetType() == s21::Stack::Type::kUnMin) {
    value = -value;
  }
  support_stack.Push(value, s21::Stack::Priority::kNum, s21::Stack::Type::kNum);
  stack.Pop();
}
