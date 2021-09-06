#include "persona_asignatura.hpp"

void Persona_Asignatura::asocia(Persona& p, Asignatura& a, Clase& c)
{
	directa[&p].insert(std::make_pair(&a, &c));
	inversa[&a].insert(std::make_pair(&p, &c));
}

void Persona_Asignatura::asocia(Asignatura& a, Persona& p, Clase& c)
{
	asocia(p, a, c);
}

Persona_Asignatura::Docencia Persona_Asignatura::asociados(Persona& p) const
{
	std::map<Persona*, Docencia>::const_iterator i = directa.find(&p);

	if (i != directa.end())
		return i->second;
	else
		return Docencia();
}

Persona_Asignatura::Profesorado Persona_Asignatura::asociados(Asignatura& a) const
{
	std::map<Asignatura*, Profesorado>::const_iterator i = inversa.find(&a);

	if (i != inversa.end())
		return i->second;
	else
		return Profesorado();
}