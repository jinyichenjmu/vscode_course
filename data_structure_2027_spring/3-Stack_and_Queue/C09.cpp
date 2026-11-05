#include <iostream>
using namespace std;

const int MaxSize = 10;

struct SqQueue{
    int data[MaxSize];
    int front;
    int rear;
};

void InitQueue(SqQueue *&q)
{
    q = new SqQueue{};
    q->front = -1;
    q->rear = -1;
}

bool QueueEmpty(SqQueue *q)
{
    return q->front == q->rear;
}

bool EnQueue(SqQueue *q, int value)
{
    if(q->rear == MaxSize - 1)
    {
        return false;
    }

    q->data[++q->rear] = value;
    return true;
}

bool DeQueue(SqQueue *q, int &e)
{
    if(QueueEmpty(q))
    {
        return false;
    }

    e = q->data[++q->front];
    return true;
}

void DestroyQueue(SqQueue *&q)
{
    delete q;
    q = nullptr;
}

int main(){
    SqQueue *q = nullptr;
    InitQueue(q);

    cout << boolalpha;
    cout << "Empty: " << QueueEmpty(q) << endl;

    EnQueue(q, 10);
    EnQueue(q, 20);
    EnQueue(q, 30);

    int value = 0;
    if(DeQueue(q, value))
    {
        cout << "DeQueue: " << value << endl;
    }

    if (DeQueue(q, value)) {
        cout << "Dequeued: " << value << '\n';
    }

    cout << "Empty now: " << QueueEmpty(q) << '\n';

    DestroyQueue(q);
    return 0;
}