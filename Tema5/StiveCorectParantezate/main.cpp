#include <iostream>

using namespace std;

typedef struct stiva
{
    char val;
    stiva *next;
} STIVA;

STIVA *top;

void push(int arg, STIVA *&top)
{
    STIVA *p = new STIVA;
	p->val = arg;
	p->next = top;
	top = p;
}

bool empty(STIVA *top)
{
    return (top == NULL);
}

int pop()
{
	if(empty(top))
    {
		std::cout<<"Stack underflow!\n";
		return -1;
	}
	STIVA *p = top;
	top = top->next;
	int v = p->val;
	delete p;
	return v;
}

int peek(STIVA *top)
{
    if(empty(top))
    {
        std::cout<<"Stack underflow!\n";
        return -1;
    }
    return top->val;
}

bool corectParantezare(STIVA *&top, int &n, int &k)
{
    for(int i = 1; i <= n; i++)
    {
        char c;
        std::cin>>c;

        if(c=='(')
            push('(', top);

        else if(c==')')
        {

            if(!empty(top) && peek(top) == '(')
            {
                pop();
            }
            else
            {
                k = i;
                return false;
            }

        }
        else
        {
            std::cout<<"Invalid! Introduceti ( sau ): ";
            n++;
        }
    }

    return empty(top);
}

int main()
{
    int n, k;
    cin>>n;
    if(corectParantezare(top, n, k))
        cout<<"Corect parantezate!";
    else
        cout<<"Nu sunt corect parantezate, cu eroare la pozitia " << k;

    return 0;
}
