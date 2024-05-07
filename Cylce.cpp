#include <iostream>
using namespace std;

class Cycle;

class Node
{
public:
	int value = 0;
	class Node *nextPtr = NULL;
    class Node *prevPtr = NULL;
    friend class Cycle;
};

class Cylce
{
    int count = 0;
    Node *root = new Node;
public:
    Cylce(int val = 0);
    int getCout() {return count;};
    Node* Prev(Node *elem) {return elem->prevPtr;};
    Node* Next(Node  *elem) {return elem->nextPtr;};
    Node* Add(Node *par, int val=0);
    Node* swap(Node *first, Node *sec);
    void print(Node *start);
    void del(Node *elem);
};

Cylce::Cylce(int val)
{
    root->value = val;
    root->prevPtr = root;
    root->nextPtr = root;
    count = 1;
}

Node* Cylce::Add(Node *par, int val)
{
    Node *elem = new Node();
    Node *next = Next(par);
    elem->value = val;
    elem->prevPtr = par;
    elem->nextPtr = par->nextPtr;
    par->nextPtr = elem;
    elem->nextPtr->prevPtr = elem;
    count++;
    
    return elem;
}
Node* Cylce::swap(Node *first, Node *sec)
{
    Node *prev1 = first->prevPtr;
    Node *prev2 = sec->prevPtr;
    Node *next1 = first->nextPtr;
    Node *next2 = sec->nextPtr;
    if (sec == next1) 
    {
        sec->nextPtr = first;
        sec->prevPtr = prev1;
        first->nextPtr = next2;
        first->prevPtr = sec;
        next2->prevPtr = first;
        prev1->nextPtr = sec;
    }
    else if (first == next2) 
    {
        first->nextPtr = sec;
        first->prevPtr = prev2;
        sec->nextPtr = next1;
        sec->prevPtr = first;
        next1->prevPtr = sec;
        prev2->nextPtr = first;
    }
    else 
    {
        prev1->nextPtr = sec;
        sec->nextPtr = next1;
        prev2->nextPtr = first;
        first->nextPtr = next2;
        sec->prevPtr = prev1;
        next2->prevPtr = first;
        first->prevPtr = prev2;
        next1->prevPtr = sec;
    }
    if (first == root)
        return(sec);
    if (sec == root)
        return(first);
    return(root);
}

void Cylce::print(Node *start)
{
    Node *el = start;
    for (int i=0; i<count; i++)
    {
        cout << el;
        el = Next(el);
    }
}
void Cylce::del(Node *elem)
{
    elem->nextPtr->prevPtr = elem->prevPtr;
    elem->prevPtr->nextPtr = elem->nextPtr;
    count--;
}

int main()
{

}
