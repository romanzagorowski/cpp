#include <iostream>
#include <tuple>
#include <string>
#include <array>

auto get_tuple()
{
    return std::make_tuple("fred", 42);
}

void foo()
{
    auto [name, age] = get_tuple();

    std::cout << "name: " << name << ", age: " << age << std::endl;
}

void moo()
{
    std::string name;
    int age;

    std::tie(name, age) = get_tuple();

    std::cout << "name: " << name << std::endl;
    std::cout << "age : " << age  << std::endl;
}

void boo()
{
    auto t = std::make_tuple(7, 0.0f);

    auto & [i, f] = t;

    i += 1;

    std::cout << std::get<0>(t) << std::endl;
}

void xoo()
{
    struct Person
    {
        std::string name;
        int         age;
        std::string city;
    };

    Person p { "Bill", 60, "New York" };

    auto [name, age, city] = p;

    std::cout << name << " (age " << age << ") lives in " << city << std::endl;
}

void zoo()
{
    std::array<int, 6> a { 10, 11, 12, 13, 14, 15 };

    auto [i, j, k, l, x, y] = a;
}

int main()
{
    zoo();
}

