#include "ejercicio2.hpp"

using namespace std;

void f(V& v)
{
	if (typeid(v) == typeid(X))
	{
		std::cout << "Processing object X...\n";
		// specific code for X
	}

	if (typeid(v) == typeid(Y))
	{
		std::cout << "Processing object Y...\n";
		// specific code for Y
	}

	if (typeid(v) == typeid(Z))
	{
		std::cout << "Processing object Z...\n";
		// specific code for Z
	}
}

int main()
{
	X x;
	V* pv = new Y;

	f(x);
	f(*pv);

	return 0;
}