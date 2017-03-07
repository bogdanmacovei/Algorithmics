#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, v[101], i, j, k;
    scanf("%d", &n);

    for(i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    ///Insertion Sort

    for(i=2; i<=n; ++i)
        if(v[i]<v[i-1])
        {
            v[0] = v[i];
            j=i-1;
            while(v[i]<v[j])
                j--;
            j++;
            for(k=i; k>=j+1; --k)
                v[k] = v[k-1];
            v[j] = v[0];
        }

    for(i=1; i<=n; ++i)
        printf("%d ", v[i]);

    return 0;
}
