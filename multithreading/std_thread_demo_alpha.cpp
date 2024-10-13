#include <iostream>
#include <thread>
#include <vector>

void threadFunction(int threadID) {
    std::cout << "Hello from thread " << threadID << std::endl;
}

int main() {
    const int numThreads = 5;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(threadFunction, i));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Hello from main!" << std::endl;
}
