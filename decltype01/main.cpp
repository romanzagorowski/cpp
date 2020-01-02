#include <iostream>

template <typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y)
{
    return x + y;
}

struct A {};
struct B {};
struct C {};

C operator + (A a, B b)
{
    return C{};
}

int main()
{
    A a;
    B b;

    C c = add(a, b);

    std::cout << sizeof(c) << std::endl;

    return 0;
}

