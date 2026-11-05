#include <iostream>
using namespace std;

const int MaxSize = 5;

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

bool QueueEmpty(SqQueue *q)
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

bool DeQueue(SqQueue *q, int &value)
{
    if(QueueEmpty(q))
    {
        return false;
    }

    q->front = (q->front + 1) % MaxSize;
    value = q->data[q->front];
    return true;
}

void DestroyQueue(SqQueue *&q)
{
    delete q;
    q = nullptr;
}

int main() {
    SqQueue* q = nullptr;
    InitQueue(q);

    EnQueue(q, 10);
    EnQueue(q, 20);
    EnQueue(q, 30);
    EnQueue(q, 40);

    int value = 0;

    DeQueue(q, value);
    cout << "Dequeued: " << value << '\n';

    DeQueue(q, value);
    cout << "Dequeued: " << value << '\n';

    // rear 原来在下标 4；这次入队会绕回下标 0。
    if (EnQueue(q, 50)) {
        cout << "Enqueued: 50\n";
    }

    cout << "Remaining: ";
    while (DeQueue(q, value)) {
        cout << value << ' ';
    }
    cout << '\n';

    DestroyQueue(q);
    return 0;
}