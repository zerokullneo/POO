#include <iostream>

using namespace std;

class B
{
	public:
		//virtual B::f();
		//B::f();
		void f(){ cout << "función de B." << endl; }
};

class D: public B
{
	public:
		void f(){ cout << "función de D." << endl; }
};

int main()
{
	B b, *bp;
	D d, *dp;
	bp = &d; //Error de coherencia, puede compilar y no funcionar correctamente
	bp->f();
	dp = &b; //Error de compilacion
	dp->f();
	dp = &d;
	dp->f();

	return 0;
}