#include <string_view>
#include <string>
#include <iostream>

int main() {
    const char *cstr_pointer = "cstr_pointer";
    char cstr_array[] = "cstr_array";
    std::string std_str = "std_str";

    std::string_view 
        sv1(cstr_pointer, 5),
        sv2(cstr_array),
        sv3("string literal", 4),
        sv4(std_str);

    std::cout
        << sv1 << std::endl
        << sv2 << std::endl
        << sv3 << std::endl
        << sv4 << std::endl;

    sv1.remove_prefix(2);
    std::cout << sv1 << std::endl;
}