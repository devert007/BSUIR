#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex>
#define N 5
#define HUNGRY 1
#define EATING 2
#define THINKING 0
std::vector<int> philosophers_state(N, THINKING);
;
typedef int semaphore;
semaphore mutex = 1;

semaphore S[N] = {1, 1, 1, 1, 1};
void test(int i)
{
  if (philosophers_state[(i - 1 % N)] != EATING && philosophers_state[(i + 1 % N)] != EATING)
  {
    philosophers_state[i] = EATING;
    std::cout << "Philosopher " << i + 1 << " is eating." << std::endl;
    S[i]++;
  }
}
void take_fork(int i)
{
  mutex--;
  philosophers_state[i] = HUNGRY;
  test(i);
  mutex++;
  S[i]--;
}

void put_fork(int i)
{
  mutex--;
  philosophers_state[i] = THINKING;
  test((i - 1) % N);
  test((i + 1) % N);
  mutex++;
}

void philosopher(int i)
{
  while (true)
  {
    take_fork(i);
    put_fork(i);
  }
}

int main()
{
  std::vector<std::thread> threads;
  for (int i = 0; i < N; ++i)
  {
    threads.emplace_back(philosopher, i);
  }
  for (auto &t : threads)
  {
    t.join();
  }

  return 0;
}
