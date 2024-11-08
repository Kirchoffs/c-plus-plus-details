template <typename T>
class smart_ptr {
public:
    explicit smart_ptr(T* ptr = nullptr): ptr(ptr) {}
    
    smart_ptr(const smart_ptr& other) {
        ptr = other.release();
    }

    smart_ptr& operator=(const smart_ptr& other) {
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
