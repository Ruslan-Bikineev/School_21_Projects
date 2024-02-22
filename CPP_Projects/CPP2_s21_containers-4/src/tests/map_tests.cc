#include <gtest/gtest.h>

#include <map>

#include "../s21_containers.h"

TEST(MapConstructors, DefaultConstructor) {
  s21::Map<int, int> s21_map;
  std::map<int, int> std_map;
  ASSERT_EQ(s21_map.Size(), 0);
  ASSERT_EQ(s21_map.Empty(), true);
}

TEST(MapConstructors, RangeConstructor) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  ASSERT_EQ(s21_map.Size(), std_map.size());
  ASSERT_EQ(s21_map.Empty(), std_map.empty());
  auto s21_map_it = s21_map.End();
  auto std_map_it = std_map.end();
  --s21_map_it;
  --std_map_it;
  for (; s21_map_it != s21_map.Begin(); s21_map_it--, std_map_it--) {
    ASSERT_EQ((*s21_map_it).first, (*std_map_it).first);
    ASSERT_EQ((*s21_map_it).second, (*std_map_it).second);
  }
}

TEST(MapConstructors, CopyConstructor) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  s21::Map<int, int> s21_map_copy(s21_map);
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map_copy(std_map);
  ASSERT_EQ(s21_map.Size(), std_map.size());
  ASSERT_EQ(s21_map.Empty(), std_map.empty());
  ASSERT_EQ(s21_map[1], std_map[1]);
  ASSERT_EQ(s21_map[2], std_map[2]);
  ASSERT_EQ(s21_map[3], std_map[3]);
  ASSERT_EQ(s21_map_copy.Size(), std_map_copy.size());
  ASSERT_EQ(s21_map_copy.Empty(), std_map_copy.empty());
  ASSERT_EQ(s21_map_copy[1], std_map_copy[1]);
  ASSERT_EQ(s21_map_copy[2], std_map_copy[2]);
  ASSERT_EQ(s21_map_copy[3], std_map_copy[3]);
}

TEST(MapConstructors, MoveConstructor) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  s21::Map<int, int> s21_map_copy(std::move(s21_map));
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map_copy(std::move(std_map));
  ASSERT_EQ(s21_map.Size(), std_map.size());
  ASSERT_EQ(s21_map.Empty(), std_map.empty());
  s21_map.Insert(1, 1);
  std_map.insert({1, 1});
  s21_map.InsertOrAssign(5, 5);
  std_map.insert_or_assign(5, 5);
  ASSERT_EQ(s21_map_copy.Size(), std_map_copy.size());
  ASSERT_EQ(s21_map_copy.Empty(), std_map_copy.empty());
  auto s21_it = s21_map.Begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.End(); ++s21_it, ++std_it) {
    ASSERT_EQ(*s21_it, *std_it);
    ASSERT_EQ(*s21_it, *std_it);
  }
  auto s21_copy_it = s21_map_copy.Begin();
  auto std_copy_it = std_map_copy.begin();
  for (; s21_copy_it != s21_map_copy.End(); ++s21_copy_it, ++std_copy_it) {
    ASSERT_EQ(*s21_copy_it, *std_copy_it);
    ASSERT_EQ(*s21_copy_it, *std_copy_it);
  }
}

TEST(MapInsert, Insert) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  s21_map.Insert({4, 4});
  s21_map.InsertOrAssign(4, 444);
  s21_map.InsertOrAssign(3, 333);
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  std_map.insert({4, 4});
  std_map.insert_or_assign(4, 444);
  std_map.insert_or_assign(3, 333);
  ASSERT_EQ(s21_map.Size(), std_map.size());
  ASSERT_EQ(s21_map.Empty(), std_map.empty());
  auto s21_it = s21_map.Begin();
  auto std_it = std_map.begin();
  while (s21_it != s21_map.End()) {
    ASSERT_EQ((*s21_it).first, (*std_it).first);
    ASSERT_EQ((*s21_it).second, (*std_it).second);
    s21_it++;
    std_it++;
  }
}

TEST(MapErase, Erase_1) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  s21_map.Erase(1);
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  std_map.erase(1);
  ASSERT_EQ(s21_map.Size(), std_map.size());
  auto s21_it = s21_map.Begin();
  auto std_it = std_map.begin();
  while (std_it != std_map.end()) {
    ASSERT_EQ((*s21_it).first, (*std_it).first);
    ASSERT_EQ((*s21_it).second, (*std_it).second);
    ++s21_it;
    ++std_it;
  }
}

TEST(MapErase, Erase_2) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  auto s21_it = s21_map.Begin();
  auto std_it = std_map.begin();
  s21_map.Erase(s21_it++);
  std_map.erase(std_it++);
  s21_map.Erase(1);
  std_map.erase(1);
  s21_map.Erase(2);
  std_map.erase(2);
  s21_map.Erase(3);
  std_map.erase(3);
  ASSERT_EQ(s21_map.Size(), std_map.size());
  auto s21_it_1 = s21_map.Begin();
  auto std_it_1 = std_map.begin();
  while (s21_it_1 != s21_map.End()) {
    ASSERT_EQ((*s21_it_1).first, (*std_it_1).first);
    ASSERT_EQ((*s21_it_1).second, (*std_it_1).second);
    ++s21_it_1;
    ++std_it_1;
  }
}

TEST(RBTreeBalanceTreeErase, Erase_3) {
  s21::Map<int, int> s21_map;
  s21_map.Insert(30, 30);
  s21_map.Insert(20, 20);
  s21_map.Insert(40, 40);
  s21_map.Insert(10, 10);
  s21_map.Insert(25, 25);
  s21_map.Insert(35, 35);
  s21_map.Insert(50, 50);
  s21_map.Insert({45, 45});
  s21_map.Erase(35);
  std::map<int, int> std_map;
  std_map.insert({30, 30});
  std_map.insert({20, 20});
  std_map.insert({40, 40});
  std_map.insert({10, 10});
  std_map.insert({25, 25});
  std_map.insert({35, 35});
  std_map.insert({50, 50});
  std_map.insert({45, 45});
  std_map.erase(35);
  ASSERT_EQ(s21_map.Size(), std_map.size());
  auto s21_it = s21_map.Begin();
  auto std_it = std_map.begin();
  while (s21_it != s21_map.End()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(MapClear, Clear) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  s21_map.Clear();
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  std_map.clear();
  ASSERT_EQ(s21_map.Size(), std_map.size());
  ASSERT_EQ(s21_map.Empty(), std_map.empty());
}

TEST(MapSwap, Swap) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  s21::Map<int, int> s21_map_copy = {{4, 4}, {5, 5}, {6, 6}};
  s21_map.Swap(s21_map_copy);
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map_copy = {{4, 4}, {5, 5}, {6, 6}};
  std_map.swap(std_map_copy);
  ASSERT_EQ(s21_map.Size(), std_map.size());
  ASSERT_EQ(s21_map.Empty(), std_map.empty());
  auto s21_it = s21_map.Begin();
  auto std_it = std_map.begin();
  while (std_it != std_map.end()) {
    ASSERT_EQ((*s21_it).first, (*std_it).first);
    ASSERT_EQ((*s21_it).second, (*std_it).second);
    ++s21_it;
    ++std_it;
  }
  ASSERT_EQ(s21_map_copy.Size(), std_map_copy.size());
  ASSERT_EQ(s21_map_copy.Empty(), std_map_copy.empty());
  auto s21_it_copy = s21_map_copy.Begin();
  auto std_it_copy = std_map_copy.begin();
  while (std_it_copy != std_map_copy.end()) {
    ASSERT_EQ((*s21_it_copy).first, (*std_it_copy).first);
    ASSERT_EQ((*s21_it_copy).second, (*std_it_copy).second);
    ++s21_it_copy;
    ++std_it_copy;
  }
}

TEST(MapMerge, Merge) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  s21::Map<int, int> s21_map_copy = {{4, 4}, {3, 5}, {6, 6}};
  s21_map.Merge(s21_map_copy);
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map_copy = {{4, 4}, {3, 5}, {6, 6}};
  std_map.merge(std_map_copy);
  ASSERT_EQ(s21_map.Size(), std_map.size());
  ASSERT_EQ(s21_map_copy.Size(), std_map_copy.size());
  ASSERT_EQ(s21_map.Empty(), std_map.empty());
  auto s21_it = s21_map.Begin();
  auto std_it = std_map.begin();
  while (std_it != std_map.end()) {
    ASSERT_EQ((*s21_it).first, (*std_it).first);
    ASSERT_EQ((*s21_it).second, (*std_it).second);
    ++s21_it;
    ++std_it;
  }
}

TEST(MapContains, Contains) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  ASSERT_EQ(s21_map.Contains(1), true);
  ASSERT_EQ(s21_map.Contains(2), true);
  ASSERT_EQ(s21_map.Contains(3), true);
  ASSERT_EQ(s21_map.Contains(4), false);
}

TEST(MapAccess, AtAndBrackets_1) {
  s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(s21_map.At(1), std_map.at(1));
  EXPECT_EQ(s21_map[2], std_map[2]);
  EXPECT_THROW(s21_map.At(4), std::out_of_range);
  s21_map[4] = 4;
  std_map[4] = 4;
  EXPECT_EQ(s21_map[4], std_map[4]);
  s21_map[2] = 5;
  std_map[2] = 5;
  EXPECT_EQ(s21_map[2], std_map[2]);
}

TEST(MapAccess, AtAndBrackets_2) {
  const s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  const std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(s21_map.At(1), std_map.at(1));
  EXPECT_THROW(s21_map.At(4), std::out_of_range);
}

TEST(MapAssignment, CopyAssignment) {
  s21::Map<int, int> s21_map_original = {{1, 10}, {2, 20}, {3, 30}};
  s21::Map<int, int> s21_map_assigned;
  s21_map_assigned = s21_map_original;
  std::map<int, int> std_map_original = {{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> std_map_assigned;
  std_map_assigned = std_map_original;
  ASSERT_EQ(s21_map_assigned.Size(), std_map_assigned.size());
  ASSERT_EQ(s21_map_original.Size(), std_map_original.size());
  auto s21_it = s21_map_original.Begin();
  auto std_it = std_map_original.begin();
  for (; s21_it != s21_map_original.End() || std_it != std_map_original.end();
       ++s21_it, ++std_it) {
    ASSERT_EQ((*s21_it).first, (*std_it).first);
    ASSERT_EQ((*s21_it).second, (*std_it).second);
  }
}

TEST(MapAssignment, MoveAssignment) {
  s21::Map<int, int> s21_map_original = {{1, 10}, {2, 20}, {3, 30}};
  s21::Map<int, int> s21_map_assigned = {{4, 40}, {5, 50}, {6, 60}};
  s21_map_assigned = std::move(s21_map_original);
  std::map<int, int> std_map_original = {{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> std_map_assigned = {{4, 40}, {5, 50}, {6, 60}};
  std_map_assigned = std::move(std_map_original);
  ASSERT_EQ(s21_map_assigned.Size(), std_map_assigned.size());
  ASSERT_TRUE(s21_map_original.Empty());
  ASSERT_TRUE(std_map_original.empty());
  s21_map_original.Insert({10, 100});
  std_map_original.insert({10, 100});
  s21_map_original.Insert({11, 110});
  std_map_original.insert({11, 110});
  ASSERT_EQ(s21_map_original.Size(), std_map_original.size());
  auto s21_it = s21_map_original.Begin();
  auto std_it = std_map_original.begin();
  for (; s21_it != s21_map_original.End() && std_it != std_map_original.end();
       ++s21_it, ++std_it) {
    ASSERT_EQ((*s21_it).first, (*std_it).first);
    ASSERT_EQ((*s21_it).second, (*std_it).second);
  }
}

TEST(MapConst, MapConstTest) {
  const s21::Map<int, int> s21_map = {{1, 1}, {2, 2}, {3, 3}};
  const std::map<int, int> std_map = {{1, 1}, {2, 2}, {3, 3}};
  ASSERT_EQ(s21_map.Size(), std_map.size());
  ASSERT_EQ(s21_map.Empty(), std_map.empty());
  auto s21_it = s21_map.Begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.End() && std_it != std_map.end();
       ++s21_it, ++std_it) {
    ASSERT_EQ((*s21_it).first, (*std_it).first);
    ASSERT_EQ((*s21_it).second, (*std_it).second);
  }
}