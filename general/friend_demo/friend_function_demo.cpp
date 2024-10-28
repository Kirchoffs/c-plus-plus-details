#include <iostream>

class Square {
private:
    int side;
public:
    Square(int side);
    friend void printSide(Square square);
    int getArea();
};

Square::Square(int side) {
    this->side = side;
}

int Square::getArea() {
    return side * side;
}

void printSide(Square square) {
    std::cout << "Side: " << square.side << std::endl;
}

/*
 *
 * // Accessing private members of a class is not allowed
 * // unless the function is a friend of the class
 * 
 * void anotherPrintSide(Square square) {
 *     std::cout << "Side: " << square.side << std::endl;
 * }
 *
 */

int main() {
    Square square(5);
    printSide(square);
}