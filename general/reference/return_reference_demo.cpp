#include <iostream>

class Data {
public:
    int value;
    Data(int value) : value(value) {}
    Data(const Data& other) : value(other.value) {}
};

class DataWrapper {
public:
    Data data;
    DataWrapper(Data data) : data(data) {}

    Data& get_data_reference() {
        return data;
    }

    Data get_data_copy() {
        return data;
    }
};

int main() {
    Data data(-1);
    DataWrapper data_wrapper(data);
    
    data_wrapper.get_data_reference().value = 42;
    std::cout << data_wrapper.data.value << std::endl;

    // data_wrapper.get_data_copy().value = 89;
    Data data_copy = data_wrapper.get_data_copy();
    data_copy.value = 89;
    std::cout << data_wrapper.data.value << std::endl;
}
