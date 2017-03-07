#include <iostream>
#include <cstdio>

using namespace std;

typedef struct nod
{
    int info;
    nod *urm;
}NOD;

NOD *prim, *ultim;
NOD *prim2, *ultim2;
NOD *primSum, *ultimSum;

void adaug_inceput(int x, NOD *&prim, NOD *&ultim)
{
    NOD *p = new NOD;
    p->info = x;
    p->urm = prim;
    prim = p;
    if(ultim == NULL)
        prim = ultim = p;
}

void afisare(NOD *prim)
{
    NOD *p = new NOD;
    for(p=prim; p; p=p->urm)
        cout<<p->info;
}

int main()
{
    prim = ultim = NULL;
    prim2 = ultim2 = NULL;
    primSum = ultimSum = NULL;
    char c;

    ///citire nr1

    scanf("%c", &c);
    int x = c - 48;
    while(c!='\n')
    {
        adaug_inceput(x, prim, ultim);
        scanf("%c", &c);
        x = c - 48;
    }

    ///citire nr2

    scanf("%c", &c);
    x = c - 48;
    while(c!='\n')
    {
        adaug_inceput(x, prim2, ultim2);
        scanf("%c", &c);
        x = c - 48;
    }

    int transport;

    for(NOD *p = prim; p; p=p->urm)
    {
        transport = 0;
        int produs = 0;
        for (NOD *q = prim2; q; q=q->urm)
        {
            produs += p->info*q->info + transport;
            transport = produs/10;
            produs %= 10;
        }
        adaug_inceput(produs, primSum, ultimSum);
        if(transport)
            adaug_inceput(transport, primSum, ultimSum);
    }

    afisare(primSum);

    return 0;
}
