#include <iostream>
#include <thread>

void addAndPrintValue(int& value) {
    ++value;
    std::cout << "Value inside function: " << value << std::endl;
}

void std_ref_bind_demo() {
    int value = 5;
    std::cout << "Value before function: " << value << std::endl;
    auto func = std::bind(addAndPrintValue, std::ref(value));
    func();
    std::cout << "Value after function: " << value << std::endl;
}

void increase(int& value) {
    ++value;
}

void std_ref_thread_demo() {
    int value = 5;
    std::thread t(increase, std::ref(value));
    std::cout << "Value before thread: " << value << std::endl;
    t.join();
    std::cout << "Value after thread: " << value << std::endl;
}

int main() {
    std_ref_bind_demo();
    std_ref_thread_demo();
}
