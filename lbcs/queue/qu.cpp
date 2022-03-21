//real life example is ticket counter,bus stop

#include <bits/stdc++.h>
using namespace std;

struct qArray
{
    int front, rear;
    int capacity;
    int *arr;
};

struct qArray *createQueue(int cap)
{
    struct qArray *q = new struct qArray[1];
    if (!q)
    {
        return NULL;
    }
    q->front = q->rear = -1;
    q->capacity = cap;
    q->arr = new int[cap];
    if (!q->arr)
    {
        return NULL;
    }
    return q;
}

bool isEmpytQueue(struct qArray *q)
{
    return (q->front == -1);
}

bool isFullQueue(struct qArray *q)
{
    return ((q->rear + 1) % q->capacity == q->front);
}

int QueueSize(struct qArray *q)
{
    int a = q->capacity - q->front + q->rear + 1;
    if (a % q->capacity == 0)
    {
        if (a != 0)
            return q->capacity;
        if (a == 0)
            return 0;
    }
    else
    {
        return ((q->capacity - q->front + q->rear + 1) % q->capacity);
    }
}

void enQueue(struct qArray *q, int data)
{
    if (isFullQueue(q))
    {
        cout << "Queue is overflow";
    }
    else
    {

        q->rear = (q->rear + 1) % q->capacity;
        q->arr[q->rear] = data;
        if (q->front == -1)
        {
            q->front = q->rear;
        }
    }
}

int deQueue(struct qArray *q)
{
    int data = -1;
    if (isEmpytQueue(q))
    {
        cout << "Queue is empty\n";
        return -1;
    }
    else
    {
        data = q->arr[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % q->capacity;
        }
    }
    return data;
}

void DeleteQueue(struct qArray *q)
{
    if (q)
    {
        if (q->arr)
        {
            free(q->arr);
        }
        free(q);
    }
}

int main()
{

    struct qArray *q = createQueue(4);
    enQueue(q, 5);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 6);
    cout << "Size of Queue is:" << QueueSize(q) << "\n";
    cout << "deleted number is:" << deQueue(q) << "\n";
    cout << "Size of Queue is:" << QueueSize(q) << "\n";
    return 0;
}