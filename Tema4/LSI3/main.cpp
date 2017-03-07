#include <iostream>

typedef struct nod {
    int val;
    nod *next;
}NOD;

NOD *prim, *ultim, *prim1, *prim2, *ultim1, *ultim2;

void adaug_final(int x, NOD *&prim, NOD *&ultim) {
    NOD *p = new NOD;
    p->val = x;
    if(ultim==NULL) {
        prim = ultim = p;
        p->next = NULL;
    }
    else {
        ultim->next = p;
        p->next = NULL;
        ultim = p;
    }
}

void impartire_liste(NOD *prim, NOD *ultim, NOD *&prim1, NOD *&ultim1, NOD *&prim2, NOD *&ultim2) {

    if(prim == ultim && ultim == NULL)
    {
        prim1 = ultim1 = prim2 = ultim2 = NULL;
        std::cout<<"NU exista elemente";
        return;
    }
    if(prim == ultim)
    {
        prim1 = ultim1 = prim;
        ultim1->next = NULL;
        prim2 = ultim2 = NULL;
        std::cout<<"Doar prima lista contine elemente\n";
        return;
    }
    int k=0;
    for(NOD *i = prim; i; i=i->next)
        k++;

    NOD *q1, *r1, *q2, *r2;
    q1 = prim;
    r1 = prim->next;

    prim1 = q1;
    prim2 = r1;

    if(k%2==0) {
        while(r1->next) {
            q2 = q1->next->next;
            r2 = r1->next->next;
            q1->next = q2;
            r1->next = r2;
            q1 = q2;
            r1 = r2;
        }
    }

    else {
        while(r1->next->next) {
            q2 = q1->next->next;
            r2 = r1->next->next;
            q1->next = q2;
            r1->next = r2;
            q1 = q2;
            r1 = r2;
        }
        q1->next = r1->next;
        q1 = r1->next;
    }

    ultim1 = q1;
    ultim1->next = NULL;
    ultim2 = r1;
    ultim2->next = NULL;
}

void afisare(NOD *prim)
{
    for(NOD *p = prim; p; p = p->next) {
        std::cout<<p->val<<" ";
    }
    std::cout<<"\n";
}

int main() {

    prim = ultim = prim1 = prim2 = ultim1 = ultim2 = NULL;

    for(int i=0; i<10; ++i) {
        adaug_final(i, prim, ultim);
    }
    afisare(prim);

    impartire_liste(prim, ultim, prim1, ultim1, prim2, ultim2);
    afisare(prim1);
    afisare(prim2);

}
