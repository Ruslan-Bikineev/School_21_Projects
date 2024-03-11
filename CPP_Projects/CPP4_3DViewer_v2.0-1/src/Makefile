OS := $(shell uname -s)
OBJ = $(patsubst %.c, %.o, $(SRC))
TEST_CC = $(shell find tests -name "*.cc")
GCC = g++ -Wall -Wextra -Werror -std=c++17
FILES = $(shell find Backend -name "*.cc")
BD = ../build/

main:
	$(GCC) main.cc $(FILES) -o test.out 
	./test.out


all: dvi clean style dist install gcov_report run

install: clean
	mkdir -p $(BD)
	cd ../build/ && qmake6 ../src/3DViewer/3DViewer_v2.pro && make && make clean && rm -rf .qmake.stash Makefile

uninstall: 
	rm -rf $(BD)

run:
ifeq ($(OS), Linux)
	$(BD)./3DViewer_v2
	# CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(BD)./3DViewer_v2
else
	$(BD)/3DViewer_v2.app/Contents/MacOS/3DViewer_v2
endif

style:
	clang-format --style=Google -n $(shell find . -name "*.cc")
	clang-format --style=Google -n $(shell find . -name "*.h")
	clang-format --style=Google -i $(shell find . -name "*.cc")
	clang-format --style=Google -i $(shell find . -name "*.h")

%.o : %.c 
	$(GCC) -c $< -o $@

test: 
ifeq ($(OS), Linux)
	$(GCC) -lgtest_main $(TEST_CC) $(FILES) -o tests.out -lgtest -pthread
	#  CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests.out
else
	$(GCC) $(TEST_C) -o tests.out -lcheck -lm
endif
	./tests.out

gcov_report:
ifeq ($(OS), Linux)
	$(GCC) -lgtest_main $(TEST_CC) $(FILES) -o tests.out -lgtest -pthread --coverage
else
	$(GCC) -o tests.out $(TEST_C) $(FILES) -lcheck -lm --coverage
endif
	./tests.out
	lcov -t "tests" -o tests.info -c -d . --no-external
	genhtml -o report tests.info
	open report/index.html


clean:
	rm -rf $(shell find . -name "*.o") *.a *.out *.gcno *.gcda *.info ../*.tar *.gif report build* $(BD) ../3DViewer_v2.0.tar.gz

rebuild: clean all

dvi:
	open manual.html
	sleep 3

dist: clean
	tar -czvf ../3DViewer_v2.0.tar.gz ../src
