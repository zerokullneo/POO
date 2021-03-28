#include <iostream>
#include <cstring>

using namespace std;

class Libro
{
	char* titulo_; int paginas_;
	public:
		Libro() : titulo_(new char[1]), paginas_(0) {*titulo_= 0;}
		Libro(const char* t, int p) : paginas_(p) {
			titulo_ = new char[strlen(t) + 1];
			strcpy(titulo_, t);
		}
		~Libro() { delete[] titulo_; }

		void paginas(int p) { paginas_ = p; }
		int paginas() const { return paginas_; }
		char* titulo() const { return titulo_; }
};
