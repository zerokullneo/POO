//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
// clase .h
// Definición de la clase de los atributos
// de enlace .
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
#include <string>

class Clase
{
	public:
		const int horasAsignatura() const { return horas;}
		const std::string aulaAsignatura() const { return aula;}
	private:
		int horas;
		std::string aula;
};