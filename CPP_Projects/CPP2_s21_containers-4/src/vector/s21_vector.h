#ifndef CPP2_S21_CONTAINERS_4_SRC_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_4_SRC_VECTOR_S21_VECTOR_H_
#include <cstddef>

namespace s21 {

template <typename T>
class Vector {
 public:
  class VectorIterator;
  class VectorConstIterator;
  /*--------------------------MEMBER_TYPES---------------------------*/
  using ValueType = T;
  using Reference = T &;
  using SizeType = size_t;
  using Iterator = VectorIterator;
  using ConstReference = const ValueType &;
  using ConstIterator = VectorConstIterator;
  /*--------------------------CONSTRUCTORS---------------------------*/
  Vector() noexcept;
  Vector(SizeType) noexcept;
  Vector(Vector<ValueType> &&) noexcept;
  Vector(const Vector<ValueType> &) noexcept;
  Vector(std::initializer_list<ValueType> const &) noexcept;
  /*---------------------------DESTRUCTOR----------------------------*/
  ~Vector();
  /*----------------------------FUNCTIONS----------------------------*/
  Vector<ValueType> &operator=(Vector<ValueType> &&) noexcept;
  Vector<ValueType> &operator=(const Vector<ValueType> &) noexcept;

  void Clear() noexcept;
  void Reserve(SizeType);
  void PopBack() noexcept;
  void PrintVector() noexcept;
  void ShrinkToFit() noexcept;
  void Erase(Iterator) noexcept;
  void PushBack(ConstReference) noexcept;
  void Swap(Vector<ValueType> &) noexcept;
  SizeType Size() noexcept { return size_; };
  bool Empty() noexcept { return !capacity_; };
  Iterator Insert(Iterator, ConstReference) noexcept;
  SizeType Capacity() noexcept { return capacity_; };
  Iterator Begin() noexcept { return Iterator(data_); };
  Iterator End() noexcept { return Iterator(data_ + size_); };
  Reference operator[](SizeType pos) noexcept { return data_[pos]; };
  ConstIterator Begin() const noexcept { return ConstIterator(data_); };
  SizeType MaxSize() noexcept { return SIZE_MAX / (sizeof(ValueType) * 2); };
  ConstIterator End() const noexcept { return ConstIterator(data_ + size_); };
  class VectorIterator {
    friend class Vector;
    friend class VectorConstIterator;

   public:
    /*--------------------------CONSTRUCTORS---------------------------*/
    VectorIterator(ValueType *ptr) : current_(ptr) {}
    /*------------------------OVERLOAD-FUNCTIONS-----------------------*/
    Iterator &operator++();
    Iterator &operator--();
    Iterator operator++(int);
    Iterator operator--(int);
    Iterator operator+=(SizeType);
    Iterator operator-=(SizeType);
    bool operator==(VectorIterator);
    bool operator!=(VectorIterator);
    Reference operator*() { return *current_; }
    operator typename Vector<ValueType>::ConstIterator();
    /*-----------------------------------------------------------------*/

   private:
    ValueType *current_;
  };

  class VectorConstIterator {
    friend class Vector;
    friend class VectorIterator;

   public:
    /*--------------------------CONSTRUCTORS---------------------------*/
    VectorConstIterator(ValueType *ptr) : current_(ptr) {}
    /*------------------------OVERLOAD-FUNCTIONS-----------------------*/
    ConstIterator &operator++();
    ConstIterator &operator--();
    ConstIterator operator++(int);
    ConstIterator operator--(int);
    ConstIterator operator+=(SizeType);
    ConstIterator operator-=(SizeType);
    operator typename Vector<ValueType>::Iterator();
    bool operator==(ConstIterator) const;
    bool operator!=(ConstIterator) const;
    ConstReference operator*() const { return *current_; }
    /*-----------------------------------------------------------------*/
   private:
    ValueType *current_;
  };

 private:
  ValueType *data_;
  SizeType size_;
  SizeType capacity_;
};

/*--------------------------VECTOR-ITERATOR-FUNCTIONS-------------------------*/
/* Prefix increment operator */
template <typename ValueType>
inline typename Vector<ValueType>::Iterator &
Vector<ValueType>::VectorIterator::operator++() {
  current_++;
  return *this;
}

/* Prefix deccrement operator */
template <typename ValueType>
inline typename Vector<ValueType>::Iterator &
Vector<ValueType>::VectorIterator::operator--() {
  current_--;
  return *this;
}

/* Postfix increment operator */
template <typename ValueType>
inline typename Vector<ValueType>::Iterator
Vector<ValueType>::VectorIterator::operator++(int) {
  Iterator temp = *this;
  ++(*this);
  return temp;
}

/* Postfix deccrement operator */
template <typename ValueType>
inline typename Vector<ValueType>::Iterator
Vector<ValueType>::VectorIterator::operator--(int) {
  Iterator temp = *this;
  --(*this);
  return temp;
}

/* Sum operators move */
template <typename ValueType>
inline typename Vector<ValueType>::Iterator
Vector<ValueType>::VectorIterator::operator+=(SizeType move) {
  return Iterator(current_ += move);
}

/* Sub operators move */
template <typename ValueType>
inline typename Vector<ValueType>::Iterator
Vector<ValueType>::VectorIterator::operator-=(SizeType move) {
  return Iterator(current_ -= move);
}

/* Comparison operators */
template <typename ValueType>
inline bool Vector<ValueType>::VectorIterator::operator==(VectorIterator it) {
  return current_ == it.current_;
}

/* Comparison operators */
template <typename ValueType>
inline bool Vector<ValueType>::VectorIterator::operator!=(VectorIterator it) {
  return current_ != it.current_;
}

/* Conversion operators */
template <typename ValueType>
inline Vector<ValueType>::VectorIterator::operator typename Vector<
    ValueType>::ConstIterator() {
  return Vector<ValueType>::ConstIterator(current_);
}
/*-----------------------VECTOR-CONST-ITERATOR-FUNCTIONS----------------------*/
/* Prefix increment operator */
template <typename ValueType>
inline typename Vector<ValueType>::ConstIterator &
Vector<ValueType>::VectorConstIterator::operator++() {
  current_++;
  return *this;
}

/* Prefix decrement operator */
template <typename ValueType>
inline typename Vector<ValueType>::ConstIterator &
Vector<ValueType>::VectorConstIterator::operator--() {
  current_--;
  return *this;
}

/* Postfix increment operator */
template <typename ValueType>
inline typename Vector<ValueType>::ConstIterator
Vector<ValueType>::VectorConstIterator::operator++(int) {
  ConstIterator temp = *this;
  ++(*this);
  return temp;
}

/* Postfix decrement operator */
template <typename ValueType>
inline typename Vector<ValueType>::ConstIterator
Vector<ValueType>::VectorConstIterator::operator--(int) {
  ConstIterator temp = *this;
  --(*this);
  return temp;
}

/* Sum operators move */
template <typename ValueType>
inline typename Vector<ValueType>::ConstIterator
Vector<ValueType>::VectorConstIterator::operator+=(SizeType move) {
  return ConstIterator(current_ += move);
}

/* Sub operators move */
template <typename ValueType>
inline typename Vector<ValueType>::ConstIterator
Vector<ValueType>::VectorConstIterator::operator-=(SizeType move) {
  return ConstIterator(current_ -= move);
}

/* Comparison operators */
template <typename ValueType>
inline bool Vector<ValueType>::VectorConstIterator::operator==(
    ConstIterator it) const {
  return current_ == it.current_;
}

/* Comparison operators */
template <typename ValueType>
inline bool Vector<ValueType>::VectorConstIterator::operator!=(
    ConstIterator it) const {
  return current_ != it.current_;
}

/* Conversion operators */
template <typename ValueType>
inline Vector<ValueType>::VectorConstIterator::operator typename Vector<
    ValueType>::Iterator() {
  return Vector<ValueType>::Iterator(current_);
}
/*----------------------------------------------------------------------------*/
#include "s21_vector.tpp"
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_4_SRC_VECTOR_S21_VECTOR_H_