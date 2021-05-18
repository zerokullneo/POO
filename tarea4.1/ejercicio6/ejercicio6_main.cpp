#include <iostream>

using namespace std;

struct B
{
	B() { std::cout << "Constructor (class␣B)\n"; }
	virtual ~B() { cout << "Destructor (class␣B)\n"; }
};

struct D: B
{
	D() { cout << "Constructor (class D)\n"; }
	~D() { cout << "Destructor (class D)\n"; }
};

int main()
{
	B *pb = new D;
	delete pb;
}