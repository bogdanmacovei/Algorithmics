#include <iostream>

typedef struct nod
{
    int info;
    nod *next;
}NOD;

NOD *prim, *ultim;

void push(int val, NOD *&prim, NOD *&ultim)
{
	if(prim==NULL)
    {
		prim=new NOD;
		prim->info = val;
		prim->next = NULL;
		ultim = prim;
	}
	else
    {
		NOD *p = new NOD;
		p->info = val;
		p->next = NULL;
		ultim->next = p;
		ultim = p;
	}
}

bool empty(NOD *prim)
{
    return (prim==NULL);
}

int pop(NOD *&prim, NOD *&ultim)
{
	if(prim==NULL)
    {
		return -1;
	}
    else if(prim == ultim)
    {
		int v = prim->info;
		delete prim;
		prim = ultim = NULL;
		return v;
	}
	else
    {
		int v = prim->info;
		NOD *p = prim;
		prim = prim->next;
		delete p;
		return v;
	}
}

int peek(NOD *prim)
{
    if(!prim)
    {
        return -1;
    }
    return prim->info;
}

void afisare(NOD *prim)
{
    for(NOD *p = prim; p; p = p->next)
        std::cout<<p->info<<" ";
    std::cout<<"\n";
}

int search(int arg, NOD *prim)
{
    bool ok = false;
    int dist = 0;
    for(NOD *p = prim; p; p = p->next)
    {
        if(p->info==arg)
        {
            ok = true;
            break;
        }
        dist++;
    }
    if(!ok)
    {
        return -1;
    }
    return dist;
}

int main()
{
    prim = ultim = NULL;
    push(1, prim, ultim);
    push(2, prim, ultim);
    push(3, prim, ultim);
    std::cout << pop(prim, ultim) << " ";
    std::cout << pop(prim, ultim) << " ";
    std::cout << pop(prim, ultim) << " ";
    std::cout << pop(prim, ultim) << " ";
    push(4, prim, ultim);
    std::cout << peek(prim);
    return 0;
}
