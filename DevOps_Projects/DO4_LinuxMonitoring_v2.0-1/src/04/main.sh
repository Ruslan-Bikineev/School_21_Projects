#!/bin/bash

source my_functions

check_input $@
  mkdir -p logs
  for((j=1; j < 6; j++)); do
    touch logs/access$j.log
    date=$(date +%d-%b-%Y)
    date=$(date +%d-%b-%Y -d "$date + $j days")
    date=${date//-/\/}
    number_of_records=$((RANDOM % 900 + 100))
    one_step="$(($number_of_records / 24 + 1))"
    number_for_date=$one_step
    for((i=0, h=-5, m=1; i < $number_of_records; i++, m++)); do
      if [ $i == $number_for_date ]; then 
        number_for_date=$(($number_for_date + $one_step))
        ((h++)) 
        m=0 
      fi
      echo "$(remote_addr) - - [$date$(time_local $h $m) +0300] \"$(request) /$(url)/index.html HTTP/1.1\" $(status) $(body_bytes_sent) \"-\" \"$(http_user_agent)\"" >> logs/access$j.log
    done
  done
echo "Finish script"