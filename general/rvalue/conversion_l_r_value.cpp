#include <string>

int main() {
    int a = 1; // a is an lvalue, modifiable lvalue
    int b = 2; // b is an lvalue, modifiable lvalue
    int c = a + b; // a + b is an rvalue

    int arr[] = {1, 2, 3};
    int* p_arr = &arr[0];
    *(p_arr + 1) = 5; // p_arr + 1 is an rvalue, *(p_arr + 1) is an lvalue

    // The unary address-of operator '&' requires an lvalue operand and returns an rvalue
    int var = 42;
    // int* bad_ptr = &(var + 1); ---> error: lvalue required as unary '&' operand
    int* good_ptr = &var; // var is an lvalue, &var is an rvalue

    // Non const lvalue reference cannot be assigned to an rvalue
    // std::string& bad_ref = std::string();

    // Const lvalue reference can be assigned to an rvalue, because it is constant and the value will not be modified through the reference
    const std::string& good_ref = std::string("Hello, World!");
}
