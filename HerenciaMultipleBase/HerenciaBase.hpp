#include <iostream>
using namespace std;

class B1
{
	public:
		void f() { cout << "B1::f()" << endl; }
		void f(char i) { cout << "B1::f(char)" << endl; }
		int b;
};

class B2
{
	public:
		void f() { cout << "B2::f()" << endl; }
		void f(int i) { cout << "B2::f(int)" << endl; }
		int b;
};

class D: public B1, public B2
{
	public:
		//Si se hereda de dos clases base lo más recomendable
		//es heredar los miembros repetidos únicamente de una de ellas
		using B2::f;
		using B2::b;
		void f(double c) { cout << "D::f(double)" << endl; }
};