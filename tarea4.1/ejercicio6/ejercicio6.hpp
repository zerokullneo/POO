#include <iostream>

using namespace std;

class rectangle
{
	public:
		rectangle(double w, double l): width(w), length(l) {}
		virtual double area() { return width * length; }
	private:
		double width, length;
};

class square: public rectangle
{
	public:
		square (double l): rectangle(l, l) {}
		double area() { return rectangle::area(); }
};