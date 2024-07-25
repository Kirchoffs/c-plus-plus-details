#include <iostream>
using namespace std;

int main() {
    int num;
    char ch = 'a';
    cout << &num << endl;
    printf("%p\n", &num);
    cout << &ch << endl;
    cout << static_cast<void*>(&ch) << endl;
    printf("%p\n", &ch);

    char* str = "abc";
    cout << str << endl;
}

// cout << &ch << endl;
// When cout is used with a character pointer (char*), it interprets the pointer as the starting address of a C-style string, 
// and attempts to print characters starting from that address up to the first null terminator ('\0'). 
// If ch is a single character and not part of a null-terminated string, the behavior can be unpredictable because cout will keep reading memory beyond ch until it happens to find a '\0', which might result in printing unexpected characters, or in some cases, it might not print anything if a '\0' is immediately after ch in memory.
