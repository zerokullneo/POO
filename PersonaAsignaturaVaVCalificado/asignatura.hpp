#ifndef ASIGNATURA_HPP_
#define ASIGNATURA_HPP_

#include <string>
#include <set>

class Persona;

class Asignatura
{
    public:
        typedef std::set<Persona*> Personas;
        Asignatura(std::string codigo, std::string nombre, std::string area);

        std::string codigo() const;
        std::string nombre() const;
        void mostrar() const;
        void impartida(Persona& persona);
        const Personas& impartida() const;
        void mostrarPersonas() const;
    
    private:
        std::string codigo_;
        std::string nombre_;
        std::string area_;
        Personas personas_;
};
#endif //ASIGNATURA_HPP_