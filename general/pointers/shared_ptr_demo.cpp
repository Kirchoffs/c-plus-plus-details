#include <memory>
#include <iostream>

void shared_ptr_non_const_to_const() {
    // shared_ptr<T> can be converted to shared_ptr<const T>
    std::shared_ptr<int> int_ptr = std::make_shared<int>(42);
    std::shared_ptr<const int> const_int_ptr = int_ptr;
    std::cout << *const_int_ptr.get() << std::endl;
}

void shared_ptr_const_to_non_const() {
    // shared_ptr<const T> can be converted to shared_ptr<T> using const_pointer_cast
    std::shared_ptr<const int> const_int_ptr = std::make_shared<int>(89);
    std::shared_ptr<int> int_ptr = std::const_pointer_cast<int>(const_int_ptr);
    std::cout << *int_ptr.get() << std::endl;
}

void unique_ptr_to_shared_ptr() {
    // unique_ptr<T> can be converted to shared_ptr<T>
    std::unique_ptr<int> unique_int_ptr = std::make_unique<int>(42);
    // std::shared_ptr<int> shared_int_ptr = std::move(unique_int_ptr);
    std::shared_ptr<int> shared_int_ptr = std::shared_ptr<int>(std::move(unique_int_ptr));
    std::cout << *shared_int_ptr.get() << std::endl;
}

// Both const_cast<T> and const_pointer_cast<T> can be used to cast away constness
int main() {
    std::cout << "Starting:" << std::endl;
    shared_ptr_non_const_to_const();
    shared_ptr_const_to_non_const();
    unique_ptr_to_shared_ptr();
    std::cout << "Done" << std::endl;
}   
