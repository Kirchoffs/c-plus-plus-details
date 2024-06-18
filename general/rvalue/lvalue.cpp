#include <iostream>
using namespace std;

int global_value = 42;

int& get_global_value() {
    return global_value;
}

int main() {
    get_global_value() = 89;
    cout << global_value << endl;
}
