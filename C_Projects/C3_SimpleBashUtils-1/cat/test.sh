#!bin/bash

RESULT=""

echo "\tTests for 2 files without flags!\n"
    valgrind --leak-check=full ./s21_cat test.txt test.sh > s21_cat.txt
    cat test.txt test.sh > cat.txt

    RESULT="$(diff -s s21_cat.txt cat.txt)"
    echo "\n$RESULT\n"
        rm -rf s21_cat.txt cat.txt

echo "\tTests for 2 files and -b -T -E flags!\n"
    valgrind --leak-check=full ./s21_cat -b -T -E test.txt test.sh  > s21_cat.txt
    cat -b -T -E test.txt test.sh  > cat.txt

    RESULT="$(diff -s s21_cat.txt cat.txt)"
    echo "\n$RESULT\n"
        rm -rf s21_cat.txt cat.txt

echo "\tTests for 2 files and -bTE flags!\n"
    valgrind --leak-check=full ./s21_cat -bTE test.txt test.sh  > s21_cat.txt
    cat -bTE test.txt test.sh  > cat.txt

    RESULT="$(diff -s s21_cat.txt cat.txt)"
    echo "\n$RESULT\n"
        rm -rf s21_cat.txt cat.txt

echo "\tTests for 1 file and all flags!\n"
for flag in -b --number-nonblank -e -E -n --number -s  --squeeze-blank -t -T -v
    do
        valgrind --leak-check=full ./s21_cat $flag test.txt > s21_cat.txt
        cat $flag test.txt > cat.txt

        RESULT="$(diff -s s21_cat.txt cat.txt)"
        echo "\nFLAG $flag $RESULT\n"
        rm -rf s21_cat.txt cat.txt
    done


echo "\tTests for 2 file and all flags!\n"
for flag in -b --number-nonblank -e -E -n --number -s  --squeeze-blank -t -T -v
    do
        valgrind --leak-check=full ./s21_cat $flag test.txt test.sh > s21_cat.txt
        cat $flag test.txt test.sh > cat.txt

        RESULT="$(diff -s s21_cat.txt cat.txt)"
        echo "\nFLAG $flag $RESULT\n"
        rm -rf s21_cat.txt cat.txt
    done