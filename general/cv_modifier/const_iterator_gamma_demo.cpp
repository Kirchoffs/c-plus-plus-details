#include <iostream>
#include <vector>
using namespace std;

class RestrictedIterationClass {
private:
    class Iterator {
    private:
        vector<string> data = {"a", "b", "c", "d", "e"};
        size_t index;

    public:
        Iterator(int index = 0) : index(index) {}

        const string& operator*() { return data[index]; }
        Iterator& operator++() { ++index; return *this; }
        bool operator!=(const Iterator& other) const { return index != other.index; }
    };

public:
    const Iterator begin() { return Iterator(); }
    const Iterator end() { return Iterator(5); }
};

int main() {
    RestrictedIterationClass data;
    
    RestrictedIterationClass& regular_iteration = data;
    for (const string& e : regular_iteration) {  // call begin(), const qualifier is required
        cout << e << ' ';
    }

    for (auto& e : regular_iteration) {  // call begin(), const qualifier is not required
        cout << e << ' ';
    }
    
    
    cout << endl;
}
