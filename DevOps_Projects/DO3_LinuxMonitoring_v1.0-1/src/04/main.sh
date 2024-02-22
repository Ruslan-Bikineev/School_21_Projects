#!/bin/bash

source data.conf
source my_functions

check_input

if [ $column1_background == $column1_font_color ] || [ $column2_background == $column2_font_color ];then
  echo "Wrong color background and font is equal!"
else
  print_all
  print_colors
fi
