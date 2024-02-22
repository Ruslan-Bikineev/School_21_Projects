/*----------------------------------------------------------------------------*/
/* Default constructor, creates empty vector */
template <typename ValueType>
s21::Vector<ValueType>::Vector() noexcept
    : data_(nullptr), size_(0), capacity_(0) {}

/* Parameterized constructor, creates the vector of size n */
template <typename ValueType>
s21::Vector<ValueType>::Vector(SizeType n) noexcept
    : data_(nullptr), size_(n), capacity_(n) {
  data_ = new ValueType[size_]();
}

/* Initializer list constructor, creates vector initizialized using
 * std::initializer_list */
template <typename ValueType>
s21::Vector<ValueType>::Vector(
    std::initializer_list<ValueType> const &items) noexcept {
  size_ = capacity_ = items.size();
  data_ = new ValueType[size_];
  SizeType it = 0;
  for (auto item : items) {
    data_[it++] = item;
  }
}

/* Copy constructor */
template <typename ValueType>
s21::Vector<ValueType>::Vector(const Vector<ValueType> &other) noexcept
    : Vector() {
  *this = other;
}

/* Move constructor */
template <typename ValueType>
s21::Vector<ValueType>::Vector(Vector<ValueType> &&other) noexcept : Vector() {
  *this = std::move(other);
}

/* Destructor */
template <typename ValueType>
s21::Vector<ValueType>::~Vector() {
  Clear();
}

/*----------------------------------------------------------------------------*/
/* Copy vector */
template <typename ValueType>
s21::Vector<ValueType> &s21::Vector<ValueType>::operator=(
    const Vector<ValueType> &other) noexcept {
  if (this != &other) {
    if (capacity_ < other.capacity_) {
      Clear();
      capacity_ = other.capacity_;
      data_ = new ValueType[other.size_]();
    }
    auto it = Begin();
    auto it_other = other.Begin();
    while (it_other != other.End()) {
      *it++ = *it_other++;
    }
    size_ = other.size_;
  }
  return *this;
}

/* Move vector */
template <typename ValueType>
s21::Vector<ValueType> &s21::Vector<ValueType>::operator=(
    Vector<ValueType> &&other) noexcept {
  Clear();
  Swap(other);
  return *this;
}

/* Allocate storage of size elements and copies current array elements to a
 * newely allocated array */
template <typename ValueType>
void s21::Vector<ValueType>::Reserve(SizeType size) {
  if (size > MaxSize()) {
    throw std::length_error("Vector::Reserve(), size is too big");
  } else if (size > capacity_) {
    Vector<ValueType> temp;
    temp.data_ = new ValueType[size]();
    temp.size_ = temp.capacity_ = size;
    temp = *this;
    Clear();
    Swap(temp);
  }
}

/* Adds an element to the end */
template <typename ValueType>
void s21::Vector<ValueType>::PushBack(ConstReference value) noexcept {
  Vector<ValueType> temp;
  if (size_ == capacity_) {
    temp.Reserve(size_ ? size_ * 2 : 1);
    temp = *this;
    Swap(temp);
  }
  data_[size_++] = value;
  temp.Clear();
}

/* Inserts elements into concrete pos and returns the Iterator that points to
 * the new element */
template <typename ValueType>
typename s21::Vector<ValueType>::Iterator s21::Vector<ValueType>::Insert(
    Iterator pos, ConstReference value) noexcept {
  ValueType *result = nullptr;
  if (pos == End()) {
    PushBack(value);
    result = data_ + size_ - 1;
  } else {
    Vector<ValueType> temp;
    if (size_ == capacity_) {
      temp.Reserve(size_ ? size_ * 2 : 1);
      temp.size_ = size_;
    }
    auto it1 = End();
    auto it2 = it1--;
    bool flag = true;
    for (auto it_temp = temp.End(); flag && it2 != Begin(); it2--, it1--) {
      if (it1 == pos) {  // begin and middle
        ((!temp.Empty()) ? *it_temp-- : *it2--) = *it1;
        result = ((!temp.Empty()) ? it_temp.current_ : it2.current_);
        ((!temp.Empty()) ? *it_temp-- : *it2) = value;
        if (temp.Empty()) flag = false;
      } else {
        ((!temp.Empty()) ? *it_temp-- : *it2) = *it1;
      }
    }
    if (!temp.Empty()) Swap(temp), temp.Clear();
    size_++;
  }
  return Iterator(result);
}

/* Clears the contents */
template <typename ValueType>
void s21::Vector<ValueType>::Clear() noexcept {
  if (!Empty()) {
    delete[] data_;
    data_ = nullptr;
    size_ = capacity_ = 0;
  }
}

/* Removes the last element */
template <typename ValueType>
void s21::Vector<ValueType>::PopBack() noexcept {
  if (!Empty()) {
    --size_;
  }
}

/* Prints the vector */
template <typename ValueType>
void s21::Vector<ValueType>::PrintVector() noexcept {
  if (Empty()) {
    std::cout << "Empty vector" << std::endl;
  } else {
    for (auto it = Begin(); it != End(); it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl
              << "Size: " << Size() << "\tCapacity: " << Capacity()
              << std::endl;
  }
}

/* Reduces memory usage by freeing unused memory */
template <typename ValueType>
void s21::Vector<ValueType>::ShrinkToFit() noexcept {
  if (size_ == 0) {
    Clear();
  } else if (capacity_ > size_) {
    Vector<ValueType> temp;
    temp.data_ = new ValueType[size_];
    temp.size_ = temp.capacity_ = capacity_ = size_;
    temp = *this;
    Clear();
    Swap(temp);
  }
}

/* Erases element at pos */
template <typename ValueType>
void s21::Vector<ValueType>::Erase(Iterator pos) noexcept {
  if (!Empty() && pos != End()) {
    auto it2 = pos;
    auto it1 = it2++;
    while (it2 != End()) {
      *it1++ = *it2++;
    }
    size_--;
  }
}

/* Swaps vectors */
template <typename ValueType>
void s21::Vector<ValueType>::Swap(Vector<ValueType> &other) noexcept {
  if (this != &other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }
}
/*----------------------------------------------------------------------------*/
