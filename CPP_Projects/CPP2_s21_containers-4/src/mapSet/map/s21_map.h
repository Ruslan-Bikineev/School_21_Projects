#ifndef CPP2_S21_CONTAINERS_4_SRC_MAPSET_MAP_S21_MAP_H_
#define CPP2_S21_CONTAINERS_4_SRC_MAPSET_MAP_S21_MAP_H_

#include "../rbTree/s21_iterators.h"

namespace s21 {
template <typename Key, typename T>
class Map {
 public:
  using KeyType = Key;
  using MappedType = T;
  using ValueType = std::pair<const KeyType, MappedType>;
  using Reference = ValueType &;
  using ConstReference = const ValueType &;
  using SizeType = size_t;
  using Iterator = s21::Iterator<ValueType>;
  using ConstIterator = s21::ConstIterator<ValueType>;

  Map() = default;
  Map(std::initializer_list<ValueType> const &items) {
    for (auto it = items.begin(); it != items.end(); ++it) {
      Insert(*it);
    }
  }
  Map(const Map &other) noexcept {
    *tree_ = *other.tree_;
    size_ = other.size_;
  }
  Map(Map &&other) noexcept : tree_(other.tree_), size_(other.size_) {
    other.tree_ = new RBTree<ValueType>();
    other.size_ = 0;
  }
  ~Map() {
    Clear();
    delete tree_;
  }
  Map &operator=(const Map &other) noexcept {
    if (this != &other) {
      Clear();
      size_ = other.size_;
      *tree_ = *other.tree_;
    }
    return *this;
  }
  Map &operator=(Map &&other) noexcept {
    if (this != &other) {
      Clear();
      delete tree_;

      tree_ = other.tree_;
      size_ = other.size_;

      other.tree_ = new RBTree<ValueType>();
      other.size_ = 0;
    }
    return *this;
  }

  MappedType &At(const KeyType &key) { return FindByKey(key)->second; }
  const MappedType &At(const KeyType &key) const {
    return FindByKey(key)->second;
  }

  MappedType &operator[](const KeyType &key) noexcept {
    try {
      return FindByKey(key)->second;
    } catch (const std::out_of_range &e) {
      return Insert({key, MappedType()}).first->second;
    }
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
    try {
      auto it = FindByKey(value.first);
      return std::make_pair(it, false);
    } catch (const std::out_of_range &e) {
      ++size_;
      RBNode<ValueType> *node = tree_->Insert(value);
      return std::make_pair(Iterator(node, tree_), true);
    }
  }
  std::pair<Iterator, bool> Insert(const KeyType &key,
                                   const MappedType &obj) noexcept {
    return Insert(std::make_pair(key, obj));
  }
  std::pair<Iterator, bool> InsertOrAssign(const KeyType &key,
                                           const MappedType &obj) noexcept {
    try {
      auto it = FindByKey(key);
      it->second = obj;
      return std::make_pair(it, false);
    } catch (const std::out_of_range &e) {
      return Insert(key, obj);
    }
  }

  void Erase(const KeyType &key) noexcept {
    try {
      auto it = FindByKey(key);
      Erase(it);
    } catch (const std::out_of_range &e) {
      return;
    }
  }

  void Erase(Iterator pos) noexcept {
    auto node = tree_->Erase(*pos);
    if (node != tree_->GetNil()) {
      --size_;
    }
  }
  void Swap(Map &other) noexcept {
    std::swap(tree_, other.tree_);
    std::swap(size_, other.size_);
  }
  void Merge(Map &other) noexcept {
    auto it = other.Begin();
    while (it != other.End()) {
      auto current = it++;
      auto inserted = Insert(*current).second;
      if (inserted) {
        other.Erase(current);
      }
    }
  }
  bool Contains(const KeyType &key) const noexcept {
    try {
      FindByKey(key);
      return true;
    } catch (const std::out_of_range &e) {
      return false;
    }
  }

 private:
  Iterator FindByKey(const KeyType &key) {
    auto it = Begin();
    while (it != End()) {
      if ((*it).first == key) {
        return Iterator(it);
      }
      ++it;
    }
    throw std::out_of_range("out of range");
  }
  ConstIterator FindByKey(const KeyType &key) const {
    auto it = Begin();
    while (it != End()) {
      if ((*it).first == key) {
        return ConstIterator(it);
      }
      ++it;
    }
    throw std::out_of_range("out of range");
  }
  RBTree<ValueType> *tree_{new RBTree<ValueType>()};
  SizeType size_{0};
  std::allocator<ValueType> allocator_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_4_SRC_MAPSET_MAP_S21_MAP_H_