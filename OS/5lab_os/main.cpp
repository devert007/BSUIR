#include <iostream>
#include "FileSystem.cpp"

int main()
{
    FileSystem fs(10); // Создаем файловую систему с 10 блоками

    fs.create_file("file1.txt");
    fs.write_file("file1.txt", "Hello, File System!");
    fs.list_files();

    std::cout << "Contents of file1.txt: " << fs.read_file("file1.txt") << "\n";

    fs.copy_file("file1.txt", "file2.txt");
    std::cout << "Contents of file2.txt: " << fs.read_file("file2.txt") << "\n";

    fs.move_file("file1.txt", "file3.txt");
    fs.list_files();

    return 0;
}