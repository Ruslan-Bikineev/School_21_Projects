/*----------------------------------------------------------------------------*/
/* Default constructor, creates empty list */
template <typename ValueType>
s21::List<ValueType>::List() noexcept {
  NodeToNull(&last_);
  head_ = tail_ = &last_;
}

/* Parameterized constructor, creates the list of size n */
template <typename ValueType>
s21::List<ValueType>::List(SizeType n) noexcept : List<ValueType>() {
  for (SizeType i = 0; i < n; i++) {
    PushFront(0);
  }
  NodeToNull(&last_);
  last_.prev_ = tail_;
  tail_->next_ = &last_;
}

/* Constructor with initializer list */
template <typename ValueType>
s21::List<ValueType>::List(
    std::initializer_list<ValueType> const &items) noexcept
    : List<ValueType>() {
  for (auto item : items) {
    PushBack(item);
  }
}

/* Copy constructor */
template <typename ValueType>
s21::List<ValueType>::List(const List &l) noexcept : List<ValueType>() {
  *this = l;
}

/* Move constructor */
template <typename ValueType>
s21::List<ValueType>::List(List &&l) noexcept : List<ValueType>() {
  *this = std::move(l);
}

/* Destructor*/
template <typename ValueType>
s21::List<ValueType>::~List() {
  Clear();
}
/*----------------------------------------------------------------------------*/
/* Copy list */
template <typename ValueType>
s21::List<ValueType> &s21::List<ValueType>::operator=(
    const s21::List<ValueType> &other) noexcept {
  if (this != &other) {
    if (!other.Empty()) {
      auto it = Begin();
      for (auto other_it = other.Begin(); other_it != other.End(); other_it++) {
        if (it == End()) {
          PushBack(*other_it);
        } else {
          *it++ = *other_it;
        }
      }
    } else {
      Clear();
      head_ = tail_ = &last_;
    }
  }
  return *this;
}

/* Move list */
template <typename ValueType>
s21::List<ValueType> &s21::List<ValueType>::operator=(
    s21::List<ValueType> &&other) noexcept {
  Clear();
  Swap(other);
  return *this;
}

/* Adds an element to the end */
template <typename ValueType>
void s21::List<ValueType>::PushFront(ConstReference value) noexcept {
  Node<ValueType> *node = new Node<ValueType>;
  node->data_ = value;
  node->next_ = head_;
  node->prev_ = nullptr;
  if (!Empty()) {
    head_->prev_ = node;
    head_ = node;
  } else {
    tail_ = head_ = node;
    last_.prev_ = tail_;
  }
  last_.next_ = head_;
  head_->prev_ = &last_;
}

/* Adds an element to the end */
template <typename ValueType>
void s21::List<ValueType>::PushBack(ConstReference value) noexcept {
  Node<ValueType> *node = new Node<ValueType>;
  node->data_ = value;
  node->next_ = &last_;
  node->prev_ = tail_;
  if (!Empty()) {
    tail_->next_ = node;
    tail_ = node;
  } else {
    node->prev_ = nullptr;
    head_ = tail_ = node;
  }
  last_.prev_ = tail_;
  last_.next_ = head_;
  head_->prev_ = &last_;
}

/* Transfers elements from list other starting from pos */
template <typename ValueType>
void s21::List<ValueType>::Splice(ConstIterator pos,
                                  s21::List<ValueType> &other) noexcept {
  if (!other.Empty()) {
    if (pos == Begin()) {
      other.tail_->next_ = head_;
      head_->prev_ = other.tail_;
      head_ = other.head_;
    } else if (pos == End()) {
      tail_->next_ = other.head_;
      other.head_->prev_ = tail_;
      other.tail_->next_ = &last_;
      tail_ = last_.prev_ = other.tail_;
    } else {
      pos.current_->prev_->next_ = other.head_;
      other.head_->prev_ = pos.current_->prev_;
      pos.current_->prev_ = other.tail_;
      other.tail_->next_ = pos.current_;
    }
    other.head_ = other.tail_ = &other.last_;
  }
}

/* Inserts element into concrete pos and returns the Iterator that points to the
 * new element */
template <typename ValueType>
typename s21::List<ValueType>::Iterator s21::List<ValueType>::Insert(
    Iterator it, ConstReference value) noexcept {
  Node<ValueType> *result = nullptr;
  if (it == Begin()) {
    PushFront(value);
    result = head_;
  } else if (it == End()) {
    PushBack(value);
    result = tail_;
  } else {
    Node<ValueType> *node = new Node<ValueType>;
    node->data_ = value;
    node->next_ = it.current_;
    node->prev_ = it.current_->prev_;
    node->prev_->next_ = node->next_->prev_ = node;
    result = node;
  }
  return Iterator(result);
}

/* Removes consecutive duplicate elements */
template <typename ValueType>
void s21::List<ValueType>::Unique() noexcept {
  if (!Empty()) {
    auto it = Begin();
    for (it++; it != End();) {
      if (*it == it.current_->prev_->data_) {
        it++;
        Erase(it.current_->prev_->prev_);
      } else {
        it++;
      }
    }
  }
}

/* Reverses the order of the elements */
template <typename ValueType>
void s21::List<ValueType>::Reverse() noexcept {
  if (Size() > 1) {
    for (auto it = Begin(); it != End(); it--) {
      std::swap(it.current_->next_, it.current_->prev_);
    }
    std::swap(head_, tail_);
    std::swap(last_.next_, last_.prev_);
  }
}

/* Removes the last_ element */
template <typename ValueType>
void s21::List<ValueType>::PopBack() noexcept {
  if (head_ == tail_) {
    head_ = &last_;
  }
  Node<ValueType> *node = tail_;
  tail_ = last_.prev_ = tail_->prev_;
  tail_->next_ = &last_;
  delete node;
}

/* Removes the first element */
template <typename ValueType>
void s21::List<ValueType>::PopFront() noexcept {
  if (head_ == tail_) {
    tail_ = &last_;
  }
  Node<ValueType> *node = head_;
  head_ = last_.next_ = head_->next_;
  head_->prev_ = &last_;
  delete node;
}

/* Erases element at pos */
template <typename ValueType>
void s21::List<ValueType>::Erase(Iterator it) noexcept {
  if (!Empty()) {
    if (it == Begin()) {
      it.current_->next_->prev_ = nullptr;
      head_ = it.current_->next_;
    } else if (it.current_ == tail_) {
      it.current_->prev_->next_ = &last_;
      tail_ = it.current_->prev_;
      last_.prev_ = tail_;
    } else {
      it.current_->next_->prev_ = it.current_->prev_;
      it.current_->prev_->next_ = it.current_->next_;
    }
    delete it.current_;
  }
}

/* Print list */
template <typename ValueType>
void s21::List<ValueType>::PrintList() noexcept {
  if (Empty()) {
    std::cout << "\nList is empty! size:" << Size() << "\n";
  } else {
    for (auto it = Begin(); it != End(); it++) {
      std::cout << *it << "->";
    }
    std::cout << "NULL" << std::endl;
    auto it = End();
    for (; it != Begin(); --it) {
      std::cout << *it << "<-";
    }
    std::cout << *it << "<-NULL";
    std::cout << std::endl << "size: " << Size() << std::endl;
  }
}

/* Node to null */
template <typename ValueType>
void s21::List<ValueType>::NodeToNull(Node<ValueType> *node) noexcept {
  node->data_ = '\0';
  node->next_ = nullptr;
  node->prev_ = nullptr;
}

/* Sorts the elements in quick sort algortm*/
template <typename ValueType>
void s21::List<ValueType>::Sort() noexcept {
  QuickSort(1, Size());
}

/* Clears the contents */
template <typename ValueType>
void s21::List<ValueType>::Clear() noexcept {
  while (!Empty()) {
    Node<ValueType> *node = head_;
    head_ = head_->next_;
    delete node;
  }
  NodeToNull(&last_);
  head_ = tail_ = &last_;
}

/* Returns the number of elements */
template <typename ValueType>
typename s21::List<ValueType>::SizeType s21::List<ValueType>::Size() noexcept {
  typename List<ValueType>::SizeType size = 0;
  if (!Empty()) {
    for (auto it = Begin(); it != End(); it++, size++) {
    }
  }
  return size;
}

/* Swaps the contents */
template <typename ValueType>
void s21::List<ValueType>::Swap(s21::List<ValueType> &other) noexcept {
  if (this->Empty() && !other.Empty()) {
    tail_ = head_ = nullptr;
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(last_, other.last_);
    tail_->next_ = &last_;
    other.tail_ = other.head_ = &other.last_;
  } else if (!Empty() && other.Empty()) {
    other.tail_ = other.head_ = nullptr;
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(last_, other.last_);
    other.tail_->next_ = &other.last_;
    tail_ = head_ = &last_;
  } else if (!this->Empty() && !other.Empty()) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(last_, other.last_);
    tail_->next_ = &last_;
    other.tail_->next_ = &other.last_;
  }
}

/* Merges two sorted lists */
template <typename ValueType>
void s21::List<ValueType>::Merge(List<ValueType> &other) noexcept {
  if (this != &other) {
    if (Empty()) {
      Swap(other);
    } else {
      auto it2 = other.Begin();
      auto it_last1 = End();
      auto it_last2 = other.End();
      for (auto it1 = Begin(); it1 != it_last1 && it2 != it_last2; it1++) {
        if (*it2 < *it1) {
          it1 = Insert(it1, *it2++);
          other.PopFront();
        }
      }
      NodeToNull(&other.last_);
      other.head_ = other.tail_ = &other.last_;
    }
  }
}

/* Returns the maximum possible number of elements*/
template <typename ValueType>
typename s21::List<ValueType>::SizeType s21::List<ValueType>::MaxSize()
    const noexcept {
  return SIZE_MAX / (sizeof(Node<ValueType>) + sizeof(Node<ValueType>));
}
/*----------------------------------------------------------------------------*/
/* QuickSort Main */
template <typename ValueType>
void s21::List<ValueType>::QuickSort(SizeType start, SizeType end) noexcept {
  if (start < end) {
    SizeType right_count = QuickSortTask(start, end);
    QuickSort(start, right_count - 1);
    QuickSort(right_count, end);
  }
}

/* Algorithm of quick sort */
template <typename ValueType>
typename s21::List<ValueType>::SizeType s21::List<ValueType>::QuickSortTask(
    SizeType start, SizeType end) noexcept {
  auto it_left = Begin();
  auto it_right = Begin();
  auto it_pivot = Begin();
  it_right.Advance(end - 1);
  it_left.Advance(start - 1);
  it_pivot.Advance((start + end - 2) / 2);
  ValueType pivot = *it_pivot;
  SizeType right_count = end;
  SizeType left_count = start;
  while (left_count <= right_count) {
    while (*it_left < pivot) it_left++, left_count++;
    while (*it_right > pivot) it_right--, right_count--;
    if (left_count <= right_count) {
      std::swap(*it_left++, *it_right--);
      left_count++;
      right_count--;
    }
  }
  return left_count;
}
/*----------------------------------------------------------------------------*/