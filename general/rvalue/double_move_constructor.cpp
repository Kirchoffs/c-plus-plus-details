#include <iostream>
#include <utility>
#include <memory>
#include <vector>

class X {
public:
    X(int val): val(val) {}

    X(X&& other) noexcept: val(other.val) {
        other.val = 0;
        std::cout << "Move constructor of X" << std::endl;
    }

    void print() {
        std::cout << "X: " << val << std::endl;
    }

private:
    int val;
};

// Below will call the move constructor of X twice
class XWrapper {
public:
    XWrapper(X x): x(std::move(x)) {}

private:
    X x;
};

// Below will call the move constructor of X once
class XBetterWrapper {
public:
    XBetterWrapper(X&& x): x(std::move(x)) {}

private:
    X x;
};

class XUniquePtrWrapper {
public:
    XUniquePtrWrapper(std::unique_ptr<X> x): x(std::move(x)) {}
    // Below would not work because it will destroy the object which the pointer points to
    // XUniquePtrWrapper(std::unique_ptr<X> x) {} 

private:
    std::unique_ptr<X> x;
};

int main() {
    X x(42);
    XWrapper x_wrapper(std::move(x));
    XBetterWrapper x_better_wrapper(std::move(x));

    std::unique_ptr<X> x_ptr = std::make_unique<X>(42); // std::make_unique is introduced in C++14
    X& x_ref = *x_ptr;
    XUniquePtrWrapper x_unique_ptr_wrapper(std::move(x_ptr));
    x_ref.print();
}
