#include <iostream>

class B
{
	public:
		virtual void mostrar() { std::cout << i << " dentro de B\n"; }
		int i;
};

class D: public B
{
	public:
		void mostrar() { std::cout << i << " dentro de D\n"; }
};

int main()
{
	B b, *pb = &b;
	D d;
	d.i = 1 + (b.i = 1); // b.i = 1, d.i = 1 + 1;
	pb->mostrar(); // B::mostrar()
	pb = &d;
	pb->mostrar(); // D::mostrar()
}