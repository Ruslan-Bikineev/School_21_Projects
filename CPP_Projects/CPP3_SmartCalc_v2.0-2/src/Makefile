OS := $(shell uname -s)
OBJ = $(patsubst %.cc, %.o, $(SRC))
TEST_CC = $(shell find tests -name "*.cc")
GCC = g++ -Wall -Wextra -Werror -std=c++17
SRC = ./mvc/controller.cc ./mvc/model.cc ./mvc/view.cc
BD = ../build/

main:
	$(GCC) main.cc $(SRC) -o test.out && ./test.out

all: clean test install run  

install: clean
	mkdir -p $(BD)
	cd $(BD) && qmake ../src/SmartCalc/SmartCalc.pro && make && make clean && rm -rf .qmake.stash Makefile

uninstall: 
	rm -rf ../build

dist: 
	tar -czvf ../SmartCalc.tar ../src

dvi:
	open manual.html

run:
ifeq ($(OS), Linux)
	$(BD)./SmartCalc
else
	$(BD)/SmartCalc.app/Contents/MacOS/./SmartCalc
endif

style:
	clang-format --style=Google -n $(shell find . -name "*.cc")
	clang-format --style=Google -i $(shell find . -name "*.cc")
	clang-format --style=Google -n $(shell find . -name "*.cpp")
	clang-format --style=Google -i $(shell find . -name "*.cpp")
	clang-format --style=Google -i $(shell find . -name "*.h")

test:
ifeq ($(OS), Linux)
	$(GCC) -lgtest_main $(TEST_CC) $(SRC) -o tests.out -lgtest -pthread
	# CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests.out
else
	$(GCC) -lgtest_main $(TEST_CC) $(SRC) -o tests.out -lgtest
endif
	./tests.out

gcov_report:
ifeq ($(OS), Linux)
	$(GCC) -lgtest_main -o tests.out $(TEST_CC) $(SRC) -lgtest -pthread --coverage
else
	$(GCC) -lgtest_main -o tests.out $(TEST_CC) $(SRC) -lgtest --coverage
endif
	./tests.out
	lcov -t "tests" -o tests.info -c -d . --no-external
	genhtml -o report tests.info
	open report/index.html

clean:
	rm -rf $(shell find . -name "*.o") *.a *.out *.gcno *.gcda *.info report s21_matrix

rebuild: clean all