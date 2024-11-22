#include <iostream>
#include <thread>
#include <mutex>

std::mutex alpha_mutex;
std::mutex beta_mutex;

void first_thread() {
    alpha_mutex.lock();
    beta_mutex.lock();

    std::cout << "Thread 1: Both mutexes locked!" << std::endl;

    alpha_mutex.unlock();
    beta_mutex.unlock();
}

void second_thread() {
    alpha_mutex.lock();
    beta_mutex.lock();

    std::cout << "Thread 2: Both mutexes locked!" << std::endl;

    alpha_mutex.unlock();
    beta_mutex.unlock();
}

int main() {
    std::thread t1(first_thread);
    std::thread t2(second_thread);

    t1.join();
    t2.join();
}
