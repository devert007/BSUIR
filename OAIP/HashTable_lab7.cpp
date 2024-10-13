#include <iostream>

using namespace std;
#include <stack>
#include <fstream>
#include <vector>

class HT
{
private:
    class sel
    {
    public:
        int infkey;
        sel* key;
        stack<string> data;
    };
    sel** table;
    int index;
    int size;

public:
    HT(int size)
    {
        table = new sel * [size];
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL;
        }
        this->size = size;
    }

    ~HT()
    {
        ofstream output("output.txt");
        output << "-----HASH TABLE-----" << '\n';
        output << "-index-" << '\t' << "key" << '\t' << "data" << '\n';
        for (int i = 0; i < size; i++)
        {
            sel* current = table[i];

            while (current != nullptr)
            {
                while (!current->data.empty())
                {
                    output << current->key << '\t' << current->infkey << '\t' << "||" << '\t' << current->data.top() << '\n';
                    current->data.pop();
                }

                current = current->key;
            }
        }

        output.close();
    }
    void insert(int key, string data);
    void del(int key);
};

/////////////////////////////////////////////////////// функция вставки элемента по ключу и данным

void HT::insert(int key, string data)
{
    sel* current = new sel;
    index = key % size;
    cout << index;
    current->data.push(data);
    current->key = table[index];
    current->infkey = key;
    table[index] = current;
}
///////////////////////////////////////////////////////////////////////////////////////////Функция удаления по ключу
void HT::del(int key)
{

    index = key % size;
    sel* current = table[index];
    sel* current_next;
    if (current == NULL)
        return;

    if (current->infkey == key)
    {
        table[index] = current->key;
        delete current;
    }
    else
    {
        current_next = current->key;
        while (current_next != NULL)
        {
            if (current_next->infkey == key)
            {
                current->key = current_next->key;
                delete current_next;
                return;
            }
            current = current_next;
            current_next = current_next->key;
        }
    }
}

int main()
{
    // чтение из файла данных
    ifstream input("input.txt");
    vector<int> keys;
    int size;
    input >> size;
    vector<string> a(size);
    keys.resize(size);

    for (int i = 0; i < size; i++)
    {
        string temp;
        int key;
        input >> temp;
        a[i] = temp;
        input >> key;
        keys[i] = key;
    }

    // ХЭЩ table
    HT table(size); // создаем
    for (int i = 0; i < size; i++)
    {
        table.insert(keys[i], a[i]); // push дата
    }

    return 0;
}