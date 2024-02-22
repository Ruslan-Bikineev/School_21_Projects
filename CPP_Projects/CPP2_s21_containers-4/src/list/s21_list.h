#ifndef CPP2_S21_CONTAINERS_4_SRC_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_4_SRC_LIST_S21_LIST_H_
#include <cstddef>
#include <initializer_list>

namespace s21 {

template <typename T>
struct Node {
 public:
  T data_;
  Node<T> *next_;
  Node<T> *prev_;
};

template <typename T>
class List {
 public:
  class ListIterator;
  class ListConstIterator;
  /*--------------------------MEMBER_TYPES---------------------------*/
  using ValueType = T;
  using Reference = T &;
  using SizeType = size_t;
  using Iterator = ListIterator;
  using ConstReference = const ValueType &;
  using ConstIterator = ListConstIterator;
  /*--------------------------CONSTRUCTORS---------------------------*/
  List() noexcept;
  List(List &&) noexcept;
  List(SizeType) noexcept;
  List(const List &) noexcept;
  List(std::initializer_list<ValueType> const &) noexcept;
  /*----------------------------DESTRUCTOR--------------------------*/
  ~List();
  /*----------------------------FUNCTIONS----------------------------*/
  List<ValueType> &operator=(List<ValueType> &&) noexcept;
  List<ValueType> &operator=(const List<ValueType> &) noexcept;

  void Sort() noexcept;
  void Clear() noexcept;
  void Unique() noexcept;
  void PopBack() noexcept;
  void Reverse() noexcept;
  void PopFront() noexcept;
  SizeType Size() noexcept;
  void PrintList() noexcept;
  void Erase(Iterator) noexcept;
  SizeType MaxSize() const noexcept;
  void Swap(List<ValueType> &) noexcept;
  void Merge(List<ValueType> &) noexcept;
  void PushBack(ConstReference) noexcept;
  void PushFront(ConstReference) noexcept;
  Iterator Insert(Iterator, ConstReference) noexcept;
  Iterator End() noexcept { return Iterator(&last_); };
  Iterator Begin() noexcept { return Iterator(head_); };
  void Splice(ConstIterator, List<ValueType> &) noexcept;
  ConstReference Back() const noexcept { return tail_->data_; };
  ConstReference Front() const noexcept { return head_->data_; };
  ConstIterator Begin() const noexcept { return ConstIterator(head_); };
  ConstIterator End() const noexcept { return ConstIterator(tail_->next_); };
  bool Empty() const noexcept { return (head_ == nullptr || head_ == &last_); };

  class ListIterator {
    friend class List;
    friend class ListConstIterator;

   public:
    /*--------------------------CONSTRUCTORS---------------------------*/
    ListIterator(Node<ValueType> *node) : current_(node){};
    /*------------------------OVERLOAD-FUNCTIONS-----------------------*/
    Iterator &operator++();
    Iterator &operator--();
    Iterator operator++(int);
    Iterator operator--(int);
    bool operator==(ListIterator);
    bool operator!=(ListIterator);
    Reference operator*() { return current_->data_; };
    operator typename List<ValueType>::ConstIterator();
    /*-----------------------------------------------------------------*/
   private:
    Node<ValueType> *current_;
    void Advance(long int) noexcept;
  };
  class ListConstIterator {
    friend class List;
    friend class ListIterator;

   public:
    /*--------------------------CONSTRUCTORS---------------------------*/
    ListConstIterator(Node<ValueType> *node) : current_(node){};
    /*------------------------OVERLOAD-FUNCTIONS-----------------------*/
    ConstIterator &operator++();
    ConstIterator &operator--();
    ConstIterator operator++(int);
    ConstIterator operator--(int);
    bool operator==(ConstIterator) const;
    bool operator!=(ConstIterator) const;
    operator typename List<ValueType>::Iterator();
    ConstReference operator*() const { return current_->data_; };
    /*-----------------------------------------------------------------*/
   private:
    Node<ValueType> *current_;
  };

 private:
  Node<ValueType> last_;
  Node<ValueType> *head_;
  Node<ValueType> *tail_;
  void NodeToNull(Node<ValueType> *) noexcept;
  void QuickSort(SizeType, SizeType) noexcept;
  SizeType QuickSortTask(SizeType, SizeType) noexcept;
};
/*---------------------------LIST-ITERATOR-FUNCTIONS--------------------------*/
/* Prefix increment operator */
template <typename ValueType>
inline typename List<ValueType>::Iterator &
List<ValueType>::ListIterator::operator++() {
  current_ = current_->next_;
  return *this;
};

/* Postfix increment operator */
template <typename ValueType>
inline typename List<ValueType>::Iterator
List<ValueType>::ListIterator::operator++(int) {
  Iterator temp = *this;
  ++(*this);
  return temp;
};

/* Prefix decrement operator */
template <typename ValueType>
inline typename List<ValueType>::Iterator &
List<ValueType>::ListIterator::operator--() {
  current_ = current_->prev_;
  return *this;
}
/* Postfix decrement operator */
template <typename ValueType>
inline typename List<ValueType>::Iterator
List<ValueType>::ListIterator::operator--(int) {
  Iterator temp = *this;
  --(*this);
  return temp;
}

/* Comparison operators */
template <typename ValueType>
inline bool List<ValueType>::ListIterator::operator==(ListIterator it) {
  return current_ == it.current_;
}

/* Comparison operators */
template <typename ValueType>
inline bool List<ValueType>::ListIterator::operator!=(ListIterator it) {
  return current_ != it.current_;
}

/* Conversion operator */
template <typename ValueType>
inline List<ValueType>::ListIterator::operator typename List<
    ValueType>::ConstIterator() {
  return List<ValueType>::ConstIterator(current_);
}

/* Advance operator */
template <typename T>
inline void List<T>::ListIterator::Advance(long int pos) noexcept {
  for (; pos > 0; pos--) {
    ++(*this);
  }
  for (; pos < 0; pos++) {
    --(*this);
  }
}
/*------------------------LIST-CONST-ITERATOR-FUNCTIONS-----------------------*/
/* Prefix increment operator */
template <typename ValueType>
inline typename List<ValueType>::ConstIterator &
List<ValueType>::ListConstIterator::operator++() {
  current_ = current_->next_;
  return *this;
}

/* Prefix decrement operator */
template <typename ValueType>
inline typename List<ValueType>::ConstIterator &
List<ValueType>::ListConstIterator::operator--() {
  current_ = current_->prev_;
  return *this;
}

/* Postfix increment operator */
template <typename ValueType>
inline typename List<ValueType>::ConstIterator
List<ValueType>::ListConstIterator::operator++(int) {
  ConstIterator temp = *this;
  ++(*this);
  return temp;
}

/* Postfix decrement operator */
template <typename ValueType>
inline typename List<ValueType>::ConstIterator
List<ValueType>::ListConstIterator::operator--(int) {
  ConstIterator temp = *this;
  --(*this);
  return temp;
}

/* Comparison operators */
template <typename ValueType>
inline bool List<ValueType>::ListConstIterator::operator==(
    ConstIterator it) const {
  return current_ == it.current_;
}

/* Comparison operators */
template <typename ValueType>
inline bool List<ValueType>::ListConstIterator::operator!=(
    ConstIterator it) const {
  return current_ != it.current_;
}

/* Conversion operator */
template <typename ValueType>
inline List<ValueType>::ListConstIterator::operator typename List<
    ValueType>::Iterator() {
  return List<ValueType>::Iterator(current_);
}
/*----------------------------------------------------------------------------*/
#include "s21_list.tpp"
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_4_SRC_LIST_S21_LIST_H_