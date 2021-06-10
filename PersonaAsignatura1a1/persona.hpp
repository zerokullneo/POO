#ifndef PERSONA_HPP_
#define PERSONA_HPP_

#include <string>

class Asignatura;

class Persona
{
    public:
        Persona(std::string nombre, std::string apellidos, std::string direccion);

        void mostrar() const;
        void imparte(Asignatura& asignatura);
        Asignatura& imparte() const;
        void mostrarAsignatura() const;
    
    private:
        std::string nombre_;
        std::string apellidos_;
        std::string direccion_;
        Asignatura* asignatura_;
};
#endif //PERSONA_HPP_