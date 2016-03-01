#include "Polinomio.hpp"

Polinomio::Polinomio()
{
	grado_ = 0;
	m_.insert(make_pair(grado_, 1));
}

Polinomio::Polinomio(nat gr)
{
	grado_ = gr;
	for(nat i = 0; i < gr; i++)
		m_.insert(make_pair(i,1));
}

Polinomio Polinomio::operator =(Polinomio& pol)
{
//	m_.erase(&pol);
	m_ = pol.m_;
	grado_ = pol.grado_;
	return *this;
}

Polinomio Polinomio::operator +=(Polinomio& pol)
{cout << "operador +=" << endl;
	nat i;
	Polinomio::Monomios::iterator it, itt;
	for(i = 0, it = m_.begin(), itt = pol.m_.begin(); i < grado_; itt++, it++, i++)
		m_[i]=(*it).second + (*itt).second;
	return *this;
}

Polinomio Polinomio::operator +(Polinomio& pol)
{cout << "operador +" << endl;
	*this += pol;
	return *this;
}

Polinomio::~Polinomio()
{
}

