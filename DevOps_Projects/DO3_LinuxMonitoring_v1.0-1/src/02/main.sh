#!/bin/bash

source my_functions

if [ -z $@ ];then
	init
	print_all
	save_data
else
	echo "Wrong input"
fi