#include <iostream>
#include <fstream>

using namespace std;

typedef struct graf
{
    int val;
    graf *next;
} GRAF;

GRAF *L[20];
int viz[100], m, n;
int prim, ultim, C[100];

void BF(int x)
{
    viz[x]=1;
    prim = ultim = 1;
    C[prim]=x;

    int varf, nr;
    GRAF *p;
    while(prim <= ultim)
    {
        varf = C[prim];
        p=L[varf];
        while(p)
        {
            nr=p->val;
            if(viz[nr]==0)
            {
                ultim++;
                C[ultim]=nr;
                viz[nr]=1;
            }
            p=p->next;
        }
        prim++;
    }

    for(int i=1;i<=ultim;i++)
        cout<<C[i]<<" ";
}


void afisare(int x)
{
    GRAF *p = L[x];
    cout<<"Vecini "<<x<<": ";
    GRAF *q = p;
    while(q)
    {
        cout<<q->val<<" ";
        q=q->next;
    }
    cout<<"\n";
}

void creare()
{
    ifstream f("muchii.txt");
    int i,j;
    GRAF *p,*q;
    f>>n>>m;
    while(f>>i>>j)
    {
        p=new GRAF;
        p->val=j;
        p->next=L[i];
        L[i]=p;
        q=new GRAF;
        q->val=i;
        q->next=L[j];
        L[j]=q;
    }

    f.close();
}

void continut()
{
    cout<<"\n"<<"Listele de adiacenta: ";

    for(int i=1;i<=n;i++)
        afisare(i);
}

int main()
{
    creare();
    continut();

    /// reinitializez viz
    for(int i = 1; i <= n; ++i)
        viz[i] = 0;

    int k = 0;
    for(int i=1; i<=n; ++i)
        if(!viz[i])
        {
            cout<<"Componenta "<<++k<<": ";
            BF(i);
            cout<<"\n";
        }
    return 0;
}
