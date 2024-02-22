namespace s21 {

template <typename T>
Queue<T>::Queue() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
Queue<T>::Queue(std::initializer_list<ValueType> const &items) : Queue() {
  for (const auto &item : items) {
    Push(item);
  }
}

template <typename T>
Queue<T>::Queue(const Queue &q) : Queue() {
  CopyQueue(q);
}

template <typename T>
Queue<T>::Queue(Queue &&q) noexcept : Queue() {
  MoveQueue(std::move(q));
}

template <typename T>
Queue<T>::~Queue() {
  ClearQueue();
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue &q) {
  if (this != &q) {
    ClearQueue();
    CopyQueue(q);
  }
  return *this;
}

template <typename T>
Queue<T> &Queue<T>::operator=(Queue &&q) noexcept {
  if (this != &q) {
    ClearQueue();
    MoveQueue(std::move(q));
  }
  return *this;
}

template <typename T>
typename Queue<T>::ConstReference Queue<T>::Front() const {
  if (Empty()) {
    throw std::runtime_error("Queue is empty");
  }
  return head_->data;
}

template <typename T>
typename Queue<T>::ConstReference Queue<T>::Back() const {
  if (Empty()) {
    throw std::runtime_error("Queue is empty");
  }
  return tail_->data;
}

template <typename T>
bool Queue<T>::Empty() const {
  return size_ == 0;
}

template <typename T>
typename Queue<T>::SizeType Queue<T>::Size() const {
  return size_;
}

template <typename T>
void Queue<T>::Push(ConstReference value) {
  Node *new_node = new Node(value);
  if (Empty()) {
    head_ = tail_ = new_node;
  } else {
    tail_->next = new_node;
    tail_ = new_node;
  }
  ++size_;
}

template <typename T>
void Queue<T>::Pop() {
  if (Empty()) {
    throw std::runtime_error("Queue is empty");
  }
  Node *temp = head_;
  head_ = head_->next;
  delete temp;
  if (head_ == nullptr) {
    tail_ = nullptr;
  }
  --size_;
}

template <typename T>
void Queue<T>::Swap(Queue &other) noexcept {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}

template <typename T>
void Queue<T>::CopyQueue(const Queue &q) {
  for (Node *current = q.head_; current != nullptr; current = current->next) {
    Push(current->data);
  }
}

template <typename T>
void Queue<T>::MoveQueue(Queue &&q) {
  head_ = q.head_;
  tail_ = q.tail_;
  size_ = q.size_;

  q.head_ = q.tail_ = nullptr;
  q.size_ = 0;
}

template <typename T>
void Queue<T>::ClearQueue() {
  while (!Empty()) {
    Pop();
  }
}

}  // namespace s21
