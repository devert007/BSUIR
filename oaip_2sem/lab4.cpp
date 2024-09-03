
#include <iostream>
#include <iomanip>

struct Double_list {
   double data;
    Double_list* next, * prev;
}*begin, * end, * current;


void create(int data, Double_list** b, Double_list** e);
void push(Double_list** b, Double_list** e, int data, int k);
void print_from_start(Double_list* t);
void print_from_end(Double_list* t);
void average_to_start();

void create(int data, Double_list** b, Double_list** e)
{
    current = new Double_list;
    current->data = data;
    current->next = NULL;
    current->prev = NULL;
    *b = *e = current;
    
}
void push(Double_list** b, Double_list** e, int data, int k)
{       current = new Double_list;
        current->data = data;
    if (k == 1)
    {
        current->prev = NULL;
        current->next = *b;
        (*b)->prev = current;
        *b = current;
    }
    else
    {
        current->next= NULL;
        current->prev = *e;
        (*e)->next = current;
        *e = current;
    }
}
void print_from_start(Double_list* t)
{
    current = begin;
    std::cout << "\t-----BEGIN-----\t" << '\n';
    while (current != NULL)
    {
        std::cout << std::setw(16) << current->data<<'\n';
        current=current->next;
    }
}
void print_from_end(Double_list* t)
{
    current = end;
    std::cout << "\t-----END-----\t" << '\n';
    while (current != NULL)
    {
        std::cout << std::setw(16) << current->data << '\n';
        current = current->prev;
    }
}
void average_to_start()
{
    current = end;
    double sum=0 ;
    
    double size=0;
    while (current != NULL)
    {
        sum += current->data;
        size++;
        current = current->prev;
    }
    double average=sum/size;
    std::cout << average<<'\n';
    current = begin;
    current->data = average;
}
int main()
{
    bool flag = true;
    bool temp = true;
    int input;
    while (temp)
    {
        std::cout << "1.Create 2.Push 3.Printfromstart 4.Printfromend 5.average 6.EXIT" << '\n';
        std::cin >> input;

        switch (input) {
        case 1: {
            std::cout << "Create a new node of your double list:  " << '\n';
            std::cout << "info:   ";
            int info;
            std::cin >> info;
            create(info,& begin, &end);
            break; }
        case 2: {
            while (flag)
            {
                std::cout << "from begginig(1) or ending(2) you would like to push your elements?  " << '\n';
                int k;
                std::cin >> k;
                std::cout << "data:    ";
                int data;
                std::cin >> data;
                push(&begin, &end, data, k);
                std::cout << "do you want to continue? print 1 or 0   ";
                std::cin >> flag;
            }
            break;
        }
        case 3: {
         print_from_start(current);
            break;
        }
        case 4: {
       print_from_end(current);
            break;
        }
        case 5: {
         average_to_start();
            break;
        }
        case 6: {
            temp = false;
            break;
        }
        }
    }
}







