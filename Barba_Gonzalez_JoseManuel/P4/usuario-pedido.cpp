/***************************************************************************
* usuario-pedido.cpp
*
* mie mayo 13 18:30:35 2020
* Copyright 2020 Jose M Barba Gonzalez
* <user@host>
****************************************************************************/
/*
* usuario-pedido.cpp
*
* Copyright (C) 2020 - Jose M Barba Gonzalez
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
#include <unistd.h>
#include "usuario-pedido.hpp"

void Usuario_Pedido::asocia(Usuario& u, Pedido& p)
{
    //asociación de usuario-pedido en ambas direcciones
	Usuario_Pedidos_[&u].insert(&p);
	Pedido_Usuario_.insert(make_pair(&p,&u));
}

void Usuario_Pedido::asocia(Pedido& p, Usuario& u)
{
	asocia(u,p);
}

Usuario_Pedido::Pedidos Usuario_Pedido::pedidos(Usuario& u)
{
	return Usuario_Pedidos_[&u];
}

Usuario* Usuario_Pedido::cliente(Pedido& p)
{
	return Pedido_Usuario_[&p];
}
