#include <iostream>
#include <string>

using namespace std;

class Articulo
{
	public:
		Articulo(string ref = "Sin Referencia", string tit = "Sin Titulo", double pvp = 0.0):referencia_(ref), titulo_(tit), precio_(pvp){};
		const string Referencia() const { return referencia_;}
		const string Titulo() const { return titulo_;}
		const double Precio() const{ return precio_;}

	private:
		string referencia_;
		string titulo_;
		double precio_;
};