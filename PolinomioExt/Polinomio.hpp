#include <cstddef>
#include <iostream>
#include <map>
#include <utility>

class Polinomio
{
	public:
		typedef unsigned int nat;
		typedef std::pair<nat, int> Monomio;
		typedef std::map<nat, int> Monomios;

		Polinomio(){ m_.empty(); }
		Polinomio(int valor);
		nat Grado() const { return m_.size();};
	private:
		Monomios m_;
		/*typedef*/ std::map<nat, Monomio> polinomio_;
};