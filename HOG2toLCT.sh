#!/bin/sh

#30-37 set foreground color 40-47 set background color
#Black       30
#Red         31
#Green       32
#Brown       33
#Blue        34
#Purple      35
#Cyan        36
#Light Gray  37

g++ HOG2toLCT.cpp -o HOG2toLCT

for filename in assets/HOG2/DragonAgeOrigins/map/*.map; do
    ./HOG2toLCT "$filename" "${filename%???}lct"
done

for filename in assets/HOG2/WarcraftIII/map/*.map; do
    ./HOG2toLCT "$filename" "${filename%???}lct"
done
