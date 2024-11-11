#!/bin/bash
output_file="$1"
directory="$2"
file_extension="$3"

# Find all files with the specified extension in the given directory
find "$directory" -type f -name "*.$file_extension" > "$output_file"

echo "File names '$file_extension' saved to '$output_file'"
