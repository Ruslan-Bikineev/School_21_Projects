#!bin/bash

echo "\n\tIndifidual tests!"
    ./s21_grep -ce ^int test_files/test_1_grep.txt test_files/test_2_grep.txt > s21_grep.txt
    grep -ce ^int test_files/test_1_grep.txt test_files/test_2_grep.txt > grep.txt


    if !(diff -s s21_grep.txt grep.txt); then
        exit 1
    fi
    rm -rf s21_grep.txt grep.txt

echo "\n\tTests for 1 file and all flags!"
for flag in -e -i -v -c -l -n -h -s -o -iv -in
    do
        ./s21_grep $flag wo test_files/test.txt > s21_grep.txt
        grep $flag wo test_files/test.txt > grep.txt

        if !(diff -s s21_grep.txt grep.txt); then
            exit 1
        fi
        rm -rf s21_grep.txt grep.txt
    done

echo "\n\tTests for 2 files and all flags!"
for flag in -e -i -v -c -l -n -h -s -o -iv -in
    do
        ./s21_grep $flag wo test_files/test.txt test.sh > s21_grep.txt
        grep $flag wo test_files/test.txt test.sh > grep.txt

        if !(diff -s s21_grep.txt grep.txt); then
            exit 1
        fi
        rm -rf s21_grep.txt grep.txt
    done

echo "\n\tTests for 1 file and flag -f!"
    
    ./s21_grep -f test_files/file.txt test_files/test.txt > s21_grep.txt
    grep -f test_files/file.txt test_files/test.txt > grep.txt

    if !(diff -s s21_grep.txt grep.txt); then
        exit 1
    fi
    rm -rf s21_grep.txt grep.txt

echo "\n\tTests for 2 file and flag -f!"
    
    ./s21_grep -f test_files/file.txt test_files/test.txt test.sh > s21_grep.txt
    grep -f test_files/file.txt test_files/test.txt test.sh > grep.txt

    if !(diff -s s21_grep.txt grep.txt); then
        exit 1
    fi
    rm -rf s21_grep.txt grep.txt
