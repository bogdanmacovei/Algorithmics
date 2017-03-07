#include <iostream>

typedef struct nod
{
    int _val, _index;
    nod *_next;
}NOD;

NOD *prim1, *ultim1, *prim2, *ultim2, *prim3, *ultim3, *prim4, *ultim4;

void adaug_final(int val, int index, NOD *&prim, NOD *&ultim)
{
    NOD *newNod = new NOD;
    newNod->_val = val;
    newNod->_index = index;
    if(ultim == NULL)
    {
        prim = ultim = newNod;
        ultim->_next = NULL;
    }
    else
    {
        ultim->_next = newNod;
        newNod->_next = NULL;
        ultim = newNod;
    }
}

int maxIndex_lista(NOD *prim)
{
    int maxIndex = 0;
    for(NOD *newNod = prim; newNod; newNod = newNod->_next)
    {
        if(newNod->_index > maxIndex)
            maxIndex = newNod->_index;
    }
    return maxIndex;
}

int caut_nod(int index, NOD *prim)
{
    for(NOD *newNod = prim; newNod; newNod = newNod->_next)
        if(newNod->_index == index)
            return newNod->_val;
    return 0;
}

void suma_liste(NOD *prim1, NOD *ultim1, NOD *prim2, NOD *ultim2, NOD *&prim3, NOD *&ultim3)
{
    int index1 = maxIndex_lista(prim1);
    int index2 = maxIndex_lista(prim2);
    int index = index1>index2?index1:index2;
    for(int i=1; i<=index; ++i)
    {
        int S = caut_nod(i, prim1) + caut_nod(i, prim2);
        if(S)
            adaug_final(S, i, prim3, ultim3);
    }
}

void produs_liste(NOD *prim1, NOD *ultim1, NOD *prim2, NOD *ultim2, NOD *&prim4, NOD *&ultim4)
{
    for(NOD *newNod = prim1; newNod; newNod = newNod->_next)
    {
        int p = newNod->_val * caut_nod(newNod->_index, prim2);
        if(p)
            adaug_final(p, newNod->_index, prim4, ultim4);
    }
}

void afisare_lista(NOD *prim)
{
    for(NOD *newNod = prim; newNod; newNod = newNod->_next)
        std::cout << newNod->_val << " " << newNod->_index << "\n";
    std::cout << "\n";
}

int main()
{
    prim1 = prim2 = prim3 = ultim1 = ultim2 = ultim3 = NULL;

    /// Implementare exemplu

    adaug_final(8, 2, prim1, ultim1);
    adaug_final(9, 6, prim1, ultim1);
    adaug_final(16, 10, prim1, ultim1);
    adaug_final(5, 13, prim1, ultim1);

    adaug_final(4, 2, prim2, ultim2);
    adaug_final(3, 4, prim2, ultim2);
    adaug_final(5, 8, prim2, ultim2);
    adaug_final(10, 10, prim2, ultim2);
    adaug_final(18, 11, prim2, ultim2);
    adaug_final(3, 14, prim2, ultim2);
    adaug_final(9, 15, prim2, ultim2);

    std::cout << "Lista 1: ";
    afisare_lista(prim1);

    std::cout << "Lista 2: ";
    afisare_lista(prim2);

    suma_liste(prim1, ultim1, prim2, ultim2, prim3, ultim3);

    std::cout << "Suma liste: ";
    afisare_lista(prim3);

    produs_liste(prim1, ultim1, prim2, ultim2, prim4, ultim4);

    std::cout << "Produs liste: ";
    afisare_lista(prim4);
}
