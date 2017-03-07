#include <iostream>

using namespace std;

typedef struct pol
{
    int coeficient, grad;
    pol *urm;
}POL;

POL *prim1, *ultim1, *prim2, *ultim2;

void creareP(int coef, int i, POL *&prim1, POL *&ultim1)
{
    POL *p = new POL;
    p->coeficient = coef;
    p->grad = i;
    p->urm = prim1;
    prim1 = p;
    if(ultim1 == NULL)
        prim1 = ultim1 = p;
}

void creareQ(int coef, int i, POL *&prim2, POL *&ultim2)
{
    POL *p = new POL;
    p->coeficient = coef;
    p->grad = i;
    p->urm = prim2;
    prim2 = p;
    if(ultim2 == NULL)
        prim2 = ultim2 = p;
}

void creareS(int coef, int i, POL *&prim3, POL *&ultim3)
{
    POL *p = new POL;
    p->coeficient = coef;
    p->grad = i;
    if(ultim3==NULL)
        prim3 = ultim3 = p;
    else
    {
        ultim3->urm = p;
        p->urm = NULL;
        ultim3 = p;
    }
}

void inmultire_scalar(int a, POL *prim)
{
    POL *p;
    for(p=prim; p; p=p->urm)
        p->coeficient *= 2;
}

void afisare(POL *prim)
{
    POL *p;
    for(p=prim; p; p=p->urm)
    {
        if(p->coeficient != 0)
            cout<<p->coeficient<<"X^"<<p->grad<<"  ";
    }
    cout<<"\n";
}

int defpow(int a, int b)
{
    int p=1;
    for(int i=1; i<=b; i++)
        p*=a;
    return p;
}

int P(int x0, POL *prim)
{
    POL *p;
    int S = 0;
    for(p=prim; p; p=p->urm)
    {
        int putere = defpow(x0, p->grad);
        S += p->coeficient * putere;
    }
    return S;
}

void suma(int n, POL *prim1, int m, POL *prim2)
{
    POL *prim3, *ultim3;
    prim3 = ultim3 = NULL;
    POL *p, *q;
    p = prim1;
    q = prim2;
    while(n>m)
    {
        creareS(p->coeficient, p->grad, prim3, ultim3);
        n--;
        p=p->urm;
    }
    while(m>n)
    {
        creareS(q->coeficient, q->grad, prim3, ultim3);
        m--;
        q=q->urm;
    }

    for(;p; p=p->urm, q=q->urm)
    {
        creareS(p->coeficient+q->coeficient, p->grad, prim3, ultim3);
    }
    afisare(prim3);
}

void sterge_poz(int poz, POL *&prim, POL *&ultim)
{
    int n = 0;
    POL *a = new POL;
    for(a=prim; a; n++, a=a->urm);

    if(n == 1)

        prim = ultim = NULL;

    else if(poz == 1)
    {
        POL *r = new POL;
        r = prim;
        prim = r->urm;
        delete r;
    }

    else if(poz == n)
    {
        POL *s = new POL;
        for(s=prim; s->urm != ultim; s=s->urm);
        POL *del = new POL;
        del = s->urm;
        delete del;
        s->urm = NULL;
        ultim = s;
    }
    else
    {
        POL *p = new POL;
        int i;
        for(p=prim, i=1; p && i+1 != n; i++, p=p->urm);
        POL *q = new POL;
        q = p->urm;
        p->urm = p->urm->urm;
        delete q;
    }
}

void sterge_lista(POL *&prim, POL *&ultim)
{
    int n = 0;
    POL *a = new POL;
    for(a=prim; a; n++, a=a->urm);

    while(n)
    {
        sterge_poz(1, prim, ultim);
        n--;
    }
}

void produs(POL *prim1, POL *prim2)
{
    POL *prim4, *ultim4;
    prim4 = ultim4 = NULL;
    POL *prim5, *ultim5;
    prim5 = ultim5 = NULL;
    POL *p, *q;
    for(p=prim1; p; p=p->urm)
    {
        for(q=prim2; q; q=q->urm)
            creareS(p->coeficient*q->coeficient, p->grad+q->grad, prim4, ultim4);
    }
    int gr = prim4->grad;
    while(gr>=0)
    {
        int sumCoef = 0;
        for(p=prim4; p; p=p->urm)
            if(p->grad == gr)
                sumCoef += p->coeficient;
        creareS(sumCoef, gr, prim5, ultim5);
        gr--;
    }
    sterge_lista(prim4, ultim4);
    afisare(prim5);
}

int main()
{
    prim1 = prim2 = ultim1 = ultim2 = NULL;
    int n = 4, m = 3;

    creareP(2, 0, prim1, ultim1);
    creareP(4, 1, prim1, ultim1);
    creareP(3, 2, prim1, ultim1);
    creareP(5, 3, prim1, ultim1);
    creareP(1, 4, prim1, ultim1);

    creareQ(6, 0, prim2, ultim2);
    creareQ(1, 1, prim2, ultim2);
    creareQ(0, 2, prim2, ultim2);
    creareQ(4, 3, prim2, ultim2);

    cout<<"  Polinoamele sunt: ";
    cout<<"\n\nP(X) = ";
    afisare(prim1);

    cout<<"\nQ(X) = ";
    afisare(prim2);

    cout<<"\n  Inmultirea cu scalar a polinomului P(X):\n\n2P(X) = ";
    inmultire_scalar(2, prim1);
    afisare(prim1);

    cout<<"\n  Valoarea intr-un punct x0\n\nP(3) = " << P(3, prim1) << "\n";

    cout<<"\n  Suma polinoamelor P(X) si Q(X): ";
    cout<<"\n\nP(X) = "; afisare(prim1);
    cout<<"\nQ(X) = "; afisare(prim2);
    cout<<"\n  este: \n\n";
    suma(n, prim1, m, prim2);

    cout<<"\n  Produsul polinoamelor P(X) si Q(X): ";
    cout<<"\n\nP(X) = "; afisare(prim1);
    cout<<"\nQ(X) = "; afisare(prim2);
    cout<<"\n  este: \n\n";
    produs(prim1, prim2);

    return 0;
}
