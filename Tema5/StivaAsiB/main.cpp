#include <iostream>
#include <string.h>

using namespace std;

typedef struct nod
{
    char val;
    nod *next;
} STIVA;

char sir[100];
STIVA *top;

void push(int arg, STIVA *&top) {
    STIVA *p = new STIVA;
	p->val = arg;
	p->next = top;
	top = p;
}

bool empty(STIVA *top) {
    return (top == NULL);
}

int pop() {
	if(empty(top)) {
		std::cout<<"Stack underflow!\n";
		return -1;
	}
	STIVA *p = top;
	top = top->next;
	int v = p->val;
	delete p;
	return v;
}

int peek(STIVA *top) {
    if(empty(top)) {
        std::cout<<"Stack underflow!\n";
        return -1;
    }
    return top->val;
}

int main()
{
    int n;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
        std::cin>>sir[i];

    for(int i = 0; i < n; ++i) {
        if(empty(top))
            push(sir[i], top);
        else {
            if(sir[i]==peek(top))
                push(sir[i], top);
            else
                pop();
        }
    }
    if(empty(top))
        std::cout<<"Este corect";
    else
        std::cout<<"Nu este corect";
}
