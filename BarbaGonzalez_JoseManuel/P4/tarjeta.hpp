/**
 * tarjeta.hpp
 *
 * lun abril 20 17:37:48 2021
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TARJETA_H
#define TARJETA_H

#include <iomanip>
#include <cstddef>
#include <algorithm>
#include <locale>
#include <functional>
#include "usuario.hpp"
#include "cadena.hpp"
#include "fecha.hpp"

class Usuario;

class Numero
{
    public:
        //Atributo que indica la no validez del número.
        enum Razon{LONGITUD, DIGITOS, NO_VALIDO};
        //Clase de verificación de número incorrecto.
        class Incorrecto
        {
            public:
            //Constructor
            Incorrecto(const Razon r):razon_(r){};
            //Método observador
            Razon razon()const {return razon_;}
            private:
                Razon razon_;
        };

        //constructor del numero de tarjeta
        Numero(const Cadena& n);
        //operador de conversión a cadena de bajo nivel
        operator const char*()const{return numero_.c_str();}
        //comparacion de dos Numero
        friend bool operator <(const Numero&, const Numero&);

    private:
        Cadena numero_;
        struct EsBlanco
        {
            //EsBlanco(){}
            //locale loc;
            bool operator() (unsigned char c) const { return isspace(c); }
        };

        struct EsDigito
        {
            //EsDigito(){}
            bool operator() (unsigned char c) const { return isdigit(c); }
        };

};

class Tarjeta
{
    public:
        //Clase de excepcion Caducada
        class Caducada
        {
		public:
			//Constructor predeterminado
			Caducada(const Fecha& f):caducada_(f){};
			//Método observador
			const Fecha& cuando() const{return caducada_;};
		private:
			Fecha caducada_;
        };
        
        /*Clase para numero duplicado*/
        class Num_duplicado
        {
        	public:
        		Num_duplicado(const Numero& numero): numeroDuplicado_(numero){}
        		const Numero& que() const { return numeroDuplicado_;}
        	private:
        		Numero numeroDuplicado_;
        };
        
        /*Clase activa/desactiva tarjeta*/
        class Desactivada
        {
        	public:
        		Desactivada(){}
        };

        Tarjeta(const Numero& tjt, Usuario& usuario, const Fecha& f_cad);

        //Evitar la copia de una Tarjeta
        Tarjeta(const Tarjeta& tjt)=delete;
        //Evitar la asignacion de una Tarjeta
        Tarjeta& operator=(const Tarjeta& tjt)=delete;

        //Métodos observadores de los atributos de Tarjeta.
        const Numero& tarjeta() const noexcept {return tarjeta_;}
        const Numero& numero() const noexcept {return tarjeta_;}
        const Fecha& caducidad() const noexcept {return f_caducidad_;}
		const Cadena titular_facial() const noexcept {return titular_facial_;}
		const Usuario* titular() const noexcept {return titular_;}
		const bool activa() const noexcept {return activa_;}

		bool activa(bool activa = true);
		void anula_titular() noexcept;

		enum Tipo{Otro, VISA, Mastercard, Maestro, JCB, AmericanExpress};
		Tipo tipo() const;

        ~Tarjeta();

    private:
        const Numero tarjeta_;
        Usuario* const titular_;
        const Fecha f_caducidad_;
        Cadena titular_facial_;
        bool activa_;
        static set<Numero> numeros_;
};

bool operator <(const Tarjeta& t1, const Tarjeta& t2);
bool operator ==(const Tarjeta& t1, const Tarjeta& t2);
bool operator <(const Numero& n1, const Numero& n2);
ostream& operator << (ostream& out, const Tarjeta& tjt);
ostream& operator << (ostream& out, const Tarjeta::Tipo& tipo);
#endif //TARJETA_H
