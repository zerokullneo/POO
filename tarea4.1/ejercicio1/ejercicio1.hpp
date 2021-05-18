#include <iostream>

class punto
{
	double x, y;
	
	public:
		punto(double a = 0., double b = 0.): x{a}, y{b} {}
		punto(const punto &p): x{p.x}, y{p.y} {}
		punto& operator =(const punto &p)
		{x = p.x; y = p.y; return *this;}
};
