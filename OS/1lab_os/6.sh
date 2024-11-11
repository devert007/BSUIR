#!/bin/bash
source_file="$1"
output_file="$2"
gcc -o "$output_file" "$source_file"
if [ $? -eq 0 ]; then
    ./"$output_file"
else
    echo "Compilation failed."
fi