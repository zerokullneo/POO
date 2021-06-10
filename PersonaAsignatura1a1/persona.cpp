#include "persona.hpp"
#include "asignatura.hpp"
#include <iostream>
#include <string>

using namespace std;

Persona::Persona(string nombre, string apellidos, string direccion): nombre_(nombre), apellidos_(apellidos), direccion_(direccion), asignatura_(nullptr)
{}

//muestra los datos de una persona
void Persona::mostrar() const
{
    cout << endl << "Nombre completo: " << nombre_ << " " << apellidos_ << "\n\tDirección: " << direccion_ << endl;
}

//Asociación: una persona imparte una asignatura.
void Persona::imparte(Asignatura& asignatura)
{
    this->asignatura_ = &asignatura;
}

//Devuelve la asignatura impartida por una persona
Asignatura& Persona::imparte() const
{
    return *asignatura_;
}

//Muestra la asignatura impartida por una persona
void Persona::mostrarAsignatura() const
{
    if(not asignatura_)
        cout << nombre_ << " " << apellidos_ << ", No imparte ni tiene ninguna Asignatura Asociada." << endl;
    else
    {
        cout << nombre_ << " " << apellidos_ << " imparte: " << "\t";
        asignatura_->mostrar();
    }
}