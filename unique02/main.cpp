#include <iostream>
#include <memory>

struct Abc
{
    Abc()  { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Abc() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

Abc* make_abc()
{
    return new Abc;
}

struct scope_mark
{
    scope_mark(const std::string & mark) : mark(mark)
    {
        std::cout << mark << " >>>" << std::endl;
    }
    
    ~scope_mark()
    {
        std::cout << mark << " <<<" << std::endl;
    }

private:
    std::string mark;
};

void foo()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    {
        scope_mark sm { "inner" };

        if(std::unique_ptr<Abc> abc { make_abc() }; abc)
        {
            scope_mark sm { "then" };

            std::cout << "abc holds some pointer" << std::endl;
        }
        else
        {
            scope_mark sm { "else" };

            std::cout << "abc is empty" << std::endl;
        }
    }

    std::cout << "foo end" << std::endl;
}

int main()
{
    foo();
}

