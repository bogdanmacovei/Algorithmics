#include <iostream>

typedef struct nod
{
    int val;
    nod *st, *dr;
}NOD;

NOD *firstNode;

int n;

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

int in = 1;
int v[100];

void SRD(NOD *rad)
{
    if(rad)
    {
        SRD(rad->st);
        v[in++] = rad->val;
        SRD(rad->dr);
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
    SRD(firstNode);
    for(int i=1; i<=n; i++)
        std::cout<<v[i]<<" ";
}
