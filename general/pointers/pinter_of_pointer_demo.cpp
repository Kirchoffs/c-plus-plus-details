#include <iostream>

void update_num_by_pointer(int* num_ptr) {
    *num_ptr = 42;
}

void update_num_by_reference(int& num_ref) {
    num_ref = 42;
}

void update_num_ptr_by_pointer_of_pointer(int** num_ptr_ptr) {
    *num_ptr_ptr = new int(42);
}

void update_num_ptr_by_reference_of_pointer(int*& num_ptr_ref) {
    num_ptr_ref = new int(42);
}

int main() {
    int alpha_num;
    update_num_by_pointer(&alpha_num);
    std::cout << alpha_num << std::endl;

    int beta_num;
    update_num_by_reference(beta_num);
    std::cout << beta_num << std::endl;

    int* alpha_num_ptr = nullptr;
    update_num_ptr_by_pointer_of_pointer(&alpha_num_ptr);
    std::cout << *alpha_num_ptr << std::endl;

    int* beta_num_ptr = nullptr;
    update_num_ptr_by_reference_of_pointer(beta_num_ptr);
    std::cout << *beta_num_ptr << std::endl;
}
