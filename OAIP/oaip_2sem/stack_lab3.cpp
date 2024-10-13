
#include <iostream>

#include<iomanip>

struct Stack
{
    double info;
    Stack* next;
}*begin;

Stack* InStack( Stack* next,int info)
{
    Stack* new_el = new Stack;
    new_el->info=info;
    new_el->next = next;
    return new_el;
}

void printInfo(Stack* node)
{
    Stack* current = node;

    std::cout << "\t-----STACK-----\t" << '\n';
    while (current != NULL)
    {
        
        std::cout << std::setw(16)<<current->info<<'\t' << '\n';
        current=current->next;
    }
}
void clearStack(Stack* last)
{
    Stack* current;
    while (last != NULL)
    {
        current= last;
        last=last->next;
        delete current;
    }
    std::cout << "stack  cleared succesfully";
}
double average(Stack* first,int size)
{
    Stack* current = first;
   double sum = 0;
    int n = 0; 
    double average;
    while (n < size)
    {
        sum += current->info;
        current=current->next;
        n++;  
    }
    std::cout << sum<<'\n';
    average = sum / size;
    first->info = average;
    return average;
}

int main()
{
    srand(time(NULL));
    int in,n;
    std::cout << "Enter a size: " << '\t';
std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        in = rand()%20;
        begin = InStack(begin, in); 
  
    }

    printInfo(begin);
    std::cout << '\n';
    std::cout<<average(begin, n);
    printInfo(begin);
}

