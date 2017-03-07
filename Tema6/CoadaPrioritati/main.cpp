#include <iostream>

typedef struct nod
{
    int val, prioritate;
    nod *next;
} NOD;

NOD *prim;

void push(NOD *&prim, int arg, int pr)
{
    NOD *q = new NOD;
    q->val = arg;
    q->prioritate = pr;

    if(!prim)
    {
        prim = q;
        q->next = NULL;
        return;
    }

    if(q->prioritate < prim->prioritate)
    {
        q->next = prim;
        prim = q;
        return;
    }

    NOD *p;
    for(p=prim; p->next && q->prioritate >= p->next->prioritate; p=p->next);

    q->next = p->next;
    p->next = q;
}

int pop(NOD *&prim, int pr)
{
    if(!prim)
        return -1;

    if(prim->prioritate == pr)
    {
        NOD *q = prim;
        prim = prim->next;
        delete q;
        return -1;
    }

    NOD *p;
    for(p=prim; p->next; p=p->next)
        if(p->next->prioritate == pr)
            break;

    if(!p->next || p->next->prioritate != pr)
        return -1;

    NOD *q = p->next;
    p->next = p->next->next;
    delete q;
}

void afisare(NOD *q)
{
    for(NOD *p=prim; p; p=p->next)
        std::cout<<p->val<<" "<<p->prioritate<<"\n";
}

int main()
{
    push(prim, 2, 2); push(prim, 1, 1); push(prim, 3, 3);
    push(prim, 33, 3); push(prim, 11, 1); push(prim, 22, 2);
    pop(prim, 0);
    afisare(prim);
}
