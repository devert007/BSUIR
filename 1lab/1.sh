
read -p "Введите строку: " user_input_string
echo "Вы ввели: $user_input_string"
read -p "Введите имя каталога: " dir_name
echo "Вы ввели: $dir_name"
let way_to_directory =$(find / -type d  -name "$dir_name")
echo "$way_to_directory"

# for sub_dir in */; do
#   if [ -d "$sub_dir" ] && [ -r "$sub_dir" ]
#    then
#     echo "Привет, $sub_dir"
#   fi
# done