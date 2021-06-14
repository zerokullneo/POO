#include "persona.hpp"
#include "asignatura.hpp"
#include <iostream>

int main()
{
    Persona genaro("Genáro", "López Sánchez", "C/ Chile 1");
    Persona maria("María", "De La O", "Plaza España 10");
    Asignatura mtp("12714011", "Metodología y Tecnología de la Programación.", "Lenguajes y Sistemas Informáticos");
    Asignatura etc("12714021", "Estructura y Tecnogía de Computadores.", "Ingeniería Automática y Redes de Computadores");

    genaro.mostrar(); genaro.mostrarAsignaturas();
    
    std::cout << std::endl << "---------------------------------------------" << std::endl;
    
    // Genaro imparte MTP
    genaro.imparte(mtp);
    //Maria imparte MTP y ETC
    maria.imparte(mtp);
    maria.imparte(etc);
    //Mostrar
    genaro.mostrar(); genaro.mostrarAsignaturas();
    maria.mostrar(); maria.mostrarAsignaturas();

    std::cout << std::endl << "---------------------------------------------" << std::endl;

    mtp.mostrar(); mtp.mostrarPersonas();

    std::cout << std::endl << "---------------------------------------------" << std::endl;

    // MTP es impartida por Genaro y Maria
    mtp.impartida(genaro);
    mtp.impartida(maria);
    mtp.mostrar(); mtp.mostrarPersonas();

    std::cout << std::endl << "---------------------------------------------" << std::endl;
 
    //ETC es impartida por Maria
    etc.impartida(maria);
    etc.mostrar(); etc.mostrarPersonas();

    std::cout << std::endl << "---------------------------------------------" << std::endl;

   // Persona p(mtp.impartida()); p.mostrar();

    return 0;
}