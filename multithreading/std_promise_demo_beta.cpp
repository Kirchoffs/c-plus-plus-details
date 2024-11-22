#include <iostream>
#include <thread>
#include <future>

void computeValue(std::promise<int> promise) {
    try {
        std::cout << "compute-thread: Computing value..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        
        int result = 42;
        promise.set_value(result);
    } catch (...) {
        promise.set_exception(std::current_exception());
    }
}

int main() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();
    
    std::thread producerThread(computeValue, std::move(promise));
    
    std::cout << "main-thread: Waiting for result..." << std::endl;
    try {
        int result = future.get();
        std::cout << "main-thread: Result received: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "main-thread: Exception: " << e.what() << std::endl;
    }
    
    producerThread.join();
}
