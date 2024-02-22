#include <gtest/gtest.h>

#include <queue>

#include "../s21_containers.h"

class QueueTest : public ::testing::Test {
 protected:
  s21::Queue<int> s21_int_queue;
  std::queue<int> std_int_queue;

  void SetUp() override {
    for (int i = 1; i <= 3; ++i) {
      s21_int_queue.Push(i);
      std_int_queue.push(i);
    }
  }

  template <typename T>
  void CompareQueues(const s21::Queue<T> &s21_queue,
                     const std::queue<T> &std_queue) {
    ASSERT_EQ(s21_queue.Empty(), std_queue.empty());
    if (!s21_queue.Empty() && !std_queue.empty()) {
      ASSERT_EQ(s21_queue.Front(), std_queue.front());
      ASSERT_EQ(s21_queue.Back(), std_queue.back());
    }
    ASSERT_EQ(s21_queue.Size(), std_queue.size());
  }
};

TEST_F(QueueTest, DefaultConstructor) {
  s21::Queue<int> s21_queue;
  std::queue<int> std_queue;
  CompareQueues(s21_queue, std_queue);
}

TEST_F(QueueTest, InitializerListConstructor) {
  CompareQueues(s21_int_queue, std_int_queue);
}

TEST_F(QueueTest, CopyConstructor) {
  s21::Queue<int> s21_copy(s21_int_queue);
  std::queue<int> std_copy(std_int_queue);
  CompareQueues(s21_copy, std_copy);
}

TEST_F(QueueTest, CopyAssignmentOperator) {
  s21::Queue<int> s21_empty;
  std::queue<int> std_empty;
  s21_empty = s21_int_queue;
  std_empty = std_int_queue;
  CompareQueues(s21_empty, std_empty);
}

TEST_F(QueueTest, MoveConstructor) {
  s21::Queue<int> s21_moved(std::move(s21_int_queue));
  std::queue<int> std_moved(std::move(std_int_queue));
  CompareQueues(s21_moved, std_moved);
}

TEST_F(QueueTest, MoveAssignmentOperator) {
  s21::Queue<int> s21_empty;
  std::queue<int> std_empty;
  s21_empty = std::move(s21_int_queue);
  std_empty = std::move(std_int_queue);
  CompareQueues(s21_empty, std_empty);
}

TEST_F(QueueTest, FrontAndBack) { CompareQueues(s21_int_queue, std_int_queue); }

TEST_F(QueueTest, Empty) {
  s21::Queue<int> s21_empty;
  std::queue<int> std_empty;
  CompareQueues(s21_empty, std_empty);
}

TEST_F(QueueTest, Push) {
  s21_int_queue.Push(4);
  std_int_queue.push(4);
  CompareQueues(s21_int_queue, std_int_queue);
}

TEST_F(QueueTest, Pop) {
  s21_int_queue.Pop();
  std_int_queue.pop();
  CompareQueues(s21_int_queue, std_int_queue);
}

TEST_F(QueueTest, Swap) {
  s21::Queue<int> s21_empty;
  std::queue<int> std_empty;
  s21_empty.Swap(s21_int_queue);
  std_empty.swap(std_int_queue);
  CompareQueues(s21_empty, std_empty);
  CompareQueues(s21_int_queue, std_int_queue);
}
