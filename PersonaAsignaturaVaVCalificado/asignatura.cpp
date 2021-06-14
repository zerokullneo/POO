#include "persona.hpp"
#include "asignatura.hpp"
#include <iostream>
#include <string>

using namespace std;

Asignatura::Asignatura(string codigo, string nombre, string area): codigo_(codigo), nombre_(nombre), area_(area)
{}

//muestra los datos de una Asignatura
void Asignatura::mostrar() const
{
    cout << endl << "Asignatura: " << this->codigo() << " - " << this->nombre() << "\n\tÁrea: " << area_ << endl;
}

//Devuelve el código de la Asignatura
std::string Asignatura::codigo() const
{
    return codigo_;
}

//Devuelve el nombre de la Asignatura
std::string Asignatura::nombre() const
{
    return nombre_;
}

//Asociación: una Asignatura es impartida por una persona.
void Asignatura::impartida(Persona& persona)
{
    personas_.insert(&persona);
}

//Devuelve la persona que imparte una asignatura
const Asignatura::Personas& Asignatura::impartida() const
{
    return personas_;
}

//Muestra la persona que imparte una asignatura
void Asignatura::mostrarPersonas() const
{
    if(personas_.empty())
        cout << this->codigo() << " - " << this->nombre() << ", No es impartida por ninguna persona, no tiene asociación." << endl;
    else
    {
        cout << codigo_ << " - " << nombre_ << " es impartida por: " << "\t";
        for(Asignatura::Personas::const_iterator it = personas_.begin(); it != personas_.end(); ++it)
            (*it)->mostrar();
    }
}