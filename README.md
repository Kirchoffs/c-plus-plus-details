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