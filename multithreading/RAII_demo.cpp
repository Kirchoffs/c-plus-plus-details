#include <iostream>
#include <thread>

class ThreadRAII {
public:
    ThreadRAII(std::thread t) : t(std::move(t)) {
        if (!this->t.joinable()) {
            throw std::logic_error("No thread to manage!");
        }
    }

    ~ThreadRAII() {
        if (t.joinable()) {
            t.join();
            std::cout << "Thread joined in RAII destructor\n";
        }
    }

    ThreadRAII(const ThreadRAII&) = delete;
    ThreadRAII& operator=(const ThreadRAII&) = delete;

    ThreadRAII(ThreadRAII&&) = default;
    ThreadRAII& operator=(ThreadRAII&&) = default;

private:
    std::thread t;
};

void thread_function() {
    std::cout << "Thread is running...\n";
}

int main() {
    std::thread t(thread_function);
    ThreadRAII threadManager(std::move(t));
    std::cout << "Main thread is doing some work...\n";
}
