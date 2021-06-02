#include <iostream>

using namespace std;

struct V
{
	virtual void fv() = 0;
	virtual ~V(){};
};

class X: V
{
	void fv(){ cout << "Función clase X" << endl; }
};

class Y: V
{
	void fv(){ cout << "Función clase Y" << endl; }
};

class Z: V
{
	void fv(){ cout << "Función clase Z" << endl; }
};