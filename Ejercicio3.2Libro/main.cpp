#include <iostream>
using namespace std;

int main()
{
    int t;
    std::cout << "Introducir temperatura: " << std::endl;
    cin >> t;

    if (22 < t and t < 25)
        cout << "Hace una temperatura agradable.";
    else
        cout << "Ese tiempo es insoportable.";
    cout << endl;
    return 0;
}
