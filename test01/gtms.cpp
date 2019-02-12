#include "gtms.h"

#include <iostream>

namespace gtms
{
    int send_to_mainpro(const char* s, size_t n)
    {
        std::cout << s << std::endl;

        return 0;
    }
}

