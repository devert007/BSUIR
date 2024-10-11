#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
using namespace std;

void print_PI(const string &message)
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    cout << message << " (pid: " << pid << ", pid родителя: " << ppid << ")" << endl;
}

int main()
{
    vector<int> arr = {0,0,0,1,1,4,5};

    pid_t pids[arr.size()];
    print_PI("Основной процесс запущен");

    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (i == 0 || pids[arr[i]] == getpid())
        {
            pid_t pid = fork();
            if (pid == 0)
            {
                print_PI("Дочерний процесс " + to_string(i+1) + " запущен");
                if (i == 2)
                {
                    cout << "Дочерний процесс 3 выполнит команду pwd позже." << endl;
                }

                pids[i] = getpid();
            }
            else if (pid > 0)
            {
                pids[i] = pid;
                wait(NULL);
            }
        }
    }
    if (pids[2] == getpid())
    {
        cout << "Процесс 3 выполняет команду pwd:"<< getpid()<< endl;
        execl("/bin/pwd", "pwd", (char *)0);
        _exit(0);
    }
    return 0;
}