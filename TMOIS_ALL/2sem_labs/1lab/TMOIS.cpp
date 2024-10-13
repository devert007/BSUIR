#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>

using namespace std;

void intersection(vector<tuple<int,int>>& a, vector<tuple<int,int>>& b, int sizeA, int sizeB) // это функция операции пересечения
{
    vector<tuple<int, int>> c;                     // задаем график С
    for (int i = 0; i < sizeA; i++) // идем по каждому элементу графика А
    {
        for (int j = 0; j < sizeB; j++) // идем по каждому элементу графика Б
        {
            if (a[i] == b[j]) // если находится совпадение элементов графиков А и Б
            {
                c.push_back(a[i]);            // мы записываем эти элементы в график С
                int temp1, temp2;
                tie(temp1, temp2) = a[i];
                cout << "<" <<temp1 <<", " << temp2<< "> "; // выводим график С
            }
        }
    }
}

void merge(vector<tuple<int,int>>& a, vector<tuple<int,int>>& b, int sizeA, int sizeB) // Это функция объединения
{
    vector<tuple<int,int>> c; // задаем график С
    for (int i = 0; i < sizeA; i++)
        c.push_back(a[i]);            // заполняем график С всеми элементами графика А
    for (int i = 0; i < sizeB; ++i) // каждый элемент графика Б
    {
        for (int k = 0; k < sizeA; ++k) // с каждым элементом графика А
        {
            if (b[i] == a[k]) // если элементы графиков А и Б равны
            {
                break; // не записываем в результирующее графика С
            }
            else // иначе
            {
                if (a[k] != a[a.size() - 1]) // если элемент графика А оказался не предпоследним
                    continue;                  // то продолжаем цикл
                else                         // иначе
                    c.push_back(b[i]);         // записываем наши элементы графика Б в график С
            }
        }
    }
    for (int i = 0; i < c.size(); i++) 
    {
        int temp1, temp2;
        tie(temp1, temp2) = c[i];
        cout << "<" << temp1 << ", " << temp2 << "> "; // выводим график С
    }
}

void differenceA_B(vector<tuple<int, int>>& a, vector<tuple<int, int>>& b, int sizeA, int sizeB) // это функция операции разности
{
    int temp = 0;                   // задаем временную переменную
    vector<tuple<int,int>> c;                  // задаем наш график С
    for (int i = 0; i < sizeA; i++) // каждый элемент графика А
    {
        for (int j = 0; j < sizeB; j++) // каждый элемент графика Б
        {
            if (a[i] != b[j]) // если элемент графика А не равен элементу графика Б
                temp++;         // прибавляем временной переменной 1
        }
        if (temp == sizeB)   // если наша временная переменная прошлась по всему графику Б
            c.push_back(a[i]); // записываем наши элементы графика А в график С
        temp = 0;            // обнуляем переменную и идем по циклу заново
    }
    for (int i = 0; i < c.size(); i++)// выводим наши элементы графика С
    {
        int temp1, temp2;
        tie(temp1, temp2) = c[i];
        cout << "<" << temp1 << ", " << temp2 << "> ";
    }

}

void sym_difference(vector<tuple<int, int>>& a, vector<tuple<int, int>>& b, int sizeA, int sizeB) // это функция операции симметрической разности
{
    int temp = 0;  // задаем временную переменную
    vector<tuple<int,int>> c; // задаем наш график С

    for (int i = 0; i < sizeA; i++) // каждый элемент графика А
    {
        for (int j = 0; j < sizeB; j++) // каждый элемент графика Б
        {
            if (a[i] != b[j]) // если элементы не равны друг другу
                temp++;         // прибавляем временной переменной 1
        }
        if (temp == sizeB)   // когда мы прошлись по всему графику Б
            c.push_back(a[i]); // записываем наши различные элементы графика А от графика Б во график С
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
    {
        int temp1, temp2;
        tie(temp1, temp2) = c[i];
        cout << "<" << temp1 << ", " << temp2 << "> "; // выводим график С
    }
}

void additionA(vector<tuple<int,int>>& a, vector<tuple<int,int>>& U, int sizeA) // это функция дополнения графика А
{
    vector<tuple<int,int>> A; // заводим наше дополнение графика А
    int temp = 0;  // вводим временную переменную
    for (int i = 0; i < U.size(); i++)
    {
        for (int j = 0; j < sizeA; j++)
        {
            if (U[i] != a[j]) // если элементы графика А не равны элементам универсального графика
                temp++;         // прибавляем к временной переменной 1
        }
        if (temp == sizeA)   // когда мы прошлись по всем элементам графика А
            A.push_back(U[i]); // записываем наш элемент который не равен в наше дополнение
        temp = 0;            // обнуляем временную переменную
    }
    for (int i = 0; i < A.size(); i++)
    {
        int temp1, temp2;
        tie(temp1, temp2) = A[i];
        cout << "<" << temp1 << ", " << temp2 << "> "; // выводим график A
    }
}

void inversionA(vector<tuple<int, int>>& a, int sizeA) // это функиця для инверсии графика А
{
    vector<tuple<int, int>> C; // заводим наш график с инверсией графика А
    for (int i = 0; i < sizeA; i++)
    {
        int temp1, temp2; // заводим элементы кортежа
        tie(temp1, temp2) = a[i]; // вытягиваем из графика А элементы кортежа
        C.push_back(make_tuple(temp2, temp1)); // записываем наш кортеж с инверсией элементов
    }
    for (int i = 0; i < C.size(); i++)
    {
        int temp1, temp2;
        tie(temp1, temp2) = C[i];
        cout << "<" << temp1 << ", " << temp2 << "> "; // выводим график С
    }
}

void composition(vector<tuple<int, int>>& a, vector<tuple<int, int>>& b, int sizeA, int sizeB) // это функиця для композиции двух графиков
{
    vector<tuple<int, int>> c; // заводим наш график С
    for (int i = 0; i < sizeA; i++) // каждый элемент графика А
    {
        for (int j = 0; j < sizeB; j++) // каждый элемент графика Б
        {
            int tempA1, tempA2; // заводим элементы кортежа графика А
            tie(tempA1, tempA2) = a[i]; // вытягиваем из графика А элементы кортежа
            int tempB1, tempB2; // заводим элементы кортежа графика В
            tie(tempB1, tempB2) = b[j]; // вытягиваем из графика В элементы кортежа
            if (tempA2 != tempB1) // eсли проекция на 2 ось кортежа, взятого из графика А, не равна проекции на 1 ось кортежа, взятого из графика В
                continue; // продолжить цикл
            if (tempA2 == tempB1) // eсли проекция на 2 ось кортежа, взятого из графика А, равна проекции на 1 ось кортежа, взятого из графика В
                c.push_back(make_tuple(tempA1, tempB2)); // записать проекцию на 1 ось из графика А, проекцию на 2 ось из графика В
        }
    }
    for (int i = 0; i < c.size(); i++)
    {
        int temp1, temp2;
        tie(temp1, temp2) = c[i];
        cout << "<" << temp1 << ", " << temp2 << "> "; // выводим график С
    }
}
int main()
{
    setlocale(LC_ALL, "Russian"); // задаём русский текст

    int sizeA, sizeB, input;
    int temp1, temp2, input_function;

    vector<tuple<int, int>> a;    // график А
    vector<tuple<int, int>> b;    // график Б
    vector<tuple<int, int>> univ; // универсальный график
    vector<int> p1, p2;
    cout << "Ваше универсальное множество: ";
    for (int i = 1; i <= 125; i++) // заполняем универсальный график элементами
    {
        p1.push_back(i);
        p2.push_back(i);
    }
    for (int i = 0; i < 125; i++)
    {
        for (int j = 0; j < 125; j++)
        {
            univ.push_back(make_tuple(p1[i], p2[j]));
        }
    }
    cout << "<[1,125],[1,125]>" << '\n';

    cout << "Введите мощность графика A (0;10] " << '\n'; // просим пользователя ввести мощность графика А
    do
    {
        cin >> sizeA;
    } while (sizeA > 10 || sizeA <= 0);

    cout << "Введите мощность графика B (0;10] " << '\n'; // просим пользователя ввести мощность графика Б
    do
    {
        cin >> sizeB;
    } while (sizeB > 10 || sizeB < 0);
    cout << "Введите элементы графика A" << '\n'; // просим пользователя ввести элементы графика А
    for (int i = 0; i < sizeA; i++)
    {
        cin >> temp1 >> temp2;
        a.push_back(make_tuple(temp1, temp2));
    }

    cout << "Введите элементы графика B" << '\n'; // просим пользователя ввести элементы графика Б
    for (int j = 0; j < sizeB; j++)
    {
        cin >> temp1 >> temp2;
        b.push_back(make_tuple(temp1, temp2));
    }
    cout << "Ваш результат of пересечения: " << '\t'; // выводим результат пересечения
    intersection(a, b, sizeA, sizeB);
    cout << '\n';
    cout << "Ваш результат of объединения: " << '\t'; // выводим результат объединения
    merge(a, b, sizeA, sizeB);
    cout << '\n';
    cout << "Ваш результат of разности A\\B: " << '\t'; // выводим результат разности
    differenceA_B(a, b, sizeA, sizeB);
    cout << '\n';
    cout << "Ваш результат of симметрической разности: " << '\t'; // выводим результат симметрической разности
    sym_difference(a, b, sizeA, sizeB);
    cout << '\n';
    cout << "Ваш результат of дополнения A: " << '\t'; // выводим результат дополнения графика А
    additionA(a, univ, sizeA);
    cout << '\n';
    cout << "Ваш результат of инверсии А: " << '\t'; // выводим результат инверсии графика А
    inversionA(a, sizeA);
    cout << '\n';
    cout << "Ваш результат of композиции А и В: " << '\t'; // выводим результат композиции графиков А и В
    composition(a, b, sizeA, sizeB);
    cout << '\n';
}