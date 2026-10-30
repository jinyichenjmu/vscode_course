#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LinkNode;

int main()
{
    LinkNode *head = new LinkNode{0,nullptr};
    LinkNode *first = new LinkNode{10,nullptr};
    LinkNode *second = new LinkNode{20,nullptr};

    head->next = first;
    first->next = second;

    LinkNode *s = new LinkNode{15,nullptr};
    LinkNode *p = first;

    s->next = p->next;
    p->next = s;

    LinkNode *current = head->next;

    while(current != nullptr)
    {
        cout << current->data << ' ';
        current = current->next;
    }
    cout << endl;

    current = head;

    while(current != nullptr){
        LinkNode *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;

    return 0;
}