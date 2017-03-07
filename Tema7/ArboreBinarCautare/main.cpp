#include <iostream>

typedef struct nod
{
    int val;
    nod *st, *dr;
}NOD;

NOD *firstNode;

int n;
int v[100];

void inserare(NOD *&r, int arg)
{
    if(r)
    {
        if(r->val == arg)
        {
            std::cout<<"\nExista deja aceasta cheie\n";
            return ;
        }
        if(r->val > arg)
            inserare(r->st, arg);
        else
            inserare(r->dr, arg);
    }

    else
    {
        r = new NOD;
        r->val = arg;
        r->st = r->dr = NULL;
    }
}

void nodDreapta(NOD *&rad, NOD *&p)
{
    NOD *aux;
    if(p->dr)
        nodDreapta(rad, p->dr);
    else
    {
        rad->val = p->val;
        aux=p;
        p=p->st;
        delete aux;
    }
}

void stergere(NOD *&rad, int k)
{
    NOD *aux, *p;
    if(rad)
        if(rad->val == k)
            if(rad->st == NULL && rad->dr == NULL)
            {
                delete rad;
                rad=0;
            }
            else
                if(rad->st == NULL)
                {
                    aux=rad->dr;
                    delete rad;
                    rad=aux;
                }
                else
                    if(rad->dr == NULL)
                    {
                        aux=rad->st;
                        delete rad;
                        rad=aux;
                    }
                    else
                        nodDreapta(rad, rad->st);

    else
        if(rad->val < k)
            stergere(rad->dr, k);
        else
            stergere(rad->st, k);

    else
      std::cout<<"\nIntroduceti o valoare valida\n";
}

void SRD(NOD *rad)
{
    if(rad)
    {
        SRD(rad->st);
        std::cout<<rad->val<<" ";
        SRD(rad->dr);
    }
}

void RSD(NOD *rad)
{
    if(rad)
    {
        std::cout<<rad->val<<" ";
        RSD(rad->st);
        RSD(rad->dr);
    }
}

int caut(NOD *rad, int x)
{
    if(rad)
    {
        if(rad->val == x)
            return 1;
        return caut(rad->st, x) || caut(rad->dr, x);
    }
    return 0;
}

int maxim(NOD *rad)
{
    while(rad->dr)
        rad=rad->dr;
    return rad->val;
}

int main()
{
    std::cin>>n;
    for(int i=1; i<=n; i++)
    {
        std::cin>>v[i];
        inserare(firstNode, v[i]);
    }
    std::cout<<"SRD: "; SRD(firstNode);
    std::cout<<"RSD: "; RSD(firstNode);
    if(caut(firstNode, 0))
        std::cout<<"\nGasit\n";
    else
        std::cout<<"\nNegasit";
    stergere(firstNode, 4);
    std::cout<<"\n";
    SRD(firstNode);
    std::cout<<"\n";
    RSD(firstNode);

    std::cout<<"\nElementul maxim este: "<<maxim(firstNode);
}
