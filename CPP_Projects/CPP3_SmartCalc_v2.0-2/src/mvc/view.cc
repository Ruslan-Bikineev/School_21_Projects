#include "view.h"

void s21::View::Start() {
  double x = 0;
  char line[100];
  std::cout << "Enter line: " << std::endl;
  std::cin >> line;
  std::cout << "Enter x: " << std::endl;
  std::cin >> x;
  std::cout << "Result: " << controller_->Calculator(line, x) << std::endl;
}