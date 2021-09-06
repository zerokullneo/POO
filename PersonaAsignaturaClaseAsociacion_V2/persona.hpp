#ifndef PERSONA_HPP_
#define PERSONA_HPP_

#include <string>
#include <set>

class Asignatura;

class Persona
{
    public:
        typedef std::set<Asignatura*> Asignaturas;
        Persona(std::string nombre, std::string apellidos, std::string direccion);

        void mostrar() const;
        void imparte(Asignatura& asignatura);
        const Asignaturas& imparte() const;
        void mostrarAsignaturas() const;
    
    private:
        std::string nombre_;
        std::string apellidos_;
        std::string direccion_;
        Asignaturas asignaturas_;
};
#endif //PERSONA_HPP_