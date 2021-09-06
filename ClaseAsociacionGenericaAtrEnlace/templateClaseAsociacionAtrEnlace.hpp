#include <map>
using std::map;
using std::make_pair;

/*
 * X e Y: clases asociadas
 * Z: clase de los atributos de enlace
*/
template <typename X, typename Y, typename Z>
class AsociacionBidireccional
{
	public:
		void asocia(X& x, Y& y, Z& z);
		void asocia(Y& y, X& x, Z& z);
		map<Y*, Z*> asociados(X& x) const;
		map<X*, Z*> asociados(Y& y) const;
	private:
		map<X*, map<Y*, Z*> > directa;
		map<Y*, map<X*, Z*> > inversa;
};

// Asocia bidireccionalmente dos objetos .
template <typename X, typename Y, typename Z>
void AsociacionBidireccional<X, Y, Z>::asocia(X& x, Y& y, Z& z)
{
	directa[&x].insert(make_pair(&y, &z));
	inversa[&y].insert(make_pair(&y, &z));
}

template <typename X, typename Y, typename Z> inline
void AsociacionBidireccional<X, Y, Z>::asocia(Y& y, X& x, Z& z)
{
	asocia(x, y, z);
}

// Devuelve el conjunto de enlaces asociados a un objeto .
template <typename X, typename Y, typename Z>
map<Y*,Z*> AsociacionBidireccional<X, Y, Z>::asociados(X& x) const
{
	typedef typename map<X*, map<Y*, Z*> >::const_iterator it;
	it i = directa.find(&x);

	if (i != directa.end())
		return i->second;
	else
		return map<Y*, Z*>();
}

template <typename X, typename Y, typename Z>
map<X*,Z*> AsociacionBidireccional<X, Y, Z>::asociados(Y& y) const
{
	typedef typename map<Y*, map<X*, Z*> >::const_iterator it;
	it i = inversa.find(&y);

	if (i != inversa.end())
		return i->second;
	else
		return map<X*, Z*>();
}