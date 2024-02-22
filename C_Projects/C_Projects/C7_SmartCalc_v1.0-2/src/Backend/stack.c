#include "smart_calc_v1.0.h"

/* Помещение нового значения на вершину стека */
void push(STACKNODEPTR *top_ptr, double value, int priority, int type,
          int *error) {
  STACKNODEPTR new_ptr;
  new_ptr = malloc(sizeof(STACKNODE));
  new_ptr->data = malloc(sizeof(DATA));
  if (new_ptr != NULL && new_ptr->data != NULL) {
    new_ptr->data->value = value;
    new_ptr->data->priority = priority;
    new_ptr->data->type = type;
    new_ptr->next_ptr = *top_ptr;
    *top_ptr = new_ptr;
  } else {
    (*error) = ERROR_4;
    if (!is_empty(*top_ptr)) {
      destroy_stack(top_ptr);
    }
  }
}

/* Удаление узла на вершине стека */
void pop(STACKNODEPTR *top_ptr) {
  STACKNODEPTR temp_ptr;
  if (!is_empty(*top_ptr)) {
    temp_ptr = *top_ptr;
    *top_ptr = (*top_ptr)->next_ptr;
    free(temp_ptr->data);
    free(temp_ptr);
  }
}

/* Просмотр вершины стека */
DATAPTR peek(STACKNODEPTR top_ptr) {
  DATAPTR temp = {0};
  if (!is_empty(top_ptr)) {
    temp = top_ptr->data;
  }
  return temp;
}

/* Освобождение памяти стека */
void destroy_stack(STACKNODEPTR *current_ptr) {
  if (!is_empty(*current_ptr)) {
    STACKNODEPTR temp_ptr;
    while (!is_empty(*current_ptr)) {
      temp_ptr = *current_ptr;
      *current_ptr = (*current_ptr)->next_ptr;
      free(temp_ptr->data);
      free(temp_ptr);
    }
  }
}

/* Переворачиваем стек */
void turn_over_stack(STACKNODEPTR *stack_ptr, int *error) {
  STACKNODEPTR temp_1_ptr = NULL;
  while (!is_empty(*stack_ptr)) {
    push(&temp_1_ptr, (*stack_ptr)->data->value, (*stack_ptr)->data->priority,
         (*stack_ptr)->data->type, error);
    pop(stack_ptr);
  }
  *stack_ptr = temp_1_ptr;
}

/* Стек пуст */
int is_empty(STACKNODEPTR top_ptr) { return top_ptr == NULL; }