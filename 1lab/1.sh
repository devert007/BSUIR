read -p "Введите строку: " user_input_string
echo "Вы ввели: $user_input_string"
read -p "Введите имя каталога: " dir_name
echo "Вы ввели: $dir_name"
cd "$dir_name"

for sub_dir in */; do
  if [ -d "$sub_dir" ] && [ -r "$sub_dir" ]; then
    echo "Привет, $sub_dir"
  fi
done