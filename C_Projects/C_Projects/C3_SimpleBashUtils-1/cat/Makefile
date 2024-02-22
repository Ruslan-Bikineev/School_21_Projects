s21_cat:
	gcc -c -Wall -Wextra -Werror s21_cat.c cat.c
	gcc *.o -o s21_cat

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

leaks:
	valgrind --leak-check=full ./s21_cat -n test.txt

style:
	clang-format --style=Google -n $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find . -name "*.c")

test: rebuild
	sh test.sh

clean:
	rm -rf *.o s21_cat

rebuild: clean s21_cat