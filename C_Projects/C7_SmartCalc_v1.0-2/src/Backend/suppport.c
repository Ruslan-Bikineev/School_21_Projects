#include "smart_calc_v1.0.h"

/* Проверка на количество и расположение скобок */
void check_brackets(char *str, int *error) {
  int count = 0;
  while (*str && !(*error)) {
    if ((*str) == '(') {
      count++;
    } else if ((*str) == ')') {
      if (count > 0) {
        count--;
      } else {
        (*error) = ERROR_1;
        count = -1;
      }
    }
    str++;
  }
  (*error) = (count == 0) ? OK : ERROR_1;
}

/* Парсим входную строку в стек */
void parser(STACKNODEPTR *stack_ptr, char *str, double variable_x, int *error) {
  if (strlen(str) < 1) {
    (*error) = ERROR_2;
  }
  while (*str && !(*error)) {
    if (is_digit(str)) {
      push(stack_ptr, strtod(str, &str), 0, 0, error);
    } else if (*str == '-' && is_empty(*stack_ptr) &&
               (*(str + 1) == '(' || is_digit(str + 1))) {
      push(stack_ptr, 0, 4, UNARNY_MINUS, error);
      str++;
    } else if (*str == '(') {
      push(stack_ptr, 0, 6, OPEN_BRACKET, error);
      str++;
      if (strchr("+-", *str) && is_digit(str + 1)) {
        push(stack_ptr, strtod(str, &str), 0, 0, error);
      }
    } else if (strchr("cstalm", *str)) {
      check_functions(stack_ptr, &str, error);
    } else if ((strchr("-+/*^", *str))) {
      check_arifmetic_operations(stack_ptr, &str, error);
    } else if (*str == 'x') {
      push(stack_ptr, variable_x, 0, 0, error);
      str++;
    } else if (*str == ')') {
      push(stack_ptr, 0, 6, CLOSE_BRACKET, error);
      str++;
    } else {
      (*error) = ERROR_2;
      destroy_stack(stack_ptr);
    }
  }
}
/* Проверка числа */
bool is_digit(char *str) { return (*str > 47 && *str < 58) ? 1 : 0; }

/* Проверка функций */
void check_functions(STACKNODEPTR *stack_ptr, char **str, int *error) {
  int len = strlen(*str);
  if (len >= 4 && !strncmp(*str, "sin(", 4)) {
    push(stack_ptr, 0, 5, SIN, error);
    (*str) += 3;
  } else if (len >= 4 && !strncmp(*str, "cos(", 4)) {
    push(stack_ptr, 0, 5, COS, error);
    (*str) += 3;
  } else if (len >= 4 && !strncmp(*str, "tan(", 4)) {
    push(stack_ptr, 0, 5, TAN, error);
    (*str) += 3;
  } else if (len >= 5 && !strncmp(*str, "acos(", 5)) {
    push(stack_ptr, 0, 5, ACOS, error);
    (*str) += 4;
  } else if (len >= 5 && !strncmp(*str, "asin(", 5)) {
    push(stack_ptr, 0, 5, ASIN, error);
    (*str) += 4;
  } else if (len >= 5 && !strncmp(*str, "atan(", 5)) {
    push(stack_ptr, 0, 5, ATAN, error);
    (*str) += 4;
  } else if (len >= 5 && !strncmp(*str, "sqrt(", 5)) {
    push(stack_ptr, 0, 5, SQRT, error);
    (*str) += 4;
  } else if (len >= 3 && !strncmp(*str, "ln(", 3)) {
    push(stack_ptr, 0, 5, LN, error);
    (*str) += 2;
  } else if (len >= 4 && !strncmp(*str, "log(", 4)) {
    push(stack_ptr, 0, 5, LOG, error);
    (*str) += 3;
  } else if (len >= 3 && !strncmp(*str, "mod", 3)) {
    push(stack_ptr, 0, 2, MOD, error);
    (*str) += 3;
  } else {
    (*error) = ERROR_2;
  }
}

/* Проверка арифметических операторов */
void check_arifmetic_operations(STACKNODEPTR *stack_ptr, char **str,
                                int *error) {
  if (**str == '-') {
    push(stack_ptr, 0, 1, SUB, error);
    (*str)++;
  } else if (**str == '+') {
    push(stack_ptr, 0, 1, ADD, error);
    (*str)++;
  } else if (**str == '/') {
    push(stack_ptr, 0, 2, DIV, error);
    (*str)++;
  } else if (**str == '*') {
    push(stack_ptr, 0, 2, MULT, error);
    (*str)++;
  } else if (**str == '^') {
    push(stack_ptr, 0, 3, POW, error);
    (*str)++;
  }
}

/* Перевод в обратную польскую нотацию */
void polish_notation(STACKNODEPTR *stack_ptr, int *error) {
  STACKNODEPTR support_ptr = NULL, main_ptr = NULL;
  DATAPTR temp;
  while (!is_empty(*stack_ptr)) {
    if ((*stack_ptr)->data->type == NUMBER) {
      push(&main_ptr, (*stack_ptr)->data->value, 0, 0, error);
    } else if ((*stack_ptr)->data->type > 0 && (*stack_ptr)->data->type < 18) {
      temp = peek(support_ptr);
      if (temp != NULL && temp->type != OPEN_BRACKET &&
          temp->priority >= (*stack_ptr)->data->priority) {
        push(&main_ptr, 0, temp->priority, temp->type, error);
        pop(&support_ptr);
        push(&support_ptr, 0, (*stack_ptr)->data->priority,
             (*stack_ptr)->data->type, error);
      } else {
        push(&support_ptr, 0, (*stack_ptr)->data->priority,
             (*stack_ptr)->data->type, error);
      }
    } else if ((*stack_ptr)->data->type == CLOSE_BRACKET) {
      while (support_ptr->data->type != OPEN_BRACKET) {
        push(&main_ptr, support_ptr->data->value, support_ptr->data->priority,
             support_ptr->data->type, error);
        pop(&support_ptr);
      }
      pop(&support_ptr);  // удаляем открытую скобку
    }
    pop(stack_ptr);
  }
  while (!is_empty(support_ptr)) {
    push(&main_ptr, 0, support_ptr->data->priority, support_ptr->data->type,
         error);
    pop(&support_ptr);
  }
  *stack_ptr = main_ptr;
}

/* Вычисление */
void calculate(STACKNODEPTR *stack_ptr, double *result, int *error) {
  STACKNODEPTR support = NULL;
  while (!is_empty(*stack_ptr) && !(*error)) {
    if ((*stack_ptr)->data->type == NUMBER) {
      push(&support, (*stack_ptr)->data->value, 0, 0, error);
      pop(stack_ptr);
    } else if ((*stack_ptr)->data->type > 0 && (*stack_ptr)->data->type < 7) {
      compute_arifmetic_operations(stack_ptr, &support, error);
    } else if ((*stack_ptr)->data->type > 6 && (*stack_ptr)->data->type < 17) {
      compute_functions(stack_ptr, &support, error);
    }
  }
  if ((*error)) {
    destroy_stack(stack_ptr);
    destroy_stack(&support);
  } else {
    *stack_ptr = support;
    (*result) = (*stack_ptr)->data->value;
    destroy_stack(stack_ptr);
  }
}

/* Вычисление арифметических операций */
void compute_arifmetic_operations(STACKNODEPTR *stack_ptr,
                                  STACKNODEPTR *support, int *error) {
  double result = 0;
  double value_2 = data_value_return(support, error);
  double value_1 = data_value_return(support, error);
  if ((*stack_ptr)->data->type == ADD) {
    result = value_1 + value_2;
    push(support, result, 0, 0, error);
  } else if ((*stack_ptr)->data->type == SUB) {
    result = value_1 - value_2;
    push(support, result, 0, 0, error);
  } else if ((*stack_ptr)->data->type == MULT) {
    result = value_1 * value_2;
    push(support, result, 0, 0, error);
  } else if ((*stack_ptr)->data->type == DIV) {
    if (fabs(value_2 - 0) < PRECISION) {
      (*error) = ERROR_3;
    } else {
      result = value_1 / value_2;
      push(support, result, 0, 0, error);
    }
  } else if ((*stack_ptr)->data->type == POW) {
    push(support, pow(value_1, value_2), 0, 0, error);
  } else if ((*stack_ptr)->data->type == MOD) {
    push(support, fmod(value_1, value_2), 0, 0, error);
  }
  pop(stack_ptr);
}

/* Вычисление функций */
void compute_functions(STACKNODEPTR *stack_ptr, STACKNODEPTR *support,
                       int *error) {
  double value = (*support)->data->value;
  pop(support);
  if ((*stack_ptr)->data->type == COS) {
    push(support, cos(value), 0, 0, error);
  } else if ((*stack_ptr)->data->type == SIN) {
    push(support, sin(value), 0, 0, error);
  } else if ((*stack_ptr)->data->type == TAN) {
    push(support, tan(value), 0, 0, error);
  } else if ((*stack_ptr)->data->type == ACOS) {
    push(support, acos(value), 0, 0, error);
  } else if ((*stack_ptr)->data->type == ASIN) {
    push(support, asin(value), 0, 0, error);
  } else if ((*stack_ptr)->data->type == ATAN) {
    push(support, atan(value), 0, 0, error);
  } else if ((*stack_ptr)->data->type == SQRT) {
    push(support, sqrt(value), 0, 0, error);
  } else if ((*stack_ptr)->data->type == LN) {
    push(support, log(value), 0, 0, error);
  } else if ((*stack_ptr)->data->type == LOG) {
    push(support, log10(value), 0, 0, error);
  } else if ((*stack_ptr)->data->type == UNARNY_MINUS) {
    push(support, -value, 0, 0, error);
  }
  pop(stack_ptr);
}

/* return data->value and pop this data */
double data_value_return(STACKNODEPTR *stack_ptr, int *error) {
  DATAPTR val;
  double result = 0;
  if (!is_empty(*stack_ptr)) {
    val = peek(*stack_ptr);
    result = val->value;
    pop(stack_ptr);
  } else {
    (*error) = ERROR_2;
  }
  return result;
}