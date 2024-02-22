#ifndef CPP2_S21_CONTAINERS_4_SRC_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_4_SRC_STACK_S21_STACK_H_

#include "../list/s21_list.h"

namespace s21 {

template <typename T>
class Stack : protected List<T> {
 public:
  /*--------------------------MEMBER_TYPES---------------------------*/
  using ValueType = T;
  using Reference = ValueType &;
  using SizeType = size_t;
  using ConstReference = const ValueType &;
  /*--------------------------CONSTRUCTORS---------------------------*/
  Stack() noexcept;
  Stack(Stack &&) noexcept;
  Stack(const Stack &) noexcept;
  Stack(std::initializer_list<ValueType> const &) noexcept;
  /*----------------------------FUNCTIONS----------------------------*/
  Stack<ValueType> &operator=(Stack<ValueType> &&) noexcept;
  Stack<ValueType> &operator=(const Stack<ValueType> &) noexcept;

  void Pop() noexcept;
  ConstReference Top();
  bool Empty() noexcept;
  SizeType Size() noexcept;
  void PrintStack() noexcept;
  void Swap(Stack &) noexcept;
  void Push(ConstReference) noexcept;
};
/*----------------------------------------------------------------------------*/
#include "s21_stack.tpp"
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_4_SRC_STACK_S21_STACK_H_