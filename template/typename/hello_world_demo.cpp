#include <vector>
#include <iostream>

template<typename T>
void print_itr(T const& itr)
{
    typename T::const_iterator end(itr.end());

    typename T::const_iterator pos;
    for (pos = itr.begin(); pos != end; ++pos)
    {
        std::cout << *pos << ' ';
    }

    std::cout << '\n';
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    print_itr(v);
}
