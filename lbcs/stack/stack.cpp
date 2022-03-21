//stack is a abstract datatype i.e a datatype where we declare a varibale to store value and also declare some operation inside that data type.

//real life example of stack pile of plates, deck of cards, pile of chair, compiler ,
#include <bits/stdc++.h>
using namespace std;

struct ArrayStack
{
    int top;
    int capacity;
    int *arr;
};

typedef struct ArrayStack st;

st *createStack(int cap)
{
    st *s = new st[1];
    s->top = -1;
    s->capacity = cap;
    s->arr = new int[cap];

    return s;
}

bool isFull(st *s)
{
    if (s->top == s->capacity - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty(st *s)
{
    if (s->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(st *s, int item)
{
    if (!isFull(s))
    {
        s->top++;
        s->arr[s->top] = item;
    }
}

int pop(st *s)
{
    int item;
    if (!isEmpty(s))
    {
        item = s->arr[s->top];
        s->top--;
        return item;
    }
    return -1;
}

int main()
{
    st *stack = createStack(5);
    // push(stack,6);
    // push(stack,8);
    // push(stack,7);
    cout << pop(stack) << endl;

    return 0;
}