#ifndef CPP2_S21_CONTAINERS_4_SRC_MAPSET_SET_S21_SET_H_
#define CPP2_S21_CONTAINERS_4_SRC_MAPSET_SET_S21_SET_H_

#include "../rbTree/s21_iterators.h"

namespace s21 {
template <typename Key>
class Set {
 public:
  using KeyType = Key;
  using ValueType = Key;
  using Reference = ValueType &;
  using ConstReference = const ValueType &;
  using SizeType = size_t;
  using Iterator = s21::Iterator<KeyType>;
  using ConstIterator = s21::ConstIterator<KeyType>;
  Set() = default;
  Set(std::initializer_list<ValueType> const &items) {
    for (auto it = items.begin(); it != items.end(); it++) {
      Insert(*it);
    }
  }
  Set(const Set &other) {
    *tree_ = *other.tree_;
    size_ = other.size_;
  }

  Set(Set &&other) noexcept : tree_(other.tree_), size_(other.size_) {
    other.tree_ = new RBTree<KeyType>();
    other.size_ = 0;
  }

  ~Set() {
    Clear();
    delete tree_;
  }

  Set &operator=(const Set &other) noexcept {
    if (this != &other) {
      Clear();
      size_ = other.size_;
      *tree_ = *other.tree_;
    }
    return *this;
  }

  Set &operator=(Set &&other) noexcept {
    if (this != &other) {
      Clear();
      delete tree_;
      tree_ = other.tree_;
      size_ = other.size_;
      other.tree_ = new RBTree<KeyType>();
      other.size_ = 0;
    }
    return *this;
  }

  Iterator Begin() noexcept {
    return Iterator(tree_->GetMin(tree_->GetRoot()), tree_);
  }
  ConstIterator Begin() const noexcept {
    return ConstIterator(tree_->GetMin(tree_->GetRoot()), tree_);
  }
  Iterator End() noexcept { return Iterator(tree_->GetNil(), tree_); }
  ConstIterator End() const noexcept {
    return ConstIterator(tree_->GetNil(), tree_);
  }

  bool Empty() const noexcept { return size_ == 0; }
  SizeType Size() const noexcept { return size_; }
  SizeType MaxSize() const noexcept {
    return allocator_.max_size() / sizeof(RBNode<KeyType>);
  }

  void Clear() noexcept {
    if (tree_ != nullptr) {
      tree_->Clear();
    }
    size_ = 0;
  }
  std::pair<Iterator, bool> Insert(const ValueType &value) noexcept {
    RBNode<KeyType> *find = tree_->Search(value);
    if (find != tree_->GetNil()) {
      return std::make_pair(Iterator(find, tree_), false);
    } else {
      ++size_;
      RBNode<KeyType> *node_ = tree_->Insert(value);
      return std::make_pair(Iterator(node_, tree_), true);
    }
  }
  void Erase(Iterator pos) noexcept { Erase(*pos); }

  void Erase(const KeyType &key) noexcept {
    auto erase = tree_->Erase(key);
    if (erase != tree_->GetNil()) {
      --size_;
    }
  }

  void Swap(Set &other) noexcept {
    std::swap(tree_, other.tree_);
    std::swap(size_, other.size_);
  }
  void Merge(Set &other) noexcept {
    auto it = other.Begin();
    while (it != other.End()) {
      Insert(*it);
      ++it;
    }
  }

  Iterator Find(const KeyType &key) const noexcept {
    return Iterator(tree_->Search(key), tree_);
  }
  bool Contains(const KeyType &key) const noexcept {
    return tree_->Search(key) != tree_->GetNil();
  }

 private:
  RBTree<KeyType> *tree_{new RBTree<KeyType>()};
  SizeType size_{0};
  std::allocator<ValueType> allocator_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_4_SRC_MAPSET_SET_S21_SET_H_
