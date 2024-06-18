#include <iostream>
#include <string>
using namespace std;

void printString(string& input) {
    cout << "void printString(string& input)" << endl;
    cout << input << endl;
}

void printString(const string& input) {
    cout << "void printString(const string& input)" << endl;
    cout << input << endl;
}

void printString(string&& input) {
    cout << "void printString(string&& input)" << endl;
    cout << input << endl;
}

void printString(const string&& input) {
    cout << "void printString(const string&& input)" << endl;
    cout << input << endl;
}

int main() {
    string x = "x";
    printString(x);
    cout << endl;

    printString("y");
}
