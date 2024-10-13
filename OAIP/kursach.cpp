
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;
struct Vedomost {
    //ФИО, номер группы, адрес, оценки.
    string name;
    int group;
    string adress;
    double average_grade;
};
void createFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        cout << "\t\t\t\t File created succesfully" <<'\n';
        file.close();
    }
    else
    {
        cout << "FAILED " << '\n';
    }
}
void addTofFile( const string&filename,  Vedomost& data) {
    ofstream file(filename,ios::app);
    
    if (file.is_open()) {
       
        file << data.name <<' ' << data.group <<' ' << data.adress << ' ' << data.average_grade << '\n';
        cout << "data added" << '\n';
         file.close();
    }
    else cout << "failed to add data" << '\n'; 
}
void looakAt( const string& filename) {
   
    std::ifstream file(filename,ios::binary);
   
    if (file.is_open()) {
        Vedomost data;
        cout << "\t\t\t\t\t||SURNAME||GROUP||CITY||AVERAGE GRADE \n";
        cout << "\t\t\t\t\t0000000000000000000000000000000000000000000\n";
        while ( file >> data.name>>data.group>>data.adress>>data.average_grade) {
            cout << "\t\t\t\t\t";
            cout << "||" << data.name << "||" <<
                data.group << "||" <<
                data.adress << "||" <<
                data.average_grade << '\n';
            cout << "\t\t\t\t\t0-------------------------------------------0\n";

        }
        file.close();
    }
}
int delete_from_file(const string& filename,string toDel) {
    ifstream file(filename);
    string line;
        string fileContents;
    if (file.is_open()) {
        Vedomost data;
       
        bool isHaveName = false;
        while (std::getline(file,line)) {
            if (line.find(toDel)!=std::string::npos) {
                isHaveName = true;
                continue;
            }
            fileContents += line + "\n";
        }
        file.close();
    }
   ofstream output(filename);
    if(output.is_open())
        output << fileContents;
        output.close();
        looakAt(filename);
        return 0;
}


///direct choice sort/////////////////////////////////////////////////
void dc_sort(vector<string>arr)
{
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] >= arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\t\t\t\tsurnames of sorted students:\n ";
    for (string el : arr) {
        cout <<"\t\t\t\t\t" << el << '\n';
    }
}
//// quick sort /////////////////////////////////////////////
void swap(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

int partition(vector<string>& arr, int low, int high) {
    string pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
///////////////////////////////////////////////////////////////


/////binary search////////////////////////////////////////////////
int binary_search(const string&filename, string& target) {
    ifstream file(filename);
    vector<string>names;
    if (file.is_open()) {
        Vedomost data;
        while (file >> data.name >> data.group >> data.adress >> data.average_grade) {
            names.push_back(data.name);
        }
    }
    int left = 0;
    int right = names.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (names[mid] == target) {
            return mid;
        }
        else if (names[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; // Имя не найдено

}
//////////////////////////////////////////////////////////////////




int main()
{

//  создание файла
    bool inputstart = false;
    cout << "\t\t\t\t\t\tchoose a way to get data: \n";
    cout << "\t\t\t----------------0-----------------  || ------------------1---------------\n";
    cout << "\t\t\tget data from already created file  || create your own file and push data\n "; cin >> inputstart;
    switch (inputstart) {
    case 0: {
        cout << " enter a way to file: \n";
        cout << '\n';
        string way_to_file;
        cin >> way_to_file;
        cout << "\t\t\t\tprocess of searching for a file in the system...\n";
        Sleep(2000);
        cout << "\t\t\t\t\t||SURNAME||GROUP||CITY||AVERAGE GRADE \n";
        cout << "\t\t\t\t\t0000000000000000000000000000000000000000000\n";
        ifstream file(way_to_file);

        //D:\LABY\2sem\laby\oaip\kursach\kursach\main.txt
        Vedomost data;
        while (file >> data.name >> data.group >> data.adress >> data.average_grade) {
            cout << "\t\t\t\t\t||" << data.name << "||" <<
                data.group << "||" <<
                data.adress << "||" <<
                data.average_grade << '\n';
            cout << "\t\t\t\t\t0----------------------------------------|0\n";
        }
        bool flag = true;
        while (flag) {
            
          
            cout << "\t\t\t\t____________________________________________________________" << '\n';
            cout << "\t\t\t\t|                    enter an operation:                   |" << '\n';
            
            cout << "\t\t\t\t|\t1.sort surnames\t\t\t\t\t   |\n" <<
                "\t\t\t\t|\t2.sum a students who have >=8.5 and live in Minsk  |\n" <<
                "\t\t\t\t| \t3.quick sort of students average grade\t\t   | \n" <<
                "\t\t\t\t| \t4.Binary search\t\t\t\t\t   | \n" <<
                "\t\t\t\t| \t5.Add a new student\t\t\t\t   | \n" <<
                "\t\t\t\t| \t6.Delete from file\t\t\t\t   | \n" <<
                "\t\t\t\t| \t7.EXIT\t\t\t\t\t\t   | \n";
            cout << "\t\t\t\t____________________________________________________________" << '\n';
            int input = 0;
            cin >> input;
            switch (input)
            {
            case 1: {
                ifstream file(way_to_file);
                if (file.is_open()) {
                    int count = 0;
                    Vedomost student;
                    vector<string>students;
                    while (file >> student.name >> student.group >> student.adress >> student.average_grade)
                    {

                        students.push_back(student.name);
                    }

                    dc_sort(students);
                    file.close();

                }
                break;
            }
            case 2: {
                int count = 0;
                vector<string>students;
                ifstream file(way_to_file);
                if (file.is_open()) {

                    Vedomost student;

                    while (file >> student.name >> student.group >> student.adress >> student.average_grade)
                    {
                        if ((student.adress == "Minsk" || student.adress == "minsk") && student.average_grade >= 8.5) {
                            count++;
                            students.push_back(student.name);
                        }
                    }
                }

                file.close();
                cout << "A number of students who have >=8.5 and live in Minsk: " << count << '\n';
                cout << "( ";
                for (string stud : students)cout << "----" << stud << "----" << " ";
                cout << " )" << '\n';
                break;
            }
            case 3: {
                vector<string> surname;
                ifstream file(way_to_file);
                if (file.is_open()) {
                    Vedomost student;
                    while (file >> student.name >> student.group >> student.adress >> student.average_grade) {
                        surname.push_back(student.name);

                    }
                    quickSort(surname, 0, surname.size() - 1);
                    cout << "\t\t\t\tSorted list of students:\n";
                    for (string stud : surname) cout << "\t\t\t\t\t" << stud << " "; cout << '\n';
                    file.close();
                }
                break;
            }
            case 4: {
                cout << "enter a name of your student: ";
                string input_name;
                cin >> input_name;

                cout << "index of student " << input_name << " is " << binary_search(way_to_file, input_name) << '\n';
                break;
            }
            case 5: {
                cout << "\t\t\t\t" << "NAME\t" << "GROUP\t" << "CITY\t" << "AVERAGE GRADE\n";
                Vedomost data;
                cout << "\t\t\t\t";
                cin >> data.name >> data.group >> data.adress >> data.average_grade;
                addTofFile(way_to_file, data);
                looakAt(way_to_file);
                break;
            }
            case 6: {
                cout << "\t\t\t\tEnter a surname of student that you want to delete" << '\n';
                cout << "\t\t\t\t";
                string todel;
                cin >> todel;
                delete_from_file(way_to_file, todel);
                input = 10;
                break;
            }
            case 7: {
                cout << "\t\t\t\tthe system is being logged out...\n";
                Sleep(2000);
                cout << "\t\t\t\t\tBYE!";
                flag = false;
            }
            }
            continue;
        }

        break;

    }
    case 1: 
    {
        cout << "\t\t\t\tEnter your filename : ";
        string filename = "some name";
        cin >> filename;
        cout << '\n' << "\t\t\t\t\tloading..." << '\n';
        Sleep(3000);
        createFile(filename);
        // добавление в файл
        bool flag = true;
        cout << "\t\t\t\tEnter an amount of your students: ";
        int n;
        cin >> n;
        cout << "\t\t\t\tEnter data of your " << n << " students\n";
        cout << "--------------------------------------------------------------------------------\n";
        cout <<"\t" << "NAME\t" << "GROUP\t" << "CITY\t" << "AVERAGE GRADE\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " student: ";
            Vedomost data;
            cin >> data.name >> data.group >> data.adress >> data.average_grade;
            addTofFile(filename, data);
        }
        cout << "\t\t\t\tYOUR DATA: \n";
        looakAt(filename);
        while (flag) {
            cout << "\t\t\t\t____________________________________________________________" << '\n';
            cout << "\t\t\t\t|                    enter an operation:                   |" << '\n';

            cout << "\t\t\t\t|\t1.sort surnames\t\t\t\t\t   |\n" <<
                "\t\t\t\t|\t2.sum a students who have >=8.5 and live in Minsk  |\n" <<
                "\t\t\t\t| \t3.quick sort of students average grade\t\t   | \n" <<
                "\t\t\t\t| \t4.Binary search\t\t\t\t\t   | \n" <<
                "\t\t\t\t| \t5.Add a new student\t\t\t\t   | \n" <<
                "\t\t\t\t| \t6.EXIT\t\t\t\t\t\t   | \n";
            cout << "\t\t\t\t____________________________________________________________" << '\n';
            int input = 0;
            cin >> input;
            switch (input)
            {
            case 1: {
                ifstream file(filename);
                if (file.is_open()) {
                    int count = 0;
                    Vedomost student;
                    vector<string>students;
                    while (file >> student.name >> student.group >> student.adress >> student.average_grade)
                    {

                        students.push_back(student.name);
                    }

                    dc_sort(students);
                    file.close();

                }
                break;
            }
            case 2: {
                int count = 0;
                vector<string>students;
                ifstream file(filename);
                if (file.is_open()) {

                    Vedomost student;

                    while (file >> student.name >> student.group >> student.adress >> student.average_grade)
                    {
                        if ((student.adress == "Minsk"||student.adress=="minsk") && student.average_grade >= 8.5) {
                            count++;
                            students.push_back(student.name);
                        }
                    }
                }

                file.close();
                cout << "\t\t\tA number of students who have >=8.5 and live in Minsk: " << count << '\n';
                cout <<"\t\t\t\t\t" << "( "; for (string stud : students)cout << stud << " "; cout << " )" << '\n';
                break;
            }
            case 3: {
                vector<string> surname;
                ifstream file(filename);
                if (file.is_open()) {
                    Vedomost student;
                    while (file >> student.name >> student.group >> student.adress >> student.average_grade) {
                        surname.push_back(student.name);

                    }
                    quickSort(surname, 0, surname.size() - 1);
                    cout << "\t\t\t\tSorted list of students:\n";
                    for (string stud : surname) cout << "\t\t\t\t\t" << stud << " "; cout << '\n';
                    
                    file.close();
                }
                break;
            }
            case 4: {
                cout << "\t\t\t\tenter a name of your student: ";
                string input_name;
                cin >> input_name;

                cout << "\t\t\t\tindex of student " << input_name << " is " << binary_search(filename, input_name) << '\n';
                break;
            }

            case 5: {
                cout << "\t\t\t\t" << "NAME\t" << "GROUP\t" << "CITY\t" << "AVERAGE GRADE\n";
                Vedomost data;
                cout << "\t\t\t\t";
                cin >> data.name >> data.group >> data.adress >> data.average_grade;
                addTofFile(filename, data);
                looakAt(filename);
                break;
            }
            case 6: {
                cout << "\t\t\t\tEnter all data(surname, group and other) of student that you want to delete" << '\n';
                cout << "\t\t\t\t";
                string todel;
                cin >> todel;
                delete_from_file(filename, todel);
                

            }
            case 7: { cout << "\t\t\t\tthe system is being logged out...\n";
                Sleep(2000);
                cout << "\t\t\t\t\tBYE!";
                flag = false;
                break;
            }
            }
            continue;
        }
        break;

    }
    }
   
}

