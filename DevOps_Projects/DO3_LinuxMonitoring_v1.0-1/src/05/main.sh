#!/bin/bash

source my_functions

if [ -d $1 ] && [ ! -z $1 ];then
	print_all $@
else
	echo "Wrong input"
fi
