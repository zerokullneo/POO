#include <iostream>
using namespace std;

int combinaciones(int comb, int cant)
{
    long combTotal = 1, cantTotal = 1;
    for (int i = comb, j = cant; i > (comb-cant); --i, --j)
    {
        combTotal = combTotal * i;
        cantTotal = cantTotal * j;
    }

    return combTotal/cantTotal;
}

int main()
{
    cout << "Combinaciones Lotería: " << endl;

    cout << "Total de combinaciones: " << combinaciones(49,6) << endl;

    return 0;
}
