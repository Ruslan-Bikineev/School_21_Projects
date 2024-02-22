OS := $(shell uname -s)
OBJ = $(patsubst %.cc, %.o, $(SRC))
TEST_CC = $(shell find tests -name "*.cc")
GCC = g++ -Wall -Wextra -Werror -std=c++17

all: clean test 

style:
	clang-format --style=Google -i $(shell find . -name "*.tpp")
	clang-format --style=Google -i $(shell find . -name "*.cc")
	clang-format --style=Google -i $(shell find . -name "*.h")
	clang-format --style=Google -n $(shell find . -name "*.tpp")
	clang-format --style=Google -n $(shell find . -name "*.cc")
	clang-format --style=Google -n $(shell find . -name "*.h")

%.o : %.c 
	$(GCC) -c $< -o $@

test:
ifeq ($(OS), Linux)
	$(GCC) -lgtest_main $(TEST_CC) -o tests.out -lgtest -pthread
	# CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests.out
else
	$(GCC) -lgtest_main $(TEST_CC) -o tests.out -lgtest
endif
	./tests.out

gcov_report:
ifeq ($(OS), Linux)
	$(GCC) -lgtest_main -o tests.out $(TEST_CC) -lgtest -pthread --coverage
else
	$(GCC) -lgtest_main -o tests.out $(TEST_CC) -lgtest --coverage
endif
	./tests.out
	lcov -t "tests" -o tests.info -c -d . --no-external
	lcov --remove tests.info '*/tests/*' -o tests.info
	genhtml -o report tests.info
	open report/index.html

clean:
	rm -rf $(shell find . -name "*.o") *.a *.out *.gcno *.gcda *.info report 

rebuild: clean all