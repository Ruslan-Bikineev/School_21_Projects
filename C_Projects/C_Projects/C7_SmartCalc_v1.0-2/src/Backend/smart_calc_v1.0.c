#include "smart_calc_v1.0.h"

void smart_calc(char *str, int *error, double variable_x, double *result) {
  STACKNODEPTR stack_ptr = NULL;
  check_brackets(str, error);
  parser(&stack_ptr, str, variable_x, error);
  if (!(*error)) {
    turn_over_stack(&stack_ptr, error);
    polish_notation(&stack_ptr, error);
    turn_over_stack(&stack_ptr, error);
    calculate(&stack_ptr, result, error);
  }
}
