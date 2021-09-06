#include <map>
#include <set>
#include "persona.hpp"
#include "asignatura.hpp"

/*
Implementación Completa map-set
*/
class PersonaImparteAsignatura
{
	public:
		void asocia(Persona& p, Asignatura& a);
		void asocia(Asignatura& a, Persona& p);
		std::set<Asignatura*> asociados(Persona& x) const;
		std::set<Persona*> asociados(Asignatura& y) const;
		//void mostrarPersonas(Asignatura& a) const;
		//void mostrarAsignaturas(Persona& p) const;

	private:
		std::map<Persona*, std::set<Asignatura*> > directa;
		std::map<Asignatura*, std::set<Persona*> > inversa;
};
/*
Fin Implementación Completa map-set
*/