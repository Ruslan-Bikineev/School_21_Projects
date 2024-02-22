# При компиляции выходит ошибка с getline неявно объявленной функции
# Проблема решается если явно указать использование библиотеки при компиляции -D_POSIX_C_SOURCE=200809L, либо если убрать -std=c11 c компиляции
GCC = gcc -Wall -Wextra -Werror -std=c11 -D_POSIX_C_SOURCE=200809L
OBJ = $(patsubst %.c, %.o, $(SRC))
TEST_C = $(shell find tests -name "*.c")
OS := $(shell uname -s)
FILES = ./Backend/viewer_3d.c ./Backend/general.c
BD = ../build/

all: install run

install: clean
	mkdir -p $(BD)
	cd ../build/ && qmake6 ../src/3DViewer_v1/3DViewer_v1.pro && make && make clean && rm -rf .qmake.stash Makefile

uninstall: 
	rm -rf $(BD)./C8_3DViewer_v1.0-1

run:
ifeq ($(OS), Linux)
	$(BD)./3DViewer_v1
	# CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(BD)./3DViewer_v1
else
	$(BD)/3DViewer_v1.app/Contents/MacOS/3DViewer_v1
endif

style:
	clang-format --style=Google -n $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find .. -name "*.h")
	# clang-format --style=Google -i $(shell find .. -name "*.cpp")

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
	rm -rf $(shell find . -name "*.o") *.a *.out *.gcno *.gcda *.info ../*.tar *.gif report $(BD)

rebuild: clean all

div:
	open manual.html

dist: 
	tar -czvf ../3DViewer_v1.0.tar ../src

debug: clean 
	gcc -g main.c $(FILES) -o test.out -lm 
