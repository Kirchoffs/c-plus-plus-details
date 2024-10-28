# Notes
## Bits of Knowledge
### Maximum Value
limits.h or limits
- `std::numeric_limits<int>::max();`
- `INT_MAX`

### Implicit Conversion
```
string answer = "42";
```

```
#include <iostream>
#include <string>
using namespace std;

void f(const string& s) {
    cout << s << endl;
}

// Below also works
// void f(string s) {
//    cout << s << endl;
// }

// Below does not work
// In C++, temporary objects (like the std::string created from the string literal "abc") can only be bound to const references. 
// They cannot be bound to non-const references.
// void f(string s) {
//     cout << s << endl;
// }

int main() {
    f("abc");
}
```
