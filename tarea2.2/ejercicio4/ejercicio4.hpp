#include <iostream>
#include <cstring>

class Libro1
{
	string titulo_, int pags_;
	
	public:
		Libro1(string t = "", int p = 0);
};


class Libro2
{
	string titulo_, int pags_;
	
	public:
		Libro2(string t, int p = 0);
		Libro2(const char* c);
}
