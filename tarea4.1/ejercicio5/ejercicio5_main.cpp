#include <iostream>

using namespace std;

class A{ public: ~A(); };
class B: public A { public: virtual ~B(); };
class C: public B { public: virtual ~C(); };
class D: public C { public: ~D(); };

int main()
{
	B *pb = new D;
	delete pb;
}