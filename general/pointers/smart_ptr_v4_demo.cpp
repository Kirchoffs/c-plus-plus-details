#include <iostream>

class shared_count {
public:
    shared_count(): count(1) {}

    void add_count() {
        ++count;
    }

    long reduce_count() {
        return --count;
    }

    long get_count() const {
        return count;
    }

private:
    long count;
};

template <typename T>
class smart_ptr {
public:
    template <typename U>
    friend class smart_ptr;
    
    explicit smart_ptr(T* ptr = nullptr): ptr(ptr) {
        if (ptr) {
            shared = new shared_count();
        }
    }

    ~smart_ptr() {
        if (ptr && shared->reduce_count() == 0) {
            delete ptr;
            delete shared;
        }
    }

    smart_ptr(const smart_ptr& other) {
        ptr = other.ptr;
        if (ptr) {
            other.shared->add_count();
            shared = other.shared;
        }
    }

    template <typename U>
    smart_ptr(const smart_ptr<U>& other) {
        ptr = other.ptr;
        if (ptr) {
            other.shared->add_count();
            shared = other.shared;
        }
    }

    template <typename U>
    smart_ptr(smart_ptr<U>&& other) {
        ptr = other.ptr;
        if (ptr) {
            shared = other.shared;
            other.ptr = nullptr;
        }
    }

    template <typename U>
    smart_ptr(const smart_ptr<U>& other, T* ptr): ptr(ptr) {
        if (ptr) {
            other.shared->add_count();
            shared = other.shared;
        }
    }

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
        std::swap(shared, other.shared);
    }

    long use_count() const {
        if (ptr) {
            return shared->get_count();
        } else {
            return 0;
        }
    }

    T* get() const { return ptr; }
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    operator bool() const { return ptr; }

private:
    T* ptr;
    shared_count* shared;
};

template <typename T, typename U>
smart_ptr<T> dynamic_pointer_cast(const smart_ptr<U>& other) {
    T* ptr = dynamic_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}

class Shape {
public:
    virtual ~Shape() {}
};

class Circle: public Shape {
public:
    ~Circle() {
        std::cout << "Circle destructor" << std::endl;
    }
};

int main() {
    smart_ptr<Circle> ptr_circle(new Circle());
    std::cout << "use count of ptr_circle: " << ptr_circle.use_count() << std::endl;

    smart_ptr<Shape> ptr_shape;
    std::cout << "use count of ptr_shape: " << ptr_shape.use_count() << std::endl;

    ptr_shape = ptr_circle;
    std::cout << "use count of ptr_shape: " << ptr_shape.use_count() << std::endl;

    if (ptr_circle) {
        std::cout << "ptr_circle is not null" << std::endl;
    }

    smart_ptr<Circle> ptr_circle_more = dynamic_pointer_cast<Circle>(ptr_shape);
    std::cout << "use count of ptr_circle_more: " << ptr_circle_more.use_count() << std::endl;
}
