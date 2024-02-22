#ifndef CPP2_S21_CONTAINERS_4_SRC_MAPSET_RBTREE_S21_RB_TREE_H_
#define CPP2_S21_CONTAINERS_4_SRC_MAPSET_RBTREE_S21_RB_TREE_H_

namespace s21 {
enum Color { kRed, kBlack };

template <typename Key>
class RBNode {
 public:
  RBNode() noexcept {
    color_ = kRed;
    left_ = nullptr;
    right_ = nullptr;
    parent_ = nullptr;
  }
  RBNode(Key key) noexcept
      : key_(key),
        color_(kRed),
        left_(nullptr),
        right_(nullptr),
        parent_(nullptr){};
  RBNode(const RBNode &node) noexcept
      : key_(node.key_),
        color_(node.color_),
        left_(node.left_),
        right_(node.right_),
        parent_(node.parent_) {}

  RBNode &operator=(const RBNode &node) {
    if (this != &node) {
      key_ = node.key_;
      color_ = node.color_;
      left_ = node.left_;
      right_ = node.right_;
      parent_ = node.parent_;
    }
    return *this;
  }

  RBNode &operator=(RBNode &&node) {
    if (this != &node) {
      key_ = std::move(node.key_);
      color_ = node.color_;
      left_ = node.left_;
      right_ = node.right_;
      parent_ = node.parent_;
      node.left_ = nullptr;
      node.right_ = nullptr;
      node.parent_ = nullptr;
    }
    return *this;
  }

  RBNode(RBNode &&node) noexcept
      : key_(std::move(node.key_)),
        color_(node.color_),
        left_(node.left_),
        right_(node.right_),
        parent_(node.parent_) {
    node.left_ = nullptr;
    node.right_ = nullptr;
    node.parent_ = nullptr;
  }
  ~RBNode() = default;

 public:
  Key key_;
  Color color_;
  RBNode *left_, *right_, *parent_;
};

template <typename Key>
class RBTree {
  using KeyType = Key;
  using ValueType = Key;
  using Reference = ValueType &;
  using ConstReference = const ValueType &;

 public:
  RBTree();
  RBTree(const RBTree &other);
  RBTree(RBTree &&other) noexcept;
  RBTree &operator=(const RBTree &other) noexcept;
  RBTree &operator=(RBTree &&other) noexcept;
  ~RBTree();
  RBNode<KeyType> *CopyTree(RBNode<KeyType> *node,
                            RBNode<KeyType> *nil) noexcept;
  RBNode<KeyType> *GetNil() const noexcept { return nil_; }
  RBNode<KeyType> *GetRoot() const noexcept { return root_; }
  RBNode<KeyType> *GetChild(RBNode<KeyType> *node) const noexcept;
  void LeftRotate(RBNode<KeyType> *node) noexcept;
  void RightRotate(RBNode<KeyType> *node) noexcept;
  RBNode<KeyType> *Insert(KeyType key) noexcept;
  void BalanceTreeInsert(RBNode<KeyType> *node) noexcept;
  RBNode<KeyType> *Search(KeyType key) const noexcept;
  RBNode<KeyType> *GetMin(RBNode<KeyType> *node) const noexcept;
  RBNode<KeyType> *GetMax(RBNode<KeyType> *node) const noexcept;
  RBNode<KeyType> *Erase(KeyType key) noexcept;
  void Clear(RBNode<KeyType> *node) noexcept;
  void Clear() noexcept;
  void TransplantNode(RBNode<KeyType> *to_node,
                      RBNode<KeyType> *from_node) noexcept;
  int GetChildrenCount(RBNode<KeyType> *node) const noexcept;
  void BalanceTreeErase(RBNode<KeyType> *node) noexcept;

 private:
  RBNode<KeyType> *nil_{new RBNode<KeyType>(KeyType{})};
  RBNode<KeyType> *root_{nil_};
  void BalanceTreeInsertUncleRight(RBNode<KeyType> *node) noexcept;
  void BalanceTreeInsertUncleLeft(RBNode<KeyType> *node) noexcept;
  bool BalanceTreeEraseBrotherRight(RBNode<Key> **node) noexcept;
  bool BalanceTreeEraseBrotherLeft(RBNode<Key> **node) noexcept;
};

}  // namespace s21
#include "s21_rb_tree.tpp"
#endif  // CPP2_S21_CONTAINERS_4_SRC_MAPSET_RBTREE_S21_RB_TREE_H_