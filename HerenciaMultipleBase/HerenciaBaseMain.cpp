#include "HerenciaBase.hpp"

int main()
{
	D d;
	d.f(); // ERROR, ¿qué f(), el de B1 o el de B2?
	d.b = 0; //ERROR, ¿qué <b>, el de B1 o el de B2?
	d.B1::f();
	d.B2::f();
	d.B1::b = 0;
	d.B2::b = 0;

	d.f('A');
	d.f(0); // ERROR, ¿qué f(), el de B1 o el de B2?
	d.f(0.0); // ERROR, ¿qué f(), el de B1 o el de B2?
	d.B1::f(0);
	d.B2::f(0.0);

	return 0;
}