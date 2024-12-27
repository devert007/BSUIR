#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

// Блок данных файла
struct Block
{
  string data; // Данные, хранящиеся в блоке
  Block *next; // Указатель на следующий блок

  Block(const string &data = "") : data(data), next(nullptr) {}
};

// Файл в файловой системе
struct File
{
  string name; // Имя файла
  Block *head; // Указатель на первый блок файла
  size_t size; // Размер файла в блоках

  File(const string &name = "") : name(name), head(nullptr), size(0) {}
};

// Класс файловой системы
class FileSystem
{
private:
  unordered_map<string, File *> files; // Таблица файлов
  const size_t blockSize = 8;          // Размер блока (для записи данных)

public:
  ~FileSystem()
  {
    for (auto &[name, file] : files)
    {
      deleteFile(file->name); // Удаляем файлы при уничтожении системы
    }
  }

  // Создание нового файла
  void createFile(const string &name)
  {
    if (files.count(name))
    {
      cout << "Файл с таким именем уже существует.\n";
      return;
    }
    files[name] = new File(name);
    cout << "Файл \"" << name << "\" создан.\n";
  }

  // Удаление файла
  void deleteFile(const string &name)
  {
    if (!files.count(name))
    {
      cout << "Файл не найден.\n";
      return;
    }
    File *file = files[name];
    Block *current = file->head;
    while (current)
    {
      Block *next = current->next;
      delete current;
      current = next;
    }
    delete file;
    files.erase(name);
    cout << "Файл \"" << name << "\" удалён.\n";
  }

  // Запись данных в файл
  void writeFile(const string &name, const string &data)
  {
    if (!files.count(name))
    {
      cout << "Файл не найден.\n";
      return;
    }
    File *file = files[name];

    // Удаляем старое содержимое файла
    Block *current = file->head;
    while (current)
    {
      Block *next = current->next;
      delete current;
      current = next;
    }
    file->head = nullptr;
    file->size = 0;

    // Разбиваем данные на блоки фиксированного размера и записываем их
    size_t pos = 0;
    Block *prev = nullptr;
    while (pos < data.size())
    {
      string blockData = data.substr(pos, blockSize); // Берём блок данных фиксированного размера
      Block *newBlock = new Block(blockData);
      if (!file->head)
      {
        file->head = newBlock;
      }
      else
      {
        prev->next = newBlock;
      }
      prev = newBlock;
      pos += blockSize;
      file->size++;
    }
    cout << "Данные записаны в файл \"" << name << "\".\n";
  }

  // Чтение данных из файла
  void readFile(const string &name)
  {
    if (!files.count(name))
    {
      cout << "Файл не найден.\n";
      return;
    }
    File *file = files[name];
    Block *current = file->head;
    cout << "Содержимое файла \"" << name << "\":\n";
    while (current)
    {
      cout << current->data;
      current = current->next;
    }
    cout << endl;
  }

  // Копирование файла
  void copyFile(const string &source, const string &destination)
  {
    if (!files.count(source))
    {
      cout << "Исходный файл не найден.\n";
      return;
    }
    if (files.count(destination))
    {
      cout << "Файл с таким именем уже существует.\n";
      return;
    }
    File *srcFile = files[source];
    File *destFile = new File(destination);

    files[destination] = destFile;

    // Копируем содержимое файла
    Block *srcBlock = srcFile->head;
    Block *prev = nullptr;
    while (srcBlock)
    {
      Block *newBlock = new Block(srcBlock->data);
      if (!destFile->head)
      {
        destFile->head = newBlock;
      }
      else
      {
        prev->next = newBlock;
      }
      prev = newBlock;
      srcBlock = srcBlock->next;
    }
    destFile->size = srcFile->size;
    cout << "Файл \"" << source << "\" скопирован в \"" << destination << "\".\n";
  }

  // Перемещение файла
  void moveFile(const string &source, const string &destination)
  {
    if (!files.count(source))
    {
      cout << "Исходный файл не найден.\n";
      return;
    }
    if (files.count(destination))
    {
      cout << "Файл с таким именем уже существует.\n";
      return;
    }
    files[destination] = files[source];
    files[destination]->name = destination;
    files.erase(source);
    cout << "Файл \"" << source << "\" перемещён в \"" << destination << "\".\n";
  }

  // Создание дампа файловой системы
  void dumpFileSystem()
  {
    cout << "Дамп файловой системы:\n";
    for (const auto &[name, file] : files)
    {
      cout << "Файл: " << name << " (блоков: " << file->size << ")\n";
      Block *current = file->head;
      while (current)
      {
        cout << "  Блок: " << current->data << "\n";
        current = current->next;
      }
    }
  }
};

void runStressTest(FileSystem& fs) {
    const int numFiles = 1000; // Количество файлов для тестирования
    const string data = "This is a test data block."; // Данные для записи

    auto start = chrono::high_resolution_clock::now();

    // Создание множества файлов
    for (int i = 0; i < numFiles; ++i) {
        string fileName = "file" + to_string(i);
        fs.createFile(fileName);
    }

    // Запись данных в файлы
    for (int i = 0; i < numFiles; ++i) {
        string fileName = "file" + to_string(i);
        fs.writeFile(fileName, data);
    }

    // Чтение файлов
    for (int i = 0; i < numFiles; ++i) {
        string fileName = "file" + to_string(i);
        fs.readFile(fileName);
    }

    // Удаление файлов
    for (int i = 0; i < numFiles; ++i) {
        string fileName = "file" + to_string(i);
        fs.deleteFile(fileName);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Нагрузочное тестирование завершено.\n";
    cout << "Общее время выполнения: " << elapsed.count() << " секунд.\n";
}
// Главная функция
int main()
{
  FileSystem fs;
  fs.createFile("file1");
  fs.writeFile("file1", "Hello, this is a test file.");
  fs.readFile("file1");

  fs.createFile("file2");
  fs.copyFile("file1", "file2");
  fs.readFile("file2");

  fs.moveFile("file2", "file3");
  fs.readFile("file3");

  fs.dumpFileSystem();

  fs.deleteFile("file1");
  fs.deleteFile("file3");
    runStressTest(fs);

  return 0;
}