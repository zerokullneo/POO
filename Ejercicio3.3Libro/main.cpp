#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Introducir n: " << endl;
    cin >> n;

    //for (size_t i = n; i >= 0; --i)
    for (int i = n; i >= 0; i--)
        cout << i << endl;
    return 0;
}
