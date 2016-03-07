#include <iostream>
#include "Racional.hpp"

using namespace std;

int main(int argc, char **argv)
{
	Racional r1(8,4);
	
	cout << " " << r1.num() << "\n---\n" << " " << r1.den() << endl;

	return 0;
}
