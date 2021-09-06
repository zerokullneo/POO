#include <iostream>
#include "persona_asignatura.hpp"
using namespace std;

/*
Implementación Completa map-set
*/
void PersonaImparteAsignatura::asocia(Persona& p, Asignatura& a)
{
	directa[&p].insert(&a);
	inversa[&a].insert(&p);
}

void PersonaImparteAsignatura::asocia(Asignatura& a, Persona& p)
{
	asocia(p, a);
}

set<Asignatura*> PersonaImparteAsignatura::asociados(Persona& p) const
{
	map<Persona*, set<Asignatura*>>::const_iterator i = directa.find(&p);

	if (i != directa.end())
		return i->second;
	else
		return set<Asignatura*>();
}

set<Persona*> PersonaImparteAsignatura::asociados(Asignatura& a) const
{
	map<Asignatura*, set<Persona*>>::const_iterator i = inversa.find(&a);

	if (i != inversa.end())
		return i->second;
	else
	return set<Persona*>();
}

/*void PersonaImparteAsignatura::mostrarAsignaturas(Persona& p) const
{
	std::set<Asignatura*>::const_iterator i;

	for (i = directa[&p].begin(); i != directa[&p].end(); ++i)
		(*i)->mostrar();
}

void PersonaImparteAsignatura::mostrarPersonas(Asignatura& a) const
{
	std::set<Persona*>::const_iterator i;

	for (i = inversa[&a].begin(); i != inversa[&a].end(); ++i)
		(*i)->mostrar();
}*/
/*
Fin Implementación Completa map-set
*/