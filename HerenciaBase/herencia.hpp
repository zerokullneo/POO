#include <iostream>

class Base
{
    public:
        int publico;
        int ver() { return privado;}
    protected:
        int protegido;
    private:
        int privado;
};

class DerivadaPublica: public Base
{
    public:
        int ver(){ return publico; }
};

class DerivadaProtegida: public Base
{
    public:
        int ver(){ return protegido; }
};

class DerivadaPrivada: private Base
{
    public:
        int ver(){ return Base::ver();}
};