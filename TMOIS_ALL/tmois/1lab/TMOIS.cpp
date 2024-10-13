#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>

using namespace std;

void intersection(vector<tuple<int,int>>& a, vector<tuple<int,int>>& b, int sizeA, int sizeB) // ��� ������� �������� �����������
{
    vector<tuple<int, int>> c;                     // ������ ������ �
    for (int i = 0; i < sizeA; i++) // ���� �� ������� �������� ������� �
    {
        for (int j = 0; j < sizeB; j++) // ���� �� ������� �������� ������� �
        {
            if (a[i] == b[j]) // ���� ��������� ���������� ��������� �������� � � �
            {
                c.push_back(a[i]);            // �� ���������� ��� �������� � ������ �
                int temp1, temp2;
                tie(temp1, temp2) = a[i];
                cout << "<" <<temp1 <<", " << temp2<< "> "; // ������� ������ �
            }
        }
    }
}

void merge(vector<tuple<int,int>>& a, vector<tuple<int,int>>& b, int sizeA, int sizeB) // ��� ������� �����������
{
    vector<tuple<int,int>> c; // ������ ������ �
    for (int i = 0; i < sizeA; i++)
        c.push_back(a[i]);            // ��������� ������ � ����� ���������� ������� �
    for (int i = 0; i < sizeB; ++i) // ������ ������� ������� �
    {
        for (int k = 0; k < sizeA; ++k) // � ������ ��������� ������� �
        {
            if (b[i] == a[k]) // ���� �������� �������� � � � �����
            {
                break; // �� ���������� � �������������� ������� �
            }
            else // �����
            {
                if (a[k] != a[a.size() - 1]) // ���� ������� ������� � �������� �� �������������
                    continue;                  // �� ���������� ����
                else                         // �����
                    c.push_back(b[i]);         // ���������� ���� �������� ������� � � ������ �
            }
        }
    }
    for (int i = 0; i < c.size(); i++) 
    {
        int temp1, temp2;
        tie(temp1, temp2) = c[i];
        cout << "<" << temp1 << ", " << temp2 << "> "; // ������� ������ �
    }
}

void differenceA_B(vector<tuple<int, int>>& a, vector<tuple<int, int>>& b, int sizeA, int sizeB) // ��� ������� �������� ��������
{
    int temp = 0;                   // ������ ��������� ����������
    vector<tuple<int,int>> c;                  // ������ ��� ������ �
    for (int i = 0; i < sizeA; i++) // ������ ������� ������� �
    {
        for (int j = 0; j < sizeB; j++) // ������ ������� ������� �
        {
            if (a[i] != b[j]) // ���� ������� ������� � �� ����� �������� ������� �
                temp++;         // ���������� ��������� ���������� 1
        }
        if (temp == sizeB)   // ���� ���� ��������� ���������� �������� �� ����� ������� �
            c.push_back(a[i]); // ���������� ���� �������� ������� � � ������ �
        temp = 0;            // �������� ���������� � ���� �� ����� ������
    }
    for (int i = 0; i < c.size(); i++)// ������� ���� �������� ������� �
    {
        int temp1, temp2;
        tie(temp1, temp2) = c[i];
        cout << "<" << temp1 << ", " << temp2 << "> ";
    }

}

void sym_difference(vector<tuple<int, int>>& a, vector<tuple<int, int>>& b, int sizeA, int sizeB) // ��� ������� �������� �������������� ��������
{
    int temp = 0;  // ������ ��������� ����������
    vector<tuple<int,int>> c; // ������ ��� ������ �

    for (int i = 0; i < sizeA; i++) // ������ ������� ������� �
    {
        for (int j = 0; j < sizeB; j++) // ������ ������� ������� �
        {
            if (a[i] != b[j]) // ���� �������� �� ����� ���� �����
                temp++;         // ���������� ��������� ���������� 1
        }
        if (temp == sizeB)   // ����� �� �������� �� ����� ������� �
            c.push_back(a[i]); // ���������� ���� ��������� �������� ������� � �� ������� � �� ������ �
        temp = 0;            // �������� ��������� ����������
    }
    // ������ ��������� ��������� �\�
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
        cout << "<" << temp1 << ", " << temp2 << "> "; // ������� ������ �
    }
}

void additionA(vector<tuple<int,int>>& a, vector<tuple<int,int>>& U, int sizeA) // ��� ������� ���������� ������� �
{
    vector<tuple<int,int>> A; // ������� ���� ���������� ������� �
    int temp = 0;  // ������ ��������� ����������
    for (int i = 0; i < U.size(); i++)
    {
        for (int j = 0; j < sizeA; j++)
        {
            if (U[i] != a[j]) // ���� �������� ������� � �� ����� ��������� �������������� �������
                temp++;         // ���������� � ��������� ���������� 1
        }
        if (temp == sizeA)   // ����� �� �������� �� ���� ��������� ������� �
            A.push_back(U[i]); // ���������� ��� ������� ������� �� ����� � ���� ����������
        temp = 0;            // �������� ��������� ����������
    }
    for (int i = 0; i < A.size(); i++)
    {
        int temp1, temp2;
        tie(temp1, temp2) = A[i];
        cout << "<" << temp1 << ", " << temp2 << "> "; // ������� ������ A
    }
}

void inversionA(vector<tuple<int, int>>& a, int sizeA) // ��� ������� ��� �������� ������� �
{
    vector<tuple<int, int>> C; // ������� ��� ������ � ��������� ������� �
    for (int i = 0; i < sizeA; i++)
    {
        int temp1, temp2; // ������� �������� �������
        tie(temp1, temp2) = a[i]; // ���������� �� ������� � �������� �������
        C.push_back(make_tuple(temp2, temp1)); // ���������� ��� ������ � ��������� ���������
    }
    for (int i = 0; i < C.size(); i++)
    {
        int temp1, temp2;
        tie(temp1, temp2) = C[i];
        cout << "<" << temp1 << ", " << temp2 << "> "; // ������� ������ �
    }
}

void composition(vector<tuple<int, int>>& a, vector<tuple<int, int>>& b, int sizeA, int sizeB) // ��� ������� ��� ���������� ���� ��������
{
    vector<tuple<int, int>> c; // ������� ��� ������ �
    for (int i = 0; i < sizeA; i++) // ������ ������� ������� �
    {
        for (int j = 0; j < sizeB; j++) // ������ ������� ������� �
        {
            int tempA1, tempA2; // ������� �������� ������� ������� �
            tie(tempA1, tempA2) = a[i]; // ���������� �� ������� � �������� �������
            int tempB1, tempB2; // ������� �������� ������� ������� �
            tie(tempB1, tempB2) = b[j]; // ���������� �� ������� � �������� �������
            if (tempA2 != tempB1) // e��� �������� �� 2 ��� �������, ������� �� ������� �, �� ����� �������� �� 1 ��� �������, ������� �� ������� �
                continue; // ���������� ����
            if (tempA2 == tempB1) // e��� �������� �� 2 ��� �������, ������� �� ������� �, ����� �������� �� 1 ��� �������, ������� �� ������� �
                c.push_back(make_tuple(tempA1, tempB2)); // �������� �������� �� 1 ��� �� ������� �, �������� �� 2 ��� �� ������� �
        }
    }
    for (int i = 0; i < c.size(); i++)
    {
        int temp1, temp2;
        tie(temp1, temp2) = c[i];
        cout << "<" << temp1 << ", " << temp2 << "> "; // ������� ������ �
    }
}
int main()
{
    setlocale(LC_ALL, "Russian"); // ����� ������� �����

    int sizeA, sizeB, input;
    int temp1, temp2, input_function;

    vector<tuple<int, int>> a;    // ������ �
    vector<tuple<int, int>> b;    // ������ �
    vector<tuple<int, int>> univ; // ������������� ������
    vector<int> p1, p2;
    cout << "���� ������������� ���������: ";
    for (int i = 1; i <= 125; i++) // ��������� ������������� ������ ����������
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

    cout << "������� �������� ������� A (0;10] " << '\n'; // ������ ������������ ������ �������� ������� �
    do
    {
        cin >> sizeA;
    } while (sizeA > 10 || sizeA <= 0);

    cout << "������� �������� ������� B (0;10] " << '\n'; // ������ ������������ ������ �������� ������� �
    do
    {
        cin >> sizeB;
    } while (sizeB > 10 || sizeB < 0);
    cout << "������� �������� ������� A" << '\n'; // ������ ������������ ������ �������� ������� �
    for (int i = 0; i < sizeA; i++)
    {
        cin >> temp1 >> temp2;
        a.push_back(make_tuple(temp1, temp2));
    }

    cout << "������� �������� ������� B" << '\n'; // ������ ������������ ������ �������� ������� �
    for (int j = 0; j < sizeB; j++)
    {
        cin >> temp1 >> temp2;
        b.push_back(make_tuple(temp1, temp2));
    }
    cout << "��� ��������� of �����������: " << '\t'; // ������� ��������� �����������
    intersection(a, b, sizeA, sizeB);
    cout << '\n';
    cout << "��� ��������� of �����������: " << '\t'; // ������� ��������� �����������
    merge(a, b, sizeA, sizeB);
    cout << '\n';
    cout << "��� ��������� of �������� A\\B: " << '\t'; // ������� ��������� ��������
    differenceA_B(a, b, sizeA, sizeB);
    cout << '\n';
    cout << "��� ��������� of �������������� ��������: " << '\t'; // ������� ��������� �������������� ��������
    sym_difference(a, b, sizeA, sizeB);
    cout << '\n';
    cout << "��� ��������� of ���������� A: " << '\t'; // ������� ��������� ���������� ������� �
    additionA(a, univ, sizeA);
    cout << '\n';
    cout << "��� ��������� of �������� �: " << '\t'; // ������� ��������� �������� ������� �
    inversionA(a, sizeA);
    cout << '\n';
    cout << "��� ��������� of ���������� � � �: " << '\t'; // ������� ��������� ���������� �������� � � �
    composition(a, b, sizeA, sizeB);
    cout << '\n';
}