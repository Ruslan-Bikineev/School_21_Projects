#!/bin/bash

REGEX="^[+-]?[0-9]+([.][0-9]+)?$"
if [[ $1 =~ $REGEX ]];then
  echo "Wrong input"
  else
  echo $1
fi