#include <iostream>
#include <string>
#include <map>
#include <any>


int main()
{
    std::any a;

    a = std::string { "Alice has a cat" };
    a = 16;

    std::cout << std::any_cast<int>(a) << std::endl;

    try
    {
        std::cout << std::any_cast<std::string>(a) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    a.reset();

    if(!a.has_value())
    {
        std::cout << "a is empty!" << std::endl;
    }

    // you can use it in a container
    std::map<std::string, std::any> m;

    m["int"] = 10;
    m["float"] = 3.1415f;
    m["string"] = std::string("Alice has a cat");

    for(auto & [key, value] : m)
    {
        if(value.type() == typeid(int))
            std::cout << "int: " << std::any_cast<int>(value) << std::endl;
        else if(value.type() == typeid(std::string))
            std::cout << "string: " << std::any_cast<std::string>(value) << std::endl;
        else if(value.type() == typeid(float))
            std::cout << "float: " << std::any_cast<float>(value) << std::endl;
    }
}

