#include <stdio.h>
#include <stdlib.h>

void swapxy(int x, int y)
{
    int aux = x;
    x = y;
    y = aux;
}

int main()
{
    int n, v[101], i, j, x;
    scanf("%d %d", &n, &x);

    for(i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    ///Sortare

    for(i=1; i<n; ++i)
    {
        int indice_minim = i;
        for(j=i+1; j<=n; ++j)
            if(v[j]<v[indice_minim])
                indice_minim = j;
        if(i!=indice_minim)
            swapxy(v[i], v[indice_minim]);
    }

    ///Binary search

    int ok = 0, m;
    i = 1, j = n;
    while(i<=j && !ok)
    {
        m=(i+j)/2;
        if(v[m]==x)
        {
            ok = 1;
            printf("Am gasit elementul %d", x);
            break;
        }
        else if(x > v[m])
            i=m+1;
        else j=m-1;
    }
    if(!ok)
        printf("Nu am gasit elementul %d", x);

    return 0;
}
