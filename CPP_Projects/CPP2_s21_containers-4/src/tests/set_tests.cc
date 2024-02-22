#include <gtest/gtest.h>

#include <set>

#include "../s21_containers.h"

TEST(SetConstructors, DefaultConstructor) {
  s21::Set<int> s21_set;
  std::set<int> std_set;
  ASSERT_EQ(s21_set.Size(), std_set.size());
  ASSERT_EQ(s21_set.Empty(), std_set.empty());
}

TEST(SetConstructors, InitializerListConstructor) {
  const s21::Set<int> s21_set = {1, 2, 3};
  const std::set<int> std_set = {1, 2, 3};
  ASSERT_EQ(s21_set.Size(), std_set.size());
  ASSERT_FALSE(s21_set.Empty());
  auto s21_it = s21_set.Begin();
  std::set<int>::const_iterator std_it = std_set.begin();
  for (; s21_it != s21_set.End() && std_it != std_set.end();
       ++s21_it, ++std_it) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(SetConstructors, CopyConstructor) {
  s21::Set<int> s21_set = {1, 2, 3};
  s21::Set<int> s21_set_copy(s21_set);
  std::set<int> std_set = {1, 2, 3};
  std::set<int> std_set_copy(std_set);
  auto s21_it_1 = s21_set_copy.Begin();
  auto std_it_1 = std_set_copy.begin();
  std_set_copy.erase(++std_it_1);
  s21_set_copy.Erase(++s21_it_1);
  std_set_copy.erase(10);
  s21_set_copy.Erase(10);
  ASSERT_EQ(s21_set_copy.Size(), std_set_copy.size());
  auto s21_it_2 = s21_set_copy.Begin();
  auto std_it_2 = std_set_copy.begin();
  for (; s21_it_2 != s21_set_copy.End() && std_it_2 != std_set_copy.end();
       ++s21_it_2, ++std_it_2) {
    ASSERT_EQ(*s21_it_2, *std_it_2);
  }
  auto s21_it = s21_set.Begin();
  auto std_it = std_set.begin();
  for (; s21_it != s21_set.End(); ++s21_it, ++std_it) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(SetConstructors, MoveConstructor) {
  s21::Set<int> original_set = {1, 2, 3};
  s21::Set<int> s21_set_copy(std::move(original_set));
  std::set<int> std_set = {1, 2, 3};
  std::set<int> std_set_copy(std::move(std_set));
  ASSERT_EQ(s21_set_copy.Size(), std_set_copy.size());
  ASSERT_FALSE(s21_set_copy.Empty());
}

TEST(SetInsert, Insert_1) {
  s21::Set<int> s21_set;
  std::set<int> std_set;
  for (int i = 0; i < 5; ++i) {
    s21_set.Insert(i);
    std_set.insert(i);
  }
  ASSERT_EQ(s21_set.Size(), std_set.size());
  auto s21_it = s21_set.End();
  auto std_it = std_set.end();
  --s21_it;
  --std_it;
  for (; s21_it != s21_set.Begin() && std_it != std_set.begin();
       s21_it--, std_it--) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(SetInsert, Insert_2) {
  s21::Set<int> s21_set = {1, 2, 3, 4, 5};
  std::set<int> std_set = {1, 2, 3, 4, 5};
  for (int i = 0; i < 10; ++i) {
    auto s21_it = s21_set.Insert(i);
    auto std_it = std_set.insert(i);
    ASSERT_EQ(*s21_it.first, *std_it.first);
    ASSERT_EQ(s21_it.second, std_it.second);
  }
  ASSERT_EQ(s21_set.Size(), std_set.size());
  auto s21_it = s21_set.Begin();
  auto std_it = std_set.begin();
  for (; s21_it != s21_set.End(); s21_it--, std_it--) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(SetErase, Erase_1) {
  s21::Set<int> s21_set = {60, 85, 54, 95, 7, 63, 98, 74, 42, 90, 81, 20, 15};
  std::set<int> std_set = {60, 85, 54, 95, 7, 63, 98, 74, 42, 90, 81, 20, 15};
  s21_set.Erase(s21_set.Find(3));
  std_set.erase(3);
  s21_set.Erase(60);
  std_set.erase(60);
  s21_set.Erase(74);
  std_set.erase(74);
  s21_set.Erase(81);
  std_set.erase(81);
  s21_set.Erase(20);
  std_set.erase(20);
  s21_set.Erase(54);
  std_set.erase(54);
  s21_set.Erase(7);
  std_set.erase(7);
  s21_set.Erase(95);
  std_set.erase(95);
  s21_set.Erase(15);
  std_set.erase(15);
  s21_set.Erase(85);
  std_set.erase(85);
  s21_set.Erase(60);
  std_set.erase(60);
  ASSERT_EQ(s21_set.Size(), std_set.size());
  auto s21_it = s21_set.Begin();
  auto std_it = std_set.begin();
  for (; s21_it != s21_set.End() && std_it != std_set.end();) {
    ASSERT_EQ((*s21_it++), *std_it++);
  }
}

TEST(SetErase, Erase_2) {
  s21::Set<int> s21_set = {1, 2, 3};
  std::set<int> std_set = {1, 2, 3};
  s21_set.Erase(1);
  std_set.erase(1);
  s21_set.Erase(2);
  std_set.erase(2);
  s21_set.Erase(3);
  std_set.erase(3);
  ASSERT_EQ(s21_set.Size(), std_set.size());
  auto s21_it = s21_set.Begin();
  auto std_it = std_set.begin();
  while (std_it != std_set.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(SetClear, Clear) {
  s21::Set<int> s21_set = {1, 2, 3, 4, 5};
  std::set<int> std_set = {1, 2, 3, 4, 5};
  s21_set.Clear();
  std_set.clear();
  ASSERT_EQ(s21_set.Empty(), std_set.empty());
  s21_set.Insert(1);
  std_set.insert(1);
  s21_set.Insert(2);
  std_set.insert(2);
  s21_set.Insert(3);
  std_set.insert(3);
  ASSERT_EQ(s21_set.Size(), std_set.size());
  auto s21_it = s21_set.Begin();
  auto std_it = std_set.begin();
  for (; s21_it != s21_set.End(); ++s21_it, ++std_it) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(SetContains, Contains) {
  s21::Set<int> s21_set = {1, 2, 3, 4, 5};
  ASSERT_TRUE(s21_set.Contains(3));
  ASSERT_FALSE(s21_set.Contains(6));
}

TEST(SetSwap, Swap) {
  s21::Set<int> s21_set1 = {1, 2, 3};
  s21::Set<int> s21_set2 = {4, 5, 6};
  std::set<int> std_set1 = {1, 2, 3};
  std::set<int> std_set2 = {4, 5, 6};
  s21_set1.Swap(s21_set2);
  std_set1.swap(std_set2);
  ASSERT_EQ(s21_set1.Size(), std_set1.size());
  ASSERT_EQ(s21_set2.Size(), std_set2.size());
  auto s21_it1 = s21_set1.Begin();
  auto std_it1 = std_set1.begin();
  for (; s21_it1 != s21_set1.End() && std_it1 != std_set1.end();
       ++s21_it1, ++std_it1) {
    ASSERT_EQ(*s21_it1, *std_it1);
  }
  auto s21_it2 = s21_set2.Begin();
  auto std_it2 = std_set2.begin();
  for (; s21_it2 != s21_set2.End(); ++s21_it2, ++std_it2) {
    ASSERT_EQ(*s21_it2, *std_it2);
  }
}

TEST(SetMerge, Merge) {
  s21::Set<int> s21_set1 = {1, 2, 3};
  s21::Set<int> s21_set2 = {3, 4, 5};
  std::set<int> std_set1 = {1, 2, 3};
  std::set<int> std_set2 = {3, 4, 5};
  s21_set1.Merge(s21_set2);
  std_set1.merge(std_set2);
  ASSERT_EQ(s21_set1.Size(), std_set1.size());
  auto s21_it = s21_set1.Begin();
  auto std_it = std_set1.begin();
  for (; s21_it != s21_set1.End() && std_it != std_set1.end();
       ++s21_it, ++std_it) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(SetIterators, EqualityInequality) {
  s21::Set<int> s21_set = {1, 2, 3, 4, 5};
  auto it1 = s21_set.Begin();
  auto it2 = s21_set.Begin();
  auto it3 = s21_set.End();
  ASSERT_TRUE(it1 == it2);
  ASSERT_FALSE(it1 == it3);
  ASSERT_FALSE(it1 != it2);
  ASSERT_TRUE(it1 != it3);
}

TEST(SetFinc, Find) {
  s21::Set<int> s21_set = {1, 2, 3, 4, 5};
  auto s21_found = s21_set.Find(3);
  std::set<int> std_set = {1, 2, 3, 4, 5};
  auto std_found = std_set.find(3);
  ASSERT_EQ(*s21_found, *std_found);
}

TEST(SetAssignment, CopyAssignment) {
  s21::Set<int> s21_set_original = {1, 2, 3};
  s21::Set<int> s21_set_assigned;
  s21_set_assigned = s21_set_original;
  std::set<int> std_set_original = {1, 2, 3};
  std::set<int> std_set_assigned;
  std_set_assigned = std_set_original;
  ASSERT_EQ(s21_set_assigned.Size(), std_set_assigned.size());
  ASSERT_EQ(s21_set_original.Size(), std_set_original.size());
  auto s21_it = s21_set_original.Begin();
  auto std_it = std_set_original.begin();
  for (; s21_it != s21_set_original.End() && std_it != std_set_original.end();
       ++s21_it, ++std_it) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(SetAssignment, MoveAssignment) {
  s21::Set<int> s21_set_original = {60, 85, 54, 95, 7,  63, 98, 63,
                                    98, 74, 42, 90, 81, 20, 15};
  s21::Set<int> s21_set_assigned = {4, 5, 6};
  s21_set_assigned = std::move(s21_set_original);
  std::set<int> std_set_original = {60, 85, 54, 95, 7,  63, 98, 63,
                                    98, 74, 42, 90, 81, 20, 15};
  std::set<int> std_set_assigned = {4, 5, 6};
  std_set_assigned = std::move(std_set_original);
  ASSERT_EQ(s21_set_assigned.Size(), std_set_assigned.size());
  ASSERT_EQ(s21_set_original.Empty(), std_set_original.empty());
  s21_set_original.Insert(63);
  std_set_original.insert(63);
  s21_set_original.Insert(11);
  std_set_original.insert(11);
  ASSERT_EQ(s21_set_original.Size(), std_set_original.size());
  auto s21_it = s21_set_original.Begin();
  auto std_it = std_set_original.begin();
  for (; s21_it != s21_set_original.End() && std_it != std_set_original.end();
       ++s21_it, ++std_it) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(SetConstIterator, ConstIterator) {
  const s21::Set<int> s21_set = {1, 2, 3, 4, 5};
  const std::set<int> std_set = {1, 2, 3, 4, 5};
  auto s21_it = s21_set.Begin();
  auto std_it = std_set.begin();
  ASSERT_EQ(s21_set.Size(), std_set.size());
  for (; s21_it != s21_set.End() || std_it != std_set.end();
       ++s21_it, ++std_it) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(SetIterator, IteratorPlus) {
  const s21::Set<int> s21_set = {1, 2, 3, 4, 5};
  const std::set<int> std_set = {1, 2, 3, 4, 5};
  auto s21_it = s21_set.Begin();
  auto std_it = std_set.begin();
  ASSERT_EQ(s21_set.Size(), std_set.size());
  size_t count = 0;
  for (; count < s21_set.Size() + 1; ++s21_it, ++std_it) {
    if (count != s21_set.Size()) {
      ASSERT_EQ(*s21_it, *std_it);
    }
    ++count;
  }
}

TEST(SetIterator, IteratorMinus) {
  const s21::Set<int> s21_set = {1, 2, 3, 4, 5};
  const std::set<int> std_set = {1, 2, 3, 4, 5};
  auto s21_it = s21_set.End();
  auto std_it = std_set.end();
  ASSERT_EQ(s21_set.Size(), std_set.size());
  size_t count = 0;
  --s21_it;
  --std_it;
  for (; count < s21_set.Size(); --s21_it, --std_it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++count;
  }
}
