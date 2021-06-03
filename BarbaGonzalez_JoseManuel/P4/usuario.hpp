/***************************************************************************
* usuario.h
*
* lun abril 20 17:47:48 2015
* Copyright 2015 Jose M Barba Gonzalez
* <user@host>
****************************************************************************/
/*
* usuario.h
*
* Copyright (C) 2015 - Jose M Barba Gonzalez
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef USUARIO_H
#define USUARIO_H

#include <random>
#include <set>
#include <map>
#include <unordered_map>
#include "cadena.hpp"
#include "fecha.hpp"
#include "articulo.hpp"
#include "tarjeta.hpp"

class Tarjeta;
class Numero;

class Clave
{
    public:
        //Atributo que indica la no validez de la clave.
        enum Razon{CORTA, ERROR_CRYPT};
        //Clase de verificación de clave incorrecta.
        class Incorrecta
        {
            public:
                //Constructor
                Incorrecta(Razon r):r_(r){};
                //Observadora
                Razon razon()const{return r_;}

            private:
                Razon r_;
        };

        //constructor
        Clave(const char* clav);
        //método observador
        const Cadena clave() const {return clave_;}
        //método verificador
        bool verifica(const char* pass) const noexcept;

    private:
        Cadena clave_;
};

class Usuario
{
    public:
        typedef set<Cadena> Usuarios;
        typedef map<Numero, Tarjeta*> Tarjetas;
        /*typedef map<Articulo*, unsigned> Articulos;*/
        typedef unordered_map<Articulo*, unsigned int> Articulos;

        //Clase de excepcion Id duplicado
        class Id_duplicado
        {
            public:
                //Constructor predeterminado
                Id_duplicado(Cadena id_d):idd_(id_d){};
                //Método observador
                const Cadena idd()const {return idd_;}
            private:
                Cadena idd_;
        };

        //Constructor
        Usuario(const Cadena& id, const Cadena& nom, const Cadena& apll, const Cadena& dir, const Clave& pass);

        //Evitar la copia de un objeto Usuario
        Usuario(const Usuario&)=delete;
        //Evitar la asignacion de un objeto Usuario
        Usuario& operator =(const Usuario&)=delete;

        //Métodos observadores de los atributos.
        const Cadena id()const {return identificador_;}
        const Cadena nombre()const {return nombre_;}
        const Cadena apellidos()const {return apellidos_;}
        const Cadena direccion()const {return direccion_;}
        const Clave clave()const {return contrasenia_;}
        const size_t n_articulos()const{return articulos_.size();}
        const Tarjetas& tarjetas()const{return tarjetas_;}
        const Articulos& compra()const{return articulos_;}

        //Métodos modificadores
        void es_titular_de(Tarjeta& T) noexcept;
        void no_es_titular_de(Tarjeta& T) noexcept;
        void compra(Articulo& A, unsigned i=1) noexcept;

        ~Usuario();

    private:
        Cadena identificador_;
        Cadena nombre_;
        Cadena apellidos_;
        Cadena direccion_;
        Clave contrasenia_;
        Articulos articulos_;
        Tarjetas tarjetas_;
};

std::ostream& operator << (std::ostream& out , const Usuario& u);
std::ostream& mostrar_carro (std::ostream& out , const Usuario& u);
#endif //USUARIO_H
