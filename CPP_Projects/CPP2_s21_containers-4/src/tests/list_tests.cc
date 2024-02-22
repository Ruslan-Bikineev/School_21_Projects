#include <gtest/gtest.h>

#include <list>

#include "../s21_containers.h"

using namespace s21;
using namespace std;

/*------------------------CONSTRUCTORS_TESTS--------------------------*/
/* Based constructor */
TEST(ConstructorListTest, ConstructorListTest_1) {
  // Arrange
  list<int> stl_list;
  auto stl_it = stl_list.begin();
  // Act
  List<int> list;
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Constructor creates the list of size n */
TEST(ConstructorListTest, ConstructorListTest_2) {
  // Arrange
  list<char> stl_list(5);
  auto stl_it = stl_list.begin();
  // Act
  List<char> list(5);
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Constructor with initializer list  */
TEST(ConstructorListTest, ConstructorListTest_3) {
  // Arrange
  list<unsigned> stl_list{5, 4, 3, 2, 1};
  auto stl_it = stl_list.begin();
  // Act
  List<unsigned> list{5, 4, 3, 2, 1};
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Copy constructor data is null*/
TEST(ConstructorListTest, ConstructorListTest_4) {
  // Arrange
  List<string> list1;
  auto it1 = list1.Begin();
  // Act
  List<string> list2(list1);
  // Assert
  ASSERT_EQ(list1.Size(), list2.Size());
  for (auto it2 = list2.Begin(); it2 != list2.End(); it1++, it2++) {
    ASSERT_EQ(*it1, *it2);
  }
}

/* Copy constructor */
TEST(ConstructorListTest, ConstructorListTest_5) {
  // Arrange
  List<string> list1{"test1", "test2", "test3", "test4", "test5"};
  auto it1 = list1.Begin();
  // Act
  List<string> list2(list1);
  // Assert
  ASSERT_EQ(list1.Size(), list2.Size());
  for (auto it2 = list2.Begin(); it2 != list2.End(); it1++, it2++) {
    ASSERT_EQ(*it1, *it2);
  }
}

/* Move constructor data is null */
TEST(ConstructorListTest, ConstructorListTest_6) {
  // Arrange
  list<double> stl_list;
  list<double> new_stl_list(move(stl_list));
  auto stl_it = stl_list.begin();
  auto new_stl_it = new_stl_list.begin();
  List<double> list;
  // Act
  List<double> new_list(move(list));
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  ASSERT_EQ(new_stl_list.size(), new_list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
  for (auto it = new_list.Begin(); it != new_list.End(); it++, new_stl_it++) {
    ASSERT_EQ(*it, *new_stl_it);
  }
}

/* Move constructor */
TEST(ConstructorListTest, ConstructorListTest_7) {
  // Arrange
  list<double> stl_list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  list<double> new_stl_list(move(stl_list));
  auto stl_it = stl_list.begin();
  auto new_stl_it = new_stl_list.begin();
  List<double> list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // Act
  List<double> new_list(move(list));
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  ASSERT_EQ(new_stl_list.size(), new_list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
  for (auto it = new_list.Begin(); it != new_list.End(); it++, new_stl_it++) {
    ASSERT_EQ(*it, *new_stl_it);
  }
}
/*----------------------------FRONT_TESTS-----------------------------*/
/* Function Front() list is null */
TEST(FrontListTest, FrontListTest_1) {
  // Arrange
  list<unsigned> stl_list;
  List<unsigned> list;
  // Act
  // Assert
  ASSERT_EQ(stl_list.front(), list.Front());
}

/* Function Front() double list */
TEST(FrontListTest, FrontListTest_2) {
  // Arrange
  list<double> stl_list{10, 5, 3, 7, 6, 1};
  List<double> list{10, 5, 3, 7, 6, 1};
  // Act
  // Assert
  ASSERT_EQ(stl_list.front(), list.Front());
}
/*-----------------------------BACK_TESTS-----------------------------*/
/* Function Back() list is null */
TEST(BackListTest, BackListTest_1) {
  // Arrange
  list<int> stl_list;
  List<int> list;
  // Act
  // Assert
  ASSERT_EQ(stl_list.back(), list.Back());
}

/* Function Back() string list */
TEST(BackListTest, BackListTest_2) {
  // Arrange
  list<string> stl_list{"test1", "test2", "test3", "test4", "test5"};
  List<string> list{"test1", "test2", "test3", "test4", "test5"};
  // Act
  // Assert
  ASSERT_EQ(stl_list.back(), list.Back());
}
/*--------------------------PUSHFRONT_TESTS---------------------------*/
/* Function PushFront() list is null */
TEST(PushFrontListTest, PushFrontListTest_1) {
  // Arrange
  list<double> stl_list;
  stl_list.push_front(777);
  auto stl_it = stl_list.begin();
  List<double> list;
  // Act
  list.PushFront(777);
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function PushFront() int list */
TEST(PushFrontListTest, PushFrontListTest_2) {
  // Arrange
  list<int> stl_list{10, 5, 3, 7, 6, 1};
  stl_list.push_front(777);
  auto stl_it = stl_list.begin();
  List<int> list{10, 5, 3, 7, 6, 1};
  // Act
  list.PushFront(777);
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function PushFront() string list */
TEST(PushFrontListTest, PushFrontListTest_3) {
  // Arrange
  list<string> stl_list{"test1", "test2"};
  stl_list.push_front("GTEST");
  auto stl_it = stl_list.begin();
  List<string> list{"test1", "test2"};
  // Act
  list.PushFront("GTEST");
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*--------------------------PUSHBACK_TESTS---------------------------*/
/* Function PushBack() list is null */
TEST(PushBackListTest, PushBackListTest_1) {
  // Arrange
  list<double> stl_list;
  stl_list.push_back(21);
  auto stl_it = stl_list.begin();
  List<double> list;
  // Act
  list.PushBack(21);
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function PushBack() int list */
TEST(PushBackListTest, PushBackListTest_2) {
  // Arrange
  list<int> stl_list{10, 5, 3, 7, 6, 1};
  stl_list.push_back(21);
  auto stl_it = stl_list.begin();
  List<int> list{10, 5, 3, 7, 6, 1};
  // Act
  list.PushBack(21);
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function PushBack() string list */
TEST(PushBackListTest, PushBackListTest_3) {
  // Arrange
  list<string> stl_list{"test1", "test2"};
  stl_list.push_back("GTEST");
  auto stl_it = stl_list.begin();
  List<string> list{"test1", "test2"};
  // Act
  list.PushBack("GTEST");
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*---------------------------POPRONT_TESTS---------------------------*/
/* Function PopFront() string list */
TEST(PopFrontListTest, PopFrontListTest_1) {
  // Arrange
  list<string> stl_list{"test1", "test2", "test3", "test4", "test5"};
  stl_list.pop_front();
  auto stl_it = stl_list.begin();
  List<string> list{"test1", "test2", "test3", "test4", "test5"};
  // Act
  list.PopFront();
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*---------------------------POPBACK_TESTS---------------------------*/
/* Function PopFront() string list */
TEST(PopBackListTest, PopBackListTest_1) {
  // Arrange
  list<string> stl_list{"test1", "test2", "test3", "test4", "test5"};
  stl_list.pop_back();
  auto stl_it = stl_list.begin();
  List<string> list{"test1", "test2", "test3", "test4", "test5"};
  // Act
  list.PopBack();
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*----------------------------UNIQUE_TESTS---------------------------*/
/* Function Unique() list is null */
TEST(UniqueListTest, UniqueListTest_1) {
  // Arrange
  list<double> stl_list;
  stl_list.unique();
  auto stl_it = stl_list.begin();
  List<double> list;
  // Act
  list.Unique();
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Unique() int list */
TEST(UniqueListTest, UniqueListTest_2) {
  // Arrange
  list<int> stl_list{1, 2, 2, 2, 3, 2, 4, 4, 5, 0, 0, 0};
  stl_list.unique();
  auto stl_it = stl_list.begin();
  List<int> list{1, 2, 2, 2, 3, 2, 4, 4, 5, 0, 0, 0};
  // Act
  list.Unique();
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Unique() char list */
TEST(UniqueListTest, UniqueListTest_3) {
  // Arrange
  list<char> stl_list{'a', 'a', 'v', 'a', 't', 't', 't', 'w', 'w', 'y', 'w'};
  stl_list.unique();
  auto stl_it = stl_list.begin();
  List<char> list{'a', 'a', 'v', 'a', 't', 't', 't', 'w', 'w', 'y', 'w'};
  // Act
  list.Unique();
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*----------------------------INSERT_TESTS---------------------------*/
/* Function Insert() list is null */
TEST(InsertListTest, InsertListTest_1) {
  // Arrange
  list<unsigned> stl_list;
  auto stl_it_return = stl_list.insert(stl_list.begin(), 5);
  auto stl_it = stl_list.begin();
  List<unsigned> list;
  // Act
  auto it_return = list.Insert(list.Begin(), 5);
  // Assert
  ASSERT_EQ(*it_return, *stl_it_return);
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() in begin string list */
TEST(InsertListTest, InsertListTest_2) {
  // Arrange
  list<string> stl_list{"test1", "test2", "test3", "test4", "test5"};
  auto stl_it_return = stl_list.insert(stl_list.begin(), "START");
  auto stl_it = stl_list.begin();
  List<string> list{"test1", "test2", "test3", "test4", "test5"};
  // Act
  auto it_return = list.Insert(list.Begin(), "START");
  // Assert
  ASSERT_EQ(*it_return, *stl_it_return);
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() in end char list */
TEST(InsertListTest, InsertListTest_3) {
  // Arrange
  list<char> stl_list{'t', 'e', 's', 't', '5'};
  auto stl_it_return = stl_list.insert(stl_list.end(), '0');
  auto stl_it = stl_list.begin();
  List<char> list{'t', 'e', 's', 't', '5'};
  // Act
  auto it_return = list.Insert(list.End(), '0');
  // Assert
  ASSERT_EQ(*it_return, *stl_it_return);
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() in middle int list */
TEST(InsertListTest, InsertListTest_4) {
  // Arrange
  list<int> stl_list{5, 0, 2, 8, 4, 6, 1};
  auto stl_it = stl_list.begin();
  advance(stl_it, 4);
  auto stl_it_return = stl_list.insert(stl_it, 100);
  stl_it = stl_list.begin();
  List<int> list{5, 0, 2, 8, 4, 6, 1};
  auto it = list.Begin();
  it++;
  it++;
  it++;
  it++;
  // Act
  auto it_return = list.Insert(it, 100);
  // Assert
  ASSERT_EQ(*it_return, *stl_it_return);
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*-----------------------------ERASE_TESTS---------------------------*/
/* Function Erase() list is null */
TEST(EraseListTest, EraseListTest_1) {
  // Arrange
  List<unsigned> list;
  auto it = list.Begin();
  // Act
  list.Erase(it);
  // Assert
  ASSERT_EQ(0, list.Size());
  for (auto it = list.Begin(); it != list.End(); it++) {
    ASSERT_EQ(*it, 0);
  }
}

/* Function Erase() in begin int list */
TEST(EraseListTest, EraseListTest_2) {
  // Arrange
  list<int> stl_list{5, 0, 2, 8, 4, 6, 1};
  auto stl_it = stl_list.begin();
  stl_list.erase(stl_it);
  stl_it = stl_list.begin();
  List<int> list{5, 0, 2, 8, 4, 6, 1};
  auto it = list.Begin();
  // Act
  list.Erase(it);
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Erase() in end double list */
TEST(EraseListTest, EraseListTest_3) {
  // Arrange
  list<double> stl_list{5, 0, 2, 8, 4, 6, 1};
  auto stl_it = stl_list.end();
  stl_it--;
  stl_list.erase(stl_it);
  stl_it = stl_list.begin();
  List<double> list{5, 0, 2, 8, 4, 6, 1};
  auto it = list.End();
  it--;
  // Act
  list.Erase(it);
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Erase() in middle string list */
TEST(EraseListTest, EraseListTest_4) {
  // Arrange
  list<string> stl_list{"test1", "test2", "test3", "test4", "test5"};
  auto stl_it = stl_list.begin();
  advance(stl_it, 2);
  stl_list.erase(stl_it);
  stl_it = stl_list.begin();
  List<string> list{"test1", "test2", "test3", "test4", "test5"};
  auto it = list.Begin();
  it++;
  ++it;
  // Act
  list.Erase(it);
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*----------------------------SIZEMAX_TESTS--------------------------*/
/* Function SizeMax() list is null */
TEST(SizeMaxListTest, SizeMaxListTest_1) {
  // Arrange
  list<unsigned> stl_list;
  List<unsigned> list;
  // Act
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  ASSERT_EQ(stl_list.max_size(), list.MaxSize());
}

/* Function SizeMax() char list  */
TEST(SizeMaxListTest, SizeMaxListTest_2) {
  // Arrange
  list<char> stl_list{'t', 'e', 's', 't', '5'};
  List<char> list{'t', 'e', 's', 't', '5'};
  auto stl_it = stl_list.begin();
  // Act
  // Assert
  ASSERT_EQ(stl_list.size(), list.Size());
  ASSERT_EQ(stl_list.max_size(), list.MaxSize());
  for (auto it = list.Begin(); it != list.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*-----------------------------SPLICE_TESTS--------------------------*/
/* Function Splice() in begin int list */
TEST(SpliceListTest, SpliceListTest_1) {
  // Arrange
  list<int> stl_list1{1, 2, 3, 4, 5};
  list<int> stl_list2{10, 20, 30, 40, 50};
  auto stl_it1 = stl_list1.begin();
  stl_list1.splice(stl_it1, stl_list2);
  stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<int> list1{1, 2, 3, 4, 5};
  List<int> list2{10, 20, 30, 40, 50};
  auto it1 = list1.Begin();
  // Act
  list1.Splice(it1, list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function Splice() in end char list */
TEST(SpliceListTest, SpliceListTest_2) {
  // Arrange
  list<char> stl_list1{'h', 'q', 'f', 'u', 'v'};
  list<char> stl_list2{'e', 'a', 'h', 't', 'z'};
  auto stl_it1 = stl_list1.end();
  stl_list1.splice(stl_it1, stl_list2);
  stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<char> list1{'h', 'q', 'f', 'u', 'v'};
  List<char> list2{'e', 'a', 'h', 't', 'z'};
  auto it1 = list1.End();
  // Act
  list1.Splice(it1, list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function Splice() in middle string list */
TEST(SpliceListTest, SpliceListTest_3) {
  // Arrange
  list<string> stl_list1{"test1", "test2", "test3", "test4"};
  list<string> stl_list2{"school", "21", "csaca", "cacac", "ascc"};
  auto stl_it1 = stl_list1.begin();
  stl_it1++;
  stl_it1++;
  stl_list1.splice(stl_it1, stl_list2);
  stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<string> list1{"test1", "test2", "test3", "test4"};
  List<string> list2{"school", "21", "csaca", "cacac", "ascc"};
  auto it1 = list1.Begin();
  it1++;
  it1++;
  // Act
  list1.Splice(it1, list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function Splice() in begin first list is null */
TEST(SpliceListTest, SpliceListTest_4) {
  // Arrange
  list<int> stl_list1;
  list<int> stl_list2{10, 20, 30, 40, 50};
  auto stl_it1 = stl_list1.begin();
  stl_list1.splice(stl_it1, stl_list2);
  stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<int> list1;
  List<int> list2{10, 20, 30, 40, 50};
  auto it1 = list1.Begin();
  // Act
  list1.Splice(it1, list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function Splice() in begin srcond list is null */
TEST(SpliceListTest, SpliceListTest_5) {
  // Arrange
  list<int> stl_list1{10, 20, 30, 40, 50};
  list<int> stl_list2;
  auto stl_it1 = stl_list1.begin();
  stl_list1.splice(stl_it1, stl_list2);
  stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<int> list1{10, 20, 30, 40, 50};
  List<int> list2;
  auto it1 = list1.Begin();
  // Act
  list1.Splice(it1, list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}
/*------------------------------SORT_TESTS---------------------------*/
/* Function Sort() int list */
TEST(SortListTest, SortListTest_1) {
  // Arrange
  list<int> stl_list{101, 21, 3, 40, 25, 4, 3, 0};
  stl_list.sort();
  auto stl_it = stl_list.begin();
  List<int> list1{101, 21, 3, 40, 25, 4, 3, 0};
  // Act
  list1.Sort();
  // Assert
  ASSERT_EQ(stl_list.size(), list1.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Sort() char list */
TEST(SortListTest, SortListTest_2) {
  // Arrange
  list<char> stl_list{'h', 'q', 'f', 'u', 'v', 'x', 'e'};
  stl_list.sort();
  auto stl_it = stl_list.begin();
  List<char> list1{'h', 'q', 'f', 'u', 'v', 'x', 'e'};
  // Act
  list1.Sort();
  // Assert
  ASSERT_EQ(stl_list.size(), list1.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Sort() char list is null */
TEST(SortListTest, SortListTest_3) {
  // Arrange
  list<char> stl_list;
  stl_list.sort();
  auto stl_it = stl_list.begin();
  List<char> list1;
  // Act
  list1.Sort();
  // Assert
  ASSERT_EQ(stl_list.size(), list1.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*----------------------------REVERSE_TESTS---------------------------*/
/* Function Reverse() int list */
TEST(ReverseListTest, ReverseListTest_1) {
  // Arrange
  list<int> stl_list{101, 21, 3, 40, 25, 4, 3, 0};
  stl_list.reverse();
  auto stl_it = stl_list.begin();
  List<int> list1{101, 21, 3, 40, 25, 4, 3, 0};
  // Act
  list1.Reverse();
  // Assert
  ASSERT_EQ(stl_list.size(), list1.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Reverse() int list is null */
TEST(ReverseListTest, ReverseListTest_2) {
  // Arrange
  list<int> stl_list;
  stl_list.reverse();
  auto stl_it = stl_list.begin();
  List<int> list1;
  // Act
  list1.Reverse();
  // Assert
  ASSERT_EQ(stl_list.size(), list1.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Reverse() char list */
TEST(ReverseListTest, ReverseListTest_3) {
  // Arrange
  list<char> stl_list{'h', 'q'};
  stl_list.reverse();
  auto stl_it = stl_list.begin();
  List<char> list1{'h', 'q'};
  // Act
  list1.Reverse();
  // Assert
  ASSERT_EQ(stl_list.size(), list1.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*------------------------------SWAP_TESTS---------------------------*/
/* Function Swap() int list */
TEST(SwapListTest, SwapListTest_1) {
  // Arrange
  list<int> stl_list1{10, 2, 35, 14, 5};
  list<int> stl_list2{101, 2, 31, 42, 5};
  stl_list1.swap(stl_list2);
  auto stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<int> list1{10, 2, 35, 14, 5};
  List<int> list2{101, 2, 31, 42, 5};
  // Act
  list1.Swap(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function Swap() string list */
TEST(SwapListTest, SwapListTest_2) {
  // Arrange
  list<string> stl_list1{"test1", "test2", "test3", "test4", "test5"};
  list<string> stl_list2;
  stl_list1.swap(stl_list2);
  auto stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<string> list1{"test1", "test2", "test3", "test4", "test5"};
  List<string> list2;
  // Act
  list1.Swap(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function Swap() string list */
TEST(SwapListTest, SwapListTest_3) {
  // Arrange
  list<string> stl_list1;
  list<string> stl_list2{"test1", "test2", "test3", "test4", "test5"};
  stl_list1.swap(stl_list2);
  auto stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<string> list1;
  List<string> list2{"test1", "test2", "test3", "test4", "test5"};
  // Act
  list1.Swap(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}
/*-----------------------------MERGE_TESTS---------------------------*/
/* Function Merge() int list */
TEST(MergeListTest, MergeListTest_1) {
  // Arrange
  list<int> stl_list1 = {1, 9, 1, 3, 3};
  list<int> stl_list2 = {8, 7, 2, 3, 4, 4};
  stl_list1.merge(stl_list2);
  auto stl_it1 = stl_list1.begin();
  List<int> list1 = {1, 9, 1, 3, 3};
  List<int> list2 = {8, 7, 2, 3, 4, 4};
  // Act
  list1.Merge(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.empty(), list2.Empty());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function Merge() int list */
TEST(MergeListTest, MergeListTest_2) {
  // Arrange
  list<int> stl_list1 = {114, 9, 1, 3, 3};
  list<int> stl_list2 = {8, 7, 2, 3, 4, 4};
  stl_list1.merge(stl_list2);
  auto stl_it1 = stl_list1.begin();
  List<int> list1 = {114, 9, 1, 3, 3};
  List<int> list2 = {8, 7, 2, 3, 4, 4};
  // Act
  list1.Merge(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.empty(), list2.Empty());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function Merge() unsigned list first list is sorted */
TEST(MergeListTest, MergeListTest_3) {
  // Arrange
  list<unsigned> stl_list1 = {1, 9, 1, 3, 3};
  list<unsigned> stl_list2 = {8, 7, 2, 3, 4, 4};
  stl_list1.sort();
  stl_list1.merge(stl_list2);
  auto stl_it1 = stl_list1.begin();
  List<unsigned> list1 = {1, 9, 1, 3, 3};
  List<unsigned> list2 = {8, 7, 2, 3, 4, 4};
  list1.Sort();
  // Act
  list1.Merge(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.empty(), list2.Empty());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function Merge() unsigned list second list is sorted */
TEST(MergeListTest, MergeListTest_4) {
  // Arrange
  list<unsigned> stl_list1 = {114, 9, 1, 3, 3};
  list<unsigned> stl_list2 = {8, 7, 2, 3, 4, 4};
  stl_list2.sort();
  stl_list1.merge(stl_list2);
  auto stl_it1 = stl_list1.begin();
  List<unsigned> list1 = {114, 9, 1, 3, 3};
  List<unsigned> list2 = {8, 7, 2, 3, 4, 4};
  list2.Sort();
  // Act
  list1.Merge(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.empty(), list2.Empty());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function Merge() double list two list is sorted */
TEST(MergeListTest, MergeListTest_5) {
  // Arrange
  list<double> stl_list1 = {2, 9, 1, 3, 3};
  list<double> stl_list2 = {8, 7, 2, 3, 4, 4};
  stl_list1.sort();
  stl_list2.sort();
  stl_list1.merge(stl_list2);
  auto stl_it1 = stl_list1.begin();
  List<double> list1 = {2, 9, 1, 3, 3};
  List<double> list2 = {8, 7, 2, 3, 4, 4};
  list1.Sort();
  list2.Sort();
  // Act
  list1.Merge(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.empty(), list2.Empty());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function Merge() unsigned list first list is null */
TEST(MergeListTest, MergeListTest_6) {
  // Arrange
  list<unsigned> stl_list1;
  list<unsigned> stl_list2 = {8, 7, 2, 3, 4, 4};
  stl_list1.merge(stl_list2);
  auto stl_it1 = stl_list1.begin();
  List<unsigned> list1;
  List<unsigned> list2 = {8, 7, 2, 3, 4, 4};
  // Act
  list1.Merge(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.empty(), list2.Empty());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}
/*------------------------------COPY_TESTS---------------------------*/
/* Function operator=(&) double list */
TEST(CopyListTest, CopyListTest_1) {
  // Arrange
  list<double> stl_list1 = {2, 9, 1, 3, 3};
  list<double> stl_list2 = {8, 7, 2, 3, 4, 4};
  stl_list1 = stl_list2;
  auto stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<double> list1 = {2, 9, 1, 3, 3};
  List<double> list2 = {8, 7, 2, 3, 4, 4};
  // Act
  list1 = list2;
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function operator=(&) double list some pointer*/
TEST(CopyListTest, CopyListTest_2) {
  // Arrange
  list<double> stl_list1 = {2, 9, 1, 3, 3};
  stl_list1 = stl_list1;
  auto stl_it1 = stl_list1.begin();
  List<double> list1 = {2, 9, 1, 3, 3};
  // Act
  list1 = list1;
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function operator=(&) double second list is null */
TEST(CopyListTest, CopyListTest_3) {
  // Arrange
  list<double> stl_list1 = {2, 9, 1, 3, 3};
  list<double> stl_list2;
  stl_list1 = stl_list2;
  List<double> list1 = {2, 9, 1, 3, 3};
  List<double> list2;
  // Act
  list1 = list2;
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  ASSERT_EQ(stl_list1.empty(), list1.Empty());
  ASSERT_EQ(stl_list2.empty(), list2.Empty());
}

/*------------------------------MOVE_TESTS---------------------------*/
/* Function operator=(&&) string list */
TEST(MoveListTest, MoveListTest_1) {
  // Arrange
  list<string> stl_list1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  list<string> stl_list2 = {"test1", "test2", "test3", "test4", "test5"};
  stl_list1 = move(stl_list2);
  auto stl_it1 = stl_list1.begin();
  auto stl_it2 = stl_list2.begin();
  List<string> list1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  List<string> list2 = {"test1", "test2", "test3", "test4", "test5"};
  // Act
  list1 = move(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = list2.Begin(); it != list2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function operator=(&&) string list some pointer */
TEST(MoveListTest, MoveListTest_2) {
  // Arrange
  list<string> stl_list1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  stl_list1 = move(stl_list1);
  auto stl_it1 = stl_list1.begin();
  List<string> list1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  // Act
  list1 = move(list1);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  for (auto it = list1.Begin(); it != list1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function operator=(&&) string second list is null */
TEST(MoveListTest, MoveListTest_3) {
  // Arrange
  list<string> stl_list1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  list<string> stl_list2;
  stl_list1 = move(stl_list2);
  List<string> list1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  List<string> list2;
  // Act
  list1 = move(list2);
  // Assert
  ASSERT_EQ(stl_list1.size(), list1.Size());
  ASSERT_EQ(stl_list2.size(), list2.Size());
  ASSERT_EQ(stl_list1.empty(), list1.Empty());
  ASSERT_EQ(stl_list2.empty(), list2.Empty());
}