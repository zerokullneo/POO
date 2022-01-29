/**
 * cadena.cpp
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

#include <locale>
#include "cadena.hpp"

using namespace std;

/**
 * CONSTRUCTORES
 */
/**
 * @brief Constructor de conversión.
 * @param longitud parámetro longitud de la cadena.
 * @param caracter parámetro inicializador de la cadena.
 */
Cadena::Cadena(unsigned int longitud, char caracter):tamano_(longitud)
{
	texto_= new char[tamano_ + 1];

	if(texto_ == NULL)
		cerr << "Cadena: Predeterminado fallo de memoria." << endl;
	else
	{
		for(unsigned int i = 0; i < tamano_; i++)
			texto_[i]=caracter;

		texto_[tamano_] = '\0';
	}
}

/**
 * Constructor de espacios vacíos.
 * @param tamano parámetro longitud de la cadena.
 */
Cadena::Cadena(unsigned int tamano):tamano_(tamano)
{
	texto_ = new char[tamano_ + 1];

	if(texto_ == NULL)
		cerr << "Cadena: unsigned int fallo de memoria." << endl;
	else
	{
		for(unsigned int i = 0; i < tamano_; i++)
			texto_[i] = ' ';

		texto_[tamano_]='\0';
	}
}

/**
 * @brief Constructor de copia de un objeto Cadena.
 * @param frase parámetro tipo Cadena para realizar la copia.
 */
Cadena::Cadena(const Cadena& frase):tamano_(frase.length())
{
	texto_ = new char[tamano_ + 1];
	if(texto_ == NULL)
		cerr << "Cadena: Cadena& fallo de memoria." << endl;
	else
		strncpy(texto_,frase.texto_, tamano_ + 1);
}

/**
 * @brief Constructor de movimiento de un objeto Cadena.
 * @param frase parámetro tipo Cadena para realizar el movimiento.
 */
Cadena::Cadena(Cadena&& frase): texto_(frase.texto_), tamano_(frase.tamano_)
{
    frase.texto_ = new char[1];
    frase.texto_[0] = '\0';
    frase.tamano_ = 0;
}

/**
 * @brief Constructor de copia de una cadena a bajo nivel.
 * @param texto parámetro tipo cadena de bajo nivel para realizar la copia.
 */
Cadena::Cadena(const char* texto): tamano_(strlen(texto))
{
	texto_ = new char[tamano_ + 1];
	if(texto_ == NULL)
		cerr << "Cadena: const char* fallo de memoria." << endl;
	else
	    strncpy(texto_, texto, tamano_ + 1);
}

/**
 * @brief Constructor de una sub-cadena de bajo nivel char*.
 * @param texto parámetro cadena de bajo nivel.
 * @param n parámetro que indica la cantidad de caracteres a copiar.
 */
Cadena::Cadena(const char* texto, size_t n): tamano_(n)
{
    texto_= new char[tamano_ + 1];
    if(texto_ == NULL or tamano_ < 0)
        cerr << "Cadena: const char* fallo de memoria." << endl;
    else
    {
        for(unsigned int i = 0; i < tamano_; i++)
            texto_[i] = texto[i];
        texto_[tamano_] = '\0';
    }
}

/**
 * @brief Constructor de una sub-cadena desde una posición sobre un objeto Cadena.
 * @param frase parámetro tipo Cadena para realizar la copia.
 * @param pos parámetro que indica la posición inicial de la copia.
 * @param n parámetro que indica la cantidad de caracteres a copiar.
 */
Cadena::Cadena(const Cadena& frase, unsigned int pos, size_t n)
{
    frase.at(pos);
    if(n == npos)
        tamano_ = (frase.length() - pos);
    else
        tamano_ = n;

    texto_= new char[tamano_+1];
    if(texto_ == NULL or tamano_ < 0)
        cerr << "Cadena: const char* fallo de memoria." << endl;
    else
    {
        for(unsigned int i = pos; i < (pos + tamano_); i++)
            texto_[i-pos] = frase[i];
        texto_[tamano_] = '\0';
    }
}

/**
 * @brief Constructor de uns sub-cadena de un objeto Cadena de un tamaño determinado.
 * @param frase parámetro tipo Cadena para realizar la copia.
 * @param pos parámetro que indica la posición inicial de la copia.
 */
Cadena::Cadena(const Cadena& frase, unsigned int pos): tamano_(frase.length() - pos)
{
    frase.at(pos);
    texto_= new char[tamano_ + 1];
    if(texto_ == NULL or tamano_ < 0)
        cerr << "Cadena: const char* fallo de memoria." << endl;
    else
    {
        for(unsigned int i = pos; i < tamano_; i++)
            texto_[i-pos] = frase[i];
        texto_[tamano_] = '\0';
    }
}
/**
 * -------------------------FIN CONSTRUCTORES-----------------------------------
 */

/**
 * -----------------------------OPERADORES--------------------------------------
 */

/**
 * @brief operador sobrecargado para la concatenación de Cadenas.
 * @param frase parámetro tipo Cadena a añadir.
 * @return devuelve el objeto cadena con la concatenación de la Cadena recibida.
 */
Cadena& Cadena::operator +=(const Cadena& frase) noexcept
{
	char* texto_aux = new char[tamano_+1];
	strncpy(texto_aux, texto_, tamano_+1);
	tamano_ = this->tamano_ + frase.length();
	delete[] texto_;
	texto_ = new char[tamano_+1];
	strncpy(texto_, texto_aux, strlen(texto_aux)+1);
	strncat(texto_, frase.texto_,frase.length()+1);
	return *this;
}

/**
 * @brief operador sobrecargada para la asignación por conversión de cadena de bajo nivel a Cadena.
 * @param texto parámetro de cadena de bajo nivel a asignar.
 * @return devuelve una Cadena construida por asignación.
 */
Cadena& Cadena::operator =(const char* texto) noexcept
{
	tamano_ = strlen(texto);
	char* txt = new char[tamano_ + 1];
	strncpy(txt, texto, tamano_ + 1);
	delete[] texto_;
	texto_ = new char[tamano_ + 1];
	strncpy(texto_, txt, tamano_ + 1);
	return *this;
}

/**
 * @brief operador sobrecargado para la asignación de copia de Cadena.
 * @param frase parámetro tipo Cadena a asignar.
 * @return devuelve una Cadena construida por asignación.
 */
Cadena& Cadena::operator =(const Cadena& frase) noexcept
{
	tamano_ = frase.length();
	delete[] texto_;
	texto_ = new char[tamano_ + 1];
	strncpy(texto_, frase.texto_, tamano_+1);
	return *this;
}

/**
 * @brief operador sobrecargado para la asignación de movimiento de Cadena.
 * @param frase parámetro tipo Cadena a mover.
 * @return devuelve una Cadena construida por asignación.
 */
Cadena& Cadena::operator =(Cadena&& frase) noexcept
{
    tamano_ = frase.tamano_;
    texto_ = frase.texto_;
    frase.texto_ = new char[1];
    frase.texto_[0] = '\0';
    frase.tamano_ = 0;
    return *this;
}

/**
 * @brief operador [] sobrecargado para la extracción de una posición determinada.
 * @param i parámetro que indica la posición a extraer.
 * @return devuelve la dirección de la posición.
 */
char& Cadena::operator [](unsigned int i) noexcept
{
    return texto_[i];
}

/**
 * @brief operador [] sobrecargado para la extracción del contenida de una posición determinada.
 * @param i parámetro que indica la posición a extraer.
 * @return devuelve el contenido de la posición.
 */
char Cadena::operator [](unsigned int i) const noexcept
{
    return texto_[i];
}
/**
 * ------------------------------FIN OPERADORES----------------------------------
 */

/**
 * ---------------------------------SUBCADENA-------------------------------------
 */
/**
 * @brief Funcion que extrae una subcadena dentro de otra.
 * @param inicio parámetro que indica el indice donde comenzara a contar.
 * @param num_caracteres parámetro que indica la cantidad de caracteres a contar.
 * @return devuelve una Cadena con la subcadena extraida.
 */
Cadena Cadena::substr(size_t inicio, size_t num_caracteres) const /*noexcept(false)const throw(out_of_range)*/
{
	if((inicio < tamano_) /*and (num_caracteres > 0)*/ and (num_caracteres <= (tamano_ - inicio)))
	{
		Cadena subtxt(num_caracteres);
		for(size_t i = inicio, j = 0; j < num_caracteres; i++, j++)
			subtxt.texto_[j] = texto_[i];

		return subtxt;
	}

	else
		throw std::out_of_range("Error substr: caracteres fuera de rango.");
}

/**at Leer caracter
char Cadena::at(unsigned int i) noexcept(false)const throw(out_of_range)
{
    if((i >= 0 and i <= tamano_) and (tamano_ > 0))
        return texto_[i];

    else
        throw std::out_of_range("Error read at: posicion fuera de rango.");
}*/

/**
 * @brief operador at sobrecargado para escribir carácter en una posición determinada.
 * @param i parámetro que indica la posición a extraer.
 * @return devuelve el contenido de la posición.
 */
char& Cadena::at(unsigned int i) const
{
    if((i >= 0 and i <= tamano_) and (tamano_ > 0))
        return texto_[i];

    else
        throw std::out_of_range("Error write at: posicion fuera de rango.");
}
/**
 * --------------------------------FIN SUBCADENA----------------------------------------
 */

/**
 * -------------------OPERACIONES SOBRE ITERADORES--------------------------
 */
/**
 * @brief iterador de comienzo.
 * @return devuelve el iterador actual.
 */
Cadena::iterator Cadena::begin() const noexcept
{
    return &texto_[0];
}

/**
 * @brief iterador de final.
 * @return devuelve el iterador actual.
 */
Cadena::iterator Cadena::end() const noexcept
{
    return &texto_[tamano_];
}

/**
 * @brief iterador constante de comienzo.
 * @return devuelve el iterador actual.
 */
Cadena::const_iterator Cadena::cbegin() const noexcept
{
    return &texto_[0];
}

/**
 * @brief iterador constante de final.
 * @return devuelve el iterador actual.
 */
Cadena::const_iterator Cadena::cend() const noexcept
{
    return &texto_[tamano_];
}

/**
 * @brief iterador de comienzo reverso.
 * @return devuelve el iterador actual.
 */
Cadena::reverse_iterator Cadena::rbegin() const noexcept
{
    return reverse_iterator(end());
}

/**
 * @brief iterador de final reverso.
 * @return devuelve el iterador actual.
 */
Cadena::reverse_iterator Cadena::rend() const noexcept
{
    return reverse_iterator(begin());
}

/**
 * @brief iterador constante de comienzo reverso.
 * @return devuelve el iterador actual.
 */
Cadena::const_reverse_iterator Cadena::crbegin() const noexcept
{
    return const_reverse_iterator(end());
}

/**
 * @brief iterador constante de final reverso.
 * @return devuelve el iterador actual.
 */
Cadena::const_reverse_iterator Cadena::crend() const noexcept
{
    return const_reverse_iterator(begin());
}
/**
 * ------------------------FIN OPERACIONES SOBRE ITERADORES-------------------------------
 */

/**
 * ------------------------------OPERADORES EXTERNOS--------------------------------------
 */
/**
 * @brief Sobrecarga el operador suma para poder unir dos clase Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la concatenación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la concatenación.
 * @return devuelve el objeto Cadena con la unión de texta1 y texto2.
 */
Cadena operator +(const Cadena& texto1,const Cadena& texto2)
{
    Cadena frase(texto1);
    frase += texto2;
    return frase;
}

/**
 * @brief Sobrecarga el operador Igualdad para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es igual que texto2 y false en caso contrario.
 */
bool operator ==(const Cadena& texto1,const Cadena& texto2)
{
    if(strcmp(texto1.c_str(),texto2.c_str()) == 0)
        return true;
    else
        return false;
}

/**
 * @brief Sobrecarga el operador Distinto para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es distinto que texto2 y false en caso contrario.
 */
bool operator !=(const Cadena& texto1,const Cadena& texto2)
{
    if(strcmp(texto1.c_str(),texto2.c_str()) != 0)
        return true;
    else
        return false;
}

/**
 * @brief Sobrecarga el operador MayorIgual para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es mayor o igual que texto2 y false en caso contrario.
 */
bool operator >=(const Cadena& texto1,const Cadena& texto2)
{
    if(strcmp(texto1.c_str(),texto2.c_str()) >= 0)
        return true;
    else
        return false;
}

/**
 * @brief Sobrecarga el operador Mayor para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es mayor que texto2 y false en caso contrario.
 */
bool operator >(const Cadena& texto1,const Cadena& texto2)
{
    if(strcmp(texto1.c_str(),texto2.c_str()) > 0)
        return true;
    else
        return false;
}

/**
 * @brief Sobrecarga el operador MenorIgual para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es menor o igual que texto2 y false en caso contrario.
 */
bool operator <=(const Cadena& texto1,const Cadena& texto2)
{
    if(strcmp(texto1.c_str(),texto2.c_str()) <= 0)
        return true;
    else
        return false;
}

/**
 * @brief Sobrecarga el operador Menor para poder comparar dos clases Cadena.
 * @param texto1 parámetro que recoge la Cadena l-valor para la comparación.
 * @param texto2 parámetro que recoge la Cadena r-valor para la comparación.
 * @return devuelve true si texto1 es menor que texto2 y false en caso contrario.
 */
bool operator <(const Cadena& texto1,const Cadena& texto2)
{
    if(strcmp(texto1.c_str(),texto2.c_str()) < 0)
        return true;
    else
        return false;
}
/**
 * ------------------------------FIN OPERADORES EXTERNOS-----------------------------------
 */

/**
 * -------------------------------OPERADORES DE FLUJO------------------------------------
 */
/**
 * @brief Sobrecarga el operador Flujo de Salida para que la Cadena sea legible por pantalla.
 * @param out parámetro flujo de salida l-valor.
 * @param texto parámetro Cadena de entrada r-valor.
 * @return devuelve el flujo os modificado para una salida personalizada.
 */
ostream& operator <<(ostream& out,const Cadena& texto)
{
	out << texto.c_str();
	return out;
}

/**
 * @brief Sobrecarga el operador Flujo de Entrada para construir una Cadena de forma directa.
 * @param in parámetro flujo de entrada l-valor.
 * @param texto parámetro Cadena de entrada r-valor.
 * @return devuelve el flujo is de entrada para una construcción personalizada.
 */
istream& operator >>(istream& in, Cadena& texto)
{
	//calcular la longitud del stream "in"
	in.seekg(0, in.end);
	unsigned int length = in.tellg();
	in.seekg(0, in.beg);
	
	// alojar memoria de "in":
	char *buffer = new char [length + 1];
	buffer[length] = '\0';

	// leer datos como un bloque:
	while(in.get() == ' ') in.peek();//Se salta los espacios iniciales.
	in.seekg(-1, in.cur);//Coloca el puntero de "in" en el primer caracter a leer despues de saltar los espacios.
	if(length > 32)
	{
		in.get(buffer, 33);//lee la entrada hasta el siguiente espacio
		//in.seekg(0, in.cur);
		//char car = in.peek();
		//cout << "@@" << car << "@@";
		//in.peek();
	}
	else
	{
		in.getline(buffer, length + 1, ' ');//lee la entrada hasta el siguiente espacio
		in.putback(' ');//deja el puntero de "in" en el espacio
	}

//cerr << endl << "#: " << buffer << endl;

	if(strspn(buffer, " \t\r\n\v") > 0)// or buffer == '\0')
	{
		const Cadena z;
		texto = z.c_str();
		return in;
	}
	else
	{
		texto = buffer;
		return in;
	}
}
/**
 * --------------------------------FIN OPERADORES DE FLUJO-------------------------------
 */
