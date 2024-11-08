#include <iostream>
#include <utility>

template <typename T>
void f(T t) {
    std::cout << "Pass value - Value: " << t << std::endl;
}

template <typename T>
void f_left_reference(T& t) {
    std::cout << "Pass left referece - Value: " << t << std::endl;
}

template <typename T>
void f_const_left_reference(const T& t) {
    std::cout << "Pass const left reference - Value: " << t << std::endl;
}

template <typename T>
void f_right_reference(T&& t) {
    std::cout << "Pass right reference - Value: " << t << std::endl;
}

int main() {
    std::string s1 = "Hello";
    f(s1);
    f(std::move(s1));

    std::string s2 = "Hello";
    f_left_reference(s2);
    // f_left_reference(std::move(s2));

    std::string s3 = "Hello";
    f_const_left_reference(s3);
    f_const_left_reference(std::move(s3));

    std::string s4 = "Hello";
    f_right_reference(s4);                 
    f_right_reference(std::move(s4));
    std::cout << "s4: " << s4 << std::endl;
}
