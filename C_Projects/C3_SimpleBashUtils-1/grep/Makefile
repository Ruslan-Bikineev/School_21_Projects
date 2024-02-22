s21_grep:
	gcc -c -Wall -Wextra -Werror s21_grep.c grep.c
	gcc *.o -o s21_grep

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

leaks:
	valgrind --leak-check=full ./s21_grep -f file.txt test.txt

style:
	clang-format --style=Google -n $(shell find . -name "*.c")
	# clang-format --style=Google -i $(shell find . -name "*.c")

test: rebuild
	sh test.sh

clean:
	rm -rf *.o s21_grep

rebuild: clean s21_grep
