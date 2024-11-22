#include <future>
#include <iostream>

int main() {
    std::promise<int> promise;
    promise.set_value(42);
    std::cout << promise.get_future().get() << std::endl;
}
