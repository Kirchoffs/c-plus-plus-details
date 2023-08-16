template <int a, int b>
struct Add_ {
    constexpr static int value = a + b;
};

template <int a, int b>
constexpr int Add = a + b;

constexpr int i = Add_<2, 3>::value;
constexpr int j = Add<2, 3>;
