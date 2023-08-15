#include <string>
#include <iostream>

using namespace std;

enum Type {
    TYPE_FOO,
    TYPE_BAR
};

class Foo {
public:
    Type type = Type::TYPE_FOO;

    string get_foo() {
        return "foo";
    }

    string get() {
        return get_foo();
    }
};

class Bar {
public:
    Type type = Type::TYPE_BAR;

    string get_bar() {
        return "bar";
    }

    string get() {
        return get_bar();
    }
};

template<typename T>
void print(T t) {
    if (t.type == Type::TYPE_FOO) {
        cout << "Foo: " << t.get() << endl;
    } else if (t.type == Type::TYPE_BAR) {
        cout << "Bar: " << t.get() << endl;
    }
}

int main() {
    Foo foo;
    Bar bar;

    print(foo);
    print(bar);
}
