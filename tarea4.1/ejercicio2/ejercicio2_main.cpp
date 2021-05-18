#include <iostream>

using namespace std;

	void f(char);
	void f(double);
	void f(void *);

int main()
{
	f(0.0);
	f(0);
	f(0.0f);
	f("Hello");
}