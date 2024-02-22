#include <math.h>

#include "./mvc/view.h"

int main() {
  // MODEL
  s21::Model model;
  s21::Controller controller(&model);
  s21::View view(&controller);
  view.Start();
 
  return 0;
}