#include <iostream>

typedef struct nod
{
    int val;
    nod *st, *dr;
}NOD;

NOD *firstNode;

int dimTree;
int v[101];

void insertTree(NOD *&r, int index)
{
    if(index <= dimTree)
    {
        r = new NOD;
        r->val = v[index];
        r->st = r->dr = NULL;
        insertTree(r->st, 2*index);
        insertTree(r->dr, 2*index+1);
    }
}

void RSD(NOD *r)
{
    if(r)
    {
        std::cout<<r->val<<" ";
        RSD(r->st);
        RSD(r->dr);
    }
}

void SRD(NOD *r)
{
    if(r)
    {
        SRD(r->st);
        std::cout<<r->val<<" ";
        SRD(r->dr);
    }
}

void SDR(NOD *r)
{
    if(r)
    {
        SDR(r->st);
        SDR(r->dr);
        std::cout<<r->val<<" ";
    }
}

int main()
{
    dimTree = 7;
    for(int i=1; i<=dimTree; ++i)
    {
        v[i] = i;
    }
    insertTree(firstNode, 1);
    RSD(firstNode);
    std::cout<<"\n";
    SRD(firstNode);
    std::cout<<"\n";
    SDR(firstNode);
}
