#include "InstrumentoMejora.hpp"
#include <vector>

int main()
{
	vector<Instrumento*> v{new Percusion("tambor"), new Percusion("triangulo"), new Instrumento("sintetizador"), new Cuerda("piano")};

	for (Instrumento* i : v)
	{
		i->tocar();
		delete i;
	}

	return 0;
}