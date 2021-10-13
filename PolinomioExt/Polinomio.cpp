#include "Polinomio.hpp"
#include <utility>

Polinomio::Polinomio(int valor)
{
	Monomio m; m.first = 1; m.second = valor;
	polinomio_.insert(std::make_pair(1, m));
}