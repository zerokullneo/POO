#include "ejercicio5.hpp"

void mostrar(Libro l)
{
	cout << l.titulo() << " tiene " << l.paginas() << " páginas" << endl;
}

int main()
{
	Libro l1("Fundamentos de C++", 474),
	l2("Por Fin: C ISO", 224),
	l3;

	l3 = l1;

	mostrar(l1), mostrar(l2), mostrar(l3);
	
	return 0;
}
