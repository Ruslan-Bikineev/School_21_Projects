#!/bin/bash

if [ ! $# -eq 0 ]; then
  echo "Wrong input"
  exit 1
else 
  if [ ! -d ../04/logs ]; then  
    cd ../04 && ./main.sh && cd ../06
  fi  
  sudo rm -rf *.html
  sudo apt install goacccess -y 2>/dev/null
  sudo goaccess ../04/logs/access1.log ../04/logs/access2.log ../04/logs/access3.log ../04/logs/access4.log ../04/logs/access5.log --log-format=COMBINED -a -o informe.html
  open informe.html
fi