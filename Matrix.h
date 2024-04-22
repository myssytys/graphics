#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h";

class Matrix {

    public:
    Vector va;
    Vector vb;
    Vector vc;
    float M[12];
    float iM[12];
       // Default constructor
    Matrix();
    Matrix(float m11, float m21, float m31, float m41,
            float m12, float m22, float m32, float m42,
            float m13, float m23, float m33, float m43);
    // Matrix init with 3 vectors
    Matrix(const Vector &A, const Vector &B, const Vector &C);
    Matrix operator+(const Matrix &A);
    Matrix operator-(const Matrix &A);
    Matrix operator/(const Matrix &A);
    Matrix operator*(const Matrix& A);
    Matrix& operator=(const Matrix &A);

    // Deconstructor
    ~Matrix();
};

#endif