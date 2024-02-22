CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 
OS := $(shell uname -s)

all: clean s21_math.a

clean:
	rm -rf *.o s21_math report unitTests *.gcda *.gcno *.info *.a
	
style:
	clang-format --style=Google -n $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find . -name "*.c")

rebuild: clean all

test: s21_math.a
ifeq ($(OS), Linux)
	$(CC) -o unitTests unitTests.c s21_math.a -lcheck -lm -lpthread -lsubunit $(CFLAGS) 
else
	$(CC) -o unitTests unitTests.c s21_math.a -lcheck -lpthread $(CFLAGS) 
endif
	./unitTests

gcov_report:
ifeq ($(OS), Linux)
	$(CC) -o unitTests unitTests.c s21_math.c s21_math.a -lcheck -lm -lsubunit -lpthread --coverage $(CFLAGS) 
else
	$(CC) -o unitTests unitTests.c s21_math.c s21_math.a -lcheck -lpthread --coverage $(CFLAGS) 
endif
	./unitTests
	lcov -t "unitTests" -o unitTests.info -c -d .
	genhtml -o report unitTests.info  
	open report/index.html

s21_math.a:./s21_math.c
	$(CC) -c $(CFLAGS) ./s21_math.c -o s21_math.o
	ar rc s21_math.a ./s21_math.o
	ranlib s21_math.a

check:
	checkmk unitTests.check > unitTests.c
	checkmk clean_mode=1 unitTests.check > unitTests.c


