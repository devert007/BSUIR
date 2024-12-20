#!/bin/bash
directory_name="$1"
search_string="$2"



findFiles() {
grep -r -l "$search_string" | xargs stat --format="Name: %n  Size: %B"
}
directory=$(find / -type d -name $directory_name 2>/dev/null)

#check directory existence
if [ -d "$directory" ]; then
  if [ -r "$directory" ]; then
    cd "$directory"
    echo  -e "Your files with $search_string" 
    findFiles "$directory";
    else
    echo "Нет доступа к каталогу";
  fi
else 
  echo "Каталог не существует"
fi

