#include <iostream>
#include "ejercicio5.hpp"

int C::n;

int main()
{
	C c;
	C::n = 3;
	c.n = 4;
	std::cout << C::n << "␣" << c.n << std::endl;
	return 0;
}
