#include <iostream>
#include <string>
#include <variant>

struct Visitor
{
    void operator () (int i) const
    {
        std::cout << "int: " << i << std::endl;
    }
    void operator () (float f) const
    {
        std::cout << "float: " << f << std::endl;
    }
    void operator () (const std::string& s) const 
    {
        std::cout << "string: " << std::endl;
    }
};

int main()
{
    std::variant<int, float, std::string> v;
    
    static_assert(std::variant_size_v<decltype(v)> == 3);

    // default initialized to the first alternative - should be 0
    std::visit(Visitor{}, v);

    // index will show the current used 'type'
    std::cout << "index = " << v.index() << std::endl;

    v = 3.1415f;
    std::cout << "index = " << v.index() << std::endl;

    v = "Alice has a cat";
    std::cout << "index = " << v.index() << std::endl;

    // try with std::get_if
    if(const auto pi { std::get_if<int>(&v) })
        std::cout << "int! " << *pi << std::endl;

    if(const auto pf { std::get_if<float>(&v) })
        std::cout << "float! " << *pf << std::endl;

    if(const auto ps { std::get_if<std::string>(&v) })
        std::cout << "string! " << *ps << std::endl;

    try
    {
        auto f = std::get<float>(v);
        std::cout << "float! " << f << std::endl;
    }
    catch(const std::bad_variant_access& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // visit
    std::visit(Visitor{}, v);

    v = 10;
    std::visit(Visitor{}, v);

    v = 3.1415f;
    std::visit(Visitor{}, v);

    return 0;
}

