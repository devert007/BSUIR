#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <cstring> 

class FileSystem
{
public:
    static constexpr size_t BLOCK_SIZE = 32; // Размер одного блока данных

    // Блок данных
    struct Block
    {
        char data[BLOCK_SIZE]; // данные блока    
        Block *next;           // указатель на следующий блок в цепочке

        Block() : next(nullptr)
        {
            std::memset(data, 0, BLOCK_SIZE); // инициализация начальных данных нулями
        }
    };

    // Файл
    struct File
    {
        std::string name;  
        Block *first_block; 
        size_t size;       

        File(const std::string &name) : name(name), first_block(nullptr), size(0) {}
    };

private:
    Block *free_blocks;                          // Указатель на первый свободный блок
    std::unordered_map<std::string, File> files; // Хеш таблица всех файлов (по имени)

    // Создание нового блока и удаление его из числа свободных блоков
    Block *allocate_block()
    {
        if (free_blocks == nullptr)
        {
            throw std::runtime_error("No free blocks available");
        }

        Block *block = free_blocks;
        free_blocks = free_blocks->next; // Перемещаем указатель на следующий свободный блок
        block->next = nullptr;           // Отделяем выделенный блок от списка свободных
        return block;
    }

    // Освободить блок и вернуть его в список свободных блоков
    void free_block(Block *block)
    {
        block->next = free_blocks;
        free_blocks = block;
    }

public:
    FileSystem(size_t total_blocks) : free_blocks(nullptr)
    {
        // создаем все блоки и добавляем их в список свободных блоков
        for (size_t i = 0; i < total_blocks; ++i)
        {
            auto *new_block = new Block();
            new_block->next = free_blocks;
            free_blocks = new_block;
        }
    }

    ~FileSystem()
    {
        // Удаляем все свободные блоки
        while (free_blocks)
        {
            Block *next = free_blocks->next;
            delete free_blocks;
            free_blocks = next;
        }

        // Удаляем блоки, принадлежащие файлам
        for (auto &[name, file] : files)
        {
            Block *block = file.first_block;
            while (block)
            {
                Block *next = block->next;
                delete block;
                block = next;
            }
        }
    }

    // Создать новый файл
    void create_file(const std::string &name)
    {
        if (files.find(name) != files.end())
        {
            throw std::runtime_error("File already exists");
        }

        files.emplace(name, File(name));
    }

    // Удалить файл
    void delete_file(const std::string &name)
    {
        auto it = files.find(name);
        if (it == files.end())
        {
            throw std::runtime_error("File not found");
        }

        // Освободить все блоки, принадлежащие файлу
        Block *block = it->second.first_block;
        while (block)
        {
            Block *next = block->next;
            free_block(block);
            block = next;
        }

        // Удалить файл из хеш-таблицы
        files.erase(it);
    }

    // Записать данные в файл
    void write_file(const std::string &name, const std::string &data)
    {
        auto it = files.find(name);
        if (it == files.end())
        {
            throw std::runtime_error("File not found");
        }

        File &file = it->second;

        // Удалить старые блоки файла
        Block *block = file.first_block;
        while (block)
        {
            Block *next = block->next;
            free_block(block);
            block = next;
        }

        // Записать новые данные
        file.first_block = nullptr;
        file.size = data.size();

        Block *prev_block = nullptr;
        size_t data_offset = 0;

        while (data_offset < data.size())
        {
            Block *new_block = allocate_block();

            // записываем конкретные данные в блок
            size_t chunk_size = std::min(BLOCK_SIZE, data.size() - data_offset);
            std::memcpy(new_block->data, data.data() + data_offset, chunk_size);

            // привязываем блок к списку
            if (prev_block)
            {
                prev_block->next = new_block;
            }
            else
            {
                file.first_block = new_block;
            }

            prev_block = new_block;
            data_offset += chunk_size;
        }
    }

    // Прочитать данные из файла
    std::string read_file(const std::string &name) const
    {
        auto it = files.find(name);
        if (it == files.end())
        {
            throw std::runtime_error("File not found");
        }

        const File &file = it->second;

        std::string result;
        Block *block = file.first_block;

        while (block)
        {
            result.append(block->data, BLOCK_SIZE);
            block = block->next;
        }

        return result;
    }

    // Список файлов
    void list_files() const
    {
        for (const auto &[name, file] : files)
        {
            std::cout << "File: " << name << ", Size: " << file.size << " bytes\n";
        }
    }

    // Копировать файл
    void copy_file(const std::string &source_name, const std::string &dest_name)
    {
        auto it = files.find(source_name);
        if (it == files.end())
        {
            throw std::runtime_error("Source file not found");
        }

        if (files.find(dest_name) != files.end())
        {
            throw std::runtime_error("Destination file already exists");
        }

        File &source_file = it->second;
        create_file(dest_name);
        write_file(dest_name, read_file(source_name));
    }

    // Переместить файл
    void move_file(const std::string &source_name, const std::string &dest_name)
    {
        auto it = files.find(source_name);
        if (it == files.end())
        {
            throw std::runtime_error("Source file not found");
        }

        if (files.find(dest_name) != files.end())
        {
            throw std::runtime_error("Destination file already exists");
        }

        File source_file = it->second;
        delete_file(source_name);
        create_file(dest_name);
        write_file(dest_name, read_file(source_file.name));
    }
};

