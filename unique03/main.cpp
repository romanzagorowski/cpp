#include <iostream>
#include <memory>
#include <utility>

struct Abc
{
    Abc()  { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Abc() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main()
{
    auto a1 = std::make_unique<Abc>();

    std::unique_ptr<Abc> a2;

    a2 = std::move(a1);

    std::cout << std::boolalpha;
    //std::cout << "a1 owns pointer: " << bool(a1) << std::endl;
    //std::cout << "a2 owns pointer: " << bool(a2) << std::endl;
    std::cout << "a1 owns pointer: " << (a1 ? true : false) << std::endl;
    std::cout << "a2 owns pointer: " << (a2 ? true : false) << std::endl;
}

