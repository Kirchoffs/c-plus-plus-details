#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int main() {
    int data = 0;
    const int numThreads = 5;

    std::vector<std::thread> threads;
    std::mutex dataMutex;

    for (int i = 0; i < numThreads; ++i) {
        int tid = i;
        threads.push_back(std::thread([&data, tid, &dataMutex] {
            std::lock_guard<std::mutex> lock(dataMutex);
            std::cout << "Thread " << tid << " sees data = " << data << std::endl;
            data += tid;
        }));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Main sees data = " << data << std::endl;
}
