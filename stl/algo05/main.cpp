#include <iostream>
#include <initializer_list>

struct X
{
	X(const std::initializer_list<int>& il)
	{
		std::cout << "X(const std::initializer_list<int>& il)" << std::endl;
	}

	X(int i)
	{
		std::cout << "X(int i)" << std::endl;
	}
};

int main()
{
	X x{ 5 };
}

