//
// Created by zerokullneo on 22/1/22.
//

#include "matrix.hpp"

// Constructor: matriz definida por una función
Matrix::Matrix(size_t m, size_t n, double delta(size_t i, size_t j)):m_(m), n_(n), d_(m * n)
{
    for (size_t i = 0; i < m_; ++i)
        for (size_t j = 0; j < n_; ++j)
            (*this)(i, j) = delta(i, j);
}

// Constructor desde lista de filas de la matriz (C++11)
Matrix::Matrix(const initializer_list<valarray<double>>& l):m_(l.size()), n_(l.begin()->size()), d_(m_ * n_)
{
    auto it = l.begin();
    for (size_t i = 0; i < m_ && it != l.end(); ++i, ++it)
        (*this)[i] = *it;
}

//operador de multiplicacion
Matrix operator *(const Matrix& a, const Matrix& b)
{
    Matrix c(a.filas(), b.columnas());

    for (size_t i = 0; i < a.filas(); ++i)
        for (size_t j = 0; j < b.columnas(); ++j)
            c(i, j) = (a[i] * b(j)).sum();

    return c;
}

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