#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int v[100];

    for(i=0; i<n; ++i)
        scanf("%d", &v[i]);

    ///Selection Sort

    for(i=0; i<n-1; ++i)
    {
        int indice_minim = i;
        for(j=i+1; j<n; ++j)
            if(v[j]<v[indice_minim])
                indice_minim = j;
        if(i!=indice_minim)
        {
            v[n] = v[i];
            v[i] = v[indice_minim];
            v[indice_minim] = v[n];
        }
    }

    for(i=0; i<n; ++i)
        printf("%d ", v[i]);
}
