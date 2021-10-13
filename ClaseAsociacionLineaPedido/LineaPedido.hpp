#include <iostream>
#include <map>
#include <string>
#include "Articulo.hpp"
#include "Pedido.hpp"

using namespace std;

class LineaPedido
{
	public:
		const double Precio_Venta() const;
		const unsigned int Cantidad() const;
		void asocia(Articulo& A, Pedido& P);
		void asocia(Pedido& P, Articulo& A);
		const map<unsigned int, Pedido*> asocia(Articulo& A) const;
		const map<string, Articulo*> asocia(Pedido& P) const;

	private:
		double precio_venta_;
		unsigned int cantidad_;
		typedef map<Articulo*, map<unsigned int, Pedido*> > AP;
		typedef map<Pedido*, map<string, Articulo*> > PA;
		AP ArticuloPedido_;
		PA PedidoArticulo_;
};