#include "LineaPedido.hpp"
#include <utility>

void LineaPedido::asocia(Articulo& A, Pedido& P)
{
	map<unsigned int, Pedido*> NP;
	map<string, Articulo*> NA;

	NP.insert(make_pair(P.NumeroPedido(), &P));
	NA.insert(make_pair(A.Referencia(), &A));
	
	ArticuloPedido_.insert(make_pair(&A, NP));
	PedidoArticulo_.insert(make_pair(&P, NA));
}

void LineaPedido::asocia(Pedido& P, Articulo &A)
{
	asocia(A, P);
}

const map<unsigned int, Pedido*> LineaPedido::asocia(Articulo& A) const
{
	map<Articulo*, map<unsigned int, Pedido*> >::const_iterator itA = ArticuloPedido_.find(&A);
	return itA->second;
}

const map<string, Articulo*> LineaPedido::asocia(Pedido& P) const
{
	map<Pedido*, map<string, Articulo*> >::const_iterator itP = PedidoArticulo_.find(&P);
	return itP->second;
}