#include "persona.hpp"
#include "asignatura.hpp"
#include <iostream>

int main()
{
    Persona genaro("Genaro", "Lopez Sanchez", "C/ Chile 1");
    Asignatura mtp("Metodologia y Tecnologia de la Programacion.", "Lenguajes y Sistemas Informaticos");

    genaro.mostrar(); genaro.mostrarAsignatura();
    std::cout << std::endl << "---------------------------------------------" << std::endl;
    // Genaro imparte MTP
    genaro.imparte(mtp);
    genaro.mostrar(); genaro.mostrarAsignatura();
    mtp.mostrar(); mtp.mostrarPersona();

    std::cout << std::endl << "---------------------------------------------" << std::endl;

    // MTP es impartida por Genaro
    mtp.impartida(genaro);
    mtp.mostrar(); mtp.mostrarPersona();

    std::cout << std::endl << "---------------------------------------------" << std::endl;

    Persona p(mtp.impartida()); p.mostrar();

    return 0;
}