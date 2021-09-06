#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_
#include <iostream>
#include <string>
using namespace std;

class Estudiante
{
	public:
		Estudiante(string nombre, int dni): nombre(nombre), dni(dni){}
		virtual void mostrar() const { cout << "<" << nombre << ", " << dni << ">" << endl;}

	protected:
		string nombre; // nombre completo
		int dni;// DNI
};
#endif