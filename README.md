# c-plus-plus-details

## General C++
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

### Pointer & Const
```
int * a;              // a is a pointer to an int
int const * b;        // b is a pointer to a const int
int * const c;        // c is a const pointer to an int
int const * const d;  // d is a const pointer to a const int
```

The name of an array usually evaluates to the address of the first element of the array, so array and &array have the same value (but different types, so array + 1 and &array + 1 will not be equal if the array is more than 1 element long).

When the array name is an operand of `sizeof` or unary `&` (address-of), the name refers to the array object itself. Thus `sizeof array` gives you the size in bytes of the entire array, not the size of a pointer.

For an array defined as T array[size], it will have type T*. When/if you increment it, you get to the next element in the array.

`&array` evaluates to the same address, but given the same definition, it creates a pointer of the type T(*)[size] -- i.e., it's a pointer to an array, not to a single element. If you increment this pointer, it'll add the size of the entire array, not the size of a single element. For example, with code like this:
```
char array[16];
printf("%p\t%p", (void*) &array, (void*) (&array + 1));
```

We can expect the second pointer to be 16 greater than the first (because it's an array of 16 char's). If we did the same thing with a pointer to char, we'd get a difference of 1 instead.

## General C
### snprintf
`snprintf()` is a C function that redirects the output of the standard `printf()` function to a buffer. 
It formats the given strings into a series of characters or values in the buffer area. 
`snprintf()` is identical to the `sprintf()` function, but with the addition of the n argument. The n argument indicates the maximum number of characters to be written to the buffer. 

`snprintf()` appends a null character to the end of the resulting output. This null character is also counted towards the size of the string, so, only n - 1 characters are written to the buffer.

### scanf & printf
- scanf scan the input from the standard input stream stdin and store the value into the variable address passed as parameter.

- sscanf scan the input from the string passed as first parameter and store the value into the variable address passed as parameter.

- printf print the output to the standard output stream stdout.

- sprintf print the output to the string passed as first parameter.

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