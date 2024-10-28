#include <iostream>
using namespace std;

class ClassB;

class ClassA {
private:
    int privateVarA;

public:
    ClassA() : privateVarA(42) {}

    // Declare ClassB as a friend class
    friend class ClassB;
};

class ClassB {
public:
    void showPrivateA(ClassA& objA) {
        // Accessing privateVarA from ClassA, because ClassB is a friend
        cout << "ClassA's privateVarA: " << objA.privateVarA << endl;
    }
};

int main() {
    ClassA objA;
    ClassB objB;

    objB.showPrivateA(objA); // Access private member of ClassA
    return 0;
}
