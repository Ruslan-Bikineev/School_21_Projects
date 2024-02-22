#ifndef CPP3_SMARTCALC_V2_0_2_SRC_SMARTCALC_VIEW_H_
#define CPP3_SMARTCALC_V2_0_2_SRC_SMARTCALC_VIEW_H_
#include "controller.h"

namespace s21 {

class View {
 public:
  View(Controller *controller) : controller_(controller){};
  void Start();

 private:
  Controller *controller_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_2_SRC_SMARTCALC_VIEW_H_