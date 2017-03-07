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

void afisare(STIVA *top) {
    for(STIVA *p = top; p; p = p->next) {
        std::cout<<p->val<<" ";
    }
    std::cout<<"\n";
}

int search(int arg, STIVA *top) {
    int dist = 0;
    bool ok = false;
    for(STIVA *p = top; p; p = p->next) {
        if(p->val == arg) {
            ok = true;
            break;
        }
        dist++;
    }
    if(!ok) {
        return -1;
    }
    return dist;
}

int main() {
    top = NULL;
    push(1, top);
    push(2, top);
    push(3, top);
    std::cout << pop() << " ";
    std::cout << pop() << " ";
    std::cout << pop() << " ";
    std::cout << pop() << " ";
    push(4, top);
    std::cout << peek(top);

}
