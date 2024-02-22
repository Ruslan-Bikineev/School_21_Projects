GCC = gcc -Wall -Wextra -Werror -std=c11
OBJ = $(patsubst %.c, %.o, $(SRC))
TEST_C = $(shell find tests -name "*.c")
OS := $(shell uname -s)
FILES = ./Backend/smart_calc_v1.0.c ./Backend/stack.c ./Backend/suppport.c
BD = ../build/

all: test gcov_report install run

style:
	clang-format --style=Google -n $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find . -name "*.h")

install: clean
	mkdir -p $(BD)
	cd $(BD) && qmake ../src/SmartCalc/SmartCalc.pro && make && make clean && rm -rf .qmake.stash Makefile

uninstall: 
	rm -rf ../build/SmartCalc

dist: 
	tar -czvf ../SmartCalc.tar ../src

dvi:
	open manual.html

run:
	$(BD)./SmartCalc

%.o : %.c 
	$(GCC) -c $< -o $@

test: 
ifeq ($(OS), Linux)
	$(GCC) $(TEST_C) -o tests.out $(FILES) -lcheck -lm -lpthread -lsubunit
	#  CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests.out
else
	$(GCC) $(TEST_C) -o tests.out -lcheck -lm
endif
	./tests.out

gcov_report: 
ifeq ($(OS), Linux)
	$(GCC) -o tests.out $(TEST_C) $(FILES) -lcheck -lm -lsubunit -lpthread --coverage
else
	$(GCC) -o tests.out $(TEST_C) $(FILES) -lcheck -lm --coverage
endif
	./tests.out
	lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html

clean:
	rm -rf $(shell find . -name "*.o") *.a *.out *.gcno *.gcda *.info ../build-Smart* report $(BD) ../*.tar

rebuild: clean all