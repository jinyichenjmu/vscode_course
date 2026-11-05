#include <iostream>
using namespace std;

struct LinkNode{
    int data;
    LinkNode *next;
};

void InitQueue(LinkNode *&rear)
{
    rear = nullptr;
}

bool QueueEmpty(LinkNode *rear)
{
    return rear == nullptr;
}

void EnQueue(LinkNode *&rear, int e)
{
    LinkNode *s = new LinkNode{e, nullptr};

    if(rear == nullptr)
    {
        s->next = s;
        rear = s; 
    }
    else
    {
        s->next = rear->next;
        rear->next = s;
        rear = s;
    }
}

bool DeQueue(LinkNode *&rear, int &e)
{
    if(QueueEmpty(rear))
    {
        return false;
    }

    LinkNode *p = rear->next;
    e = p->data;

    if(p == rear)
    {
        rear = nullptr;
    }
    else
    {
        rear->next = p->next;
    }

    delete p;
    return true;
}

void DestroyQueue(LinkNode *&rear)
{
    int value;

    while(DeQueue(rear, value))
    {
        //释放结点
    }
}

int main() {
    LinkNode* rear = nullptr;
    InitQueue(rear);

    cout << boolalpha;
    cout << "Empty: " << QueueEmpty(rear) << '\n';

    EnQueue(rear, 10);
    EnQueue(rear, 20);
    EnQueue(rear, 30);

    int value = 0;

    while (DeQueue(rear, value)) {
        cout << "Dequeued: " << value << '\n';
    }

    cout << "Empty now: " << QueueEmpty(rear) << '\n';

    DestroyQueue(rear);
    return 0;
}