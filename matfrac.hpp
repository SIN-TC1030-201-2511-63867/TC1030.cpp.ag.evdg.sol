#pragma once
#include <iostream>
#include "fraccion.hpp"

#define MAX_ROW 10
#define MAX_COL 10

class matfrac {
private:
    int n,m;
    fraccion a[MAX_ROW][MAX_COL];
public:
    matfrac(int, int);
    matfrac(std::string);

    void setA(int, int, fraccion);
    int getn();
    int getm();

    fraccion getA(int, int);

    matfrac suma(matfrac);

    bool igualA(matfrac);
    bool igualDimensionA(matfrac);

    void imprime();
};