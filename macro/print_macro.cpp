#include <iostream>

#define PRINT_MACRO_VALUE(x) std::cout << #x << " = " << x << std::endl

int main() {
    PRINT_MACRO_VALUE(__cplusplus);
}
