#include <iostream>
#include "persona_asignatura.hpp"

/*int main()
{
	Persona genaro("Genaro", "López Sánchez", "C/ Chile s/n");
	Persona felisa("Felisa", "González Pérez", "C/ Bolivia s/n");
	Asignatura mtp("MTP", "LSI");
	Asignatura poo("POO", "LSI");
	PersonaImparteAsignatura d;
	d.asocia(genaro, mtp); // genaro.imparte(mtp);
	d.asocia(felisa, poo); // felisa.imparte(poo);

	std::cout << "Listado de asignaturas que imparte cada persona\n"
	<< "-----------------------------------------------\n";
	genaro.mostrar();
	d.mostrarAsignaturas(genaro);
	felisa.mostrar();
	d.mostrarAsignaturas(felisa);
}*/

int main()
{
	Persona genaro("Genaro", "LópezSánchez", "C/ Chile s/n");
	Persona felisa("Felisa", "González Pérez", "C/ Bolivia s/n");
	Persona marisa("Marisa", "Gómez Jiménez", "C/ Argentina s/n");
	Asignatura mtp("MTP", "LSI");
	Asignatura poo("POO", "LSI");
	PersonaImparteAsignatura d;
	d.asocia(genaro, mtp); // d.asocia(mtp, genaro);
	d.asocia(poo, genaro);
	d.asocia(poo, felisa);

	std::cout << "Listado de asignaturas que imparte cada persona\n"
	<< "-----------------------------------------------\n";
	genaro.mostrar(); d.mostrarAsignaturas(genaro);
	felisa.mostrar(); d.mostrarAsignaturas(felisa);
	std::cout << "Listado de personas que imparten cada asignatura\n"
	<< "------------------------------------------------\n";
	mtp.mostrar(); d.mostrarPersonas(mtp);
	poo.mostrar(); d.mostrarPersonas(poo);
}