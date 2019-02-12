#include <optional>
#include <iostream>
#include <string>

struct X
{
    //X(int i) : i(i) {}

    int i = 7;
};

int main()
{
    std::optional<X> x;
    //std::optional<X> x { std::in_place };

    std::cout << x->i << std::endl;

    return 0;
}

