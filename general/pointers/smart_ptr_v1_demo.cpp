#include <iostream>

template <typename T>
class smart_ptr {
public:
    explicit smart_ptr(T* ptr = nullptr): ptr(ptr) {}
    smart_ptr(const smart_ptr&) = delete;
    smart_ptr& operator=(const smart_ptr&) = delete;

    ~smart_ptr() {
        delete ptr;
    }

    T* get() const { return ptr; }
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    operator bool() const { return ptr; }

private:
    T* ptr;
};

int main() {
    smart_ptr<int> ptr(new int(42));
    std::cout << *ptr << std::endl;
}
