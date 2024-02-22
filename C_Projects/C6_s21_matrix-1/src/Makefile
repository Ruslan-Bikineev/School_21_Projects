GCC = gcc -Wall -Wextra -Werror -std=c11
LIB = s21_matrix.a
SRC = s21_matrix.c
OBJ = $(patsubst %.c, %.o, $(SRC))
TEST_C = $(shell find tests -name "*.c")
OS := $(shell uname -s)

all: clean s21_matrix.a test 

clang:
	clang-format --style=Google -n $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find . -name "*.h")

s21_matrix.a: $(OBJ)
	ar rcs $(LIB) $(OBJ)
	ranlib $(LIB)

%.o : %.c 
	$(GCC) -c $< -o $@

test: s21_matrix.a
ifeq ($(OS), Linux)
	$(GCC) $(TEST_C) -o tests.out $(LIB) -lcheck -lm -lpthread -lsubunit
		# CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests.out
else
	$(GCC) $(TEST_C) -o tests.out $(LIB) -lcheck -lm
endif
	./tests.out

gcov_report: 
ifeq ($(OS), Linux)
	$(GCC) -o tests.out $(TEST_C) $(SRC) $(LIB) -lcheck -lm -lsubunit -lpthread --coverage
else
	$(GCC) -o tests.out $(TEST_C) $(SRC) $(LIB) -lcheck -lm --coverage
endif
	./tests.out
	lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html

clean:
	rm -rf $(shell find . -name "*.o") *.a *.out *.gcno *.gcda *.info report s21_matrix

rebuild: clean all

debug: clean s21_matrix.a
	gcc -g s21_*.c -o s21_matrix $(LIB) -lcheck -lm -lpthread -lsubunit

