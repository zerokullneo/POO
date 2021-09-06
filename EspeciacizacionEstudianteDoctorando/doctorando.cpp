#include "doctorando.hpp"
#include <iostream>
#include <string>
using namespace std;

Doctorando::Doctorando(string nombre, int dni, string tutor, int programa): Estudiante(nombre, dni), tutor(tutor), programa(programa) {}

void Doctorando::mostrar() const
{
	// Muestra los datos que posee como estudiante
	Estudiante::mostrar();
	// Y los específicos de su condición de doctorando
	cout << "\tPrograma de doctorado: " << programa << "\n\t" << "Tutor en el programa: " << tutor << endl;
}