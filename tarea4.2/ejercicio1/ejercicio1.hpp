#include <iostream>

class B
{
	public:
		virtual void f()/*{ cout << "Función clase Base" << endl; }*/ const = 0;
};

class D
{
	public:
		void f(){ cout << "Función clase Derivada" << endl; }
};