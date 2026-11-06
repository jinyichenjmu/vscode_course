#include <iostream>
using namespace std;

const int MaxSize = 5;

struct Deque{
    int data[MaxSize];
    int front;
    int rear;
};

void InitDeque(Deque *&q)
{
    q = new Deque{};
    q->front = 0;
    q->rear = 0;
};

bool DequeEmpty(Deque *q)
{
    return q->front == q->rear;
}

bool DequeFull(Deque *q)
{
    return (q->rear + 1) % MaxSize == q->front;
}

bool PushRear(Deque *q, int e)
{
    if(DequeFull(q))
    {
        return false;
    }

    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

// 从前端入队：先写 front，再让 front 后退。
bool PushFront(Deque *q, int e)
{
    if(DequeFull(q))
    {
        return false;
    }

    q->data[q->front] = e;
    q->front = (q->front - 1 + MaxSize) % MaxSize;
    return true;
}

// 从后端出队：先取 rear，再让 rear 后退。
bool PopRear(Deque *q, int &e)
{
    if(DequeEmpty(q))
    {
        return false;
    }

    e = q->data[q->rear];
    q->rear = (q->rear - 1 + MaxSize) % MaxSize;
    return true;
}


bool PopFront(Deque *q, int &e)
{
    if(DequeEmpty(q))
    {
        return false;
    }

    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}

void DestroyDeque(Deque *&q)
{
    delete q;
    q = nullptr;
}

int main() {
    Deque* q = nullptr;
    InitDeque(q);

    PushRear(q, 1);
    PushRear(q, 2);
    PushRear(q, 3);

    int e = 0;

    if (PopRear(q, e)) {
        cout << "Back out: " << e << '\n';
    }

    PushFront(q, 4);

    cout << "Front to back: ";
    while (PopFront(q, e)) {
        cout << e << ' ';
    }
    cout << '\n';

    DestroyDeque(q);
    return 0;
}