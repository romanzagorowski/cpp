#include <optional>
#include <iostream>

int main()
{
    std::optional<int> i = 7;

    if(i)
        std::cout << "i has value of " << *i << std::endl;
    else
        std::cout << "i has NOT value yet" << std::endl;

    return 0;
}

