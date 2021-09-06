#include <iostream>
#include "templateClaseAsociacion.hpp"
using namespace std;

template <typename T>
ostream& operator <<(ostream& fs, const set<T*>& c)
{
	typename set<T*>::const_iterator i;

	for (i = c.begin(); i != c.end(); ++i)
		fs << **i;

	return fs;
}

ostream& operator <<(ostream& fs, const Persona& p)
{
	p.mostrar();
	return fs;
}

ostream& operator <<(ostream& fs, const Asignatura& a)
{
	a.mostrar();
	return fs;
}

int main()
{
	Persona genaro("Genaro", "López Sánchez", "C/ Chile s/n");
	Persona marisa("Marisa", "Gómez Jiménez", "C/ Argentina s/n");
	Asignatura mtp("MTP", "LSI");
	Asignatura poo("POO", "LSI");

	AsociacionBidireccional<Persona, Asignatura> imparte;
	imparte.asocia(genaro, mtp);
	imparte.asocia(poo, genaro);
	imparte.asocia(poo, marisa);

	cout << "Listado de asignaturas que imparte cada persona\n"
	<< "-----------------------------------------------\n";
	cout << genaro << imparte.asociados(genaro) << endl;
	cout << marisa << imparte.asociados(marisa) << endl;

	cout << "Listado de personas que imparten cada asignatura\n"
	<< "------------------------------------------------\n";
	cout << mtp << imparte.asociados(mtp) << endl;
	cout << poo << imparte.asociados(poo) << endl;
}