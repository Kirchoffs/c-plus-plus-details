# c-plus-plus-details

## General
### CV Type Qualifier
CV: Const & Volatile

### constexpr
Since C++ 11

### static_assert
Since C++ 11

### is_same_v
Since C++ 17

### Overload
```
int f(int a) {
    return 1;
}

// Valid
double f(int a, int b) {
    return 2;
}

// Not valid
// At least one parameter type must be different
double f(int a) {
    return 3;
}
```

### default & delete
When you use `=default` for a special member function (constructor, destructor, copy constructor, move constructor, copy assignment operator, or move assignment operator), you are telling the compiler to generate the default implementation of that function if it would not be generated otherwise. This can be useful when you want to use the default behavior provided by the compiler but also need to define custom behavior for other special member functions.

When you use =delete for a special member function, you are explicitly instructing the compiler to prevent the generation of that function. This is often used when you want to disable certain operations, like copying or moving objects of a class, to make your code safer or to enforce a particular design.

## Template
### Two-phase Translation
Two-phase translation leads to an important problem in the handling of templates in practice: When a function template is used in a way that triggers its instantiation, a compiler will (at some point) need to see that template’s definition. This breaks the usual compile and link distinction for ordinary functions, when the declaration of a function is sufficient to compile its use. One simple way to resolve this is to implement each template inside a header file.

### decay & decay_t
```
#include <type_traits>

template <typename T>
void foo() {
    using DecayedType = typename std::decay<T>::type;
    // ...
}
```

```
#include <type_traits>

template <typename T>
void foo() {
    using DecayedType = std::decay_t<T>;
    // ...
}
```

### Overload Example
```
int max (int a, int b)
{
    return b < a ? a : b;
}

template<typename T> T max (T a, T b)
{
    return b < a ? a : b;
}
```

For `max(7, 42)`, the first one will be called.  
For `max(7.0, 42.0)`, the second one will be called.  
For `max('a', 42.0)`, the first one will be called, because __automatic type conversion__ is not considered for deduced template parameters but is considered for ordinary function parameters. It uses the nontemplate function (while 'a' and 42.0 both are converted to int).