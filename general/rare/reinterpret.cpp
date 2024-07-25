#include <iostream>
using namespace std;

int main() {
    int n = 65;
    char* p = reinterpret_cast<char*>(&n);
    cout << p << endl;
}
