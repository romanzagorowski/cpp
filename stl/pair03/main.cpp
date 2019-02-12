#include <iostream>
#include <utility>
#include <tuple>

struct foo
{
    foo(std::tuple<int, float>)
    {
        std::cout << "foo(std::tuple<int, float>)" << std::endl;
    }

    template <typename ... A>
    foo(A ... args)
    {
        std::cout << "foo(A ... args)" << std::endl;
    }

    foo(int, float)
    {
        std::cout << "foo(int, float)" << std::endl;
    }
};

int main()
{
    std::tuple<int, float> t { 7, 3.1415 };

    std::pair<int, foo> p1 { 5, t };
    std::pair<int, foo> p2 { std::piecewise_construct, std::make_tuple(42), t };
}

