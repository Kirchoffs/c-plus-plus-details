#include <iostream>
#include <vector>
using namespace std;

class RestrictedIterationClass {
private:
    class Iterator {
    private:
        vector<int> data = {1, 2, 3, 4, 5};
        size_t index;

    public:
        Iterator(int index = 0) : index(index) {}

        int& operator*() { return data[index]; }
        Iterator& operator++() { ++index; return *this; }
        bool operator!=(const Iterator& other) const { return index != other.index; }
    };

    class ConstIterator {
    private:
        vector<int> data = {11, 12, 13, 14, 15};
        size_t index = 0;
    
    public:
        ConstIterator(int index = 0) : index(index) {}

        const int& operator*() const { return data[index]; }
        ConstIterator& operator++() { ++index; return *this; }
        bool operator!=(const ConstIterator& other) const { return index != other.index; }
    };

public:
    Iterator begin() { return Iterator(); }
    Iterator end() { return Iterator(5); }

    ConstIterator begin() const { return ConstIterator(); }
    ConstIterator end() const { return ConstIterator(5); }
};

int main() {
    RestrictedIterationClass data;
    
    RestrictedIterationClass& regular_iteration = data;
    for (auto& e : regular_iteration) {  // call begin()
        cout << e << ' ';
    }
    cout << endl;
    for (const auto& e : regular_iteration) {  // call begin()
        cout << e << ' ';
    }
    cout << endl;

    const RestrictedIterationClass& const_iteration = data;
    for (auto& e : const_iteration) {  // call begin()-const
        cout << e << ' ';
    }
    cout << endl;
    for (const auto& e : const_iteration) {  // call begin()-const
        cout << e << ' ';
    }
    cout << endl;
}
