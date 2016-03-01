#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <iostream>
#include <map>

using namespace std;


class Polinomio
{
	public:
		typedef int nat;
		typedef map<nat,double> Monomios;
		//Constructores.
		Polinomio();
		Polinomio(nat gr);

		//Observadores.
		nat ver_grado()const {return grado_;}
		Monomios ver_polinomio() const {return m_;}

		//Sobrecarga de operadores.
		Polinomio operator =(Polinomio& pol);
		Polinomio operator +=(Polinomio& pol);
		Polinomio operator +(Polinomio& pol);
		~Polinomio();

	private:
		Monomios m_;
		nat grado_;
};

#endif // POLINOMIO_HPP
