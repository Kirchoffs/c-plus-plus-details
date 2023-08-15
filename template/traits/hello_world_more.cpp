#include <iostream>

template <typename T>
struct TraitsHelper {
    typedef T return_type;
    typedef T parameter_type;
};

template <>
struct TraitsHelper<int> {
    typedef int return_type;
    typedef int parameter_type;
};

template <>
struct TraitsHelper<double> {
    typedef int return_type;
    typedef double parameter_type;
};

template <typename T>
class Mathematics {
public:
    typename TraitsHelper<T>::return_type double_get(typename TraitsHelper<T>::parameter_type value) {
        return value + value;
    }
};

template <typename T>
typename TraitsHelper<T>::return_type triple_get(typename TraitsHelper<T>::parameter_type value) {
    return value + value + value;
}

int main() {
    Mathematics<int> mathematics_int;
    Mathematics<double> mathematics_float;

    std::cout << mathematics_int.double_get(42) << std::endl;
    std::cout << mathematics_float.double_get(2.718) << std::endl;

    std::cout << triple_get<int>(42) << std::endl;
    std::cout << triple_get<double>(2.718) << std::endl;
}
