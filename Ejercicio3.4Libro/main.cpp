#include <iostream>

int main()
{
    int n = 0, num = 0, d = -1;

    do {
        num += n;
        d++;

        std::cout << "Introducir numero, 0 para terminar: " << std::endl;
        std::cin >> n;
    } while (n != 0);

    std::cout << "Media aritmética: " << num/d << std::endl;
    return 0;
}
