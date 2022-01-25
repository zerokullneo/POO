#include <iostream>
using namespace std;

int main()
{
    int precio;
    cout << "Introducir precio: ";
    cin >> precio;
    cout << endl;

    if (precio > 10)
        if (precio < 30)
            cout << "Está en el rango normal.";
    else
        cout << "¿O no?";
    cout << endl;
    return 0;
}
