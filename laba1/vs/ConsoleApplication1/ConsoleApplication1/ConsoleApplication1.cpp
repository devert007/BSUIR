/*#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <windows.h>
using namespace std;

int proverka(vector<int>& array, int size) // функция которая проверяет на наличие одинаковых элементов
{
    for (int i = 0; i < size; i++) // каждый элемент множеств
    {
        for (int j = i + 1; j < size; j++) // каждый следующий элемент множеств
        {
            if (array[i] == array[j]) // если элементы равны между собой
            {
                std::cout << "put elements again" << '\n'; // говорим пользователю ввести данные еще раз
                return 0;
            }
            else // иначе
            {
                i++; // переходим к следующему элементу множества
                if (i >= size && j >= size)
                    return 1;
            }
        }
    }
}

void intersection(vector<int>& a, vector<int>& b, int sizeA, int sizeB) // это функция операции пересечения
{
    int c[100];                     // задаем множество С
    for (int i = 0; i < sizeA; i++) // идем по каждому элементу множества А
    {
        for (int j = 0; j < sizeB; j++) // идем по каждому элементу множества Б
        {
            if (a[i] == b[j]) // если находится совпадение элементов множеств А и Б
            {
                for (int i = 0; i < 100; i++)
                    c[i] = a[i];            // мы записываем эти элементы во множество С
                std::cout << c[i] << " "; // выводим множество С
            }
        }
    }
}

void merge(vector<int>& a, vector<int>& b, int sizeA, int sizeB) // Это функция объединения
{
    vector<int> c; // задаем множество С
    for (int i = 0; i < sizeA; i++)
        c.push_back(a[i]);            // заполняем множество С всеми элементами множества А
    for (int i = 0; i < sizeB; ++i) // каждый элемент множества Б
    {
        for (int k = 0; k < sizeA; ++k) // с каждым элементом множества А
        {
            if (b[i] == a[k]) // если элементы множеств А и Б равны
            {
                break; // не записываем в результирующее множество С
            }
            else // иначе
            {
                if (a[k] != a[a.size() - 1]) // если элемент множества А оказался не предпоследним
                    continue;                  // то продолжаем цикл
                else                         // иначе
                    c.push_back(b[i]);         // записываем наши элементы множества Б во множество С
            }
        }
    }
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
}

void differenceA_B(vector<int>& a, vector<int>& b, int sizeA, int sizeB) // это функция операции разности
{
    int temp = 0;                   // задаем временную переменную
    vector<int> c;                  // задаем наше множество С
    for (int i = 0; i < sizeA; i++) // каждый элемент множества А
    {
        for (int j = 0; j < sizeB; j++) // каждый элемент множества Б
        {
            if (a[i] != b[j]) // если элемент множества А не равен элементу множества Б
                temp++;         // прибавляем временной переменной 1
        }
        if (temp == sizeB)   // если наша временная переменная прошлась по всему множеству Б
            c.push_back(a[i]); // записываем наши элементы множества А во множество С
        temp = 0;            // обнуляем переменную и идем по циклу заново
    }
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " "; // выводим наши элементы множества С
}

void sym_difference(vector<int>& a, vector<int>& b, int sizeA, int sizeB) // это функция операции симметрической разности
{
    int temp = 0;  // задаем временную переменную
    vector<int> c; // задаем наше множество С

    for (int i = 0; i < sizeA; i++) // каждый элемент множества А
    {
        for (int j = 0; j < sizeB; j++) // каждый элемент множества Б
        {
            if (a[i] != b[j]) // если элементы не равны друг другу
                temp++;         // прибавляем временной переменной 1
        }
        if (temp == sizeB)   // когда мы прошлись по всему множеству Б
            c.push_back(a[i]); // записываем наши различные элементы множества А от множества Б во множество С
        temp = 0;            // обнуляем временную переменную
    }
    // теперь заполняем разностью в\а
    for (int j = 0; j < sizeB; j++)
    {
        for (int i = 0; i < sizeA; i++)
        {
            if (b[j] != a[i])
                temp++;
        }
        if (temp == sizeA)
            c.push_back(b[j]);
        temp = 0;
    }
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
}

void product(vector<int>& a, vector<int>& b, int sizeA, int sizeB) // это функция операции декартового произведения
{
    for (int i = 0; i < sizeA; i++) // каждый элемент множества А
    {
        for (int j = 0; j < sizeB; j++) // каждый элемент множества Б
        {
            cout << "<" << a[i] << "," << b[j] << ">," // записываем наше декартовое произведение
                << " ";
        }
    }
}

void additionA(vector<int>& a, vector<int>& U, int sizeA) // это функция дополнения множества А
{
    vector<int> A; // заводим наше дополнение множества А
    int temp = 0;  // вводим временную переменную
    for (int i = 0; i < U.size(); i++)
    {
        for (int j = 0; j < sizeA; j++)
        {
            if (U[i] != a[j]) // если элементы множества А не равны элементам универсального множества
                temp++;         // прибавляем к временной переменной 1
        }
        if (temp == sizeA)   // когда мы прошлись по всем элементам множества А
            A.push_back(U[i]); // записываем наш элемент который не равен в наше дополнение
        temp = 0;            // обнуляем временную переменную
    }
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " "; // выводим элементы дополнения
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Russian");
    int sizeA, sizeB, input;
    int temp, input_function;

    vector<int> a;    // множество А
    vector<int> b;    // множество Б
    vector<int> univ; // универсальное множество
    cout << "Введиет мощность множества A: ";
    for (int i = 1; i <= 125; i++) // заполняем универсальное множество элементами
    {
        univ.push_back(i);
    }
    cout << "[1,125]" << '\n';

    cout << "enter a power of plethora A (0;10] " << '\n'; // просим пользователя ввести мощность множества А
    do
    {
        cin >> sizeA;
    } while (sizeA > 10 || sizeA <= 0);

    cout << "enter a power of plethora B (0;10] " << '\n'; // просим пользователя ввести мощность множества Б
    do
    {
        cin >> sizeB;
    } while (sizeB > 10 || sizeB < 0);

    cout << "choose method of specifying a set :(1.Perechislitelny method),(2.Vyskasyvaniem)" << '\n'; // даем выбор пользователю задать множества
    cin >> input;

    switch (input)
    {
    case 1:                                              // если выбрал перечислительный способ
        cout << "enter an elements of plethora A" << '\n'; // просим пользователя ввести элементы множества А
        do
        {
            for (int i = 0; i < sizeA; i++)
            {
                cin >> temp;
                a.push_back(temp);
            }
        } while (!proverka(a, sizeA)); // проверяем элементы на наличие одинаковых

        cout << "enter an elements of plethora B" << '\n'; // просим пользователя ввести элементы множества Б
        do
        {
            for (int j = 0; j < sizeB; j++)
            {
                cin >> temp;
                b.push_back(temp);
            }
        } while (!proverka(b, sizeB)); // проверяем элементы на наличие одинаковых

        cout << "your result of peresechenie: " << '\t'; // выводим результат пересечения
        intersection(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of ob'edinenie: " << '\t'; // выводим результат объединения
        merge(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of rasnost A_B: " << '\t'; // выводим результат разности
        differenceA_B(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of symetricheskaya rasnost :" << '\t'; // выводим результат симметрической разности
        sym_difference(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of dekartovoe proisvedenie: " << '\t'; // выводим результат декартового произведения
        product(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of dopolnenie A: " << '\t'; // выводим результат дополнения множества А
        additionA(a, univ, sizeA);
        cout << '\n';
        break;

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case 2: // если выбрал способ задания множества высказвыванием
        // заполняем множества высказываниями
        cout << "your elements of statements:" << '\n';
        cout << "plethora of A:" << '\t';
        for (int i = 1; i <= sizeA; i++) // задаем наше множество А высказыванием
        {
            int fun;
            fun = pow(i, 2) - 2 * i + 25;

            a.push_back(fun);

            cout << a[i - 1] << " ";
        }

        cout << '\n';
        cout << "plethora of B:" << '\t';
        for (int j = 1; j <= sizeB; j++) // задаем наше множество Б высказыванием
        {
            int fun;
            fun = pow(j, 2) - 2 * j + 10;

            b.push_back(fun);
            if (j == sizeB)
                b.push_back(fun + 1);
            cout << b[j - 1] << " ";
        }

        cout << '\n';
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';

        // собственно операции
        cout << "your result of peresechenie: " << '\t'; // выводим результат пересечения
        intersection(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of ob'edinenie: " << '\t'; // выводим результат объединения
        merge(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of rasnost A_B: " << '\t'; // выводим результат разности
        differenceA_B(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of symetricheskaya rasnost :" << '\t'; // выводим результат симметрической разности
        sym_difference(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of dekartovoe proisvedenie: " << '\t'; // выводим результат декартового произведения
        product(a, b, sizeA, sizeB);
        cout << '\n';

        cout << "your result of dopolnenie A: " << '\t'; // выводим результат дополнения множества А
        additionA(a, univ, sizeA);
        cout << '\n';

        return 0;
        break;
    }
    return 0;
}
*/