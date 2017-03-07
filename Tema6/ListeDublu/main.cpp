#include <iostream>

typedef struct nod
{
    int val;
    nod *next, *prev;
} NOD;

NOD *prim;

void adaug_inceput(int arg, NOD *&prim)
{
    NOD *q = new NOD;
    q->val = arg;
    q->prev = NULL;
    q->next = prim;
    if(prim != NULL)
        prim->prev = q;
    prim = q;
}

void adaug_sfarsit(int arg, NOD *&prim)
{
    NOD *q = new NOD;
    q->val = arg;
    q->next = NULL;
    q->prev = NULL;

    if(!prim)
        prim = q;

    else
    {
        NOD *p;
        for(p=prim; p->next; p=p->next);
        p->next = q;
        q->prev = p;
    }

}

void adaug_interior(int arg, int argNod, NOD *&prim)
{
    NOD *q = new NOD;
    q->val = arg;
    q->next = NULL;
    q->prev = NULL;

    if (prim == NULL)
    {
        prim = q;
        return;
    }

    NOD *p;
    for(p = prim; p; p=p->next)
        if(p->val == argNod)
            break;

    if (prim == p)
    {
        q->next = prim;
        prim->prev = q;
        prim = q;
        return;
    }

    q->next = p->next;
    q->prev = p;
    p->next->prev = q;
    p->next = q;
}

void stergere_pozitie(int poz, NOD *&prim)
{
    if (!prim || poz == 0)
        return;

    if (poz == 1)
    {
        NOD *q = prim;
        if(prim->next)
            prim = prim->next;
        else
        {
            prim = NULL;
            delete q;
            return;
        }
        prim->prev = NULL;
        delete q;
        return;
    }

    int i;
    NOD *p;

    for(p=prim, i=1; p; p=p->next, i++)
        if(i==poz)
            break;

    p->prev->next = p->next;
    p->next->prev = p->prev;

    delete p;

}

void stergere_valoare(int arg, NOD *&prim)
{
    if (!prim)
        return;

    if (prim->val == arg)
    {
        NOD *q = prim;
        if(prim->next)
            prim = prim->next;
        else
        {
            prim = NULL;
            delete q;
            return;
        }
        prim->prev = NULL;
        delete q;
        return;
    }

    NOD *p;
    for(p = prim; p; p = p->next)
        if(p->val == arg)
            break;

    if (p->next)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
    }
}

void afisare(NOD *&prim)
{
    for(NOD *p = prim; p; p = p->next)
        std::cout<<p->val<<" ";
}

int main()
{
    adaug_inceput(1, prim);
    adaug_sfarsit(3, prim);
    stergere_valoare(1, prim);
    stergere_valoare(3, prim);
    stergere_valoare(2, prim);
    adaug_inceput(9, prim);
    adaug_sfarsit(8, prim);
    //stergere_valoare(5, prim);
    afisare(prim);
}
