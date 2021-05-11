// tarjeta.cpp
//
// lun abril 20 17:37:48 2015
// Copyright 2015 Jose M Barba Gonzalez
// <user@host>
//
// tarjeta.cpp
//
// Copyright (C) 2015 - Jose M Barba Gonzalez
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

/*#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/locid.h>*/
#include "tarjeta.hpp"
#include "usuario.hpp"

/*VALIDACIÓN DEL NÚMERO DE TARJETA*/

bool luhn(const Cadena& numero/*, size_t n*/);

/*FIN VALIDACIÓN*/

/*CLASE NUMERO*/
Numero::Numero(const Cadena& n)/*: numero_(n)*/
{
	Cadena c;
	//([](unsigned char c){ return std::isspace(c); } || ::isspace) quita los espacios en blanco que encuentra
	//remove_copy_if(n.begin(), n.end(), c.begin(), EsBlanco());
	remove_if(n.begin(), n.end(), EsBlanco());
	c = n.c_str();

	if(c.length() < 13 or c.length() > 19)
		throw Incorrecto(LONGITUD);
	else
	{
		if( find_if(c.begin(), c.end(), not_fn(EsDigito())) != c.end() )
			throw Incorrecto(DIGITOS);

		if(luhn(c))
			numero_ = c;
		else
			throw Incorrecto(NO_VALIDO);
	}
}

bool operator <(const Numero& n1, const Numero& n2)
{
	if(strcmp( n1.numero_.c_str(), n2.numero_.c_str()) < 0)
		return true;
	else
		return false;
}
/*FIN CLASE NUMERO*/

/*CLASE TARJETA*/
set<Numero> Tarjeta::numeros_;

Tarjeta::Tarjeta(const Numero& tjt, Usuario& usuario, const Fecha& f_cad):
tarjeta_(tjt), titular_(&usuario), f_caducidad_(f_cad), titular_facial_((usuario.nombre() + " " + usuario.apellidos())), activa_(true)
{
    const Fecha f_hoy;
    if((f_hoy > f_cad) == true)
        throw Caducada(f_cad);
       
    pair<set<Numero>::iterator, bool> par_tjt = numeros_.insert(tarjeta_);
    
    if(!par_tjt.second)
    	throw Tarjeta::Num_duplicado(tarjeta_);

    titular_->es_titular_de(*this);
}

void Tarjeta::anula_titular() noexcept
{
	activa_ = false;
	const_cast<Usuario*&>(titular_) = nullptr;//puntero nulo sobre el titular
}

bool Tarjeta::activa(bool activa)
{
	activa_ = activa;
	return activa_;
}

Tarjeta::Tipo Tarjeta::tipo() const
{
	Tarjeta::Tipo tp;
	
	switch(tarjeta_[0])
	{
		case '3':
			switch(tarjeta_[1])
			{
				case '4':
				case '7':
					tp = Tarjeta::AmericanExpress;
					break;
				default:
					tp = Tarjeta::JCB;
					break;
			}
			break;
		case '4':
			tp = Tarjeta::VISA;
			break;
		case '5':
			tp = Tarjeta::Mastercard;
			break;
		case '6':
			tp = Tarjeta::Maestro;
			break;
		default:
			tp = Tarjeta::Otro;
			break;
	}

	return tp;
}

Tarjeta::~Tarjeta()
{
    Usuario *user = const_cast<Usuario*>(titular_);
    if(user)//se desasigna al usuario eliminado de las tarjetas.
    {
        this->anula_titular();
        user->no_es_titular_de(*this);
    }
    this->numeros_.erase(tarjeta_);
}
/*FIN CLASE TARJETA*/

/*OPERADORES*/
bool operator <(const Tarjeta& t1, const Tarjeta& t2)
{
    if(strcmp(t1.numero(), t2.numero()) < 0)
        return true;
    else
        return false;
}

bool operator ==(const Tarjeta& t1, const Tarjeta& t2)
{
    if(strcmp(t1.numero(), t2.numero()) == 0)
        return true;
    else
        return false;
}

ostream& operator <<(ostream& out, const Tarjeta& tjt)
{
	Cadena nom_{tjt.titular()->nombre()};
	//out << transform(tjt.titular()->nombre().begin(), tjt.titular()->nombre().end(), nom_.begin(), [](unsigned char c){ return toupper(c); });
	transform(nom_.begin(), nom_.end(), nom_.begin(), ::toupper);
	Cadena ape_{ tjt.titular()->apellidos()};
	transform(ape_.begin(), ape_.end(), ape_.begin(), ::toupper);
	
	out << tjt.tipo() << endl << tjt.numero() << endl;
	out << nom_ << " " << ape_ << endl;
	out << "Caduca: " << setw(2) << setfill('0') << tjt.caducidad().mes() << "/" << setw(2) << ((tjt.caducidad().anno()) % 100) << endl;

	return out;
}

ostream& operator <<(ostream& out, const Tarjeta::Tipo& tipo)
{
	switch(tipo)
	{
		case Tarjeta::VISA:
			out << "VISA" << endl;
			break;
		case Tarjeta::Mastercard:
			out << "MasterCard" << endl;
			break;
		case Tarjeta::Maestro:
			out << "Maestro" << endl;
			break;
		case Tarjeta::AmericanExpress:
			out << "AmericanExpress" << endl;
			break;
		case Tarjeta::JCB:
			out << "JCB" << endl;
			break;
		case Tarjeta::Otro:
			out << "Otro" << endl;
			break;
		default:
			out << "Error, tarjeta desconocida" << endl;
			break;
	}

	return out;
}
