#!/bin/bash
echo $1
for i in `ls $1`; do
    if [[ -f $1/$i ]];then
        echo $i
    fi
done
    
