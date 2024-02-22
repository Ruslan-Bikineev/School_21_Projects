
GCC = gcc -Wall -Wextra -Werror -std=c11
LIB = s21_string.a
SRC = s21_string.c s21_sprintf.c s21_sscanf.c
OBJ = $(patsubst %.c, %.o, $(SRC))
TEST_C = $(shell find string_tests -name "*.c")
# TEST_C = $(shell find new_tests -name "*.c")
OS := $(shell uname -s)

all: clean s21_string.a test

clang:
	clang-format --style=Google -n $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find . -name "*.c")

s21_string.a: $(OBJ)
	ar rcs $(LIB) $(OBJ)
	ranlib $(LIB)

%.o : %.c 
	$(GCC) -c $< -o $@

test: s21_string.a
ifeq ($(OS), Linux)
	$(GCC) $(TEST_C) -o tests $(LIB) -lcheck -lm -lpthread -lsubunit
	#  CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests
else
	$(GCC) $(TEST_C) -o tests $(LIB) -lcheck -lpthread
endif
	./tests

gcov_report: 
ifeq ($(OS), Linux)
	$(GCC) -o tests $(TEST_C) $(SRC) $(LIB) -lcheck -lm -lsubunit -lpthread --coverage
else
	$(GCC) -o tests $(TEST_C) $(SRC) $(LIB) -lcheck -lpthread --coverage
endif
	./tests
	lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html

clean:
	rm -rf $(shell find . -name "*.o") *.a *.out s21_string *.gcno *.gcda *.info report tests

rebuild: clean all
