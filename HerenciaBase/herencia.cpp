#include "herencia.hpp"
#include <iostream>
#include <ostream>

int main()
{
    Base Bs;
    DerivadaPublica DPu;
    DerivadaProtegida DPt;
    DerivadaPrivada DPr;

    std::cout << "Entero publico:" << DPu.ver() << std::endl;

    std::cout << "Entero Protegido: " << DPt.ver() << std::endl;

    std::cout << "Entero Privado: " << DPr.ver() << std::endl;

    return 0;
}