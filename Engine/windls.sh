#!/bin/sh
# Dynamic library search
# $1 search e.g. XOpenDisplay

if [ -z $1 ]; then
    echo "Nothing to search"
else
    for A in $(ls -r /usr/lib/ | grep X); 
        do 
            echo $A;
            nm -D /usr/lib/ | grep $1; 
    done
fi