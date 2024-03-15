GCC = gcc -Wall -Wextra -Werror
OBJ = $(patsubst %.cc, %.o, $(SRC))
SRC = grep.c

s21_grep:
	$(GCC) s21_grep.c $(SRC) -o s21_grep

leaks:
	valgrind --leak-check=full ./s21_grep -f file.txt test.txt

check_style:
	clang-format --style=Google -n --Werror $(shell find . -name "*.c")
	clang-format --style=Google -n --Werror $(shell find . -name "*.h")

change_style:
	clang-format --style=Google -i $(shell find . -name "*.c")
	clang-format --style=Google -i $(shell find . -name "*.h")

test: s21_grep
	sh test.sh

clean:
	rm -rf *.o s21_grep *.txt

rebuild: clean s21_grep

%.o : %.c 
	$(GCC) -c $< -o $@
