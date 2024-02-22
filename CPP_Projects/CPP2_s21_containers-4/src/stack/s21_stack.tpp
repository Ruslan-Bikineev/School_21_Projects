/*----------------------------------------------------------------------------*/
/* Default constructor, creates empty stack */
template <typename ValueType>
s21::Stack<ValueType>::Stack() noexcept : List<ValueType>(){};

/* Initializer list constructor, creates stack initizialized using
 * std::initializer_list */
template <typename ValueType>
s21::Stack<ValueType>::Stack(
    std::initializer_list<ValueType> const &items) noexcept
    : List<ValueType>::List(items) {}

/* Copy constructor */
template <typename ValueType>
s21::Stack<ValueType>::Stack(const Stack &s) noexcept : Stack<ValueType>() {
  *this = s;
}

/* Move constructor */
template <typename ValueType>
s21::Stack<ValueType>::Stack(Stack &&s) noexcept : Stack<ValueType>() {
  *this = std::move(s);
}
/*----------------------------------------------------------------------------*/
/* Copy stack */
template <typename ValueType>
s21::Stack<ValueType> &s21::Stack<ValueType>::operator=(
    const Stack<ValueType> &other) noexcept {
  static_cast<List<ValueType> &>(*this) = other;
  return *this;
}

/* Move stack */
template <typename ValueType>
s21::Stack<ValueType> &s21::Stack<ValueType>::operator=(
    Stack<ValueType> &&other) noexcept {
  static_cast<List<ValueType> &>(*this) = std::move(other);
  return *this;
}

/* Returns the number of elements */
template <typename ValueType>
typename s21::Stack<ValueType>::SizeType
s21::Stack<ValueType>::Size() noexcept {
  return List<ValueType>::Size();
}

/* Removes the top element */
template <typename ValueType>
void s21::Stack<ValueType>::Pop() noexcept {
  List<ValueType>::PopBack();
}

/* Swaps the contents */
template <typename ValueType>
void s21::Stack<ValueType>::Swap(Stack &other) noexcept {
  List<ValueType>::Swap(other);
}

/* Accesses the top element */
template <typename ValueType>
typename s21::Stack<ValueType>::ConstReference s21::Stack<ValueType>::Top() {
  if (Empty()) {
    throw std::out_of_range("Stack is empty!");
  }
  return List<ValueType>::Back();
}

/* Inserts element at the top */
template <typename ValueType>
void s21::Stack<ValueType>::Push(ConstReference value) noexcept {
  List<ValueType>::PushBack(value);
}

/* Checks whether the container is empty */
template <typename ValueType>
bool s21::Stack<ValueType>::Empty() noexcept {
  return List<ValueType>::Empty();
}

/* Print stack  */
template <typename ValueType>
void s21::Stack<ValueType>::PrintStack() noexcept {
  std::cout << std::endl;
  if (Empty()) {
    std::cout << "Stack is empty!\n";
  } else {
    Stack<ValueType> temp(*this);
    while (!temp.Empty()) {
      std::cout << temp.Top() << "->";
      temp.Pop();
    }
    std::cout << "NULL"
              << "\nSize: " << Size() << std::endl;
  }
}
