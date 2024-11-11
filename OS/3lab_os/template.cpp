#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#define N 5
#define HUNGRY 2
#define EATING 3
#define THINKING 0

std::vector<int> philosophers_state(N, THINKING);
std::mutex mtx;
std::condition_variable cv;

void test(int philosopher) {
    if (philosophers_state[philosopher] == HUNGRY &&
        philosophers_state[(philosopher + 4) % N] != EATING &&
        philosophers_state[(philosopher + 1) % N] != EATING) {
        philosophers_state[philosopher] = EATING;
        cv.notify_one();
    }
}

void take_fork(int philosopher) {
    std::unique_lock<std::mutex> lock(mtx);
    philosophers_state[philosopher] = HUNGRY;
    test(philosopher);
    cv.wait(lock, [philosopher] { return philosophers_state[philosopher] != HUNGRY; });
}

void put_fork(int philosopher) {
    std::unique_lock<std::mutex> lock(mtx);
    philosophers_state[philosopher] = THINKING;
    test((philosopher + 4) % N);
    test((philosopher + 1) % N);
}

void philosopher(int philosopher) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
        take_fork(philosopher);
        std::cout << "Philosopher " << philosopher + 1 << " is eating.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
        put_fork(philosopher);
        std::cout << "Philosopher " << philosopher + 1 << " is thinking.\n";
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < N; ++i) {
        threads.emplace_back(philosopher, i);
    }
    for (auto &t : threads) {
        t.join();
    }
    return 0;
}