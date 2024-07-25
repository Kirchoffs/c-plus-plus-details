#include <array>

int main() {
    const int n = 256;
    std::array<int, n> data;
    for (int i = 0; i < n; ++i) {
        data[i] = i;
    }
}
