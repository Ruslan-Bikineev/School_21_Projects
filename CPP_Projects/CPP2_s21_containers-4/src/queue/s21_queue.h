#ifndef CPP2_S21_CONTAINERS_4_SRC_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_4_SRC_QUEUE_S21_QUEUE_H_

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace s21 {

template <typename T>
class Queue {
 public:
  // Member types
  using ValueType = T;
  using Reference = T &;
  using ConstReference = const T &;
  using SizeType = std::size_t;

  // Constructors and destructor
  Queue();
  explicit Queue(std::initializer_list<ValueType> const &items);
  Queue(const Queue &q);
  Queue(Queue &&q) noexcept;
  ~Queue();

  // Assignment operators
  Queue &operator=(const Queue &q);
  Queue &operator=(Queue &&q) noexcept;

  // Element access
  ConstReference Front() const;
  ConstReference Back() const;

  // Capacity
  bool Empty() const;
  SizeType Size() const;

  // Modifiers
  void Push(ConstReference value);
  void Pop();
  void Swap(Queue &other) noexcept;

 private:
  struct Node {
    ValueType data;
    Node *next;
    Node(ConstReference data, Node *next = nullptr) : data(data), next(next) {}
  };

  Node *head_;
  Node *tail_;
  SizeType size_;

  void CopyQueue(const Queue &q);
  void MoveQueue(Queue &&q);
  void ClearQueue();
};

}  // namespace s21

#include "s21_queue.tpp"
#endif  // CPP2_S21_CONTAINERS_4_SRC_QUEUE_S21_QUEUE_H_
