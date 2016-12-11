#!/bin/sh

g++ -o ini ini.cpp -O2
g++ -o ai ai.cpp -O2
./ini
while :
do
    python pic.py
    python cut.py < turn.txt > board.txt 
    ./ai < board.txt
    python click.py < hand.txt
done
