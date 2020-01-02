#include <iostream>
#include <iomanip>

void foo() {}
void boo() noexcept {}

template<typename F>
void foo()
{
    if(noexcept(F()))
    {
        F();
    }
    else
    {
        try
        {
            F();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << noexcept(foo()) << std::endl;
    std::cout << noexcept(boo()) << std::endl;

    return 0;
}

