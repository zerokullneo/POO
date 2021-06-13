#include "persona.hpp"
#include "asignatura.hpp"
#include <iostream>

int main()
{
    Persona genaro("Genaro", "Lopez Sanchez", "C/ Chile 1");
    Persona maria("Maria", "De La O", "Plaza España 10");
    Asignatura mtp("Metodologia y Tecnologia de la Programacion.", "Lenguajes y Sistemas Informaticos");
    Asignatura etc("Estructura y Tecnogía de Computadores.", "Ingeniería Automática y Redes de Computadores");

    genaro.mostrar(); genaro.mostrarAsignaturas();
    
    std::cout << std::endl << "---------------------------------------------" << std::endl;
    
    // Genaro imparte MTP
    genaro.imparte(mtp);
    maria.imparte(mtp);
    maria.imparte(etc);
    genaro.mostrar(); genaro.mostrarAsignaturas(); maria.mostrarAsignaturas();
    mtp.mostrar(); mtp.mostrarPersonas();

    std::cout << std::endl << "---------------------------------------------" << std::endl;

    // MTP es impartida por Genaro
    mtp.impartida(genaro);
    mtp.impartida(maria);
    mtp.mostrar(); mtp.mostrarPersonas();

    std::cout << std::endl << "---------------------------------------------" << std::endl;

   // Persona p(mtp.impartida()); p.mostrar();

    return 0;
}