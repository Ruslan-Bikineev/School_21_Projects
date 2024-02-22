#ifndef CPP3_SMARTCALC_V2_0_2_SRC_STACK_H_
#define CPP3_SMARTCALC_V2_0_2_SRC_STACK_H_

#include <iostream>
#include <stack>

namespace s21 {

class Stack {
 public:
  enum class Type {
    kNum,
    kSum,
    kSub,
    kMult,
    kDiv,
    kPow,
    kMod,
    kCos,
    kSin,
    kTan,
    kAcos,
    kAsin,
    kAtan,
    kSqrt,
    kLn,
    kLog,
    kUnMin,
    kOpBr,
    kClBr
  };

  enum class Priority {
    kNum,
    kSumSub,
    kMultDivMod,
    kPow,
    kUnMin,
    kFunction,
    kBracket
  };

  typedef struct {
    double value;
    Stack::Priority priority;
    Stack::Type type;
  } Data;
  /*---------------------------CONSTRUCTORS--------------------------*/
  Stack() noexcept : data_(){};
  Stack(const Stack &other) noexcept : Stack() { data_ = other.data_; };
  Stack(Stack &&other) noexcept : Stack() { data_ = std::move(other.data_); };
  /*----------------------------FUNCTIONS----------------------------*/
  Stack &operator=(Stack &&) noexcept;
  Stack &operator=(const Stack &) noexcept;

  Stack::Type GetType() const;
  double GetValue() const;
  void PrintTop() noexcept;
  void TurnOver() noexcept;
  void Pop() { data_.pop(); };
  Stack::Priority GetPrority() const;
  Data Top() { return data_.top(); };
  bool Empty() const noexcept { return data_.empty(); };
  void Push(const double, const Stack::Priority, const Stack::Type) noexcept;
  void Swap(Stack &other) noexcept { data_.swap(other.data_); };
  void Push(const Data &new_data) noexcept { data_.push(new_data); };
  /*-----------------------------------------------------------------*/
 private:
  std::stack<Data> data_;
};

/* Return priority */
inline Stack::Priority Stack::GetPrority() const {
  if (data_.empty()) {
    throw std::out_of_range("GetPrority(): Stack is empty!");
  } else {
    return data_.top().priority;
  }
}

/* Return value in stack */
inline double Stack::GetValue() const {
  if (data_.empty()) {
    throw std::out_of_range("GetValue(): Stack is empty!");
  } else {
    return data_.top().value;
  }
}

/* Move stack */
inline Stack &Stack::operator=(Stack &&other) noexcept {
  data_ = std::move(other.data_);
  return *this;
}

/* Copy stack */
inline Stack &Stack::operator=(const Stack &other) noexcept {
  data_ = other.data_;
  return *this;
}

/* Return type of type */
inline Stack::Type Stack::GetType() const {
  if (data_.empty()) {
    throw std::out_of_range("GetType(): Stack is empty!");
  } else {
    return data_.top().type;
  }
}

/* Turn over stack */
inline void Stack::TurnOver() noexcept {
  Stack temp;
  while (!Empty()) {
    temp.Push(Top());
    Pop();
  }
  *this = std::move(temp);
}

/* Push data in stack */
inline void Stack::Push(const double v, const Stack::Priority p,
                        const Stack::Type o) noexcept {
  Data temp;
  temp.value = v;
  temp.priority = p;
  temp.type = o;
  data_.push(temp);
};

/* Print Top in stack */
inline void Stack::PrintTop() noexcept {
  if (!Empty()) {
    std::cout << "value: " << data_.top().value
              << " priority: " << static_cast<int>(data_.top().priority)
              << " type: " << static_cast<int>(data_.top().type) << std::endl;
  } else {
    std::cout << "Stack is empty!" << std::endl;
  }
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_2_SRC_STACK_H_