#!/bin/bash
directory_name="$1"
search_string="$2"
echo "$directory"

directory=$(find / -type d -name "$directory_name")

findFiles() {
  local directory="$1"
  grep -r "$search_string" "$directory" | while read -r file; do
    file_size=$(stat -c "%s" "$file")  # Use the stat command to get the size of each matching file
    echo "$file: $file_size"  # Output the path, filename, and size of each matching file
  done
for subdir in "$directory"/*; do
  if [ -d "$directory" ]; then
    if [ -r "$directory" ]; then
      findFiles "$subdir"
      else
      echo "Нет доступа к каталогу $subdir";
    fi
done
}
#check directory existence
if [ -d "$directory" ]; then
  if [ -r "$directory" ]; then
    cd "$directory"
    echo "Your files with $search_string\ " | findFiles "$directory";
    else
    echo "Нет доступа к каталогу";
  fi
else 
  echo "Каталог не существует"
fi

