#include <iostream>

typedef struct nod
{
    int val;
    nod *next;
}NOD;

NOD *prim1, *prim2, *prim, *ultim1, *ultim2, *ultim, *q1, *q2, *p1, *p2;

void adaug_final(int x, NOD *&prim, NOD *&ultim)
{
    NOD *p = new NOD;
    p->val = x;
    if(ultim==NULL)
    {
        prim = ultim = p;
        p->next = NULL;
    }
    else
    {
        ultim->next = p;
        p->next = NULL;
        ultim = p;
    }
}

void afisare(NOD *prim)
{
    NOD *p;
    for(p = prim; p; p=p->next)
        std::cout<<p->val<<" ";
    std::cout<<"\n";
}

void interclasare(NOD *prim1, NOD *ultim1, NOD *prim2, NOD *ultim2, NOD *&prim, NOD *&ultim)
{
    if(prim1 == ultim1 && prim2 == ultim2 && ultim1 == ultim2 && ultim2 == NULL)
    {
        std::cout<<"Eroare, introduceti elemente!";
        return;
    }
    if(prim1 == ultim1 && ultim1 == NULL)
    {
        prim = prim2;
        ultim = ultim2;
        return;
    }
    if(prim2 == ultim2 && ultim2 == NULL)
    {
        prim = prim1;
        ultim = ultim1;
        return;
    }
    if(prim1 == ultim1 && prim2==ultim2)
    {
        if(prim1->val < prim2->val)
        {
            prim1->next = prim2;
            prim = prim1;
            ultim = ultim2;
            return;
        }
        else
        {
            prim2->next = prim1;
            prim = prim2;
            ultim = ultim1;
            return;
        }
        return;
    }
    if(prim1 == ultim1)
    {
        ///lista1 are doar un element, trebuie pus in lista2
        NOD *r;
        if(prim1->val < prim2->val)
        {
            prim = prim1;
            prim->next = prim2;
            return;
        }
        if(ultim1->val > ultim2->val)
        {
            ultim = ultim2;
            ultim->next = ultim1;
            ultim = ultim1;
            return;
        }
        prim = prim2;
        ultim = ultim2;
        for(r=prim2; prim1->val < r->next->val; r=r->next)
        {
            prim1->next = r->next;
            r->next = prim1;
            return;
        }
        return;
    }

    if(prim2 == ultim2)
    {
        ///lista2 are doar un element, trebuie pus in lista1
        NOD *r;
        if(prim2->val < prim1->val)
        {
            prim = prim2;
            prim->next = prim1;
            return;
        }
        if(ultim2->val > ultim1->val)
        {
            ultim = ultim1;
            ultim->next = ultim2;
            ultim = ultim2;
            return;
        }
        prim = prim1;
        ultim = ultim1;
        for(r=prim1; prim2->val < r->next->val; r=r->next)
        {
            prim2->next = r->next;
            r->next = prim2;
            return;
        }
        return;
    }

    NOD *q1, *q2, *r1, *r2, *t;
    if(prim1->val < prim2->val)
    {
        prim = prim1;
        q1 = prim->next;
        q2 = q1->next;
        r1 = prim2;
        r2 = r1->next;
        t = prim;
    }
    else
    {
        prim = prim2;
        q1 = prim1;
        q2 = q1->next;
        r1 = prim->next;
        r2 = r1->next;
        t = prim;
    }
    while(q1 && r1)
    {
        if(q1->val < r1->val)
        {
            t->next = q1;
            t = q1;
            q2 = q2->next;
            q1 = q1->next;
        }
        else
        {
            t->next = r1;
            t = r1;
            r2 = r2->next;
            r1 = r1->next;
        }
        if(!q2) q2 = q1;
        if(!r2) r2 = r1;
    }
    if(!q1)
    {
        ultim1->next = r1;
        ultim = ultim2;
    }
    else if(!r1)
    {
        ultim2->next = q1;
        ultim = ultim1;
    }
}

int main()
{
    prim1 = ultim1 = NULL;
    prim2 = ultim2 = NULL;
    prim = ultim = NULL;

    adaug_final(2, prim1, ultim1);
    adaug_final(3, prim1, ultim1);
    adaug_final(5, prim1, ultim1);
    adaug_final(7, prim1, ultim1);
    adaug_final(9, prim1, ultim1);
    adaug_final(11, prim1, ultim1);
    adaug_final(25, prim1, ultim1);
    adaug_final(29, prim1, ultim1);
    afisare(prim1);

    adaug_final(1, prim2, ultim2);
    adaug_final(4, prim2, ultim2);
    adaug_final(9, prim2, ultim2);
    adaug_final(12, prim2, ultim2);
    adaug_final(14, prim2, ultim2);
    adaug_final(24, prim2, ultim2);
    adaug_final(26, prim2, ultim2);
    adaug_final(28, prim2, ultim2);
    adaug_final(45, prim2, ultim2);
    adaug_final(54, prim2, ultim2);
    afisare(prim2);

    interclasare(prim1, ultim1, prim2, ultim2, prim, ultim);
    afisare(prim);

    return 0;
}
