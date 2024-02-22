#ifndef CPP3_SMARTCALC_V2_0_2_SRC_CONTROLLER_
#define CPP3_SMARTCALC_V2_0_2_SRC_CONTROLLER_

#include "model.h"

namespace s21 {

class Controller {
 public:
  Controller(Model *model) : model_(model){};
  double Calculator(char *, double);

 private:
  Model *model_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_2_SRC_CONTROLLER_