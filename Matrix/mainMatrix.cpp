#include "matrix.hpp"
//Inserción de una matriz en un flujo de salida.
ostream& operator <<(ostream& fs, const Matrix& a)
{
    for (size_t i = 0; i < a.filas(); ++i)
    {
        for (size_t j = 0; j < a.columnas(); ++j)
            fs << a(i,j) << ' ';
        fs << endl;
    }
    return fs;
}

int main()
{
    Matrix A(3, 3);
    // Matriz nula de 3 x 3
    Matrix B(3, 3, 2.0); // Matriz de 3 x 3 con todos sus elementos a 2
    Matrix C(3, 3, delta); // Matriz identidad de 3 x 3
    Matrix D = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};
    A = C;
    cout << "A =\n" << A << endl;
    B += -A;
    cout << "B =\n" << B << endl;
    C *= C += C;
    cout << "C =\n" << C << endl;
    cout << "2A + B * C =\n"
         << 2 * A + B * C << endl;
    cout << "D=\n" << D << endl;

    Matrix tD(3, 3);
    for (size_t i = 0; i < D.filas(); ++i)
        tD[i] = D(i);
    cout << "traspuesta de D = \n" << tD << endl;
    for (size_t i = 0; i < D.filas(); ++i)
        for (size_t j = 0; j < D.columnas(); ++j)
            --D(i,j);
    cout << "D=\n" << D << endl;
    D = -1.;
    cout << "D=\n" << D << endl;

    return 0;
}
