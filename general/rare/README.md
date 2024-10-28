# Notes
## std::bind
```
#include <iostream>
#include <functional>

int add(int x, int y) {
    return x + y;
}

int main() {
    auto add_with_42 = std::bind(add, 42, std::placeholders::_1);
    std::cout << add_with_42(8) << std::endl;
}
```
