#include "fraccion.hpp"
#include "matfrac.hpp"
#include <iostream>

int main()
{
    fraccion f{5,7};
    fraccion g{3,8};
    fraccion s;
    fraccion m;

    s=f.suma(g);
    m=f.multiplica(g);

    std::cout << "Creando fracciones:\n";
    f.imprime(); std::cout << "\n";
    g.imprime(); std::cout << "\n";

    std::cout << "Su suma es:\n";
    s.imprime(); std::cout << "\n";

    std::cout << "Su multiplicación es:\n";
    m.imprime(); std::cout << "\n";

    std::cout << "Leyendo archivos de matrices (m1.f, m2.f y m3.f)...\n";
    matfrac m1("../m1.f"), m2("../m2.f"), m3("../m3.f");

    std::cout << "Sumando m1+m2:\n";
    m1.imprime();
    std::cout << "+\n";
    m2.imprime();
    std::cout << "=\n";
    m2.suma(m1).imprime();

    std::cout << "Comparando m1 contra m2 (son iguales/diferentes)...\n";
    if (m1.igualA(m2))
    {
       std::cout << "m1 es igual a m2 \n";
    }
    else
    {
        std::cout << "m1 es diferente a m2 \n";
    }

    std::cout << "Matriz m3=\n";
    m3.imprime();

    std::cout << "Comparando m1+m2 contra m3 para verificar que la suma es (correcta/incorrecta)...\n";
    if (m2.suma(m1).igualA(m3))
    {
        std::cout << "Suma correcta \n";
    }
    else {
        std::cout << "Suma incorrecta \n";
    }

    return 0;
}