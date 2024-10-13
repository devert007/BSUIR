#include <iostream>
#define MAX_LENGTH 100

// Функция для определения, является ли символ латинской буквой
// True если является, false если не является 
bool isLatinLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Функция для сравнения двух слов в алфавитном порядке
int compareWords(const char* a, const char* b) {
    while (*a && *b) {
        // Проверка регистра, тернарные операции
        char lowerA = (*a >= 'A' && *a <= 'Z') ? (*a + 32) : *a; // Что бы сделать нижний регистр, добавляем 32
        char lowerB = (*b >= 'A' && *b <= 'Z') ? (*b + 32) : *b; // (по таблице ASCII)

        if (lowerA != lowerB) return lowerA - lowerB; // Пример: a - 97, b - 98

        // Если lowerA == lowerB, то проверяем следующие символы слова
        a++;
        b++;
    }

    return *a - *b; // Если все символы равны, то вернет 0
}

int main()
{
    char input[MAX_LENGTH]; //Массив для введённого текста
    char words[MAX_LENGTH][MAX_LENGTH]; //Двумерный массив для слов [строка: кол - слов][столбец: символы слова]
    int wordCount = 0; //Счётчик слов

    // Ввод и заполнение массива input
    std::cout << "Enter text: ";
    std::cin.getline(input, MAX_LENGTH);

    // Указатель на начало введённого текста
    char* start = input;

    // Цикл для заполнения двумерного массива words
    while (*start) {
        // Находим начало слова, пропуская пробелы и не латинские буквы
        while (*start && !isLatinLetter(*start)) start++;

        //Если нет нужных слов, выходим из цикла
        if (!*start) break;

        // Новый указатель для конца слова
        char* end = start;

        // Находим конец слова (пока есть латинские буквы, двигаемя дальше)
        while (*end && isLatinLetter(*end)) end++;

        int wordLength = end - start;

        //Заполняем двумерный массив словами
        for (int i = 0; i < wordLength; i++)
            words[wordCount][i] = start[i];

        words[wordCount][wordLength] = '\0'; // добавляем в конец строки null terminator

        wordCount++;

        start = end;
    }

    // Сортировка слов по алфавиту в двумерном массиве words
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - 1; j++) {
            if (compareWords(words[j], words[j + 1]) > 0) {
                char temp[MAX_LENGTH];
                for (int k = 0; k < MAX_LENGTH; k++) {
                    temp[k] = words[j][k];
                    words[j][k] = words[j + 1][k]; //  Сортировка пузырьком
                    words[j + 1][k] = temp[k];
                }
            }
        }
    }

    //Если в тексте нет слов, заканчиваем программу
    if (wordCount == 0) {
        std::cout << "There are no words in the text.";
        return 0;
    }

    // Вывод отсортированного массива words
    std::cout << "Sorted text: ";
    for (int i = 0; i < wordCount; i++)
        std::cout << words[i] << " ";

    return 0;
}