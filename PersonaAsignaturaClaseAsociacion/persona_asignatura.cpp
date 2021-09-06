#include <iostream>
#include "persona_asignatura.hpp"

/*
Implementación Básica
*/
/*bool PersonaImparteAsignatura::esta(Persona& p, Asignatura& a) const
{
	std::pair<I, I> rango = asociacion.equal_range(&p);

	for (I i = rango.first; i != rango.second; ++i)
		if (i->second == &a) return true;

	return false;
}

void PersonaImparteAsignatura::asocia(Persona& p, Asignatura& a)
{
	if (!esta(p, a)) asociacion.insert(std::make_pair(&p, &a));
}

void PersonaImparteAsignatura::mostrarAsignaturas(Persona& p) const
{
	std::pair<I, I> rango = asociacion.equal_range(&p);

	if (rango.first == rango.second)
		std::cout << "No imparte ninguna asignatura." << std::endl;
	else
		for (I i = rango.first; i != rango.second; ++i)

	(i->second)->mostrar();
}*/
/*
Fin Implementación Básica
*/

/*
Implementación Completa multimap
*/
bool PersonaImparteAsignatura::esta(Persona& p, Asignatura& a) const
{
	std::pair<PersonaImparteAsignatura::ID,	PersonaImparteAsignatura::ID> rango = directa.equal_range(&p);

	for (PersonaImparteAsignatura::ID i = rango.first; i != rango.second; ++i)
		if (i->second == &a) return true;

	return false;
}

void PersonaImparteAsignatura::asocia(Persona& p, Asignatura& a)
{
	if (!esta(p, a))
	{
		directa.insert(std::make_pair(&p, &a));
		inversa.insert(std::make_pair(&a, &p));
	}
}

void PersonaImparteAsignatura::asocia(Asignatura& a, Persona& p)
{
	asocia(p, a);
}

void PersonaImparteAsignatura::mostrarAsignaturas(Persona& p) const
{
	std::pair<PersonaImparteAsignatura::ID, PersonaImparteAsignatura::ID> rango = directa.equal_range(&p);

	if (rango.first == rango.second)
		std::cout << "No imparte ninguna asignatura." << std::endl;
	else
		for (PersonaImparteAsignatura::ID
			i = rango.first; i != rango.second; ++i)

	(i->second)->mostrar();
}

void PersonaImparteAsignatura::mostrarPersonas(Asignatura& a) const
{
	std::pair<PersonaImparteAsignatura::II, PersonaImparteAsignatura::II> rango = inversa.equal_range(&a);

	if (rango.first == rango.second)
		std::cout << "No es impartida por ninguna persona." << std::endl;
	else
		for (PersonaImparteAsignatura::II
			i = rango.first; i != rango.second; ++i)

	(i->second)->mostrar();
}
/*
Fin Implementación Completa multimap
*/

/*
Implementación Completa map-set
*/
/*void PersonaImparteAsignatura::asocia(Persona& p, Asignatura& a)
{
	directa[&p].insert(&a); inversa[&a].insert(&p);
}

void PersonaImparteAsignatura::asocia(Asignatura& a, Persona& p)
{
	asocia(p, a);
}

void PersonaImparteAsignatura::mostrarAsignaturas(Persona& p) const
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