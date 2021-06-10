#ifndef ASIGNATURA_HPP_
#define ASIGNATURA_HPP_

#include <string>

class Persona;

class Asignatura
{
    public:
        Asignatura(std::string nombre, std::string area);

        void mostrar() const;
        void impartida(Persona& persona);
        Persona& impartida() const;
        void mostrarPersona() const;
    
    private:
        std::string nombre_;
        std::string area_;
        Persona* persona_;
};
#endif //ASIGNATURA_HPP_