#include <iostream>

class X {
public:
    int v;
};

int main() {
    X* x = new X();
    x->v = 42;
    delete x;
    x->v = 89; 

    std::cout << x->v << std::endl;
}