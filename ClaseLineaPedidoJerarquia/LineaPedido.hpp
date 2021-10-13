#include <iostream>
#include <string>
#include "Articulo.hpp"
#include "Pedido.hpp"

class LineaPedido: public Articulo, Pedido
{
	public:
		const double Precio_Venta() const;
		const unsigned int Cantidad() const;
		void articulo(Articulo& A);
		void pedido(Pedido& P);
		const Articulo& articulo() const;
		const Pedido& pedido() const;

	private:
		double precio_venta_;
		unsigned int cantidad_;
		Articulo* articulo_;
		Pedido* pedido_;
};