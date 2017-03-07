#include <iostream>

using namespace std;

typedef struct nod
{
    float info;
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
    prim = ultim = NULL;
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        adaug_final(x, prim, ultim);
    }

    NOD *p;
    for(p=prim; p->urm != NULL;)
    {
        float s = (p->info + p->urm->info)/2;
        NOD *q = new NOD;
        q->info = s;
        q->urm = p->urm;
        p->urm = q;
        p=p->urm->urm;
    }

    for(p=prim; p; p=p->urm)
        cout<<p->info<<" ";

    return 0;
}
