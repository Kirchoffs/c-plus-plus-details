#include <type_traits>

template<typename T>
T max(T a, T b) 
{
    return a > b ? a : b;
}

template<typename T, typename U>
auto max_decltype(T a, U b) -> typename std::decay<decltype(a > b ? a : b)>::type
{
    return b < a ? a : b;
}

template<typename T, typename U>
std::common_type_t<T, U> max_common_type (T a, U b)
{
  return b < a ? a : b;
}

template<typename T1, typename T2, typename RT = std::common_type_t<T1,T2>>
RT max_default_template_arguments(T1 a, T2 b)
{
  return b < a ? a : b;
}
