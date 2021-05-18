#include "ejercicio1.hpp"

using namespace std;

void print(int i) { cout << i << " [integer]" << endl; }
void print(float f) { cout << f << " [float]" << endl; }
void print(double f) { cout << f << " [double]" << endl; }

int main()
{
	print(2);
	print(2.0);
	print('a');
	return 0;
}