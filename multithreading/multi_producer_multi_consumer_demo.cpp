#include <iostream>
#include <queue>
#include <thread>

template <class T>
class Channel {
public:
    Channel() = default;
    ~Channel() = default;

    void put(T element) {
        std::unique_lock<std::mutex> lk(mu);
        q.push(std::move(element));
        lk.unlock();
        cv.notify_all();
    }

    auto get() -> T {
        std::unique_lock<std::mutex> lk(mu);
        cv.wait(lk, [&]() { return !q.empty(); });
        T element = std::move(q.front());
        q.pop();
        return element;
    }

private:
    std::mutex mu;
    std::condition_variable cv;
    std::queue<T> q;
};

int main() {
    Channel<int> ch;

    std::thread producer1([&ch]() {
        for (int i = 1; i <= 42; i++) {
            ch.put(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(42));
        }
    });
    std::thread producer2([&ch]() {
        for (int i = 1; i <= 42; i++) {
            ch.put(i + 42);
            std::this_thread::sleep_for(std::chrono::milliseconds(42));
        }
    });
    
    std::thread consumer1([&ch]() {
        for (int i = 1; i <= 42; i++) {
            int element = ch.get();
            std::cout << "consumer1: " << element << std::endl;
        }
    });
    std::thread consumer2([&ch]() {
        for (int i = 1; i <= 42; i++) {
            int element = ch.get();
            std::cout << "consumer2: " << element << std::endl;
        }
    });

    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();

    std::cout << "main: done" << std::endl;
}
