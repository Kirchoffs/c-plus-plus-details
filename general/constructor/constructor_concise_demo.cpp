#include <iostream>
#include <utility>
using namespace std;

class Student {
public:
    Student () {
        cout << "default constructor" << endl;
    }  
    
    Student(const Student& other) {
        cout << "copy constructor" << endl;
    }
    
    Student(Student&& other) {
        cout << "move constructor" << endl;
    }
    
    Student& operator=(const Student& other) {
        cout << "copy assignment" << endl;
        return *this;
    }
    
    Student& operator=(Student&& other) {
        cout << "move assignment" << endl;
        return *this;
    }

    ~Student() {
        cout << "destructor" << endl;
    }
};

int main()
{
    Student s1; // default constructor
    cout << "-----" << endl;
    Student s2 = s1; // copy constructor
    cout << "-----" << endl;
    Student s3 = Student(); // default constructor
    cout << "-----" << endl;
    Student s4 = std::move(s3); // move constructor
    cout << "-----" << endl;
    Student s5(std::move(s4)); // move constructor
    cout << "-----" << endl;
    s1 = s3; // copy assignment
    cout << "-----" << endl;
    s1 = Student(); // default construcor + move assignment + destructor
    cout << "-----" << endl;
    s1 = std::move(s3); // move assignment
    cout << "-----" << endl;
    // 5 destructors
}
