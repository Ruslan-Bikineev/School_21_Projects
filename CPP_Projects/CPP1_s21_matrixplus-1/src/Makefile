GCC = g++ -Wall -Wextra -Werror -std=c++17
LIB = s21_matrix_oop.a
SRC = s21_matrix_oop.cc
OBJ = $(patsubst %.cc, %.o, $(SRC))
TEST_CC = $(shell find tests -name "*.cc")
OS := $(shell uname -s)

main:
	$(GCC) main.cc $(SRC) -o test.out
	./test.out

all: clean s21_matrix_oop.a test 

style:
	clang-format --style=Google -n $(shell find . -name "*.cc")
	clang-format --style=Google -i $(shell find . -name "*.cc")
	# clang-format --style=Google -n $(shell find . -name "*.cpp")
	# clang-format --style=Google -i $(shell find . -name "*.cpp")
	clang-format --style=Google -i $(shell find . -name "*.h")

s21_matrix_oop.a: $(OBJ)
	ar rcs $(LIB) $(OBJ)

%.o : %.c 
	$(GCC) -c $< -o $@

test: s21_matrix_oop.a
ifeq ($(OS), Linux)
	$(GCC) -lgtest_main $(TEST_CC) -o tests.out $(LIB) -lgtest -pthread
	# CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests.out
else
	$(GCC) -lgtest_main $(TEST_CC) -o tests.out $(LIB) -lgtest
endif
	./tests.out

gcov_report: s21_matrix_oop.a
ifeq ($(OS), Linux)
	$(GCC) -lgtest_main -o tests.out $(TEST_CC) $(SRC) $(LIB) -lgtest -pthread --coverage
else
	$(GCC) -lgtest_main -o tests.out $(TEST_CC) $(SRC) $(LIB) -lgtest --coverage
endif
	./tests.out
	lcov -t "tests" -o tests.info -c -d . --no-external
	genhtml -o report tests.info
	open report/index.html

clean:
	rm -rf $(shell find . -name "*.o") *.a *.out *.gcno *.gcda *.info report s21_matrix

rebuild: clean all