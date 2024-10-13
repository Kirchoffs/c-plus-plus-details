#include <iostream>
#include <thread>
#include <memory>
#include <vector>

class SharedResource {
public:
    int value = 42;
};

std::shared_ptr<SharedResource> global_resource;

void writer_thread() {
    for (int i = 0; i < 1000; ++i) {
        auto new_resource = std::make_shared<SharedResource>();
        new_resource->value = i;
        global_resource = new_resource;
        std::cout << global_resource.get() << std::endl;
    }
}

void reader_thread() {
    for (int i = 0; i < 1000; ++i) {
        auto local_copy = global_resource;
        if (local_copy) {
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }
    }
}

int main() {
    global_resource = std::make_shared<SharedResource>();
    std::cout << global_resource->value << std::endl;

    std::vector<std::thread> threads;
    threads.emplace_back(writer_thread);
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(reader_thread);
    }

    for (auto& t : threads) {
        t.join();
    }
}
