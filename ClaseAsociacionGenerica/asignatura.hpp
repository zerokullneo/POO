#ifndef ASIGNATURA_HPP_
#define ASIGNATURA_HPP_

#include <string>
#include <set>

class Persona;

class Asignatura
{
    public:
        typedef std::set<Persona*> Personas;
        Asignatura(std::string nombre, std::string area);

        void mostrar() const;
        void impartida(Persona& persona);
        const Personas& impartida() const;
        void mostrarPersonas() const;
    
    private:
        std::string nombre_;
        std::string area_;
        Personas personas_;
};
#endif //ASIGNATURA_HPP_