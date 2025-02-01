#pragma once

class fraccion {
private:
    int n,d;
    void simplifica();
    int mcd();
public:
    fraccion();
    fraccion(int, int);

    int getN();
    int getD();

    void setN(int);
    void setD(int);

    fraccion suma(fraccion);
    fraccion multiplica(fraccion);

    bool igualA(fraccion);
    
    void imprime();
};