/***************************************************************************
* fecha.h
*
* lun marzo 16 17:53:48 2021
* Copyright 2021 Jose M Barba Gonzalez
* <user@host>
****************************************************************************/
/*
* fecha.h
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

#include "cadena.hpp"

#ifndef FECHA_H_
#define FECHA_H_

#include <ctime>

class Fecha
{
	public:
		//Limites de fecha
		static const int AnnoMaximo = 2037;
		static const int AnnoMinimo = 1902;

		//Constructor de enteros con los 3 parámetros.
		explicit Fecha(int dia=0, int mes=0, int year=0);
		//Constructor de conversión de Cadena a Fecha.
		Fecha(const char* string_fecha);

		//operadores sobrecargados
		Fecha& operator += (int incremento);
		Fecha& operator -= (int decremento);
		Fecha& operator ++ ();//postincremento
		Fecha& operator -- ();//postdecremento
		Fecha operator ++(int);//preincremento
		Fecha operator --(int);//predecremento
		
		//funciones modificadoras
		Fecha& sumadias(int incmt_d);
		Fecha& restadias(int decmt_d);
		Fecha& sumames(int incmt_m);
		Fecha& restames(int decmt_m);
		Fecha& sumayear(int incmt_a);
		Fecha& restayear(int decmt_a);
		
		//funciones observadoras
		const char* cadena()const noexcept;
		char* literal()const{static char cad[1]; sprintf(cad,"%d/%d/%4d",d_, m_, a_); return cad;}
		int anno()const noexcept {return a_;}
		int mes()const noexcept {return m_;}
		int dia()const noexcept {return d_;}

		class Invalida
		{
			public:
				Invalida(const char* t): tp_(t) {};

				const char* por_que() const {return tp_;}

			private:
				const char* tp_;
		};

	private:
		int d_, m_, a_;

		bool comprueba_fecha();
};

/*operadores sobrecargados de mas de un argumento*/
//Sobrecarga el operador Igualdad para poder comparar dos clases Fecha.
bool operator ==(const Fecha& fec1, const Fecha& fec2);

//Sobrecarga el operador Menor para poder comparar dos clases Fecha.
bool operator <(const Fecha& fec1, const Fecha& fec2);

//Sobrecarga el operador Mayor para poder comparar dos clases Fecha.
bool operator >(const Fecha& fec1, const Fecha& fec2);

//Sobrecarga el operador MenorIgual para poder comparar dos clases Fecha.
bool operator <=(const Fecha& fec1, const Fecha& fec2);

//Sobrecarga el operador MayorIgual para poder comparar dos clases Fecha.
bool operator >=(const Fecha& fec1, const Fecha& fec2);

//Sobrecarga el operador Distinto para poder comparar dos clases Fecha.
bool operator !=(const Fecha& fec1, const Fecha& fec2);

//Sobrecarga el operador suma para poder sumar dias a una clase Fecha.
Fecha operator + (int incremento, const Fecha& fec);
Fecha operator + (const Fecha& fec, int incremento);

//Sobrecarga el operador suma para poder restar dias a una clase Fecha.
Fecha operator - (int decremento, const Fecha& fec);
Fecha operator - (const Fecha& fec, int decremento);

//Sobrecarga el operador suma para poder restar dos clase Fecha.
long int operator - (const Fecha& f1, const Fecha& f2);

//Sobrecarga el operador Flujo de Salida para que la fecha sea legible por pantalla.
ostream& operator <<(ostream& os, const Fecha& fec);

//Sobrecarga el operador Flujo de Entrada para construir una Fecha de forma directa.
istream& operator >>(istream& is, Fecha& fec);
#endif	/* FECHA_H_ */
