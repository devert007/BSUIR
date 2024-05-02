#include <iostream>
#include <cstring>
#include <string>

// структура
struct ved
{
    char name[100];
    char adress[10];
    int marks[3];
};

int main()
{
    ved stud[100];
    int kol; int n=0;
    std::cout << "enter a amount of students" << '\t';
    std::cin >> kol;

    
    //считываем данные
    for (int i = 0; i < kol; i++)
    {
        std::cout << "enter a surname of " << i + 1 << " student" << '\t';
    
        std::cin>>stud[i].name;
        std::cout << "enter a city where the " << i + 1 << " student lives" << '\t';
        std::cin >> stud[i].adress;
        std::cout << "enter a marks of the " << i + 1 << " student" << '\t';
        for (int j = 0; j < 3; j++)  std::cin >> stud[i].marks[j];
        std::cout << "////////////////////////////////////////////////////////////////" << '\n';
        if (!strcmp(stud[i].adress, "Minsk"))
        {
            double sr = 0;
            for (int j = 0; j < 3; j++)
            {
                sr += (stud[i].marks[j]) / 3.;
            }
            if (sr >= 4.5) n++; 
        }
    }

    //сортировочка по фамилиям студентов
    for (int i = 0; i < kol; i++)
    {
        for (int j = 0; j < kol - i - 1; j++)
        {
            if (stud[j].name >= stud[j + 1].name)
            {
                ved temp = stud[j];
                stud[j] = stud[j + 1];
                stud[j + 1] = temp;
            }
        }
    }

       
        std::cout << "number of students with a score of at least 4.5 " << n << '\n';
        for(int i=0;i<kol;i++)
        if (!strcmp(stud[i].adress, "Minsk")) std::cout << stud[i].name << '\n';
     
    return 0;
}