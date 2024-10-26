#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>
#include <mutex>
#include <condition_variable>
#define N 5
#define LEFT (i - 1) % N
#define RIGHT (i + 1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
using namespace std;

int state[N];
int pidd[N];
int ate_hm_times[N];

mutex mtx;
condition_variable cv[N];

void eat(int i)
{
  cout << "My pid is: " << getpid() << " my number is " << i << " and I'm eating now\n";
  ate_hm_times[i]++;
}

void think(int i)
{
  cout << "My pid is: " << getpid() << " my number is " << i << " and I'm thinking now\n";
}

void test(int i)
{
  if ((state[i] == HUNGRY) &&
      (state[LEFT] != EATING) &&
      (state[RIGHT] != EATING))
  {
    state[i] = EATING;
    cv[i].notify_one();
  }
}

void take_forks(int i)
{
  unique_lock<mutex> lock(mtx);
  state[i] = HUNGRY;
  test(i);
  cv[i].wait(lock, [i]
             { return state[i] != HUNGRY; });
}

void put_forks(int i)
{
  unique_lock<mutex> lock(mtx);
  state[i] = THINKING;
  test(LEFT);
  test(RIGHT);
}

void philosopher(int i)
{

  think(i);
  take_forks(i);
  eat(i);
  put_forks(i);
}

int main()
{
  for (int i = 0; i < N; i++)
  {
    state[i] = THINKING;
  }

  for (int i = 0; i < N; i++)
  {
    ate_hm_times[i] = 0;
  }
  int round = 0;
  for (int i = 0; i < N; i++)
  {
    if (fork() == 0)
    {
      //pidd[i] = getpid();
      cout << "I'm  " << i << " philosopher, my pid is: " << getpid() << "\n";
      philosopher(i);
      if (i == N-1   && round < 2)
      {
        cout<<"ROUND:"<<round<<'\n';
        round++;
        i = 0;
        continue;
      }
      exit(0);
    }
  }

  for (int i = 0; i < N; i++)
  {
    wait(NULL);
  }

  return 0;
}