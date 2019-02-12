#include <cstdlib>

struct Error
{
    int code;

    operator bool ()
    {
        return code != 0;
    }
};

struct String
{
    const char* s;

    operator int ()
    {
        return std::atoi(s);
    }
};

void F1()
{
    String s = { "7" };

    int i = 5 + s;
}


int main()
{
    Error error = { 0 };

    if(!error)
    {
    }

    return 0;
}

