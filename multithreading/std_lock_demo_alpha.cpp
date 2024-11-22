#include <iostream>
#include <thread>
#include <mutex>

std::mutex alpha_mutex;
std::mutex beta_mutex;

void first_thread() {
    std::lock(alpha_mutex, beta_mutex);
    std::lock_guard<std::mutex> alpha_lock(alpha_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> beta_lock(beta_mutex, std::adopt_lock);

    std::cout << "Thread 1: Both mutexes locked!" << std::endl;
}

void second_thread() {
    std::lock(alpha_mutex, beta_mutex);
    std::lock_guard<std::mutex> alpha_lock(alpha_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> beta_lock(beta_mutex, std::adopt_lock);

    std::cout << "Thread 2: Both mutexes locked!" << std::endl;
}

int main() {
    std::thread t1(first_thread);
    std::thread t2(second_thread);

    t1.join();
    t2.join();
}
