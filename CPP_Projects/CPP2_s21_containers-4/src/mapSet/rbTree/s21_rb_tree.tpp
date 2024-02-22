namespace s21 {

template <typename Key>
RBTree<Key>::RBTree() {
  nil_->color_ = kBlack;
  root_ = nil_;
}

template <typename Key>
RBTree<Key>::RBTree(const RBTree &other) {
  if (this != &other) {
    if (other.root_ != other.nil_) {
      root_ = CopyTree(other.root_, other.nil_);
    } else {
      root_ = nil_;
    }
  }
}

template <typename Key>
RBTree<Key>::RBTree(RBTree &&other) noexcept
    : nil_(other.nil_), root_(other.root_) {
  other.nil_ = nullptr;
  other.root_ = nullptr;
}

template <typename Key>
RBTree<Key> &RBTree<Key>::operator=(const RBTree &other) noexcept {
  if (this != &other) {
    Clear();
    if (other.root_ != other.nil_) {
      root_ = CopyTree(other.root_, other.nil_);
    } else {
      root_ = nil_;
    }
  }
  return *this;
}

template <typename Key>
RBTree<Key> &RBTree<Key>::operator=(RBTree &&other) noexcept {
  if (this != &other) {
    Clear();
    delete nil_;
    root_ = other.root_;
    nil_ = other.nil_;
    other.root_ = nullptr;
    other.nil_ = nullptr;
  }
  return *this;
}

template <typename Key>
RBTree<Key>::~RBTree() {
  Clear();
  delete nil_;
  root_ = nullptr;
  nil_ = nullptr;
}

template <typename Key>
RBNode<Key> *RBTree<Key>::CopyTree(RBNode<Key> *node,
                                   RBNode<Key> *nil) noexcept {
  if (node == nil) {
    return nil_;
  }
  RBNode<Key> *new_node = new RBNode<Key>(*node);
  new_node->left_ = CopyTree(node->left_, nil);
  if (new_node->left_ != nil_) {
    new_node->left_->parent_ = new_node;
  }
  new_node->right_ = CopyTree(node->right_, nil);
  if (new_node->right_ != nil_) {
    new_node->right_->parent_ = new_node;
  }
  return new_node;
}

template <typename Key>
RBNode<Key> *RBTree<Key>::GetChild(RBNode<Key> *node) const noexcept {
  if (node->left_ == nil_) {
    return node->right_;
  } else {
    return node->left_;
  }
}

template <typename Key>
void RBTree<Key>::LeftRotate(RBNode<Key> *node) noexcept {
  RBNode<Key> *new_root = node->right_;
  new_root->parent_ = node->parent_;
  if (node->parent_ != nil_) {
    if (node == node->parent_->left_) {
      node->parent_->left_ = new_root;
    } else {
      node->parent_->right_ = new_root;
    }
  }
  if (node == root_) {
    root_ = new_root;
  }
  node->right_ = new_root->left_;
  if (new_root->left_ != nil_) {
    new_root->left_->parent_ = node;
  }
  node->parent_ = new_root;
  new_root->left_ = node;
}

template <typename Key>
void RBTree<Key>::RightRotate(RBNode<Key> *node) noexcept {
  RBNode<Key> *new_root = node->left_;
  new_root->parent_ = node->parent_;
  if (node->parent_ != nil_) {
    if (node == node->parent_->left_) {
      node->parent_->left_ = new_root;
    } else {
      node->parent_->right_ = new_root;
    }
  }
  if (node == root_) {
    root_ = new_root;
  }
  node->left_ = new_root->right_;
  if (new_root->right_ != nil_) {
    new_root->right_->parent_ = node;
  }
  node->parent_ = new_root;
  new_root->right_ = node;
}

template <typename Key>
RBNode<Key> *RBTree<Key>::Insert(Key key) noexcept {
  RBNode<Key> *parent = nil_;
  RBNode<Key> *current = root_;
  while (current != nil_ && current->key_ != key) {
    parent = current;
    if (key < current->key_) {
      current = current->left_;
    } else if (key > current->key_) {
      current = current->right_;
    } else {
      return current;
    }
  }
  RBNode<Key> *new_node = new RBNode<Key>(key);
  new_node->parent_ = parent;
  new_node->left_ = nil_;
  new_node->right_ = nil_;
  if (parent == nil_) {
    root_ = new_node;
    root_->color_ = kBlack;
  } else if (key < parent->key_) {
    parent->left_ = new_node;
  } else {
    parent->right_ = new_node;
  }
  BalanceTreeInsert(new_node);
  return new_node;
}

template <typename Key>
void RBTree<Key>::BalanceTreeInsert(RBNode<Key> *node) noexcept {
  while (node->parent_->color_ == kRed) {
    if (node->parent_ == node->parent_->parent_->left_) {
      BalanceTreeInsertUncleRight(node);
    } else {
      BalanceTreeInsertUncleLeft(node);
    }
  }
  root_->color_ = kBlack;
}

template <typename Key>
void RBTree<Key>::BalanceTreeInsertUncleRight(RBNode<Key> *node) noexcept {
  RBNode<Key> *uncle = node->parent_->parent_->right_;
  if (uncle->color_ == kRed) {
    node->parent_->color_ = kBlack;
    uncle->color_ = kBlack;
    node->parent_->parent_->color_ = kRed;
    node = node->parent_->parent_;
  } else {
    if (node->parent_->right_ == node) {
      node = node->parent_;
      LeftRotate(node);
    }
    node->parent_->color_ = kBlack;
    node->parent_->parent_->color_ = kRed;
    RightRotate(node->parent_->parent_);
  }
}

template <typename Key>
void RBTree<Key>::BalanceTreeInsertUncleLeft(RBNode<Key> *node) noexcept {
  RBNode<Key> *uncle = node->parent_->parent_->left_;
  if (uncle->color_ == kRed) {
    node->parent_->color_ = kBlack;
    uncle->color_ = kBlack;
    node->parent_->parent_->color_ = kRed;
    node = node->parent_->parent_;
  } else {
    if (node->parent_->left_ == node) {
      node = node->parent_;
      RightRotate(node);
    }
    node->parent_->color_ = kBlack;
    node->parent_->parent_->color_ = kRed;
    LeftRotate(node->parent_->parent_);
  }
}

template <typename Key>
RBNode<Key> *RBTree<Key>::Search(Key key) const noexcept {
  if (root_ == nil_) {
    return nil_;
  }
  RBNode<Key> *node = root_;
  while (node != nil_) {
    if (node->key_ == key) {
      return node;
    }
    if (node->key_ > key) {
      node = node->left_;
    } else {
      node = node->right_;
    }
  }
  return nil_;
}

template <typename Key>
RBNode<Key> *RBTree<Key>::GetMin(RBNode<Key> *node) const noexcept {
  if (node == nil_) {
    return nil_;
  }
  while (node->left_ != nil_) {
    node = node->left_;
  }
  return node;
}

template <typename Key>
RBNode<Key> *RBTree<Key>::GetMax(RBNode<Key> *node) const noexcept {
  if (node == nil_) {
    return nil_;
  }
  while (node->right_ != nil_) {
    node = node->right_;
  }
  return node;
}

template <typename Key>
RBNode<Key> *RBTree<Key>::Erase(Key key) noexcept {
  RBNode<Key> *node = Search(key);
  if (node != nil_) {
    Color removed_color = node->color_;
    RBNode<Key> *child;
    if (GetChildrenCount(node) < 2) {
      child = GetChild(node);
      TransplantNode(node, child);
      if (removed_color == kBlack) {
        BalanceTreeErase(child);
      }
      delete node;
    } else {
      RBNode<Key> *max_or_min;
      if (node->left_ != nil_) {
        max_or_min = GetMax(node->left_);
      } else {
        max_or_min = GetMin(node->right_);
      }
      removed_color = max_or_min->color_;
      child = GetChild(max_or_min);
      if (max_or_min->parent_ != node) {
        TransplantNode(max_or_min, child);
        max_or_min->left_ = node->left_;
        max_or_min->left_->parent_ = max_or_min;
        max_or_min->color_ = node->color_;
      }
      TransplantNode(node, max_or_min);
      max_or_min->right_ = node->right_;
      max_or_min->right_->parent_ = max_or_min;
      max_or_min->color_ = node->color_;
      if (removed_color == kBlack) {
        BalanceTreeErase(child);
      }
      delete node;
    }
  }
  return node;
}

template <typename Key>
void RBTree<Key>::Clear(RBNode<Key> *node) noexcept {
  if (node != nil_ && node != nullptr) {
    if (node->left_ != nil_ && node->left_ != nullptr) {
      Clear(node->left_);
    }
    if (node->right_ != nil_ && node->right_ != nullptr) {
      Clear(node->right_);
    }
    delete node;
  }
}

template <typename Key>
void RBTree<Key>::Clear() noexcept {
  if (root_ != nullptr && root_ != nil_) {
    Clear(root_);
    root_ = nil_;
  }
}

template <typename Key>
void RBTree<Key>::TransplantNode(RBNode<Key> *to_node,
                                 RBNode<Key> *from_node) noexcept {
  if (to_node == root_) {
    root_ = from_node;
  } else if (to_node == to_node->parent_->left_) {
    to_node->parent_->left_ = from_node;
  } else {
    to_node->parent_->right_ = from_node;
  }
  from_node->parent_ = to_node->parent_;
}

template <typename Key>
int RBTree<Key>::GetChildrenCount(RBNode<Key> *node) const noexcept {
  int count = 0;
  if (node->left_ != nil_) {
    count++;
  }
  if (node->right_ != nil_) {
    count++;
  }
  return count;
}

template <typename Key>
void RBTree<Key>::BalanceTreeErase(RBNode<Key> *node) noexcept {
  bool flag = true;
  while (flag && node != root_ && node->color_ == kBlack) {
    if (node == node->parent_->left_) {
      flag = BalanceTreeEraseBrotherRight(&node);
    } else {
      flag = BalanceTreeEraseBrotherLeft(&node);
    }
  }
}

template <typename Key>
bool RBTree<Key>::BalanceTreeEraseBrotherRight(RBNode<Key> **node) noexcept {
  bool flag = true;
  RBNode<Key> *brother = (*node)->parent_->right_;
  if (brother->color_ == kRed) {
    brother->color_ = kBlack;
    (*node)->parent_->color_ = kRed;
    LeftRotate((*node)->parent_);
    brother = (*node)->parent_->right_;
  }
  if (brother->color_ == kBlack &&
      (brother->left_ == nil_ || brother->left_->color_ == kBlack) &&
      (brother->right_ == nil_ || brother->right_->color_ == kBlack)) {
    brother->color_ = kRed;
    if ((*node)->parent_->color_ == kRed) {
      (*node)->parent_->color_ = kBlack;
      flag = false;
    }
    if (flag) {
      (*node) = (*node)->parent_;
    }
  } else {
    if (brother->left_ != nil_ && brother->left_->color_ == kRed &&
        (brother->right_ == nil_ || brother->right_->color_ == kBlack)) {
      brother->left_->color_ = kBlack;
      brother->color_ = kRed;
      RightRotate(brother);
      brother = (*node)->parent_->right_;
    }
    brother->color_ = (*node)->parent_->color_;
    (*node)->parent_->color_ = kBlack;
    brother->right_->color_ = kBlack;
    LeftRotate((*node)->parent_);
    (*node) = root_;
  }
  return flag;
}

template <typename Key>
bool RBTree<Key>::BalanceTreeEraseBrotherLeft(RBNode<Key> **node) noexcept {
  bool flag = true;
  RBNode<Key> *brother = (*node)->parent_->left_;
  if (brother->color_ == kRed) {
    brother->color_ = kBlack;
    (*node)->parent_->color_ = kRed;
    RightRotate((*node)->parent_);
    brother = (*node)->parent_->left_;
  }
  if (brother->color_ == kBlack &&
      (brother->right_ == nil_ || brother->right_->color_ == kBlack) &&
      (brother->left_ == nil_ || brother->left_->color_ == kBlack)) {
    brother->color_ = kRed;
    if ((*node)->parent_->color_ == kRed) {
      (*node)->parent_->color_ = kBlack;
      flag = false;
    }
    if (flag) {
      (*node) = (*node)->parent_;
    }
  } else {
    if (brother->right_ != nil_ && brother->right_->color_ == kRed &&
        (brother->left_ == nil_ || brother->left_->color_ == kBlack)) {
      brother->right_->color_ = kBlack;
      brother->color_ = kRed;
      LeftRotate(brother);
      brother = (*node)->parent_->left_;
    }
    brother->color_ = (*node)->parent_->color_;
    (*node)->parent_->color_ = kBlack;
    brother->left_->color_ = kBlack;
    RightRotate((*node)->parent_);
    (*node) = root_;
  }
  return flag;
}

}  // namespace s21