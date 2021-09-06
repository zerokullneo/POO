#include "virtual.hpp"
int main()
{
	D d;
	B b, *pb = &d;

	b.mostrar(9);//B:: mostrar( int )
	b.mostrar(9.5);//B:: mostrar(double)
	b.mostrar('a');//B:: mostrar(char)
	d.mostrar(9);//D::mostrar( int )
	d.mostrar(9.5);//D::mostrar( int )
	d.mostrar('a');//D::mostrar( int )
	pb->mostrar(9);//D::mostrar( int )
	pb->mostrar(9.5);//B:: mostrar(double)
	pb->mostrar('a');//B:: mostrar(char)
}