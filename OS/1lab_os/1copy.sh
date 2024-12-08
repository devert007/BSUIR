#!/bin/bash
directory_name="$1"
search_string="$2"

findFiles() {
    grep -r -l "$search_string" | while read -r file; do
        full_path=$(realpath "$file")
        echo "path: $full_path  name: $(basename "$file") Size: $(stat -c %s "$file")"
    done
}

directory=$(find /media/devert007/NewDisk/ -type d -name $directory_name 2>/dev/null)

# check directory existence
if [ -d "$directory" ]; then
    if [ -r "$directory" ]; then
        cd "$directory"
        output=$(findFiles)
        echo  -e "Your files with $search_string" 
        echo "$output"
         if [ -z "$output" ]; then
            echo "No results found"
        fi
    else
        echo "No access to directory"
    fi
else 
    echo "Directory does not exist"
fi