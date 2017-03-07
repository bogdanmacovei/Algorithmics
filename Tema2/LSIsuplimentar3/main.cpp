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

    NOD *p, *q;
    int ord = 0;
    for(p=prim, q=prim2; p && q; p=p->urm, q=q->urm)
    {
        int S = p->info + q->info + ord;
        if(S>9)
            S=S%10, ord=1;
        else ord = 0;
        adaug_inceput(S, primSum, ultimSum);
    }
    cout<<"\n";

    while(p)
    {
        int S = p->info + ord;
        if(S>9)
            S=S%10, ord=1;
        else ord = 0;
        adaug_inceput(S, primSum, ultimSum);
        p=p->urm;
    }

    while(q)
    {
        int S = q->info + ord;
        if(S>9)
            S=S%10, ord=1;
        else ord = 0;
        adaug_inceput(S, primSum, ultimSum);
        q=q->urm;
    }

    if(ord==1)
        adaug_inceput(ord, primSum, ultimSum);

    afisare(primSum);

    return 0;
}
