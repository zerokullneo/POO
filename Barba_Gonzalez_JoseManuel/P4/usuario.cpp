// usuario.cpp
//
// lun abril 20 17:47:48 2015
// Copyright 2015 Jose M Barba Gonzalez
// <user@host>
//
// usuario.cpp
//
// Copyright (C) 2015 - Jose M Barba Gonzalez
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#define _XOPEN_SOURCE
#include <unistd.h>
#include "usuario.hpp"
#include "articulo.hpp"
#include "tarjeta.hpp"

/*CLASE CLAVE*/
Clave::Clave(const char* clav)
{
    /*if(strlen(clav) < 5)throw Incorrecta(CORTA);

    const char* c = crypt(clav,"./ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    clave_ = c;

    if(!clave_.length())throw Incorrecta(ERROR_CRYPT);*/
        if(strlen(clav) < 5)//clave demasiado corta
        throw Clave::Incorrecta(Clave::CORTA);
    
    static std::random_device gen; // generador de números aleatorios
    static std::uniform_int_distribution<std::size_t> dist(0, 63); // distribución uniforme de size_t entre 0 y 63
    char const caracteres[] = "./ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char salt[2] = { caracteres[dist(gen)], caracteres[dist(gen)]};
    char* cifrada = crypt(clav, salt); //Aqui se encripta la clave
    //dist(gen); dist.operator()(gen); => devuelve un número aleatorio distribuido uniformemente entre 0 y 63 usando el generador gen
    if(cifrada == nullptr) //crypt no esta implementado en mi sistema
        throw Clave::Incorrecta(Razon::ERROR_CRYPT);
    if(strlen(cifrada) < 13)//sal incorrecta, caracteres invalidos
        throw Clave::Incorrecta(Razon::ERROR_CRYPT);
    clave_ = cifrada;
}

bool Clave::verifica(const char* pass) const noexcept
{
	//pass = crypt(pass,"./ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
	pass = crypt(pass, clave_.c_str());

	if(0 == strcmp(pass, clave_.c_str()))
		return true;
	else
		return false;
}
/*FIN CLASE CLAVE*/

/*CLASE USUARIO*/
//Columna de identificadores de usuarios.
static Usuario::Usuarios id_;

Usuario::Usuario(const Cadena& id, const Cadena& nom, const Cadena& apll, const Cadena& dir, const Clave& pass):
identificador_(id), nombre_(nom), apellidos_(apll), direccion_(dir), contrasenia_(pass)
{
    //comprobamos si ese identificador de usuario ya existe.
    if(id_.insert(identificador_).second == false)
       throw Id_duplicado(id);
}

void Usuario::es_titular_de(Tarjeta& T) noexcept
{
	if(T.titular() == this)
		//insertamos el par Numero-Tarjeta en el map de tarjetas_
		tarjetas_.insert(pair<Numero,Tarjeta*>(T.tarjeta(),&T));
}

void Usuario::no_es_titular_de(Tarjeta& T) noexcept
{
    //eliminamos el par de tarjetas_ dada la tarjeta T
    tarjetas_.erase(T.tarjeta());
    //anulamos el titular de T
    T.anula_titular();
}

void Usuario::compra(Articulo& A, unsigned i) noexcept
{
    if(i == 0)//si se recibe un 0 como cantidad se vacía el carro.
        articulos_.erase(&A);
    else
    {
        //si no existe el Articulo se inserta en el par y se indica la cantidad
        if(!articulos_.insert(pair<Articulo*,unsigned>(&A,i)).second)
            articulos_[&A] = i;
    }
}

Usuario::~Usuario()
{
    //eliminación de usuario y de todas sus Tarjetas
    id_.erase(identificador_);
    for(Usuario::Tarjetas::const_iterator it=tarjetas_.begin(); it!=tarjetas_.end(); it++)
        (it->second)->anula_titular();
}

/*Inserccion en flujo*/
ostream& operator <<(ostream& out, const Usuario& u)
{
    out << u.id() << " [" << u.clave().clave() << "] " << u.nombre() << " " << u.apellidos() << endl << u.direccion() << endl << "Tarjetas:\n";

    for(Usuario::Tarjetas::const_iterator it = u.tarjetas().begin(); it != u.tarjetas().end(); it++)
        out << *((*it).second) << endl;

    return out;
}

ostream& mostrar_carro(ostream& out, const Usuario& u)
{
    out << "Carrito de compras de " << u.id() << " [Artículos: " << u.n_articulos() << "]\n";

    if(u.n_articulos() != 0)
    {
        out << " Cant. Artículo\n";
        out << "=======================================================================\n";
        for(Usuario::Articulos::const_iterator it = u.compra().begin(); it != u.compra().end(); it++)
        {
            out << (*it).second << " " << "[" << it->first->referencia() << "] \"" << it->first->titulo() << "\", " << it->first->f_publi().anno();
            out << ". " << setprecision(2) << fixed << it->first->precio() << " €" << endl;
        }
    }

    return out;
}
