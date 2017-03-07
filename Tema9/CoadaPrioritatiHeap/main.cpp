#include <iostream>

using namespace std;

struct heapStruct
{
    int cheie, prioritate;
}heap[101];

int n;

void insert(int key, int pr)
{
	n++;
	int i = n; // unde am inserat noul element
	while(i > 1 && heap[i/2].prioritate < pr)
	{
		heap[i] = heap[i/2];
		i=i/2;
	}
	heap[i].prioritate = pr;
	heap[i].cheie = key;
}

int maximum()
{
    if(heap[1].cheie)
        return heap[1].cheie;
    return -12;
}

void Max_Heapify(int i)
{
	int left = 2*i; // 1<<i
	int right = 2*i+1; // (1<<i)|1;
	int index_max = i;
	if(left <= n && heap[left].prioritate > heap[index_max].prioritate)
		index_max = left;
	if(right <= n && heap[right].prioritate > heap[index_max].prioritate)
		index_max = right;
	if(index_max != i)
	{
		swap(heap[i], heap[index_max]);
		Max_Heapify(index_max);
	}
}

int extragere_max()
{
	swap(heap[1], heap[n]);
	int r = heap[n].cheie;
	n--;
	Max_Heapify(1);
	return r;
}

void afisare()
{
    for(int i=1; i<=n; ++i)
        cout<<"("<<heap[i].cheie<<", "<<heap[i].prioritate<<") ";
}

int main()
{
    int n = 6;
    insert(2, 2); insert(1, 1); insert(3, 3);
    insert(33, 3); insert(11, 1); insert(22, 2);

    afisare();
    cout<<"\n";

    cout<<"Elementul maxim: "<<maximum();
    cout<<"\n";

    extragere_max();

    afisare();
}
