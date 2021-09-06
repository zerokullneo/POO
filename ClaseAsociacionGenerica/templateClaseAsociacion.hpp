#include <map>
#include <set>
#include "persona.hpp"
#include "asignatura.hpp"

// Clase genérica de asociación bidireccional

template <typename X, typename Y>
class AsociacionBidireccional
{
	public:
		void asocia(X& x, Y& y);
		void asocia(Y& y, X& x);
		std::set<Y*> asociados(X& x) const;
		std::set<X*> asociados(Y& y) const;

	private:
		std::map<X*, std::set<Y*> > directa;
		std::map<Y*, std::set<X*> > inversa;
};

// Asocia bidireccionalmente dos objetos .
template <typename X, typename Y>
void AsociacionBidireccional<X, Y>::asocia(X& x, Y& y)
{
	directa[&x].insert(&y);
	inversa[&y].insert(&x);
}

template <typename X, typename Y>
inline void AsociacionBidireccional<X, Y>::asocia(Y& y, X& x)
{ asocia(x, y); }

// Devuelve el conjunto de enlaces asociados a un objeto .
template <typename X, typename Y>
std::set<Y*> AsociacionBidireccional<X, Y>::asociados(X& x) const
{
	typename std::map<X*, std::set<Y*>>::const_iterator i = directa.find(&x);

	if (i != directa.end())
		return i->second;
	else
		return std::set<Y*>();
}

template <typename X, typename Y>
std::set<X*> AsociacionBidireccional<X, Y>::asociados(Y& y) const
{
	typename std::map<Y*, std::set<X*>>::const_iterator i = inversa.find(&y);

	if (i != inversa.end())
		return i->second;
	else
		return std::set<X*>();
}