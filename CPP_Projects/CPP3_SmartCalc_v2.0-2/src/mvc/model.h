#ifndef CPP3_SMARTCALC_V2_0_2_SRC_MODEL_H_
#define CPP3_SMARTCALC_V2_0_2_SRC_MODEL_H_

#include <iostream>

#include "stack.h"

namespace s21 {
class Model : protected Stack {
 public:
  /*---------------------------CONSTRUCTORS--------------------------*/
  Model() : result_(0){};
  /*----------------------------FUNCTIONS----------------------------*/
  void Calculate(Stack &);
  void CheckBrackets(char *);
  Stack Parser(char *, double *);
  void ReversePolishNotation(Stack &x);
  double GetResult() const noexcept { return result_; };
  /*-----------------------------------------------------------------*/
 protected:
  bool IsArifmetic(Stack *) const;
  bool IsFunction(Stack *) const;
  void CheckFunctions(Stack &, char *&);
  void ComputeFunctions(Stack &, Stack &);
  void CheckArifmeticOperations(Stack &, char *&);
  void ComputeArifmeticOperations(Stack &, Stack &);
  /*-----------------------------------------------------------------*/
 private:
  double result_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_2_SRC_MODEL_H_