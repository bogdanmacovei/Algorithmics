#include <iostream>

typedef struct stiva {
    int val;
    stiva *next;
} STIVA;

STIVA *top;

void push(int arg, STIVA *&top) {
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

bool corectPin(int *v, int n, STIVA *&top)
{
    for(int i = 1; i <= n; i++)
    {
        if(empty(top) || peek(top) < v[i])
            push(v[i], top);

        else if(v[i] == peek(top))
            pop();

            else
                return false;
    }

    return true;
}

int main()
{
    int n;
    n = 8;
    int v[] = {0, 1, 2, 2, 1, 3, 3, 4, 4};
    if(corectPin(v, n, top))
        std::cout<<"Corect";
    else
        std::cout<<"Incorect";
    return 0;
}
