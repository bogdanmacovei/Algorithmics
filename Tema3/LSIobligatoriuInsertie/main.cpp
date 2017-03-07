#include <iostream>

using namespace std;

typedef struct nod
{
    int info;
    nod *urm;
}NOD;

NOD *prim, *ultim;

void inserare(int x, NOD *&prim, NOD *&ultim)
{
    if(prim==ultim)
        if(prim==NULL)
        {
            prim = new NOD;
            ultim = new NOD;
            prim->info = ultim->info = x;
            ultim->urm = NULL;
            prim = ultim;
        }
        else
            if(x<prim->info)
            {
                NOD *p = new NOD;
                p->info = x;
                p->urm = prim;
                prim = p;
            }
            else
            {
                NOD *p = new NOD;
                p->info = x;
                ultim->urm = p;
                ultim = p;
                ultim->urm = NULL;
            }
    else
    {
        NOD *b = new NOD;
        b->info = x;

        if(x>=ultim->info)
        {
            ultim->urm = b;
            ultim = b;
            ultim->urm = NULL;
        }
        else if(x<=prim->info)
        {
            b->urm = prim;
            prim = b;
        }
        else
        {
            NOD *a;
            for(a=prim; a; a=a->urm)
                if(a->urm->info >= x)
                {
                    b->urm = a->urm;
                    a->urm = b;
                    break;
                }
        }
    }
}

void afisare(NOD *prim)
{
    NOD *p;
    for(p=prim; p; p=p->urm)
        cout<<p->info<<" ";
}

int main()
{
    prim = ultim = NULL;

    ///exemplu
    inserare(9, prim, ultim);
    inserare(1, prim, ultim);
    inserare(8, prim, ultim);
    inserare(10, prim, ultim);
    inserare(0, prim, ultim);
    inserare(10, prim, ultim);
    inserare(3, prim, ultim);
    inserare(7, prim, ultim);
    inserare(-1, prim, ultim);
    inserare(5, prim, ultim);
    inserare(4, prim, ultim);
    inserare(11, prim, ultim);
    inserare(10, prim, ultim);
    inserare(-1, prim, ultim);
    inserare(0, prim, ultim);
    inserare(8, prim, ultim);


    afisare(prim);
    return 0;
}
