#include <iostream>
using namespace std;

class B
{
	public:
		virtual void mostrar(int i){ cout << i << " dentro de B::mostrar(int)\n"; }

		virtual void mostrar(double d){ cout << d << " dentro de B::mostrar(double)\n"; }

		virtual void mostrar(char c){ cout << c << " dentro de B::mostrar(char)\n"; }
};

class D: public B
{
	public:
		virtual void mostrar(int i){ cout << i << " dentro de D::mostrar(int)\n"; }

		void mostrar(double d){ cout << d << " dentro de D::mostrar(double)\n"; }
};