#include <shared_mutex>
#include <iostream>
#include <thread>
#include <vector>

class ReaderWriterLock {
public:
    void write_lock() {
        mutex.lock();
    }

    void write_unlock() {
        mutex.unlock();
    }

    void read_lock() {
        mutex.lock_shared();
    }

    void read_unlock() {
        mutex.unlock_shared();
    }

private:
    std::shared_mutex mutex;
};

void writer(ReaderWriterLock& lock, int& shared_data, int id) {
    lock.write_lock();
    std::cout << "Writer " << id << " is modifying data." << std::endl;
    shared_data += 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(256));
    std::cout << "Writer " << id << " finished modifying data: " << shared_data << std::endl;
    lock.write_unlock();
}

void reader(ReaderWriterLock& lock, int& shared_data, int id) {
    lock.read_lock();
    std::cout << "Reader " << id << " is reading data: " << shared_data << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(128));
    lock.read_unlock();
}

int main() {
    ReaderWriterLock lock;
    int shared_data = 0;

    std::vector<std::thread> threads;
    for (int i = 0; i < 25; i++) {
        threads.push_back(std::thread(reader, std::ref(lock), std::ref(shared_data), i));
        if (i % 2 == 0) {
            threads.push_back(std::thread(writer, std::ref(lock), std::ref(shared_data), i));
        }
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Final shared data: " << shared_data << std::endl;
}
