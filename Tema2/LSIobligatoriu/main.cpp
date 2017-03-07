#include <iostream>

using namespace std;

typedef struct nod
{
    int info;
    nod *urm;
}NOD;

NOD *prim, *ultim;

void adaug_inceput(int x, NOD *&prim, NOD *&ultim)
{
    NOD *p = new NOD;
    p->info = x;
    p->urm = prim;
    prim = p;
    if(ultim == NULL)
        prim = ultim = p;
}

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

void afisare(NOD *prim)
{
    NOD *p = new NOD;
    for(p=prim; p; p=p->urm)
        cout<<p->info<<" ";
}

void inserare(NOD *prim, NOD *& ultim)
{
    NOD *p, *q;
    for(p=prim; p; p=p->urm)
        if(p->info % 2 == 1)
        {
            q = new NOD;
            q->info = p->info + 1;

            if(p==ultim)
            {
                p->urm = q;
                q->urm = NULL;
                ultim = q;
            }
            else
            {
                q->urm = p->urm;
                p->urm = q;
            }

        }
}

int caut_val(int x, NOD *prim)
{
    NOD *p = new NOD;
    for(p=prim; p; p=p->urm)
        if(p->info == x)
            return 1;
    return 0;
}

int caut_poz(int x, NOD *prim)
{
    int i=1;
    NOD *p = new NOD;
    for(p=prim; p; p=p->urm, i++)
        if(i==x)
            return 1;
    return 0;
}

void sterge_val(int x, NOD *&prim, NOD *&ultim)
{
    if(!caut_val(x, prim))
    {
        cout<<"\nNu exista elementul " << x <<"!\n";
    }
    else
    {
        if(prim==ultim)
        {
            prim = ultim = NULL; ///lista vida
        }
        else if(prim->info == x)
        {
            NOD *r = new NOD;
            r = prim;
            prim = r->urm;
            delete r;
        }
        else if(ultim->info == x)
        {
            NOD *s = new NOD;
            for(s=prim; s->urm != ultim; s=s->urm);
            NOD *del = new NOD;
            del = s->urm;
            delete del;
            s->urm = NULL;
            ultim = s;
        }
        else
        {
            NOD *p = new NOD;
            for(p=prim; p->urm->info != x; p=p->urm);
            NOD *q = new NOD;
            q = p->urm;
            p->urm = p->urm->urm;
            delete q;
        }

    }

}

void sterge_poz(int poz, NOD *&prim, NOD *&ultim)
{
    if(!caut_poz(poz, prim))
        cout<<"Nu exista pozitia " << poz << " in lista!\n";
    else
    {
        int n = 0;
        NOD *a = new NOD;
        for(a=prim; a; n++, a=a->urm);

        if(n == 1)
        {
            prim = ultim = NULL;
        }
        else if(poz == 1)
        {
            NOD *r = new NOD;
            r = prim;
            prim = r->urm;
            delete r;
        }
        else if(poz == n)
        {
            NOD *s = new NOD;
            for(s=prim; s->urm != ultim; s=s->urm);
            NOD *del = new NOD;
            del = s->urm;
            delete del;
            s->urm = NULL;
            ultim = s;
        }
        else
        {
            NOD *p = new NOD;
            int i;
            for(p=prim, i=1; p && i+1 != n; i++, p=p->urm);
            NOD *q = new NOD;
            q = p->urm;
            p->urm = p->urm->urm;
            delete q;
        }
    }
}

void sterge_lista()
{
    int n = 0;
    NOD *a = new NOD;
    for(a=prim; a; n++, a=a->urm);

    while(n)
    {
        sterge_poz(1, prim, ultim);
        n--;
    }
}

int main()
{
    prim = ultim = NULL;
    /*int x, n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        adaug_final(x, prim, ultim);
    }
    inserare(prim, ultim);
    afisare(prim);

    cout<<"\n"<<caut_val(2, prim);
    cout<<"\n"<<caut_poz(3, prim);

    sterge_lista();


    cout<<"\n";
    afisare(prim); /// se obtine lista vida*/

    adaug_inceput(2, prim, ultim);
    adaug_final(3, prim, ultim);
    adaug_inceput(1, prim, ultim);
    afisare(prim);
    sterge_val(2, prim, ultim);
    sterge_val(3, prim, ultim);
    sterge_val(1, prim, ultim);
    adaug_inceput(4, prim, ultim);
    afisare(prim);
    return 0;
}
