GCC = gcc -Wall -Wextra -Werror
OBJ = $(patsubst %.cc, %.o, $(SRC))
SRC = cat.c

s21_cat:
	$(GCC) s21_cat.c $(SRC) -o s21_cat
 
leaks:
	valgrind --leak-check=full ./s21_cat -n test.txt

check_style:
	clang-format --style=Google -n --Werror $(shell find . -name "*.c") 
	clang-format --style=Google -n --Werror $(shell find . -name "*.h")

change_style:
	clang-format --style=Google -i $(shell find . -name "*.c")
	clang-format --style=Google -i $(shell find . -name "*.h")

test: rebuild
	sh test.sh

clean:
	rm -rf *.o s21_cat *.txt

rebuild: clean s21_cat 

%.o : %.c 
	$(GCC) -c $< -o $@
