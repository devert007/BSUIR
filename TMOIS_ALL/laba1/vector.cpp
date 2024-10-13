#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int proverka(vector<int> &array, int size) // ������� ������� ��������� �� ������� ���������� ���������
{
  for (int i = 0; i < size; i++) // ������ ������� ��������
  {
    for (int j = i + 1; j < size; j++) // ������ ��������� ������� ��������
    {
      if (array[i] == array[j]) // ���� �������� ����� ����� �����
      {
        std::cout << "put elements again" << '\n'; // ������� ������������ ������ ������ ��� ���
        return 0;
      }
      else // �����
      {
        i++; // ��������� � ���������� �������� ���������
        if (i >= size && j >= size)
          return 1;
      }
    }
  }
}

void intersection(vector<int> &a, vector<int> &b, int sizeA, int sizeB) // ��� ������� �������� �����������
{
  int c[100];                     // ������ ��������� �
  for (int i = 0; i < sizeA; i++) // ���� �� ������� �������� ��������� �
  {
    for (int j = 0; j < sizeB; j++) // ���� �� ������� �������� ��������� �
    {
      if (a[i] == b[j]) // ���� ��������� ���������� ��������� �������� � � �
      {
        for (int i = 0; i < 100; i++)
          c[i] = a[i];            // �� ���������� ��� �������� �� ��������� �
        std::cout << c[i] << " "; // ������� ��������� �
      }
    }
  }
}

void merge(vector<int> &a, vector<int> &b, int sizeA, int sizeB) // ��� ������� �����������
{
  vector<int> c; // ������ ��������� �
  for (int i = 0; i < sizeA; i++)
    c.push_back(a[i]);            // ��������� ��������� � ����� ���������� ��������� �
  for (int i = 0; i < sizeB; ++i) // ������ ������� ��������� �
  {
    for (int k = 0; k < sizeA; ++k) // � ������ ��������� ��������� �
    {
      if (b[i] == a[k]) // ���� �������� �������� � � � �����
      {
        break; // �� ���������� � �������������� ��������� �
      }
      else // �����
      {
        if (a[k] != a[a.size() - 1]) // ���� ������� ��������� � �������� �� �������������
          continue;                  // �� ���������� ����
        else                         // �����
          c.push_back(b[i]);         // ���������� ���� �������� ��������� � �� ��������� �
      }
    }
  }
  for (int i = 0; i < c.size(); i++)
    cout << c[i] << " ";
}

void differenceA_B(vector<int> &a, vector<int> &b, int sizeA, int sizeB) // ��� ������� �������� ��������
{
  int temp = 0;                   // ������ ��������� ����������
  vector<int> c;                  // ������ ���� ��������� �
  for (int i = 0; i < sizeA; i++) // ������ ������� ��������� �
  {
    for (int j = 0; j < sizeB; j++) // ������ ������� ��������� �
    {
      if (a[i] != b[j]) // ���� ������� ��������� � �� ����� �������� ��������� �
        temp++;         // ���������� ��������� ���������� 1
    }
    if (temp == sizeB)   // ���� ���� ��������� ���������� �������� �� ����� ��������� �
      c.push_back(a[i]); // ���������� ���� �������� ��������� � �� ��������� �
    temp = 0;            // �������� ���������� � ���� �� ����� ������
  }
  for (int i = 0; i < c.size(); i++)
    cout << c[i] << " "; // ������� ���� �������� ��������� �
}

void sym_difference(vector<int> &a, vector<int> &b, int sizeA, int sizeB) // ��� ������� �������� �������������� ��������
{
  int temp = 0;  // ������ ��������� ����������
  vector<int> c; // ������ ���� ��������� �

  for (int i = 0; i < sizeA; i++) // ������ ������� ��������� �
  {
    for (int j = 0; j < sizeB; j++) // ������ ������� ��������� �
    {
      if (a[i] != b[j]) // ���� �������� �� ����� ���� �����
        temp++;         // ���������� ��������� ���������� 1
    }
    if (temp == sizeB)   // ����� �� �������� �� ����� ��������� �
      c.push_back(a[i]); // ���������� ���� ��������� �������� ��������� � �� ��������� � �� ��������� �
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
    cout << c[i] << " ";
}

void product(vector<int> &a, vector<int> &b, int sizeA, int sizeB) // ��� ������� �������� ����������� ������������
{
  for (int i = 0; i < sizeA; i++) // ������ ������� ��������� �
  {
    for (int j = 0; j < sizeB; j++) // ������ ������� ��������� �
    {
      cout << "<" << a[i] << "," << b[j] << ">," // ���������� ���� ���������� ������������
           << " ";
    }
  }
}

void additionA(vector<int> &a, vector<int> &U, int sizeA) // ��� ������� ���������� ��������� �
{
  vector<int> A; // ������� ���� ���������� ��������� �
  int temp = 0;  // ������ ��������� ����������
  for (int i = 0; i < U.size(); i++)
  {
    for (int j = 0; j < sizeA; j++)
    {
      if (U[i] != a[j]) // ���� �������� ��������� � �� ����� ��������� �������������� ���������
        temp++;         // ���������� � ��������� ���������� 1
    }
    if (temp == sizeA)   // ����� �� �������� �� ���� ��������� ��������� �
      A.push_back(U[i]); // ���������� ��� ������� ������� �� ����� � ���� ����������
    temp = 0;            // �������� ��������� ����������
  }
  for (int i = 0; i < A.size(); i++)
    cout << A[i] << " "; // ������� �������� ����������
}

int main()
{
  setlocale(LC_ALL, "Russian"); // ����� ������� �����

  int sizeA, sizeB, input;
  int temp, input_function;

  vector<int> a;    // ��������� �
  vector<int> b;    // ��������� �
  vector<int> univ; // ������������� ���������
  cout << "���� ������������� ���������: ";
  for (int i = 1; i <= 125; i++) // ��������� ������������� ��������� ����������
  {
    univ.push_back(i);
  }
  cout << "[1,125]" << '\n';

  cout << "������� �������� ��������� A (0;10] " << '\n'; // ������ ������������ ������ �������� ��������� �
  do
  {
    cin >> sizeA;
  } while (sizeA > 10 || sizeA <= 0);

  cout << "������� �������� ��������� B (0;10] " << '\n'; // ������ ������������ ������ �������� ��������� �
  do
  {
    cin >> sizeB;
  } while (sizeB > 10 || sizeB < 0);

  cout << "�������� ����� ������� ���� �������� :(1.Perechislitelny method),(2.Vyskasyvaniem)" << '\n'; // ���� ����� ������������ ������ ���������
  cin >> input;

  switch (input)
  {
  case 1:                                           // ���� ������ ���������������� ������
    cout << "������� �������� ��������� A" << '\n'; // ������ ������������ ������ �������� ��������� �
    do
    {
      for (int i = 0; i < sizeA; i++)
      {
        cin >> temp;
        a.push_back(temp);
      }
    } while (!proverka(a, sizeA)); // ��������� �������� �� ������� ����������

    cout << "������� �������� ��������� B" << '\n'; // ������ ������������ ������ �������� ��������� �
    do
    {
      for (int j = 0; j < sizeB; j++)
      {
        cin >> temp;
        b.push_back(temp);
      }
    } while (!proverka(b, sizeB)); // ��������� �������� �� ������� ����������

    cout << "��� ��������� of �����������: " << '\t'; // ������� ��������� �����������
    intersection(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of �����������: " << '\t'; // ������� ��������� �����������
    merge(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of �������� A'\'B: " << '\t'; // ������� ��������� ��������
    differenceA_B(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of �������������� �������� :" << '\t'; // ������� ��������� �������������� ��������
    sym_difference(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of ����������� ������������: " << '\t'; // ������� ��������� ����������� ������������
    product(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of ���������� A: " << '\t'; // ������� ��������� ���������� ��������� �
    additionA(a, univ, sizeA);
    cout << '\n';
    break;

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  case 2: // ���� ������ ������ ������� ��������� ��������������
    // ��������� ��������� ��������������
    cout << "���� ��������� ��������:" << '\n';
    cout << "��������� of A:" << '\t';
    for (int i = 1; i <= sizeA; i++) // ������ ���� ��������� � �������������
    {
      int fun;
      fun = pow(i, 2) - 2 * i + 25;

      a.push_back(fun);

      cout << a[i - 1] << " ";
    }

    cout << '\n';
    cout << "��������� of B:" << '\t';
    for (int j = 1; j <= sizeB; j++) // ������ ���� ��������� � �������������
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

    // ���������� ��������
    cout << "��� ��������� of peresechenie: " << '\t'; // ������� ��������� �����������
    intersection(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of ob'edinenie: " << '\t'; // ������� ��������� �����������
    merge(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of rasnost A_B: " << '\t'; // ������� ��������� ��������
    differenceA_B(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of symetricheskaya rasnost :" << '\t'; // ������� ��������� �������������� ��������
    sym_difference(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of dekartovoe proisvedenie: " << '\t'; // ������� ��������� ����������� ������������
    product(a, b, sizeA, sizeB);
    cout << '\n';

    cout << "��� ��������� of dopolnenie A: " << '\t'; // ������� ��������� ���������� ��������� �
    additionA(a, univ, sizeA);
    cout << '\n';

    return 0;
    break;
  }
  return 0;
}
