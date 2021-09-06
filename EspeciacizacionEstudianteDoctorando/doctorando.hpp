#ifndef DOCTORANDO_H_
#define DOCTORANDO_H_
#include "estudiante.hpp"
#include <string>
using namespace std;

class Doctorando: public Estudiante {
	public:
		Doctorando(string nombre, int dni, string tutor, int programa);
		void mostrar() const;

	protected:
		string tutor; // tutor en el programa de doctorado
		int programa; // código del programa
};
#endif