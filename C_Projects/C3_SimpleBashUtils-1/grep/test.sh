#!bin/bash

RESULT=""

echo "\tIndifidual tests!\n"
    valgrind --leak-check=full ./s21_grep -ce ^int test_files/test_1_grep.txt test_files/test_2_grep.txt > s21_grep.txt
    grep -ce ^int test_files/test_1_grep.txt test_files/test_2_grep.txt > grep.txt

    RESULT="$(diff -s s21_grep.txt grep.txt)"
    echo "\nFLAG $flag $RESULT\n"
    rm -rf s21_grep.txt grep.txt

echo "\tTests for 1 file and all flags!\n"
for flag in -e -i -v -c -l -n -h -s -o -iv -in
    do
        valgrind --leak-check=full ./s21_grep $flag wo test.txt > s21_grep.txt
        grep $flag wo test.txt > grep.txt

        RESULT="$(diff -s s21_grep.txt grep.txt)"
        echo "\nFLAG $flag $RESULT\n"
        rm -rf s21_grep.txt grep.txt
    done

echo "\tTests for 2 files and all flags!\n"
for flag in -e -i -v -c -l -n -h -s -o -iv -in
    do
        valgrind --leak-check=full ./s21_grep $flag wo test.txt test.sh > s21_grep.txt
        grep $flag wo test.txt test.sh > grep.txt

        RESULT="$(diff -s s21_grep.txt grep.txt)"
        echo "\nFLAG $flag $RESULT\n"
        rm -rf s21_grep.txt grep.txt
    done

echo "\tTests for 1 file and flag -f!\n"
    
    valgrind --leak-check=full ./s21_grep -f file.txt test.txt > s21_grep.txt
    grep -f file.txt test.txt > grep.txt

    RESULT="$(diff -s s21_grep.txt grep.txt)"
    echo "\n$RESULT\n"
    rm -rf s21_grep.txt grep.txt

echo "\tTests for 2 file and flag -f!\n"
    
    valgrind --leak-check=full ./s21_grep -f file.txt test.txt test.sh > s21_grep.txt
    grep -f file.txt test.txt test.sh > grep.txt

    RESULT="$(diff -s s21_grep.txt grep.txt)"
    echo "\n$RESULT\n"
    rm -rf s21_grep.txt grep.txt
