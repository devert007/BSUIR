#include <iostream>
using namespace std;

int main()
{
     int size;
    cout << "vvedite kolichestvo elementov : ";
    cin >> size;
    int a[100], b[100];
    cout << "first massive:\n ";
    for (int i = 0; i < size; i++)
        cin >> a[i];
    cout << "\nsecond massive:\n ";
    for (int i = 0; i < size; i++)
        cin >> b[i];
    int min = a[0];
    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] < min)
                min = a[i];
        }
    }
    cout << "Minimum = " << min;
}

