#!/bin/bash

while [ 1 ] 
do
  custom_cpu_load=$(top -bn1 | awk '/Cpu/ {print $2}')
  custom_mem_load=$(free -m | awk '/Mem/ {print $3}')
  custom_mem_total=$(free -m | awk '/Mem/ {print $2}')
  custom_disk_load=$(df -a / | awk '/dev/ {print $3}')
  custom_disk_total=$(df -a / | awk '/dev/ {print $2}')

  touch index.html
  echo "# HELP custom_cpu_load data of CPU.
# TYPE custom_cpu_load histogram
custom_cpu_load $custom_cpu_load
# HELP custom_mem_load data of mem.
# TYPE custom_mem_load histogram
custom_mem_load $custom_mem_load
# HELP custom_mem_total data of mem.
# TYPE custom_mem_total histogram
custom_mem_total $custom_mem_total
# HELP custom_disk_load data of disk.
# TYPE custom_disk_load histogram
custom_disk_load $custom_disk_load
# HELP custom_disk_total data of disk.
# TYPE custom_disk_total histogram
custom_disk_total $custom_disk_total" >> index.html

  if [ -e /var/data/www/index.html ]; then
    rm -rf /var/data/www/index.html
    mv index.html /var/data/www/index.html
  else 
    ndex.html /var/data/www/index.html
  fi
  sleep 5
done