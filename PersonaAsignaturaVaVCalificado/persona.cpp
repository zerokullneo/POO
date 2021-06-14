#include "persona.hpp"
#include "asignatura.hpp"
#include <iostream>
#include <string>

using namespace std;

Persona::Persona(string nombre, string apellidos, string direccion): nombre_(nombre), apellidos_(apellidos), direccion_(direccion)
{}

//muestra los datos de una persona
void Persona::mostrar() const
{
    cout << endl << "Nombre completo: " << nombre_ << " " << apellidos_ << "\n\tDirección: " << direccion_ << endl;
}

//Asociación: una persona imparte una asignatura.
void Persona::imparte(Asignatura& asignatura)
{
    asignaturas_.insert(make_pair(asignatura.codigo(), &asignatura));
}

//Devuelve la asignatura impartida por una persona
const Persona::AsignaturasCalificadas& Persona::imparte() const
{
    return asignaturas_;
}

//Muestra la asignatura impartida por una persona
void Persona::mostrarAsignaturas() const
{
    if(asignaturas_.empty())
        cout << nombre_ << " " << apellidos_ << ", No imparte ni tiene ninguna Asignatura Asociada." << endl;
    else
    {
        cout << nombre_ << " " << apellidos_ << " imparte: " << "\t";
        for(Persona::AsignaturasCalificadas::const_iterator it = asignaturas_.begin(); it != asignaturas_.end(); ++it)
            (it->second)->mostrar();
    }
}