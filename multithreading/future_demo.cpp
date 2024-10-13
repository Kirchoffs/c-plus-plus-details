#include <iostream>
#include <future>
#include <chrono>
#include <thread>

// Function to be executed asynchronously
int calculateSum(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

int main() {
    // Start asynchronous task
    std::future<int> result = std::async(std::launch::async, calculateSum, 15, 27);
    
    std::cout << "Calculating sum in the background...\n";

    int sum = result.get();
    std::cout << "The sum is: " << sum << std::endl;

    return 0;
}
