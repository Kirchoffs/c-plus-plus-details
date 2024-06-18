# Notes
## Conversion
An lvalue of a non-function, non-array type T can be converted to an rvalue.  
If T is a non-class type, the type of the rvalue is the __cv-unqualified__ version of T. Otherwise, the type of the rvalue is T.

### Class types
- Classes
- Structs
- Unions

### Non-class types
- Primitive types
- Pointer types
- Enumeration types
- Void type
- Built-in arrays and functions

### CV Qualifiers
In C, rvalues never have cv-qualified types. Only lvalues do.  
In C++, on the other hand, class rvalues can have cv-qualified types, but built-in types (like int) can't.

## Reference
### Value
rvalue:
- xvalue (eXpiring value, introduced in C++11, return value of std::move)
- prvalue (Pure rvalue, literal, temporary result of an expression)

```
class A {};

A a;
auto b = std::move(a);        // xvalue
auto c = static_cast<A&&>(a); // xvalue
```

### Categories after C++11
- const lvalue reference
- non-const lvalue reference
- const rvalue reference
- non-const rvalue reference

### Before C++11
#### non-const lvalue reference
```
Foo foo(42);
Foo& foo_ref = foo;
```

#### const lvalue reference
```
Foo foo(42);
const Foo& foo_ref = foo;
```

#### const rvalue reference
```
const Foo& foo_ref = Foo(42);
```

#### Copy constructor and copy assignment operator
```
struct Foo {
    Foo();                       // default constructor
    Foo(const Foo&);             // copy constructor

    Foo& operator=(const Foo&);  // copy assignment operator
};
```

```
Foo foo_alpha;             // default constructor
Foo foo_beta = foo_alpha;  // copy constructor
Foo foo_gamma;
foo_gamma = foo_alpha;     // copy assignment operator
```

### C++11 
```
struct Foo {
    Foo();                       // default constructor
    Foo(const Foo&);             // copy constructor
    Foo(Foo&&);                  // move constructor

    Foo& operator=(const Foo&);  // copy assignment operator
    Foo& operator=(Foo&&);       // move assignment operator
};
```

```
Foo foo_alpha;                       // Default constructor
Foo foo_beta = foo_alpha;            // Copy constructor
Foo foo_gamma;                       // Default constructor
foo_gamma = foo_alpha;               // Copy assignment
Foo foo_delta = Foo();               // Default constructor
Foo foo_epsilon;                     // Default constructor
foo_epsilon = Foo();                 // Move assignment
Foo foo_zeta = std::move(foo_alpha); // Move constructor
```

#### Executable code
```
#include <iostream>
using namespace std;

struct Foo {
   Foo() {
       cout << "Default constructor" << endl;
   }
   
   Foo(const Foo& foo) {
       cout << "Copy constructor" << endl;
   }
   
   Foo(Foo&& foo) {
       cout << "Move constructor" << endl;
   }
   
   Foo& operator=(const Foo& foo) {
       cout << "Copy assignment" << endl;
   }
   
   Foo& operator=(Foo&& foo) {
       cout << "Move assignment" << endl;
   }
};

int main() {
    Foo foo_alpha;              
    Foo foo_beta = foo_alpha;   
    Foo foo_gamma;
    foo_gamma = foo_alpha;
    Foo foo_delta = Foo();
    Foo foo_epsilon;
    foo_epsilon = Foo();
    Foo foo_zeta = std::move(foo_alpha);
}
```

### Perfect forwarding
```
#include <iostream>

template <typename T>
void print(T& t) {
    std::cout << "lvalue" << std::endl;
}

template <typename T>
void print(T&& t) {
    std::cout << "rvalue" << std::endl;
}

template <typename T>
void testForward(T&& t) {
    print(t);
    print(std::forward<T>(t));
    print(std::move(t));
}

int main() {
    int x = 42;
    testForward(x);  // lvalue, lvalue, rvalue
    testForward(42); // lvalue, rvalue, rvalue
}
```

### Related Data Structure
#### Usage
```
vector<string> v;
v.push_back("hello");
v.emplace_back("hello");

set<string> s;
s.insert("hello");
s.emplace("hello");

map<int, string> m;
m.insert({1, "hello"});
m.emplace(1, "hello");
```

#### Executable demo
```
#include <iostream>
#include <vector>
using namespace std;

class Foo {
private:
    int i;
    string s;

public:
    Foo(int i, string s) : i(i), s(s) {
        cout << "Constructor" << endl;
    }

    Foo(const Foo& foo) : i(foo.i), s(foo.s) {
        cout << "Copy constructor" << endl;
    }

    Foo(Foo&& foo) : i(foo.i), s(move(foo.s)) {
        cout << "Move constructor" << endl;
    }
};

int main() {
    vector<Foo> v1;
    v1.reserve(2);
    v1.push_back(Foo(42, "hello"));    // Constructor, Move constructor
    cout << "---" << endl;
    v1.emplace_back(Foo(42, "hello")); // Constructor, Move constructor
    cout << "===" << endl;
    
    vector<Foo> v2;
    v2.reserve(2);
    Foo foo(42, "hello");              // Constructor
    v2.push_back(foo);                 // Copy constructor
    cout << "---" << endl;
    v2.emplace_back(foo);              // Copy constructor
    cout << "===" << endl;
    
    vector<Foo> v3;
    v3.reserve(2);
    v3.push_back(Foo(42, "hello"));    // Constructor, Move constructor
    cout << "---" << endl;
    v3.emplace_back(42, "hello");      // Constructor
    cout << "===" << endl;

    return 0;
}
```
