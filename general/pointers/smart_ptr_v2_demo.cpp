#include <iostream>

template <typename T>
class smart_ptr {
public:
    explicit smart_ptr(T* ptr = nullptr): ptr(ptr) {}
    
    smart_ptr(smart_ptr& other) {
        ptr = other.release();
    }

    // Self-assignment is handled by the copy-and-swap idiom.
    smart_ptr& operator=(smart_ptr& other) {
        smart_ptr(other).swap(*this);
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
    smart_ptr<int> beta_ptr = alpha_ptr;
    std::cout << *beta_ptr << std::endl;
}
