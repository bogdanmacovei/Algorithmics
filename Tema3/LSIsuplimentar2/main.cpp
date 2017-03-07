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
    {
        prim = ultim = p;
        ultim->urm = NULL;
        prim->urm = NULL;
    }
    else
    {
        ultim->urm = p;
        p->urm = NULL;
        ultim = p;
    }
}

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
    NOD *p;
    for(p=prim; p; p=p->urm)
        cout<<p->info<<" ";
}

void inversare_suplimentara(NOD *&prim, NOD *&ultim)
{
    ///cazuri exceptie
    if(prim==ultim && ultim==NULL)
        return;
    if(prim==ultim && prim!=NULL)
    {
        cout<<prim->info;
        return;
    }

    ///lista noua
    NOD *prim2, *ultim2;
    prim2 = ultim2 = NULL;

    NOD *p;
    for(p=prim; p; p=p->urm)
        adaug_inceput(p->info, prim2, ultim2);
    afisare(prim2);

}

void inversare(NOD *&prim, NOD*&ultim)
{
    if(prim==ultim && ultim==NULL)
        return;
    if(prim==ultim && prim!=NULL)
        return;
    NOD *p, *q, *r, *a;
    p = prim;
    a = prim;
    q = prim->urm;
    r = prim->urm->urm;
    while(r!=NULL)
    {
        q->urm = p;
        p = q;
        q = r;
        r=r->urm;
    }
    q->urm = p;
    p=q;
    prim = p;
    ultim = a;
    ultim->urm=NULL;
}

int main()
{
    prim = ultim = NULL;
    int n, x;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin >> x;
        adaug_final(x, prim, ultim);
    }
    cout<<"\nInversare cu memorie suplimentara:\n";
    inversare_suplimentara(prim, ultim);
    cout<<"\n\nInversare fara memorie suplimentara:\n";
    inversare(prim, ultim);
    afisare(prim);
    cout<<"\n";
}
