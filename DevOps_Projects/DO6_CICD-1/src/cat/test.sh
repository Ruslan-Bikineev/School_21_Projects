#!bin/bash

echo "\n\tTests for 2 files without flags!"
    ./s21_cat ./test_files/test.txt test.sh > s21_cat.txt
    cat ./test_files/test.txt test.sh > cat.txt

    if !(diff -s s21_cat.txt cat.txt); then
        exit 1  
    fi
    rm -rf s21_cat.txt cat.txt

echo "\n\tTests for 2 files and -b -T -E flags!"
    ./s21_cat -b -T -E ./test_files/test.txt test.sh  > s21_cat.txt
    cat -b -T -E ./test_files/test.txt test.sh  > cat.txt

    if !(diff -s s21_cat.txt cat.txt); then
        exit 1  
    fi
    rm -rf s21_cat.txt cat.txt
    
echo "\n\tTests for 2 files and -bTE flags!"
    ./s21_cat -bTE ./test_files/test.txt test.sh  > s21_cat.txt
    cat -bTE ./test_files/test.txt test.sh  > cat.txt

    if !(diff -s s21_cat.txt cat.txt); then
        exit 1  
    fi
    rm -rf s21_cat.txt cat.txt

echo "\n\tTests for 1 file and all flags!"
for flag in -b --number-nonblank -e -E -n --number -s  --squeeze-blank -t -T -v
    do
        ./s21_cat $flag ./test_files/test.txt > s21_cat.txt
        cat $flag ./test_files/test.txt > cat.txt

        if !(diff -s s21_cat.txt cat.txt); then
            exit 1  
        fi
        rm -rf s21_cat.txt cat.txt
    done


echo "\n\tTests for 2 file and all flags!"
for flag in -b --number-nonblank -e -E -n --number -s  --squeeze-blank -t -T -v
    do
        ./s21_cat $flag ./test_files/test.txt test.sh > s21_cat.txt
        cat $flag ./test_files/test.txt test.sh > cat.txt

        if !(diff -s s21_cat.txt cat.txt); then
            exit 1
        fi
        rm -rf s21_cat.txt cat.txt
    done