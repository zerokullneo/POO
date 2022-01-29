/**
 * fecha.hpp
 *
 * lun marzo 16 17:53:48 2021
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

class Fecha
{
	public:
		/**
		 * Límite inferior de fecha.
		 */
		static const int AnnoMaximo = 2037;
        /**
         * Límite superior de fecha.
         */
		static const int AnnoMinimo = 1902;

		/**
		 * @brief Constructor de Fecha explicito que implementa el constructor por defecto y los 3 constructores
		 * con los diferentes parámetros por defecto.
		 * @param dia parámetro que indica el dia introducido, si es 0 guarda el dia actual por defecto.
		 * @param mes parámetro que indica el mes introducido, si es 0 guarda el mes actual por defecto.
		 * @param year parámetro que indica el año introducido, si es 0 guarda el año actual por defecto.
		 */
		explicit Fecha(int dia=0, int mes=0, int year=0);

		/**
		 * @brief Constructor de conversión de Cadena a Fecha.
		 * @param string_fecha parámetro que recoge una cadena de bajo nivel.
		 */
		Fecha(const char* string_fecha);

		/**
		 * @brief operador auto incremento.
		 * @param incremento parámetro que recoge cantidad de enteros a incrementar.
		 * @return Devuelve el objeto Fecha con el incremento indicado.
		 */
		Fecha& operator += (int incremento);

        /**
         * @brief operador auto decremento.
         * @param decremento parámetro que recoge cantidad de enteros a decrementar.
         * @return Devuelve el objeto Fecha con el decremento indicado.
         */
		Fecha& operator -= (int decremento);

        /**
         * @brief operador postincrement
         * @return Devuelve el objeto Fecha con el incremento indicado.
         */
		Fecha& operator ++ ();

        /**
         * @brief operador postdecrement
         * @return Devuelve el objeto Fecha con el decremento indicado.
         */
		Fecha& operator -- ();

        /**
         * @brief operador preincrement
         * @return Devuelve el objeto Fecha con el incremento indicado.
         */
		Fecha operator ++(int);

        /**
         * @brief operador predecrement
         * @return Devuelve el objeto Fecha con el decremento indicado.
         */
		Fecha operator --(int);
		
		/**
		 * metodos modificadoras
		 */
		/**
		 * @brief método que suma un numero determinado de dias a la fecha existente.
		 * @param incmt_d cantidad de días a sumar.
		 * @return devuelve el objeto modificado con la nueva fecha.
		 */
		Fecha& sumadias(int incmt_d);

		/**
		 * @brief método que resta un numero determinado de dias a la fecha existente.
		 * @param decmt_d cantidad de días a restar.
		 * @return devuelve el objeto modificado con la nueva fecha.
		 */
		Fecha& restadias(int decmt_d);

		/**
		 * @brief método que suma un numero determinado de meses a la fecha existente.
		 * @param incmt_m cantidad de meses a sumar.
		 * @return devuelve el objeto modificado con la nueva fecha.
		 */
		Fecha& sumames(int incmt_m);

		/**
		 * @brief método que resta un numero determinado de meses a la fecha existente.
		 * @param decmt_m cantidad de meses a restar.
		 * @return devuelve el objeto modificado con la nueva fecha.
		 */
		Fecha& restames(int decmt_m);

		/**
		 * @brief método que suma un numero determinado de años a la fecha existente.
		 * @param incmt_a cantidad de años a sumar.
		 * @return devuelve el objeto modificado con la nueva fecha.
		 */
		Fecha& sumayear(int incmt_a);

		/**
		 * @brief método que resta un numero determinado de años a la fecha existente.
		 * @param decmt_a cantidad de años a restar.
		 * @return devuelve el objeto modificado con la nueva fecha.
		 */
		Fecha& restayear(int decmt_a);
		
		/**
		 * funciones observadoras
		 */
		/**
		 * @brief método que genera una cadena escrita en lenguaje natural a partir de la fecha creada del objeto.
		 * @return devuelve una cadena de bajo nivel con la fecha en texto.
		 */
		const char* cadena() const noexcept;

		/**
		 * @brief método observador que genera una cadena en formato castellano a partir de la fecha creada del objeto.
		 * @return devuelve una cadena de bajo nivel con la fecha en formato 1/1/1970.
		 */
		char* literal() const { static char cad[9]; sprintf(cad,"%d/%d/%4d",d_, m_, a_); return cad; }

		/**
		 * @brief metodo observador del atributo año a_.
		 * @return devuelve el anno del objeto creado.
		 */
		int anno() const noexcept { return a_; }

		/**
		 * @brief metodo observador del atributo mes m_.
		 * @return devuelve el mes del objeto creado.
		 */
		int mes() const noexcept { return m_; }

		/**
		 * @brief metodo observador del atributo dia d_.
		 * @return devuelve el dia del objeto creado.
		 */
		int dia() const noexcept { return d_; }

		class Invalida
		{
			public:
				Invalida(const char* t): tp_(t) {};

				const char* por_que() const { return tp_; }

			private:
				const char* tp_;
		};

	private:
        /**
         * @brief atributos de la clase d_(dia), m_(mes), a_(año);
         */
		int d_, m_, a_;
        /**
         * @brief método privado que comprueba si los datos de la fecha introducida son correctos, tanto si son
         * enteros válidos para una fecha y si están dentro de los límites de una fecha.
         * @return devuelve true si la fecha es válida y false si no es correcta.
         */
		bool comprueba_fecha();
};

/**
 * operadores sobrecargados de mas de un argumento
 */
/**
 * @brief Sobrecarga el operador Igualdad para poder comparar dos clases Fecha.
 * @param fec1 parámetro que recoge la fecha l-valor para la comparación.
 * @param fec2 parámetro que recoge la fecha r-valor para la comparación.
 * @return devuelve true si las fechas son iguales y false en caso contrario.
 */
bool operator ==(const Fecha& fec1, const Fecha& fec2);

/**
 * @brief Sobrecarga el operador Menor para poder comparar dos clases Fecha.
 * @param fec1 parámetro que recoge la fecha l-valor para la comparación.
 * @param fec2 parámetro que recoge la fecha r-valor para la comparación.
 * @return devuelve true si fec1 es menor estricto que fec2 y false en caso contrario.
 */
bool operator <(const Fecha& fec1, const Fecha& fec2);

/**
 * @brief Sobrecarga el operador Mayor para poder comparar dos clases Fecha.
 * @param fec1 parámetro que recoge la fecha l-valor para la comparación.
 * @param fec2 parámetro que recoge la fecha r-valor para la comparación.
 * @return devuelve true si fec1 es mayor estricto que fec2 y false en caso contrario.
 */
bool operator >(const Fecha& fec1, const Fecha& fec2);

/**
 * @brief Sobrecarga el operador MenorIgual para poder comparar dos clases Fecha.
 * @param fec1 parámetro que recoge la fecha l-valor para la comparación.
 * @param fec2 parámetro que recoge la fecha r-valor para la comparación.
 * @return devuelve true si fec1 es menor o igual que fec2 y false en caso contrario.
 */
bool operator <=(const Fecha& fec1, const Fecha& fec2);

/**
 * @brief Sobrecarga el operador MayorIgual para poder comparar dos clases Fecha.
 * @param fec1 parámetro que recoge la fecha l-valor para la comparación.
 * @param fec2 parámetro que recoge la fecha r-valor para la comparación.
 * @return devuelve true si fec1 es mayor o igual que fec2 y false en caso contrario.
 */
bool operator >=(const Fecha& fec1, const Fecha& fec2);

/**
 * @brief Sobrecarga el operador Distinto para poder comparar dos clases Fecha.
 * @param fec1 parámetro que recoge la fecha l-valor para la comparación.
 * @param fec2 parámetro que recoge la fecha r-valor para la comparación.
 * @return devuelve true si fec1 es distinta a fec2 y false en caso contrario.
 */
bool operator !=(const Fecha& fec1, const Fecha& fec2);

/**
 * @brief Sobrecarga el operador suma para poder sumar dias a una clase Fecha indistintamente al orden de llamada
 * de los parámetros.
 * @param incremento parámetro que recoge el l-valor para la suma.
 * @param fec parámetro que recoge el r-valor para la suma.
 * @return devuelve el objeto fecha con el incremento dado.
 */
Fecha operator + (int incremento, const Fecha& fec);

/**
 * @brief Sobrecarga el operador suma para poder sumar dias a una clase Fecha indistintamente al orden de llamada
 * de los parámetros.
 * @param fec parámetro que recoge el l-valor para la suma.
 * @param incremento parámetro que recoge el r-valor para la suma.
 * @return devuelve el objeto fecha con el incremento dado.
 */
Fecha operator + (const Fecha& fec, int incremento);

/**
 * @brief Sobrecarga el operador resta para poder restar dias a una clase Fecha indistintamente al orden de llamada
 * de los parámetros.
 * @param decremento parámetro que recoge el l-valor para la suma.
 * @param fec parámetro que recoge el r-valor para la suma.
 * @return devuelve el objeto fecha con el decremento dado.
 */
Fecha operator - (int decremento, const Fecha& fec);

/**
 * @brief Sobrecarga el operador resta para poder restar dias a una clase Fecha indistintamente al orden de llamada
 * de los parámetros.
 * @param fec parámetro que recoge el l-valor para la suma.
 * @param decremento parámetro que recoge el r-valor para la suma.
 * @return devuelve el objeto fecha con el decremento dado.
 */
Fecha operator - (const Fecha& fec, int decremento);

/**
 * @brief Sobrecarga el operador resta para poder restar dos clase Fecha.
 * @param f1 parámetro que recoge la fecha l-valor para la resta.
 * @param f2 parámetro que recoge la fecha r-valor para la resta.
 * @return devuelve el objeto fecha con el decremento de f2 sobre f1.
 */
long int operator - (const Fecha& f1, const Fecha& f2);

/**
 * @brief Sobrecarga el operador Flujo de Salida para que la fecha sea legible por pantalla.
 * @param os parámetro flujo de salida l-valor.
 * @param fec parámetro Fecha de entrada r-valor.
 * @return devuelve el flujo os modificado para una salida personalizada.
 */
ostream& operator <<(ostream& os, const Fecha& fec);

/**
 * @brief Sobrecarga el operador Flujo de Entrada para construir una Fecha de forma directa.
 * @param is parámetro flujo de entrada l-valor.
 * @param fec parámetro Fecha de entrada r-valor.
 * @return devuelve el flujo is de entrada para una construcción personalizada.
 */
istream& operator >>(istream& is, Fecha& fec);
#endif	/* FECHA_H_ */
