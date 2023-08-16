#include <type_traits>

template <template <typename> class T1, typename T2>
struct Fun_ {
    using type = typename T1<T2>::type;
};

template <template <typename> class T1, typename T2>
using Fun = typename Fun_<T1, T2>::type;

Fun<std::remove_reference, int&> x = 42;
