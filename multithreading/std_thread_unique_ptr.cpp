#include <iostream>
#include <memory>
#include <thread>

class big_object {
public:
    big_object() { std::cout << "big_object constructed" << std::endl; }
    ~big_object() { std::cout << "big_object destructed" << std::endl; }
    
    void prepare_data(int data) {
        this->data = data;
        std::cout << "Data prepared: " << data << std::endl;
    }

    void process() {
        std::cout << "Processing data: " << data << std::endl;
    }

private:
    int data;
};

void process_big_object(std::unique_ptr<big_object> obj) {
    if (obj) {
        obj->process();
    }
}

int main() {
    std::unique_ptr<big_object> p(new big_object);
    p->prepare_data(42);

    std::thread t(process_big_object, std::move(p));
    t.join();

    if (!p) {
        std::cout << "p is now empty after move\n";
    }
}
