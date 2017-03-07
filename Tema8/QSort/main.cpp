#include <iostream>
#include <cstdlib>

void swapv(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

void QSort(int st, int dr, int *v)
{
	int i = st, j = dr;
	int pivot = v[st+rand()%(dr-st+1)];
	while(i<=j)
	{
		while(v[i] < pivot) i++;
		while(v[j] > pivot) j--;
		if(i<=j)
		{
			swapv(v[i], v[j]);
			i++;
			j--;
		}
	}
	if(st<j)
		QSort(st, j, v);
	if(i<dr)
		QSort(i, dr, v);
}

int main()
{
    int v[100], n;
    std::cin>>n;
    for(int i=0; i<n; ++i)
        std::cin>>v[i];
    QSort(0, n-1, v);
    for(int i=0; i<n; ++i)
        std::cout<<v[i]<<" ";
}
