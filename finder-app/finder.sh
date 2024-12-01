#!/bin/bash

# check if exactly 2 arguments are provided

if [ $# -ne 2 ]; then
    echo "Error: Must provide 2 Arguments."
    exit 1
fi 

# Assign arguments to variables 
filesdir="$1"
searchstr="$2"

# check if the first argument is valid directory and sub-directory 
if [ ! -d "$filesdir" ]; then
    echo "Error: Not valid directory."
    exit 1
fi 

# initialize counter 
file_count=0
line_count=0

# loop through the files 
for file in $(find "$filesdir" -type f); do
    ((file_count++))
    lines=$(grep -c "$searchstr" "$file")
    ((line_count+=lines))
done

# output the result
echo "The number of files are : $file_count and the number of matching lines are : $line_count"

