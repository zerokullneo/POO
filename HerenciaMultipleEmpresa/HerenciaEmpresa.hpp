#include <iostream>
using namespace std;

class Empleado
{
	// ...
};

class Administrador: public Empleado
{
	protected:
		typedef unsigned int Nivel;
		Nivel nivel;
		// ...
};

class Director: public Administrador
{
	// ...
};

class Temporal
{
	// ...
};

class Secretaria: public Empleado
{
	// ...
};

class SecretariaTemporal: public Temporal, public Secretaria
{
	// ...
};

class Asesor: public Temporal, public Administrador
{
	// ...
};