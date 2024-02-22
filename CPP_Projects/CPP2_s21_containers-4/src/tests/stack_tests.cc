#include <gtest/gtest.h>

#include <stack>

#include "../s21_containers.h"

using namespace s21;
using namespace std;

class StackTestWithStl : public testing::Test {
 protected:
  void SetUp() {
    // init stl_int_stack
    stl_int_stack.push(55451);
    stl_int_stack.push(254566489);
    stl_int_stack.push(0);
    stl_int_stack.push(-4155616);
    stl_int_stack.push(849);
    // init stl_char_stack1
    stl_char_stack1.push('s');
    stl_char_stack1.push('h');
    stl_char_stack1.push('c');
    stl_char_stack1.push('o');
    stl_char_stack1.push('o');
    stl_char_stack1.push('l');
    stl_char_stack1.push('2');
    stl_char_stack1.push('1');
    // init stl_char_stack2
    stl_char_stack2.push('@');
    stl_char_stack2.push(';');
    stl_char_stack2.push('/');
    // init stl_string_stack
    stl_string_stack.push("dsv58ds");
    stl_string_stack.push("cs#d*cs");
    stl_string_stack.push("vds%&&bvsd");
    stl_string_stack.push("fb5");
    stl_string_stack.push("!fe#");
    // inti stl_double_stack
    stl_double_stack.push(84.5151);
    stl_double_stack.push(91552131.131);
    stl_double_stack.push(0.121);
    stl_double_stack.push(-4542.1531);
    stl_double_stack.push(156165.115);
    stl_double_stack.push(-984899.0001);
  }
  stack<int> stl_int_stack;
  stack<char> stl_char_stack1;
  stack<char> stl_char_stack2;
  stack<string> stl_string_stack;
  stack<double> stl_double_stack;
};

/* Function for equal stl stack and our stack */
template <typename T>
::testing::AssertionResult Equal(stack<T> stl_stack, Stack<T> stack) {
  if (stl_stack.size() != stack.Size()) {
    return ::testing::AssertionFailure()
           << "stl_stack: " << stl_stack.size() << " | stack: " << stack.Size()
           << " - Size is not equal!";
  }
  while (!stl_stack.empty()) {
    if (stl_stack.top() != stack.Top()) {
      return ::testing::AssertionFailure()
             << "stl_stack: " << stl_stack.top() << " | stack: " << stack.Top()
             << " - is not equal!";
    } else {
      stl_stack.pop();
      stack.Pop();
    }
  }
  return ::testing::AssertionSuccess();
}

/* Based constructor */
TEST(ConstructorStackTest, ConstructorStackTest_1) {
  // Arrange
  stack<int> stl_stack;
  // Act
  Stack<int> stack;
  // Assert
  ASSERT_EQ(stl_stack.size(), stack.Size());
}

/* Based constructor test throw in Top() */
TEST(ConstructorStackTest, ConstructorStackTest_2) {
  // Arrange
  // Act
  Stack<int> stack;
  // Assert
  ASSERT_THROW(stack.Top(), out_of_range);
}
/* Copy constructor data is null*/
TEST(ConstructorStackTest, ConstructorStackTest_3) {
  // Arrange
  Stack<string> stack1;
  // Act
  Stack<string> stack2(stack1);
  // Assert
  ASSERT_EQ(stack1.Size(), stack2.Size());
  ASSERT_EQ(stack1.Empty(), stack2.Empty());
}

/* Move constructor data is null */
TEST(ConstructorStackTest, ConstructorStackTest_4) {
  // Arrange
  stack<double> stl_stack;
  stack<double> new_stl_stack(move(stl_stack));
  Stack<double> stack;
  // Act
  Stack<double> new_stack(move(stack));
  // Assert
  EXPECT_TRUE(Equal(stl_stack, stack));
  EXPECT_TRUE(Equal(new_stl_stack, new_stack));
}

/* Constructor with initializer list  */
TEST_F(StackTestWithStl, StackTest_1) {
  // Arrange
  // Act
  Stack<char> stack{'s', 'h', 'c', 'o', 'o', 'l', '2', '1'};
  // Assert
  EXPECT_TRUE(Equal(stl_char_stack1, stack));
  ASSERT_EQ(stl_char_stack1.empty(), stack.Empty());
}

/* Copy constructor */
TEST_F(StackTestWithStl, StackTest_2) {
  // Arrange
  Stack<string> stack1{"dsv58ds", "cs#d*cs", "vds%&&bvsd", "fb5", "!fe#"};
  // Act
  Stack<string> stack2(stack1);
  // Assert
  EXPECT_TRUE(Equal(stl_string_stack, stack1));
  EXPECT_TRUE(Equal(stl_string_stack, stack2));
}

/* Move constructor */
TEST_F(StackTestWithStl, StackTest_3) {
  // Arrange
  stack<double> new_stl_stack(move(stl_double_stack));
  Stack<double> stack{84.5151,    91552131.131, 0.121,
                      -4542.1531, 156165.115,   -984899.0001};
  // Act
  Stack<double> new_stack(move(stack));
  // Assert
  EXPECT_TRUE(Equal(stl_double_stack, stack));
  EXPECT_TRUE(Equal(new_stl_stack, new_stack));
}

/* Swap one stack is null*/
TEST_F(StackTestWithStl, StackTest_4) {
  // Arrange
  stack<int> stl_stack;
  Stack<int> stack1;
  Stack<int> stack2{55451, 254566489, 0, -4155616, 849};
  stl_stack.swap(stl_int_stack);
  // Act
  stack1.Swap(stack2);
  // Assert
  EXPECT_TRUE(Equal(stl_stack, stack1));
  EXPECT_TRUE(Equal(stl_int_stack, stack2));
}

/* Swap */
TEST_F(StackTestWithStl, StackTest_5) {
  // Arrange
  Stack<char> stack1{'s', 'h', 'c', 'o', 'o', 'l', '2', '1'};
  Stack<char> stack2{'@', ';', '/'};
  stl_char_stack1.swap(stl_char_stack2);
  // Act
  stack1.Swap(stack2);
  // Assert
  EXPECT_TRUE(Equal(stl_char_stack1, stack1));
  EXPECT_TRUE(Equal(stl_char_stack2, stack2));
}

/* Push stack is null*/
TEST_F(StackTestWithStl, StackTest_6) {
  // Arrange
  Stack<string> stack;
  // Act
  stack.Push("dsv58ds");
  stack.Push("cs#d*cs");
  stack.Push("vds%&&bvsd");
  stack.Push("fb5");
  stack.Push("!fe#");
  // Assert
  EXPECT_TRUE(Equal(stl_string_stack, stack));
}

/* Push and Pop */
TEST_F(StackTestWithStl, StackTest_7) {
  // Arrange
  Stack<char> stack{'@', ';', '/'};
  // Act
  stack.Pop();
  stack.Pop();
  stack.Pop();
  stack.Push('@');
  stack.Push(';');
  stack.Push('/');
  // Assert
  EXPECT_TRUE(Equal(stl_char_stack2, stack));
}