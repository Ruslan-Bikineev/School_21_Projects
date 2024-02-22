#include <gtest/gtest.h>

#include <vector>

#include "../s21_containers.h"

using namespace s21;
using namespace std;

/*------------------------CONSTRUCTORS_TESTS--------------------------*/
/* Based constructor */
TEST(ConstructorVectorTest, ConstructorVectorTest_1) {
  // Arrange
  vector<int> stl_vector;
  // Act
  Vector<int> vector;
  // Assert
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.empty(), vector.Empty());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
}

/* Constructor creates the vector of size n */
TEST(ConstructorVectorTest, ConstructorVectorTest_2) {
  // Arrange
  vector<char> stl_vector(5);
  auto stl_it = stl_vector.begin();
  // Act
  Vector<char> vector(5);
  // Assert
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.empty(), vector.Empty());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Constructor with initializer vector  */
TEST(ConstructorVectorTest, ConstructorVectorTest_3) {
  // Arrange
  vector<unsigned> stl_vector{5, 4, 3, 2, 1};
  auto stl_it = stl_vector.begin();
  // Act
  Vector<unsigned> vector{5, 4, 3, 2, 1};
  // Assert
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.empty(), vector.Empty());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Copy constructor data is null*/
TEST(ConstructorVectorTest, ConstructorVectorTest_4) {
  // Arrange
  Vector<string> vector1;
  auto it1 = vector1.Begin();
  // Act
  Vector<string> vector2(vector1);
  // Assert
  ASSERT_EQ(vector1.Size(), vector2.Size());
  ASSERT_EQ(vector1.Empty(), vector2.Empty());
  ASSERT_EQ(vector1.Capacity(), vector2.Capacity());
  for (auto it2 = vector2.Begin(); it2 != vector2.End(); it1++, it2++) {
    ASSERT_EQ(*it1, *it2);
  }
}

/* Copy constructor */
TEST(ConstructorVectorTest, ConstructorVectorTest_5) {
  // Arrange
  Vector<string> vector1{"test1", "test2", "test3", "test4", "test5"};
  auto it1 = vector1.Begin();
  // Act
  Vector<string> vector2(vector1);
  // Assert
  ASSERT_EQ(vector1.Size(), vector2.Size());
  ASSERT_EQ(vector1.Empty(), vector2.Empty());
  ASSERT_EQ(vector1.Capacity(), vector2.Capacity());
  for (auto it2 = vector2.Begin(); it2 != vector2.End(); it1++, it2++) {
    ASSERT_EQ(*it1, *it2);
  }
}

/* Move constructor data is null */
TEST(ConstructorVectorTest, ConstructorVectorTest_6) {
  // Arrange
  vector<double> stl_vector;
  vector<double> new_stl_vector(move(stl_vector));
  auto stl_it = stl_vector.begin();
  auto new_stl_it = new_stl_vector.begin();
  Vector<double> vector;
  // Act
  Vector<double> new_vector(move(vector));
  // Assert
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(new_stl_vector.size(), new_vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  ASSERT_EQ(new_stl_vector.capacity(), new_vector.Capacity());
  ASSERT_EQ(stl_vector.empty(), vector.Empty());
  ASSERT_EQ(new_stl_vector.empty(), new_vector.Empty());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
  for (auto it = new_vector.Begin(); it != new_vector.End();
       it++, new_stl_it++) {
    ASSERT_EQ(*it, *new_stl_it);
  }
}

/* Move constructor */
TEST(ConstructorVectorTest, ConstructorVectorTest_7) {
  // Arrange
  vector<double> stl_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<double> new_stl_vector(move(stl_vector));
  auto stl_it = stl_vector.begin();
  auto new_stl_it = new_stl_vector.begin();
  Vector<double> vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // Act
  Vector<double> new_vector(move(vector));
  // Assert
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(new_stl_vector.size(), new_vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  ASSERT_EQ(new_stl_vector.capacity(), new_vector.Capacity());
  ASSERT_EQ(stl_vector.empty(), vector.Empty());
  ASSERT_EQ(new_stl_vector.empty(), new_vector.Empty());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
  for (auto it = new_vector.Begin(); it != new_vector.End();
       it++, new_stl_it++) {
    ASSERT_EQ(*it, *new_stl_it);
  }
}

/*------------------------------COPY_TESTS---------------------------*/
/* Function operator=(&) int vector */
TEST(CopyVectorTest, CopyVectorTest_1) {
  // Arrange
  vector<int> stl_vector1 = {2, 9, 1, 3, 3};
  vector<int> stl_vector2 = {8, 7, 2, 3, 4, 4};
  stl_vector1 = stl_vector2;
  auto stl_it1 = stl_vector1.begin();
  auto stl_it2 = stl_vector2.begin();
  Vector<int> vector1 = {2, 9, 1, 3, 3};
  Vector<int> vector2 = {8, 7, 2, 3, 4, 4};
  // Act
  vector1 = vector2;
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector2.size(), vector2.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  ASSERT_EQ(stl_vector2.capacity(), vector2.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = vector2.Begin(); it != vector2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function operator=(&) double vector some pointer*/
TEST(CopyVectorTest, CopyVectorTest_2) {
  // Arrange
  vector<double> stl_vector1 = {2, 9, 1, 3, 3};
  stl_vector1 = stl_vector1;
  auto stl_it1 = stl_vector1.begin();
  Vector<double> vector1 = {2, 9, 1, 3, 3};
  // Act
  vector1 = vector1;
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function operator=(&) double second vector is null */
TEST(CopyVectorTest, CopyVectorTest_3) {
  // Arrange
  vector<double> stl_vector1 = {2, 9, 1, 3, 3};
  vector<double> stl_vector2;
  stl_vector1 = stl_vector2;
  Vector<double> vector1 = {2, 9, 1, 3, 3};
  Vector<double> vector2;
  // Act
  vector1 = vector2;
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector2.size(), vector2.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  ASSERT_EQ(stl_vector2.capacity(), vector2.Capacity());
}

/*------------------------------MOVE_TESTS---------------------------*/
/* Function operator=(&&) string vector */
TEST(MoveVectorTest, MoveVectorTest_1) {
  // Arrange
  vector<string> stl_vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  vector<string> stl_vector2 = {"test1", "test2", "test3", "test4", "test5"};
  stl_vector1 = move(stl_vector2);
  auto stl_it1 = stl_vector1.begin();
  auto stl_it2 = stl_vector2.begin();
  Vector<string> vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  Vector<string> vector2 = {"test1", "test2", "test3", "test4", "test5"};
  // Act
  vector1 = move(vector2);
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector2.size(), vector2.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  ASSERT_EQ(stl_vector2.capacity(), vector2.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
  for (auto it = vector2.Begin(); it != vector2.End(); it++, stl_it2++) {
    ASSERT_EQ(*it, *stl_it2);
  }
}

/* Function operator=(&&) string vector some pointer */
TEST(MoveVectorTest, MoveVectorTest_2) {
  // Arrange
  vector<string> stl_vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  stl_vector1 = move(stl_vector1);
  auto stl_it1 = stl_vector1.begin();
  Vector<string> vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  // Act
  vector1 = move(vector1);
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function operator=(&&) string second vector is null */
TEST(MoveVectorTest, MoveVectorTest_3) {
  // Arrange
  vector<string> stl_vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  vector<string> stl_vector2;
  stl_vector1 = move(stl_vector2);
  Vector<string> vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  Vector<string> vector2;
  // Act
  vector1 = move(vector2);
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector2.size(), vector2.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  ASSERT_EQ(stl_vector2.capacity(), vector2.Capacity());
}
/*----------------------------SIZEMAX_TESTS--------------------------*/
/* Function SizeMax() vector is null */
TEST(SizeMaxVectorTest, SizeMaxVectorTest_1) {
  // Arrange
  vector<unsigned> stl_vector;
  Vector<unsigned> vector;
  // Act
  // Assert
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.max_size(), vector.MaxSize());
}

/* Function SizeMax() char vector  */
TEST(SizeMaxVectorTest, SizeMaxVectorTest_2) {
  // Arrange
  vector<char> stl_vector{'t', 'e', 's', 't', '5'};
  Vector<char> vector{'t', 'e', 's', 't', '5'};
  auto stl_it = stl_vector.begin();
  // Act
  // Assert
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.max_size(), vector.MaxSize());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*----------------------------RESERVE_TESTS--------------------------*/
/* Function Reserve() string vector*/
TEST(ReserveVectorTest, ReserveVectorTest_1) {
  // Arrange
  vector<string> stl_vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  stl_vector1.reserve(10);
  auto stl_it = stl_vector1.begin();
  Vector<string> vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  // Act
  vector1.Reserve(10);
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Reserve() string vector*/
TEST(ReserveVectorTest, ReserveVectorTest_2) {
  // Arrange
  vector<string> stl_vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  stl_vector1.reserve(4);
  auto stl_it = stl_vector1.begin();
  Vector<string> vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  // Act
  vector1.Reserve(4);
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Reserve() double vector is null*/
TEST(ReserveVectorTest, ReserveVectorTest_3) {
  // Arrange
  vector<double> stl_vector1;
  stl_vector1.reserve(8);
  auto stl_it = stl_vector1.begin();
  Vector<double> vector1;
  // Act
  vector1.Reserve(8);
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Reserve() int vector tests exception */
TEST(ReserveVectorTest, ReserveVectorTest_4) {
  // Arrange
  Vector<int> vector1;
  vector<int> stl_vector1;
  // Act
  // Assert
  ASSERT_THROW(vector1.Reserve(2305843009213693952), std::length_error);
  ASSERT_THROW(stl_vector1.reserve(2305843009213693952), std::length_error);
}
/*-------------------------SHRINK-TO-FIT-TESTS-----------------------*/
/* Function ShrinkToFit() double vector */
TEST(ShrinkToFitVectorTest, ShrinkToFitVectorTest_1) {
  // Arrange
  vector<double> stl_vector1 = {2, 9, 1, 3, 3};
  stl_vector1.reserve(11);
  stl_vector1.shrink_to_fit();
  auto stl_it1 = stl_vector1.begin();
  Vector<double> vector1 = {2, 9, 1, 3, 3};
  vector1.Reserve(11);
  // Act
  vector1.ShrinkToFit();
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function ShrinkToFit() double vector is null*/
TEST(ShrinkToFitVectorTest, ShrinkToFitVectorTest_2) {
  // Arrange
  vector<double> stl_vector1;
  stl_vector1.reserve(7);
  stl_vector1.shrink_to_fit();
  Vector<double> vector1;
  vector1.Reserve(7);
  // Act
  vector1.ShrinkToFit();
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.empty(), vector1.Empty());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
}
/*---------------------------PUSHBACK_TESTS--------------------------*/
/* Function PushBack() double vector */
TEST(PushBackVectorTest, PushBackVectorTest_1) {
  // Arrange
  vector<double> stl_vector1 = {2, 9, 1, 3, 3};
  stl_vector1.reserve(11);
  stl_vector1.push_back(21);
  auto stl_it1 = stl_vector1.begin();
  Vector<double> vector1 = {2, 9, 1, 3, 3};
  vector1.Reserve(11);
  // Act
  vector1.PushBack(21);
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function PushBack() string vector */
TEST(PushBackVectorTest, PushBackVectorTest_2) {
  // Arrange
  vector<string> stl_vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  stl_vector1.push_back("fdsdssdvd");
  auto stl_it1 = stl_vector1.begin();
  Vector<string> vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  // Act
  vector1.PushBack("fdsdssdvd");
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}

/* Function PushBack() double vector is null*/
TEST(PushBackVectorTest, PushBackVectorTest_3) {
  // Arrange
  vector<double> stl_vector1;
  stl_vector1.push_back(21);
  auto stl_it1 = stl_vector1.begin();
  Vector<double> vector1;
  // Act
  vector1.PushBack(21);
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it1++) {
    ASSERT_EQ(*it, *stl_it1);
  }
}
/*-----------------------------INSERT_TESTS--------------------------*/
/* Function Insert() char vector pos is in begin with Reserve() */
TEST(InsertVectorTest, InsertVectorTest_1) {
  // Arrange
  vector<char> stl_vector{'t', 'e', 's', 't', '5'};
  stl_vector.reserve(10);
  Vector<char> vector{'t', 'e', 's', 't', '5'};
  vector.Reserve(10);
  auto stl_it1 = stl_vector.insert(stl_vector.begin(), '1');
  auto stl_it = stl_vector.begin();
  // Act
  auto it1 = vector.Insert(vector.Begin(), '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() char vector pos is in end with Reserve() */
TEST(InsertVectorTest, InsertVectorTest_2) {
  // Arrange
  vector<char> stl_vector{'t', 'e', 's', 't', '5'};
  stl_vector.reserve(10);
  Vector<char> vector{'t', 'e', 's', 't', '5'};
  vector.Reserve(10);
  auto stl_it1 = stl_vector.insert(stl_vector.end(), '1');
  auto stl_it = stl_vector.begin();
  // Act
  auto it1 = vector.Insert(vector.End(), '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() char vector pos is in middle with Reserve() */
TEST(InsertVectorTest, InsertVectorTest_3) {
  // Arrange
  vector<char> stl_vector{'t', 'e', 's', 't', '5'};
  stl_vector.reserve(10);
  Vector<char> vector{'t', 'e', 's', 't', '5'};
  vector.Reserve(10);
  auto stl_it1 = stl_vector.insert(stl_vector.end(), '1');
  auto stl_it = stl_vector.begin();
  // Act
  auto it1 = vector.Insert(vector.End(), '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() char vector is null pos in in end with Reserve() */
TEST(InsertVectorTest, InsertVectorTest_4) {
  // Arrange
  vector<char> stl_vector;
  stl_vector.reserve(10);
  Vector<char> vector;
  vector.Reserve(10);
  auto stl_it1 = stl_vector.insert(stl_vector.begin(), '1');
  auto stl_it = stl_vector.begin();
  // Act
  auto it1 = vector.Insert(vector.Begin(), '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() char vector is null pos is in begin with Reserve() */
TEST(InsertVectorTest, InsertVectorTest_5) {
  // Arrange
  vector<char> stl_vector;
  stl_vector.reserve(10);
  Vector<char> vector;
  vector.Reserve(10);
  auto stl_it1 = stl_vector.insert(stl_vector.end(), '1');
  auto stl_it = stl_vector.begin();
  // Act
  auto it1 = vector.Insert(vector.End(), '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() char vector pos is in begin */
TEST(InsertVectorTest, InsertVectorTest_6) {
  // Arrange
  vector<char> stl_vector{'t', 'e', 's', 't', '5'};
  Vector<char> vector{'t', 'e', 's', 't', '5'};
  auto stl_it1 = stl_vector.insert(stl_vector.begin(), '1');
  auto stl_it = stl_vector.begin();
  // Act
  auto it1 = vector.Insert(vector.Begin(), '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() char vector pos is in end */
TEST(InsertVectorTest, InsertVectorTest_7) {
  // Arrange
  vector<char> stl_vector{'t', 'e', 's', 't', '5'};
  Vector<char> vector{'t', 'e', 's', 't', '5'};
  auto stl_it1 = stl_vector.insert(stl_vector.end(), '1');
  auto stl_it = stl_vector.begin();
  // Act
  auto it1 = vector.Insert(vector.End(), '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() char vector pos is in middle */
TEST(InsertVectorTest, InsertVectorTest_8) {
  // Arrange
  vector<char> stl_vector{'t', 'e', 's', 't', '5'};
  Vector<char> vector{'t', 'e', 's', 't', '5'};
  auto stl_it = stl_vector.begin();
  stl_it += 2;
  auto stl_it1 = stl_vector.insert(stl_it, '1');
  stl_it = stl_vector.begin();
  auto it = vector.Begin();
  it += 2;
  // Act
  auto it1 = vector.Insert(it, '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() char vector is null pos in in end */
TEST(InsertVectorTest, InsertVectorTest_9) {
  // Arrange
  vector<char> stl_vector;
  Vector<char> vector;
  auto stl_it1 = stl_vector.insert(stl_vector.begin(), '1');
  auto stl_it = stl_vector.begin();
  // Act
  auto it1 = vector.Insert(vector.Begin(), '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Insert() char vector is null pos is in begin */
TEST(InsertVectorTest, InsertVectorTest_10) {
  // Arrange
  vector<char> stl_vector;
  Vector<char> vector;
  auto stl_it1 = stl_vector.insert(stl_vector.end(), '1');
  auto stl_it = stl_vector.begin();
  // Act
  auto it1 = vector.Insert(vector.End(), '1');
  // Assert
  ASSERT_EQ(*it1, *stl_it1);
  ASSERT_EQ(stl_vector.size(), vector.Size());
  ASSERT_EQ(stl_vector.capacity(), vector.Capacity());
  for (auto it = vector.Begin(); it != vector.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}
/*----------------------------POPBACK_TESTS--------------------------*/
/* Function PopBack() string vector*/
TEST(PopBackVectorTest, PopBackVectorTest_1) {
  // Arrange
  vector<string> stl_vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  stl_vector1.pop_back();
  auto stl_it = stl_vector1.begin();
  Vector<string> vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  // Act
  vector1.PopBack();
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function PopBack() string vector is null*/
TEST(PopBackVectorTest, PopBackVectorTest_2) {
  // Arrange
  Vector<string> vector1;
  // Act
  vector1.PopBack();
  // Assert
  ASSERT_EQ(0, vector1.Size());
  ASSERT_EQ(1, vector1.Empty());
  ASSERT_EQ(0, vector1.Capacity());
}

/*-----------------------------ERASE_TESTS---------------------------*/
/* Function Erase() string vector pos is on begin */
TEST(EraseVectorTest, EraseVectorTest_1) {
  // Arrange
  vector<string> stl_vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  stl_vector1.erase(stl_vector1.begin());
  auto stl_it = stl_vector1.begin();
  Vector<string> vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  // Act
  vector1.Erase(vector1.Begin());
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Erase() string vector pos is on middle */
TEST(EraseVectorTest, EraseVectorTest_3) {
  // Arrange
  vector<string> stl_vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  auto stl_it = stl_vector1.begin();
  stl_it += 2;
  stl_vector1.erase(stl_it);
  stl_it = stl_vector1.begin();
  Vector<string> vector1 = {"dvsv", "vsdv", "dvs", "svsf", "dsvdv"};
  auto it = vector1.Begin();
  it += 2;
  // Act
  vector1.Erase(it);
  // Assert
  ASSERT_EQ(stl_vector1.size(), vector1.Size());
  ASSERT_EQ(stl_vector1.capacity(), vector1.Capacity());
  for (auto it = vector1.Begin(); it != vector1.End(); it++, stl_it++) {
    ASSERT_EQ(*it, *stl_it);
  }
}

/* Function Erase() string vector is null*/
TEST(EraseVectorTest, EraseVectorTest_4) {
  // Arrange
  Vector<string> vector1;
  // Act
  vector1.Erase(vector1.Begin());
  // Assert
  ASSERT_EQ(0, vector1.Size());
  ASSERT_EQ(1, vector1.Empty());
  ASSERT_EQ(0, vector1.Capacity());
}
