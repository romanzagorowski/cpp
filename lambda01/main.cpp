#include <iostream>

void f01()
{
    [] { std::cout << "hello lambda01" << std::endl; } ();
}

void f02()
{
    auto l = [] { std::cout << "f02" << std::endl; };
    l();
}

void f03()
{
    static const char* text = "Ala ma kota";

    auto l = [] { std::cout << text << std::endl; };
    l();
}

void f04()
{
    auto l = [] (const char* s) { std::cout << s << std::endl; };
    const char* text = "Ala ma kota";
    l(text);
}

void f05()
{
    auto l = [] { return 7; };
    std::cout << l() << std::endl;
}

void f06()
{
    auto l = [] () -> double { return 7; };
    std::cout << l() << std::endl;
}

int main()
{
    f05();
    f06();

    return 0;
}

