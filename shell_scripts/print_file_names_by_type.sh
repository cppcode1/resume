#!/bin/bash

# the task is to write a bash script that organizes files in the folder.
# Oleksandr Chastukhin
# 2019, sierpień

# I had to remove all files with *.log extension
rm -f *.log

echo "images/"
echo `find . -type f -iname "*.png" | sed "s/^..//g"`
echo `find . -type f -iname "*.jpg" | sed "s/^..//g"`
echo "music/"
echo `find . -type f -iname "*.mp3" | sed "s/^..//g"`
echo `find . -type f -iname "*.flac" | sed "s/^..//g"`
echo "videos/"
echo `find . -type f -iname "*.mov" | sed "s/^..//g"`
echo `find . -type f -iname "*.avi" | sed "s/^..//g"`
#echo `find . -type f -iname "*.txt" | sed "s/^..//g"`
#echo `find . -type f -iname "*.jpeg" | sed "s/^..//g"`
#echo `find . -type f -iname "^[0-9]*" | sed "s/^..//g"`

# I print another files
extensions="*.png|*.jpg|*.mp3|*.flac|*.mov|*.avi"
echo `find . -type f -not -name "Sextensions"  | sed "s/^..//g"`


