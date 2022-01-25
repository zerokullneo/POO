#include <iostream>
using namespace std;

void mostrar(int i) { cout << "Entero: " << i << endl; }
void mostrar(double d) { cout << "Doble: " << d << endl; }

int main()
{
    std::cout << "Hello, mostrar!" << std::endl;

    mostrar('A');
    mostrar(2);
    mostrar(2.2f);
    mostrar(2.2);

    return 0;
}
