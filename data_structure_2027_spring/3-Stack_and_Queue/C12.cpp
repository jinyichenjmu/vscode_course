#include <iostream>
using namespace std;

struct DataNode{
    int data;
    DataNode *next;
};

struct LinkQueue{
    DataNode *front;
    DataNode *rear;
};

void InitQueue(LinkQueue *&q)
{
    q = new LinkQueue{nullptr,nullptr};
}

bool QueueEmpty(LinkQueue *q)
{
    return q->front == nullptr;
}

void EnQueue(LinkQueue *q, int e)
{
    DataNode *s = new DataNode{e, nullptr};

    if(q->front == nullptr)
    {
        q->front = s;
        q->rear = s;
    }
    else
    {
        q->rear->next = s;
        q->rear = s;
    }
}

bool DeQueue(LinkQueue *q, int &e)
{
    if(QueueEmpty(q))
    {
        return false;
    }

    DataNode *p = q->front;
    e = p->data;
    q->front = p->next;

    if(q->front == nullptr)
    {
        q->rear = nullptr;
    }

    delete p;
    return true;
}

void DestroyQueue(LinkQueue *&q)
{
    DataNode *p = q->front;
    while(p != nullptr)
    {
        DataNode *next = p->next;
        delete p;
        p = next;
    }
    delete q;
    q = nullptr;
}

int main() {
    LinkQueue* q = nullptr;
    InitQueue(q);

    cout << boolalpha;
    cout << "Empty: " << QueueEmpty(q) << '\n';

    EnQueue(q, 10);
    EnQueue(q, 20);
    EnQueue(q, 30);

    int value = 0;

    while (DeQueue(q, value)) {
        cout << "Dequeued: " << value << '\n';
    }

    cout << "Empty now: " << QueueEmpty(q) << '\n';

    DestroyQueue(q);
    return 0;
}