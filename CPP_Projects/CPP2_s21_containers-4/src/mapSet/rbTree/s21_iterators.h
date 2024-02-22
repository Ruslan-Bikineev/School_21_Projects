#ifndef CPP2_S21_CONTAINERS_4_SRC_MAPSET_RBTREE_S21_ITERATORS_H_
#define CPP2_S21_CONTAINERS_4_SRC_MAPSET_RBTREE_S21_ITERATORS_H_
#include "s21_rb_tree.h"
namespace s21 {

template <typename Key>
class Iterator {
 public:
  using KeyType = Key;
  using Reference = KeyType &;
  using Pointer = KeyType *;

  Iterator(RBNode<KeyType> *node, RBTree<KeyType> *tree)
      : node_(node), tree_(tree) {}
  ~Iterator() = default;
  Iterator(const Iterator &it) : node_(it.node_), tree_(it.tree_) {}
  Iterator &operator=(const Iterator &other) {
    if (this != &other) {
      node_ = other.node_;
      tree_ = other.tree_;
    }
    return *this;
  }
  Iterator &operator++() {
    if (node_ == nullptr) {
      return *this;
    }
    if (node_ == tree_->GetNil()) {
      return --(*this);
    }
    if (node_->right_ != tree_->GetNil()) {
      node_ = node_->right_;
      while (node_->left_ != tree_->GetNil()) {
        node_ = node_->left_;
      }
    } else {
      RBNode<KeyType> *parent = node_->parent_;
      while (parent != tree_->GetNil() && node_ == parent->right_) {
        node_ = parent;
        parent = parent->parent_;
      }
      node_ = parent;
    }

    return *this;
  }
  Iterator operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
  }
  Iterator &operator--() noexcept {
    if (node_ == nullptr) {
      return *this;
    }
    if (node_ == tree_->GetNil()) {
      node_ = tree_->GetMax(tree_->GetRoot());
    } else {
      if (node_->left_ != tree_->GetNil()) {
        node_ = node_->left_;
        while (node_->right_ != tree_->GetNil()) {
          node_ = node_->right_;
        }
      } else {
        RBNode<KeyType> *parent = node_->parent_;
        while (parent != tree_->GetNil() && node_ == parent->left_) {
          node_ = parent;
          parent = parent->parent_;
        }
        node_ = parent;
      }
    }
    return *this;
  }
  Iterator operator--(int) {
    Iterator tmp = *this;
    --(*this);
    return tmp;
  }
  Reference operator*() const { return node_->key_; }
  Pointer operator->() const { return &(node_->key_); }
  bool operator==(const Iterator &other) const { return node_ == other.node_; }
  bool operator!=(const Iterator &other) const { return node_ != other.node_; }

 private:
  RBNode<KeyType> *node_;
  RBTree<KeyType> *tree_;
};

template <typename Key>
class ConstIterator : public Iterator<Key> {
 public:
  using KeyType = Key;
  using Reference = const KeyType &;
  using Pointer = const KeyType *;
  using Iterator<KeyType>::Iterator;
  ConstIterator(const Iterator<KeyType> &it) : Iterator<KeyType>(it) {}
  Reference operator*() const { return Iterator<KeyType>::operator*(); }
  Pointer operator->() const { return Iterator<KeyType>::operator->(); }
  ConstIterator &operator++() {
    Iterator<KeyType>::operator++();
    return *this;
  }
  ConstIterator operator++(int) {
    ConstIterator tmp = *this;
    Iterator<KeyType>::operator++();
    return tmp;
  }
  ConstIterator &operator--() {
    Iterator<KeyType>::operator--();
    return *this;
  }
  ConstIterator operator--(int) {
    ConstIterator tmp = *this;
    Iterator<KeyType>::operator--();
    return tmp;
  }
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_4_SRC_MAPSET_RBTREE_S21_ITERATORS_H_
