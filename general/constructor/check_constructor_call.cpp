#include <iostream>
using namespace std;

class B {
public:
    B() {
        cout << "B constructor" << endl;
    }
    
    B(const B& b) {
        cout << "B copy constructor" << endl;
    }

    B& operator=(const B& b) {
        cout << "B assignment operator" << endl;
        return *this;
    }
};

class A1 {
public:
    A1(B b): b(b) {
        cout << "A1 copy constructor" << endl;
    }

private:
    B b;
};

class A2 {
public:
    A2(B b) {
        cout << "A2 copy constructor" << endl;
        this->b = b;  
    }

private:
    B b;
};

class A3 {
public:
    A3(B b) {
        this->b = b;
        cout << "A3 copy constructor" << endl;  
    }

private:
    B b;
};

void f(B b_input) {
    B b(b_input);
}

int main() {
    B b;
    
    cout << "----------------" << endl;
    A1 a1(b);
    cout << "----------------" << endl;
    A2 a2(b);
    cout << "----------------" << endl;
    A3 a3(b);
    cout << "----------------" << endl;
    f(b);
    cout << "----------------" << endl;

    return 0;
}

/**
 * Constructor and Copy Constructor Call Sequence:
 * 
 * 
 * B constructor
 * ----------------
 * B copy constructor
 * B copy constructor
 * A1 copy constructor
 * ----------------
 * B copy constructor
 * B constructor
 * A2 copy constructor
 * B assignment operator
 * ----------------
 * B copy constructor
 * B constructor
 * B assignment operator
 * A3 copy constructor
----------------
 * B copy constructor
 * B copy constructor
 * ----------------
 * 
 * 
 */