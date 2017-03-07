#include <iostream>
#include <fstream>

using namespace std;

int n, m, viz[101], a[21][21], c[101];
int p, u;

void citire()
{
    ifstream f("graf.in");
    f>>n>>m;
    for(int i=1; i<=m; ++i)
    {
        int x, y;
        f>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    f.close();
}

void BF(int x)
{
    p=u=1;
    c[u]=x;
    viz[x]=1;
    cout<<x<<" ";
    while(p<=u)
    {
        x=c[p++];
        for(int i=1; i<=n; ++i)
            if(a[x][i] && !viz[i])
            {
                c[++u]=i;
                viz[i]=1;
                cout<<i<<" ";
            }
    }
}

void DF(int x)
{
    cout<<x<<" ";
    viz[x]=1;
    for(int i = 1; i <= n; i++)
        if(a[x][i]==1 && viz[i]==0)
            DF(i);
}

int grad(int x)
{
    int gr = 0;
    for(int i = 1; i <= n; ++i)
        gr += a[i][x];
    return gr;
}

int nrmuchii()
{
    int nrm = 0;
    for(int i=1; i<=n; ++i)
        for(int j = 1; j < i; ++j)
            nrm += a[i][j];
    return nrm;
}

void gradMax()
{
    int max_grad = 0;
    for(int i = 1; i <= n; ++i)
        if(grad(i) > max_grad)
            max_grad = i;
    for(int i = 1; i <= n; ++i)
        if(grad(i) == max_grad)
            cout<<i<<" ";
}

int main()
{
    int k=0;
    citire();
    BF(1);
    for(int i = 1; i <= n; ++i)
        viz[i] = 0;
    cout<<"\n";
    DF(1);
    /*for(int i=1; i<=n; ++i)
        if(!viz[i])
        {
            cout<<"Componenta "<<++k<<": ";
            BF(i);
            cout<<"\n";
        }*/
    cout<<"\nGradul nodului 2: "<<grad(2);
    cout<<"\nNumarul de muchii este: "<<nrmuchii();
    cout<<"\nNodurile cu grad maxim sunt: ";
    gradMax();
    return 0;
}
