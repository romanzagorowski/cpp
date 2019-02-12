#include <cstddef>
#include <iostream>

int main()
{
    std::byte b { 0xff };

    std::cout << std::to_integer<int>(b) << std::endl;

    std::byte mask { 0x0f };

    b &= mask;
}

