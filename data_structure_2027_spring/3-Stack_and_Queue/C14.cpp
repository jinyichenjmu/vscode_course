#include <iostream>
using namespace std;

const int MaxSize = 100;

struct SqQueue{
    int data[MaxSize];
    int front;
    int rear;
};

void InitQueue(SqQueue *&q)
{
    q = new SqQueue{};
    q->front = 0;
    q->rear = 0;
}

bool QueueEmpty(const SqQueue *q)
{
    return q->front == q->rear;
}

bool EnQueue(SqQueue *q, int value)
{
    if((q->rear + 1) % MaxSize == q->front)
    {
        return false;
    }

    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = value;
    return true;
}

bool DeQueue(SqQueue *q, int &e)
{
    if(QueueEmpty(q))
    {
        return false;
    }

    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}

void DestroyQueue(SqQueue *&q)
{
    delete q;
    q = nullptr;
}

bool Number(int n)
{
    if(n < 1 || n >= MaxSize)
    {
        return false;
    }

    SqQueue *q = nullptr;
    InitQueue(q);

    for(int i = 1; i <= n; i++)
    {
        EnQueue(q, i);
    }

    int e = 0;

    while(!QueueEmpty(q))
    {
        DeQueue(q, e);      //报1
        cout << e << ' ';

        if(!QueueEmpty(q))      //报2
        {
            DeQueue(q, e);
            EnQueue(q, e);
        }
    }
    cout << endl;
    DestroyQueue(q);
    return true;
}

int main() {
    if (!Number(8)) {
        cout << "Invalid number of people.\n";
    }

    return 0;
}