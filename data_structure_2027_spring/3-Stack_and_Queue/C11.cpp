#include <iostream>
using namespace std;

const int MaxSize = 5;
struct QuType{
    int data[MaxSize];
    int front;
    int count;
};

void InitQueue(QuType *&q)
{
    q = new QuType{};
    q->front = 0;
    q->count = 0; 
}

bool QueueEmpty(QuType *q)
{
    return q->count == 0;
}

bool EnQueue(QuType *q, int value)
{
    if(q->count == MaxSize)
    {
        return false;
    }

    int rear = (q->front + q->count) % MaxSize;
    rear = (rear + 1) % MaxSize;

    q->data[rear] = value;
    q->count ++;
    return true;
}

bool DeQueue(QuType *q, int &value)
{
    if(QueueEmpty(q))
    {
        return false;
    }

    q->front = (q->front + 1) % MaxSize;
    value = q->data[q->front];
    
    q->count --;

    return true;
}

void DestroyQueue(QuType *&q)
{
    delete q;
    q = nullptr;
}

int main() {
    QuType* q = nullptr;
    InitQueue(q);

    for (int value = 10; value <= 50; value += 10) {
        EnQueue(q, value);
    }

    cout << "Count: " << q->count << '\n';

    if (!EnQueue(q, 60)) {
        cout << "Queue full\n";
    }

    int value = 0;

    DeQueue(q, value);
    cout << "Dequeued: " << value << '\n';

    // 出队腾出空间后，可以再次入队。
    EnQueue(q, 60);

    cout << "Remaining: ";
    while (DeQueue(q, value)) {
        cout << value << ' ';
    }
    cout << '\n';

    DestroyQueue(q);
    return 0;
}