#include <iostream>

struct I
{
    I(int i) : i(i) { std::cout << "I(int i)" << std::endl; }

    int i;
};

struct F
{
    F(float f) : f(f) { std::cout << "F(float f)" << std::endl; }

    float f;
};

union U
{
    I i;
    F f;

    U() { std::cout << "U()"  << std::endl; }
    U(int i) : i(i) { std::cout << "U(int i)"  << std::endl; }
    U(float f) : f(f) { std::cout << "U(float f)"  << std::endl; }
    ~U() { std::cout << "~U()" << std::endl; }
};

int main()
{
    U u;
    U ui { 7 };
    U uf { 3.1415f };

    return 0;
}

