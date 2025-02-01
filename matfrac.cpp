#include "fraccion.hpp"
#include "matfrac.hpp"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

// Construye una matriz de fracciones con n renglones y m columnas
matfrac::matfrac(int n, int m)
{
    this->n = n;
    this->m = m;
}

// Construye una matriz de fracciones leyendo sus datos iniciales de un archivo
matfrac::matfrac(std::string amf) {

    std::ifstream mf(amf);

    if (mf)
    {
        std::string nxm;
        std::getline(mf, nxm);

        //Extrayendo las dimensiones
        std::stringstream check1(nxm);
        std::string n;
        std::string m;
        std::getline(check1, n, 'x');
        std::getline(check1, m, 'x');

        this->n = stoi(n);
        this->m = stoi(m);

        // Leyendo renglon por renglon
        int i=0;
        while (mf)
        {
            std::string r;
            std::getline(mf, r);

            // Extrayendo fraccion x fraccion        
            std::stringstream check1(r);
            std::string f;

            int j=0;
            while(getline(check1, f, ' '))
            {
                // Extrayendo numerador y denominador
                std::stringstream check1(f);
                std::string n;
                std::string d;
                std::getline(check1, n, '/');
                std::getline(check1, d, '/');

                a[i][j]=fraccion(stoi(n),stoi(d));

                j++;
            }
            i++;
        }
        mf.close();
    }
    else
    {
        std::cerr << "Archivo de matriz no encontrado para lectura\n";
        std::cerr << "Asignando matriz de 2x2 de 0s por default\n";
        this->n = 2;
        this->m = 2;
    }
}


// Almacena una fracción f en el renglón r y columna c
void matfrac::setA(int r, int c, fraccion f)
{
     a[r][c] = f;
}

// Consulta la fracción en el renglón r y la columna c
fraccion matfrac::getA(int r, int c)
{
     return a[r][c];
}

// Consulta el número de renglones de la matriz de fracciones
int matfrac::getn()
{
    return n;
}

// Consulta el número de columnas de la matriz de fracciones
int matfrac::getm()
{
    return m;
}

// Suma la matriz de fracciones m2 a la  matriz actual
matfrac matfrac::suma(matfrac m2)
{
     matfrac ms(n,m);
     for (auto i=0; i< n; i++)
     {
         for (auto j=0; j < m; j++)
         {
             fraccion f1{this->getA(i, j)}, f2{m2.getA(i, j)};
             fraccion fs;

             fs=f1.suma(f2);

             ms.setA(i, j, fs);
         }
     }  
     return ms;
}

// Compara la matriz de fracciones actual con la matriz de fracciones mf
bool matfrac::igualA(matfrac mf)
{
     bool iguales=true;

     if (igualDimensionA(mf))
     {
     for (auto i=0; i<n; i++)
     {
         for (auto j=0; j<m; j++)
         {
             if (!this->getA(i, j).igualA(mf.getA(i, j)))
             {
                 iguales=false;
                 break;
             }
         }
     }
     }
     else {
        iguales = false;
     }

     return iguales;
}

// Compara las dimensiones de la matriz actual con la matriz mf
bool matfrac::igualDimensionA(matfrac mf)
{
    return n == mf.getn() && m == mf.getm();
}

// Muestra en consola la matriz actual
void matfrac::imprime()
{
    std::cout << n << "x" << m << "\n";
    for (auto i=0; i<n;i++)
    {
        for(auto j=0; j<m; j++) 
        {
            a[i][j].imprime();
            std::cout << " ";
        };
        std::cout << "\n";
    }
}
