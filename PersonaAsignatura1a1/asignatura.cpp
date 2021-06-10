#include "persona.hpp"
#include "asignatura.hpp"
#include <iostream>
#include <string>

using namespace std;

Asignatura::Asignatura(string nombre, string area): nombre_(nombre), area_(area), persona_(nullptr)
{}

//muestra los datos de una Asignatura
void Asignatura::mostrar() const
{
    cout << endl << "Asignatura: " << nombre_ << "\n\tÁrea: " << area_ << endl;
}

//Asociación: una Asignatura es impartida por una persona.
void Asignatura::impartida(Persona& persona)
{
    this->persona_ = &persona;
}

//Devuelve la persona que imparte una asignatura
Persona& Asignatura::impartida() const
{
    return *persona_;
}

//Muestra la persona que imparte una asignatura
void Asignatura::mostrarPersona() const
{
    if(not persona_)
        cout << nombre_ << ", No es impartida por ninguna persona, no tiene asociación." << endl;
    else
    {
        cout << nombre_ << " es impartida por: " << "\t";
        persona_->mostrar();
    }
}