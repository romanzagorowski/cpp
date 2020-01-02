#include <iostream>
#include <iomanip>
#include <exception>

template<typename F>
void foo(F f)
{
    if(noexcept(f()))
    {
        f();
    }
    else
    {
        try
        {
            f();
        }
        catch(const std::exception& e)
        {
            std::cerr << "An exception caught: 'e.what()'" << std::endl;
        }
    }
}

void T()
{
    std::cout << "T()" << std::endl;

    throw std::exception {};
}

void S()
{
    std::cout << "S()" << std::endl;
}

int main()
{
    foo(S);

    return 0;
}

