#include <iostream>

using namespace std;

typedef struct nod
{
    int info;
    nod *urm;
}NOD;

NOD *prim, *ultim;

void adaug_final(int x, NOD *&prim, NOD *&ultim)
{
    NOD *p = new NOD;
    p->info = x;
    if(ultim==NULL)
        prim = ultim = p;
    else
    {
        ultim->urm = p;
        p->urm = NULL;
        ultim = p;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        adaug_final(x, prim, ultim);
    }

    int sumPar = 0, sumImpar = 0, nrImpar = 0;
    NOD *p;
    for(p=prim; p; p=p->urm)
        if(p->info%2)
        {
            sumImpar += p->info;
            nrImpar ++;
        }
        else
            sumPar += p->info;

    cout<<"\nsumPar = " << sumPar;
    if(nrImpar)
        cout<<"\nmedieImpar = "<<(float)sumImpar / nrImpar;
    else
        cout<<"\nNu exista numere impare!\n\n";

    return 0;
}
