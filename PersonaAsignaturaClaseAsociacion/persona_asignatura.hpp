#include <map>
#include <set>
#include "persona.hpp"
#include "asignatura.hpp"

/*
Implementación Básica
*/
/*class PersonaImparteAsignatura
{
    public:
        void asocia(Persona& p, Asignatura& a);
        void mostrarAsignaturas(Persona& p) const;
    private:
        bool esta(Persona& p, Asignatura& a) const;
        typedef std::multimap<Persona*, Asignatura*> A;
        typedef A::const_iterator I;
        A asociacion;
};*/
/*
Fin Implementación Básica
*/

/*
Implementación Completa multimap
*/
class PersonaImparteAsignatura
{
	public:
		void asocia(Persona& p, Asignatura& a);
		void asocia(Asignatura& a, Persona& p);
		void mostrarPersonas(Asignatura& a) const;
		void mostrarAsignaturas(Persona& p) const;

	private:
		bool esta(Persona& x, Asignatura& y) const;
		typedef std::multimap<Persona*, Asignatura*> AD;
		typedef std::multimap<Asignatura*, Persona*> AI;
		typedef AD::const_iterator ID;
		typedef AI::const_iterator II;
		AD directa;
		AI inversa;
};
/*
Fin Implementación Completa multimap
*/

/*
Implementación Completa map-set
*/
/*class PersonaImparteAsignatura
{
	public:
		void asocia(Persona& p, Asignatura& a);
		void asocia(Asignatura& a, Persona& p);
		void mostrarPersonas(Asignatura& a) const;
		void mostrarAsignaturas(Persona& p) const;

	private:
		std::map<Persona*, std::set<Asignatura*> > directa;
		std::map<Asignatura*, std::set<Persona*> > inversa;
};*/
/*
Fin Implementación Completa map-set
*/