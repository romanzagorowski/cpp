#include <optional>
#include <iostream>
#include <string>

std::optional<std::string> GetSomeString()
{
    return "Alice has a cat";
}

std::optional<int> GetSomeInt()
{
    return 5;
}

int main()
{
    auto s = GetSomeString();

    return 0;
}

