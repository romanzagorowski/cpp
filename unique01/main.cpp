#include <iostream>
#include <memory>
#include <cassert>

struct Abc
{
    Abc() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Abc() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

void foo(Abc* abc)
{
    assert(abc);

    std::cout << __PRETTY_FUNCTION__ << std::endl;
    delete abc;
}

int main()
{
    auto abc = std::unique_ptr<Abc>{ new Abc };

    foo(abc.release());
}

