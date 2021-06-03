// articulo.cpp
//
// lun abril 20 17:52:48 2015
// Copyright 2015 Jose M Barba Gonzalez
// <user@host>
//
// articulo.cpp
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
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "articulo.hpp"

/*CLASE ARTICULO - */
Articulo::Articulo(const Autores& aut, const Cadena& refr, const Cadena& tit, const Fecha& fec, double pvp):
autores_(aut),referencia_(refr), titulo_(tit), f_publi_(fec), precio_(pvp)
{
	if(autores_.empty())//excepción en caso que no se hayan asignado autores_
		throw Autores_vacios();
}
/*FIN CLASE ARTICULO*/

/*CLASE ARTICULOALMACENABLE - */
ArticuloAlmacenable::ArticuloAlmacenable(const Autores& a,const Cadena& r,const Cadena& t,const Fecha& f,double p,unsigned int s):Articulo(a,r,t,f,p),stock_(s)
{
}
/*FIN CLASE ARTICULOALMACENABLE*/

/*CLASE LIBRODIGITAL - */
LibroDigital::LibroDigital(const Autores& a,const Cadena& r,const Cadena& t,const Fecha& f,double p,const Fecha& e):Articulo(a,r,t,f,p),expiracion_(e)
{
}

void LibroDigital::impresion_especifica(ostream& out) const
{
	out << "A la venta hasta el " << f_expir() << ".";
}
/*FIN CLASE LIBRODIGITAL*/

/*CLASE LIBRO - */
Libro::Libro(const Autores& a,const Cadena& r,const Cadena& t,const Fecha& f,double p,unsigned int pg,unsigned int s):ArticuloAlmacenable(a,r,t,f,p,s),paginas_(pg)
{
}

void Libro::impresion_especifica(ostream& out) const
{
	out << paginas_ << " págs., " << stock() << " unidades.";
}
/*FIN CLASE LIBRO*/

/*CLASE CEDERRON - */
Cederron::Cederron(const Autores& a, const Cadena& r,const Cadena& t,const Fecha& f,double p,unsigned tm,unsigned int s):ArticuloAlmacenable(a,r,t,f,p,s),tamano_(tm)
{
}

void Cederron::impresion_especifica(ostream& out) const
{
	out << tam() << " MB, " << stock() << " unidades.";
}
/*FIN CLASE CEDERRON*/

/* Operador Inserccion Externo*/
ostream& operator <<(ostream& out, const Articulo& art)
{
    Articulo::Autores::const_iterator aut = art.autores().begin();
    size_t num_aut = 1;
	out << "[" << art.referencia() << "] \"" << art.titulo() << "\", de ";
	for(;aut != art.autores().end(); ++aut)
    {
        out << (*aut)->apellidos();//muestra los apellidos de cada autor
        if(num_aut != art.autores().size() ) out << ", ";//muestra una coma por cada autor hasta uno antes del último
        num_aut++;
    }
	out << ". " << art.f_publi().anno() << ". " << setprecision(2) << fixed << art.precio() << " €";
	out << endl << "\t";
	art.impresion_especifica(out);
	return out;
}
