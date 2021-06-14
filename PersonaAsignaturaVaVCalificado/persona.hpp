#ifndef PERSONA_HPP_
#define PERSONA_HPP_

#include <string>
#include <map>

class Asignatura;

class Persona
{
    public:
        typedef std::map<std::string, Asignatura*> AsignaturasCalificadas;
        Persona(std::string nombre, std::string apellidos, std::string direccion);

        void mostrar() const;
        void imparte(Asignatura& asignatura);
        const AsignaturasCalificadas& imparte() const;
        void mostrarAsignaturas() const;
    
    private:
        std::string nombre_;
        std::string apellidos_;
        std::string direccion_;
        AsignaturasCalificadas asignaturas_;
};
#endif //PERSONA_HPP_