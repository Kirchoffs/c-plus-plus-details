# Notes
## Bits of Knowledge
### std::thread & std::bind
Both the operation of the std::thread constructor and the operation of std::bind are defined in terms of the same mechanism. The std::thread constructor takes a function object and arguments and creates a new thread that runs that function object with the given arguments. std::bind takes a function object and arguments and returns a new function object that, when called, runs the original function object with the given arguments. The std::thread constructor is essentially a wrapper around std::bind that creates a new thread to run the function object that std::bind returns.

## Examples
### Multi-Producer Multi-Consumer
``` C++
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
```

The corresponding Java version is:
``` Java
package org.syh.demo.java.multithreading.others;

import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Channel<T> {
    private final Queue<T> queue = new LinkedList<>();
    private final Lock lock = new ReentrantLock();
    private final Condition notEmpty = lock.newCondition();

    // The methods on a Condition object, such as await(), signal(), and signalAll(), must be called while holding the associated lock.
    public void put(T element) {
        lock.lock();
        try {
            queue.add(element);
            notEmpty.signalAll();
        } finally {
            lock.unlock();
        }
    }

    public T get() throws InterruptedException {
        lock.lock();
        try {
            while (queue.isEmpty()) {
                notEmpty.await();
            }
            return queue.poll();
        } finally {
            lock.unlock();
        }
    }
}

public class MultiProducerMultiConsumerDemo {
    public static void main(String[] args) throws InterruptedException {
        Channel<Integer> channel = new Channel<>();

        Thread producer1 = new Thread(() -> {
            try {
                for (int i = 1; i <= 42; i++) {
                    channel.put(i);
                    System.out.println("producer-1: " + i);
                }
            } catch (Exception e) {
                Thread.currentThread().interrupt();
            }
        });

        Thread producer2 = new Thread(() -> {
            try {
                for (int i = 1; i <= 42; i++) {
                    channel.put(i + 42);
                    System.out.println("producer-2: " + i);
                }
            } catch (Exception e) {
                Thread.currentThread().interrupt();
            }
        });

        Thread consumer1 = new Thread(() -> {
            try {
                for (int i = 1; i <= 42; i++) {
                    Integer element = channel.get();
                    System.out.println("consumer-1: " + element);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        Thread consumer2 = new Thread(() -> {
            try {
                for (int i = 1; i <= 42; i++) {
                    Integer element = channel.get();
                    System.out.println("consumer-2: " + element);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        producer1.start();
        producer2.start();
        consumer1.start();
        consumer2.start();

        producer1.join();
        producer2.join();
        consumer1.join();
        consumer2.join();

        // consumer1.interrupt();
        // consumer2.interrupt();

        System.out.println("main: done");
    }
}
```
