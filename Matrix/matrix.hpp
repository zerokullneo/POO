//
// Created by zerokullneo on 22/1/22.
//

#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP
#include <iostream>
#include <valarray>
#include <initializer_list>

using namespace std;

class Matrix
{
    public:
        //Constructores
        explicit Matrix(size_t m = 1, size_t n = 1, double d = 0.0);
        Matrix(size_t m, size_t n, double f(size_t i, size_t j));
        Matrix(const initializer_list<valarray<double>>& l);

        //Copia y Movimiento
        Matrix(const Matrix&) = default;
        Matrix(Matrix&&) = default;
        Matrix& operator =(const Matrix&) = default;
        Matrix& operator =(Matrix&&) = default;

        //Dimension
        size_t filas() const;
        size_t columnas() const;

        //Operadores Indices
        double operator ()(size_t i, size_t j) const;
        double& operator ()(size_t i, size_t j);
        valarray<double> operator [](size_t i) const;
        valarray<double> operator ()(size_t j) const;
        slice_array<double> operator [](size_t i);
        slice_array<double> operator ()(size_t j);

        //Asignacion de valor constante
        Matrix& operator =(double y);

        //Operadores de asignacion compuesta
        Matrix& operator +=(const Matrix& a);
        Matrix& operator -=(const Matrix& a);
        Matrix& operator *=(const Matrix& a);
        Matrix& operator *=(double y);

        //Matriz opuesta
        friend Matrix operator -(const Matrix& a);
    private:
        size_t m_, n_;
        valarray<double> d_;
};
const Matrix& operator +(const Matrix& a);
//const Matrix& operator -(const Matrix& a);
Matrix operator +(const Matrix& a, const Matrix& b);
Matrix operator -(const Matrix& a, const Matrix& b);
Matrix operator *(const Matrix& a, const Matrix& b);
Matrix operator *(const Matrix& a, double k); // producto escalar
Matrix operator *(double k, const Matrix& a); // conmutativa

// Inserción de una matriz en un flujo de salida.
ostream& operator <<(ostream& fs, const Matrix& a);

//Constructor Matrix constante
inline Matrix::Matrix(size_t m, size_t n, double d):m_(m), n_(n), d_(d, m*n){}

//Dimension
inline size_t Matrix::filas() const { return m_; }
inline size_t Matrix::columnas() const{ return n_; }

//Seleccion de elementos
inline double Matrix::operator()(size_t i, size_t j) const { return d_[i * n_ + j]; }
inline double& Matrix::operator()(size_t i, size_t j) { return d_[i * n_ + j]; }

//Seleccion de fila
inline valarray<double> Matrix::operator[](size_t i) const { return d_[slice(i * n_, n_, 1)]; }
inline slice_array<double> Matrix::operator[](size_t i) { return d_[slice(i * n_, n_, 1)]; }

//Seleccion de columna
inline valarray<double> Matrix::operator()(size_t j) const { return d_[slice(j, m_, n_)]; }
inline slice_array<double> Matrix::operator()(size_t j) { return d_[slice(j, m_, n_)]; }

//Asignacion de valor constante
inline Matrix& Matrix::operator =(double y) { d_ = y; return *this; }

//Operador auto-suma
inline Matrix& Matrix::operator +=(const Matrix &a) { d_ += a.d_; return *this; }

//Operador auto-resta
inline Matrix& Matrix::operator -=(const Matrix &a) { d_ -= a.d_; return *this; }

//operador auto-multiplicacion
inline Matrix& Matrix::operator *=(const Matrix &a) { d_ *= a.d_; return *this; }
inline Matrix& Matrix::operator *=(double y) { d_ *= y; return *this; }

//operadores de signo
inline const Matrix& operator +(const Matrix& a) { return a; }
inline Matrix operator -(const Matrix& a) { Matrix c(a); c.d_ = -c.d_; return c; }

//operador de suma y resta
inline Matrix operator +(const Matrix& a, const Matrix& b) { return Matrix(a) += b; }
inline Matrix operator -(const Matrix& a, const Matrix& b) { return Matrix(a) -= b; }

//operadores de producto por escalar
inline Matrix operator *(const Matrix& a, double k) { return k * a; }
inline Matrix operator *(double k, const Matrix& a) { return Matrix(a) *= k; }

// Función delta de Kronecker.
inline double delta(size_t i, size_t j){ return i == j; }

#endif //MATRIX_MATRIX_HPP
