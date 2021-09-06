#include <map>
#include "persona.hpp"
#include "asignatura.hpp"
#include "clase.hpp"

class Persona_Asignatura
{
	public:
		typedef std::map<Asignatura*, Clase*> Docencia;
		typedef std::map<Persona*, Clase*> Profesorado;
		void asocia(Persona& p, Asignatura& a, Clase& c);
		void asocia(Asignatura& a, Persona& p, Clase& c);
		Docencia asociados(Persona& x) const;
		Profesorado asociados(Asignatura& y) const;

	private:
		std::map<Persona*, Docencia> directa;
		std::map<Asignatura*, Profesorado> inversa;
};