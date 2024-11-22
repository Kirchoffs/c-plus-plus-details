#include <iostream>

template <typename T>
class smart_ptr {
public:
    explicit smart_ptr(T* ptr = nullptr): ptr(ptr) {}
    
    smart_ptr(smart_ptr&& other) {
        ptr = other.release();
    }

    // Copy constructor is implicitly deleted because of the move constructor.
    smart_ptr& operator=(smart_ptr other) {
        other.swap(*this);
        return *this;
    }

    T* release() {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void swap(smart_ptr& other) {
        std::swap(ptr, other.ptr);
    }

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
    smart_ptr<int> alpha_ptr(new int(42));
    smart_ptr<int> beta_ptr;
    // beta_ptr = alpha_ptr; <--- This line will not compile.
    beta_ptr = std::move(alpha_ptr); // This will call the move constructor.
    std::cout << *beta_ptr << std::endl;
}
