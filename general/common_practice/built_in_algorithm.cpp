#include <vector>
#include <iostream>

void find_if_test() {
    const std::vector<int> data = {-3, -2, -1, 0, 1, 2, 3};

    const auto is_positive = [](const auto& x) { return x > 0; };
    auto first_pos_it = std::find_if(
        data.cbegin(), data.cend(), is_positive
    );
    std::cout << "First positive number: " << *first_pos_it << std::endl;
}

int main() {
    find_if_test();
}
