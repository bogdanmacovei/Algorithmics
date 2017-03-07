#include <iostream>

using namespace std;

class Polinom
{
    Polinom();
    Polinom(int, int);
    int coeficient, grad;
    Polinom *pol;
    void creareP(int, int, Polinom*&, Polinom *&);
    void afisare(Polinom *);
};

Polinom :: Polinom()
{
    coeficient = grad = 0;
    Polinom *pol = NULL;
}

Polinom :: Polinom(int x, int y)
{
    coeficient = x;
    grad = y;
    Polinom *pol = NULL;
}

void Polinom :: creareP(int coef, int i, Polinom *&prim1, Polinom *&ultim1)
{
    Polinom p(coef, i);
    p.urm = prim1;
    prim1 = p;
    if(ultim1 == NULL)
        prim1 = ultim1 = p;
}

int main()
{
    Polinom *prim, *ultim;
}
