/**
 * cadena.hpp
 *
 * lun marzo 16 17:53:35 2021
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

#ifndef CADENA_H_
#define CADENA_H_
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stdexcept>
#include <vector>
#include <iterator>

using namespace std;

class Cadena
{
	public:
        /**
         * iterador de cadena de bajo nivel.
         */
		typedef char* iterator;
        /**
         * iterador constante de cadena de bajo nivel.
         */
		typedef const char* const_iterator;
        /**
         * iterador reverso de cadena de bajo nivel.
         */
		typedef std::reverse_iterator<iterator> reverse_iterator;
        /**
         * iterador reverso constante de cadena de bajo nivel.
         */
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		/**
		 * numero de posiciones a copiar.
		 */
        static const size_t npos = -1;

		/**
		 * Constructores
		 */
        /**
         * @brief Constructor predeterminado texto_[0]=' ';
         */
		explicit Cadena(){tamano_ = 0;texto_ = new char[1];texto_[0]='\0';}

        /**
         * @brief Constructor de conversión.
         * @param longitud parámetro longitud de la cadena.
         * @param caracter parámetro inicializador de la cadena.
         */
		Cadena(unsigned int longitud, char caracter);

        /**
         * Constructor de espacios vacíos.
         * @param tamano parámetro longitud de la cadena.
         */
		explicit Cadena(unsigned int tamano);

		/**
		 * @brief Constructor de copia de un objeto Cadena.
		 * @param frase parámetro tipo Cadena para realizar la copia.
		 */
        Cadena(const Cadena& frase);

        /**
         * @brief Constructor de movimiento de un objeto Cadena.
         * @param frase parámetro tipo Cadena para realizar el movimiento.
         */
		Cadena(Cadena&& frase);

        /**
         * @brief Constructor de copia de una cadena a bajo nivel.
         * @param texto parámetro tipo cadena de bajo nivel para realizar la copia.
         */
		Cadena(const char* texto);

        /**
         * @brief Constructor de una sub-cadena de bajo nivel char*.
         * @param texto parámetro cadena de bajo nivel.
         * @param n parámetro que indica la cantidad de caracteres a copiar.
         */
		Cadena(const char* texto, size_t n);

        /**
         * @brief Constructor de una sub-cadena desde una posición sobre un objeto Cadena.
         * @param frase parámetro tipo Cadena para realizar la copia.
         * @param pos parámetro que indica la posición inicial de la copia.
         * @param n parámetro que indica la cantidad de caracteres a copiar.
         */
		Cadena(const Cadena& frase, unsigned int pos, size_t n);

        /**
         * @brief Constructor de uns sub-cadena de un objeto Cadena de un tamaño determinado.
         * @param frase parámetro tipo Cadena para realizar la copia.
         * @param pos parámetro que indica la posición inicial de la copia.
         */
		Cadena(const Cadena& frase, unsigned int pos);

		/**
		 * operadores sobrecargados
		 */
        /**
         * @brief operador sobrecargado para la concatenación de Cadenas.
         * @param frase parámetro tipo Cadena a añadir.
         * @return devuelve el objeto cadena con la concatenación de la Cadena recibida.
         */
		Cadena& operator +=(const Cadena& frase) noexcept;

        /**
         * @brief operador sobrecargada para la asignación por conversión de cadena de bajo nivel a Cadena.
         * @param texto parámetro de cadena de bajo nivel a asignar.
         * @return devuelve una Cadena construida por asignación.
         */
		Cadena& operator =(const char* texto) noexcept;

		/**
		 * @brief operador sobrecargado para la asignación de copia de Cadena.
		 * @param frase parámetro tipo Cadena a asignar.
		 * @return devuelve una Cadena construida por asignación.
		 */
		Cadena& operator =(const Cadena& frase) noexcept;

		/**
		 * @brief operador sobrecargado para la asignación de movimiento de Cadena.
         * @param frase parámetro tipo Cadena a mover.
         * @return devuelve una Cadena construida por asignación.
         */
		Cadena& operator =(Cadena&& frase) noexcept;

        /**
         * @brief operador [] sobrecargado para la extracción de una posición determinada.
         * @param i parámetro que indica la posición a extraer.
         * @return devuelve la dirección de la posición.
         */
		char& operator[](unsigned int i) noexcept;

        /**
         * @brief operador [] sobrecargado para la extracción del contenida de una posición determinada.
         * @param i parámetro que indica la posición a extraer.
         * @return devuelve el contenido de la posición.
         */
		char operator[](unsigned int i) const noexcept;

		/**
         * @brief Funcion que extrae una subcadena dentro de otra.
         * @param inicio parámetro que indica el indice donde comenzara a contar.
         * @param num_caracteres parámetro que indica la cantidad de caracteres a contar.
         * @return devuelve una Cadena con la subcadena extraida.
         */
		Cadena substr(size_t inicio, size_t num_caracteres) const;

        /**
         * @brief operador at sobrecargado para escribir carácter en una posición determinada.
         * @param i parámetro que indica la posición a extraer.
         * @return devuelve el contenido de la posición.
         */
		char& at(unsigned int i) const;

		/**
		 * funciones observadoras
		 */
        /**
         * @brief método observador del atributo texto_.
         * @return devuelve el atributo cadena de bajo nivel.
         */
		const char* c_str() const noexcept {return texto_;}

        /**
         * @brief recibe un objeto Cadena para verificar su longitud.
         * @param c parámetro tipo Cadena a consultar.
         * @return devuelve la longitud de la Cadena.
         */
		unsigned int length(Cadena& c)const noexcept {return c.tamano_;}

        /**
         * @brief método observador del atributo tamano_ del objeto Cadena actual.
         * @return devuelve el atributo tamano_ del objeto Cadena actual.
         */
		unsigned int length()const noexcept {return tamano_;}

		/**
		 * funciones sobre iteradores
		 */
        /**
         * @brief iterador de comienzo.
         * @return devuelve el iterador actual.
         */
		iterator begin() const noexcept;

        /**
         * @brief iterador de final.
         * @return devuelve el iterador actual.
         */
		iterator end() const noexcept;

        /**
         * @brief iterador constante de comienzo.
         * @return devuelve el iterador actual.
         */
		const_iterator cbegin() const noexcept;

        /**
         * @brief iterador constante de final.
         * @return devuelve el iterador actual.
         */
		const_iterator cend() const noexcept;

        /**
         * @brief iterador de comienzo reverso.
         * @return devuelve el iterador actual.
         */
		reverse_iterator rbegin() const noexcept;

        /**
         * @brief iterador de final reverso.
         * @return devuelve el iterador actual.
         */
		reverse_iterator rend() const noexcept;

        /**
         * @brief iterador constante de comienzo reverso.
         * @return devuelve el iterador actual.
         */
		const_reverse_iterator crbegin() const noexcept;

        /**
         * @brief iterador constante de final reverso.
         * @return devuelve el iterador actual.
         */
		const_reverse_iterator crend() const noexcept;

        /**
         * @brief Destructor de Cadena.
         */
		~Cadena(){delete [] texto_;};

	private:
        /**
         * atributo de la clase para la cadena de bajo nivel.
         */
		char* texto_;
        /**
         * atributo de la clase para el tamaño de la cadena de bajo nivel.
         */
		unsigned int tamano_;
};

/**
 * operadores sobrecargados externos de mas de un elemento
 */
/**
 * @brief Sobrecarga el operador suma para poder unir dos clase Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la concatenación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la concatenación.
 * @return devuelve el objeto Cadena con la unión de texta1 y texto2.
 */
Cadena operator+(const Cadena& texto1,const Cadena& texto2);

/**
 * @brief Sobrecarga el operador Igualdad para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es igual que texto2 y false en caso contrario.
 */
bool operator ==(const Cadena& texto1,const Cadena& texto2);

/**
 * @brief Sobrecarga el operador Distinto para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es distinto que texto2 y false en caso contrario.
 */
bool operator !=(const Cadena& texto1,const Cadena& texto2);

/**
 * @brief Sobrecarga el operador MayorIgual para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es mayor o igual que texto2 y false en caso contrario.
 */
bool operator >=(const Cadena& texto1,const Cadena& texto2);

/**
 * @brief Sobrecarga el operador Mayor para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es mayor que texto2 y false en caso contrario.
 */
bool operator >(const Cadena& texto1,const Cadena& texto2);

/**
 * @brief Sobrecarga el operador MenorIgual para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es menor o igual que texto2 y false en caso contrario.
 */
bool operator <=(const Cadena& texto1,const Cadena& texto2);

/**
 * @brief Sobrecarga el operador Menor para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es menor que texto2 y false en caso contrario.
 */
bool operator <(const Cadena& texto1,const Cadena& texto2);

/**
 * Insercción y extracción de flujo
 */
/**
 * @brief Sobrecarga el operador Flujo de Salida para que la Cadena sea legible por pantalla.
 * @param out parámetro flujo de salida l-valor.
 * @param texto parámetro Cadena de entrada r-valor.
 * @return devuelve el flujo os modificado para una salida personalizada.
 */
ostream& operator <<(ostream& out,const Cadena& texto);

/**
 * @brief Sobrecarga el operador Flujo de Entrada para construir una Cadena de forma directa.
 * @param in parámetro flujo de entrada l-valor.
 * @param texto parámetro Cadena de entrada r-valor.
 * @return devuelve el flujo is de entrada para una construcción personalizada.
 */
istream& operator >>(istream& in,Cadena& texto);

namespace std
{
    /**
     * @brief Clas paramétrica que realiza un hash de comprobación de la cadena construida.
     */
	template <> struct hash<Cadena>
	{
        /**
         * @brief operador () sobrecargado para la comprobación de la cadena.
         * @param cad parámetro Cadena a verificar.
         * @return devuelve el tamaño del hash de comprobación.
         */
		size_t operator() (const Cadena& cad) const
		{
			return hash<string>{}(cad.c_str());
		}
	};
}
#endif	/* CADENA_H_ */
