#include <iostream>
#include <cstring>

class Person {
public:
    // Default constructor
    Person() {
        name = nullptr;
        age = 0;
    }

    // Parameterized constructor
    Person(const char* name, int age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }

    // Copy constructor
    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
    }

    // Move constructor
    Person(Person&& other) noexcept {
        name = other.name;
        age = other.age;
        other.name = nullptr;
    }

    // Destructor
    ~Person() {
        delete[] name;
    }

    // Copy assignment operator
    Person& operator=(const Person& other) {
        if (this == &other) {
            return *this;
        }
            

        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
        return *this;
    }

    // Move assignment operator
    Person& operator=(Person&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        delete[] name;
        name = other.name;
        age = other.age;
        other.name = nullptr;
        return *this;
    }

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    void set_name(const char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void set_age(int age) {
        this->age = age;
    }

private:
    char* name;
    int age;
};

int main() {
    // Using different constructors
    Person person1;                          // Default constructor
    Person person2("Alice", 30);             // Parameterized constructor
    Person person3 = person2;                // Copy constructor
    Person person4 = std::move(person3);     // Move constructor
    Person person5(person2);                 // Copy constructor
    Person person6(std::move(person4));      // Move constructor

    person1.set_name("John");
    person1.set_age(10);

    person3.set_name("Bob");
    person3.set_age(40);

    person4.set_name("Charlie");
    person4.set_age(50);

    // Displaying the persons
    std::cout << "Person 1: ";
    person1.display();
    std::cout << "Person 2: ";
    person2.display();
    std::cout << "Person 3: ";
    person3.display();                       // Note: After move, person3's state is unspecified
    std::cout << "Person 4: ";
    person4.display();
    std::cout << "Person 5: ";
    person5.display();
    std::cout << "Person 6: ";
    person6.display();

    // Using assignment operators
    Person person7;
    person7 = person2;                       // Copy assignment operator
    Person person8;
    person8 = std::move(person4);            // Move assignment operator

    // Displaying the updated persons
    std::cout << "Person 7: ";
    person7.display();
    std::cout << "Person 8: ";
    person8.display();

    return 0;
}
