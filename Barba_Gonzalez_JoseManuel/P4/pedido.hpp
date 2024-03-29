/**
 * pedido.hpp
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

#ifndef PEDIDO_H
#define PEDIDO_H

#include "fecha.hpp"
#include "cadena.hpp"
#include "usuario.hpp"
#include "tarjeta.hpp"
#include "articulo.hpp"

class Tarjeta;
class Usuario;
class Articulo;
class Pedido_Articulo;
class Usuario_Pedido;

class Pedido
{
	public:
		// Excepcion no hay articulos en el carro
		class Vacio
		{
			public:
				Vacio(const Usuario& u):u(&u){}
				const Usuario& usuario() const noexcept {return *u;}
			private:
				const Usuario* u;
		};

		//Excepcion tarjeta de pago y tarjeta de usuario no coinciden
		class Impostor
		{
			public:
				Impostor(const Usuario& u):u(&u){}
				const Usuario& usuario() const noexcept {return *u;}
			private:
				const Usuario* u;
		};

		//Excepcion Articulo sin stock
		class SinStock
		{
			public:
				SinStock(const Articulo& a):a(&a){}
				const Articulo& articulo() const noexcept {return *a;}
			private:
				const Articulo* a;
		};

		//Constructor
		Pedido(Usuario_Pedido& U_P,Pedido_Articulo& P_A,Usuario& U, const Tarjeta& T, const Fecha& F=Fecha());

		//Metodos Observadores
		static int n_total_pedidos(){return N_pedidos;}
		//El numero del pedido
		const int numero() const noexcept {return num_;}
		//Tarjeta de pago del pedido
		const Tarjeta* tarjeta() const noexcept {return tarjeta_;}
		//El precio total del pedido
		const double total() const noexcept {return total_;}
		//Fecha del pedido
		const Fecha fecha() const noexcept {return fecha_pedido_;}

		~Pedido(){};

	private:
		static int N_pedidos;
		int num_;
		double total_;
		const Tarjeta* tarjeta_;
		Fecha fecha_pedido_;
};

ostream& operator <<(ostream& out, const Pedido& P);

#endif //PEDIDO_H
