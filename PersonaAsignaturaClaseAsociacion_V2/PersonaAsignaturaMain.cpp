#include <iostream>
#include "persona_asignatura.hpp"
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
	Persona felisa("Felisa", "González Pérez", "C/ Bolivia s/n");
	Persona marisa("Marisa", "Gómez Jiménez", "C/ Argentina s/n");
	Asignatura mtp("MTP", "LSI");
	Asignatura ada("ADA", "LSI");
	Asignatura poo("POO", "LSI");
	PersonaImparteAsignatura d;
	d.asocia(genaro, mtp);
	d.asocia(mtp, genaro);
	d.asocia(poo, genaro);
	d.asocia(poo, felisa);

	std::cout << "Listado de asignaturas que imparte cada persona\n"
	<< "-----------------------------------------------\n";
	cout << genaro << d.asociados(genaro) << endl;
	cout << marisa << d.asociados(marisa) << endl;
	cout << felisa << d.asociados(felisa) << endl;

	cout << "Listado de personas que imparten cada asignatura\n"
	<< "------------------------------------------------\n";
	cout << mtp << d.asociados(mtp) << endl;
	cout << ada << d.asociados(ada) << endl;
	cout << poo << d.asociados(poo) << endl;
}