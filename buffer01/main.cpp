#include <iostream>

struct Buffer
{
    Buffer(size_t size)
    {
        memory = new int[size];
        
        std::cout << "Buffer(size_t size)" << std::endl;
    }

    ~Buffer()
    {
        delete [] memory;
        
        std::cout << "~Buffer()" << std::endl;
    }

    int* memory;
};

int main()
{
    Buffer b { 1000 };

    return 0;
}

