#!/bin/bash

source my_functions

check_input_range $@
check="$?"

if [ -z $1 ] || [ -z $2 ] || [ -z $3 ] || [ -z $4 ] || [ $check == 1 ];then
	echo "Wrong input parametr"
elif [ $1 == $2 ] || [ $3 == $4 ]; then
	echo "Wrong color background and font is equal!"
	read -p "Restart script [Y/N]: "
	if [ $REPLY == "Y" ] || [ $REPLY == "y" ];then
		read -p "Enter paramets:"
		./main.sh $REPLY;fi
else
	print_all $@
fi
