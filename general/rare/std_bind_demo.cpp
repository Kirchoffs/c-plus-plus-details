#include <algorithm>
#include <iostream>

bool greaterThan(int num, int limit) {
    return num > limit;
}

int main() {
    int arr[5] = {1, 3, 5, 7, 9};
    int limit = 5;
    auto countFunc = std::count_if(arr, arr + sizeof(arr) / sizeof(int), std::bind(greaterThan, std::placeholders::_1, limit));
    std::cout << countFunc << std::endl;
}
