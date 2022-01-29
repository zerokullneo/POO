/**
 * articulo_pedido.hpp
 *
 * mie mayo 13 18:30:35 2021
 *
 * Copyright (C) 2021 - Jose M Barba Gonzalez
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PEDIDO_ARTICULO_H
#define PEDIDO_ARTICULO_H

#include "pedido.hpp"
#include "articulo.hpp"
#include "tarjeta.hpp"

class Articulo;
class Pedido;

/*##########Clase LineaPedido##########*/
class LineaPedido
{
	public:
		/**
		 * @brief Construct a new Linea Pedido object
		 * 
		 * @param p precio de venta del articulo de la linea del pedido
		 * @param c cantidad de articulos de la linea del pedido
		 */
		explicit LineaPedido(double p,unsigned c=1);

		/*Metodos Observadores*/
		const double precio_venta() const noexcept {return precio_venta_;}
		const unsigned cantidad() const noexcept {return cantidad_;}

	private:
		double precio_venta_;
		unsigned cantidad_;
};

ostream& operator <<(ostream& out, const LineaPedido& L);

/*##########Clase OrdenaPedidos##########*/
class OrdenaPedidos
{
	public:
		bool operator()(Pedido* P1,Pedido* P2)const;
};

/*##########Clase OrdenaArticulos##########*/
class OrdenaArticulos
{
	public:
		bool operator()(Articulo* A1, Articulo* A2)const;
};

/*##########Clase Pedido_Articulo##########*/
class Pedido_Articulo
{
	public:
		typedef map<Articulo*,LineaPedido,OrdenaArticulos> ItemsPedido;
		typedef map<Pedido*,LineaPedido,OrdenaPedidos> Pedidos;

		void pedir(Pedido& pedido,Articulo& articulo,double precio, unsigned cantidad = 1);
		void pedir(Articulo& articulo,Pedido& pedido,double precio, unsigned cantidad = 1);

		ItemsPedido& detalle(Pedido& P);
		Pedidos& ventas(Articulo& A);

		void mostrarDetallePedidos(ostream& out)const;
		void mostrarVentasArticulos(ostream& out)const;

	private:
		map<Pedido*,ItemsPedido,OrdenaPedidos> Pedido_Articulo_;
		map<Articulo*,Pedidos,OrdenaArticulos> Articulo_Pedido_;
};

ostream& operator <<(ostream& out, const Pedido_Articulo::ItemsPedido& I);
ostream& operator <<(ostream& out, const Pedido_Articulo::Pedidos& P);
#endif //PEDIDO_ARTICULO_H
