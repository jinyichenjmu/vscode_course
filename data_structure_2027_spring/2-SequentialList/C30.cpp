#include <iostream>
using namespace std;

const int MaxCol = 10;

struct DList{
    int data[MaxCol];
    DList *next;
};

struct HList{
    int Row;
    int Col;
    DList *next;
};

HList *CreateTable(int col)
{
    HList *h = new HList{0,col,nullptr};
    return h;
}

void AppendRow(HList *h, const int values[])
{
    DList *s = new DList{};

    for(int i = 0;i<h->Col;i++)
    {
        s->data[i] = values[i];
    }

    s->next = nullptr;

    if(h->next == nullptr)
    {
        h->next = s;
    }
    else
    {
        DList *r = h->next;
        while(r->next != nullptr)
        {
            r = r->next;
        }

        r->next = s;
    }

    h->Row ++;
}

void DispTable(HList *h)
{
    DList *p = h->next;

    while(p != nullptr)
    {
        for(int i = 0;i<h->Col;i++)
        {
            cout << p->data[i] << ' ';
        }

        cout << endl;
        p = p->next;
    }
}

HList *LinkTable(HList *A, HList *B, int colA, int colB)
{
    if(colA < 1 || colA > A->Col || colB < 1 || colB > B->Col || A->Col + B->Col > MaxCol)
    {
        return nullptr;
    }

    HList *C = CreateTable(A->Col + B->Col);

    for(DList *p = A->next; p != nullptr; p = p->next)
    {
        for(DList *q = B->next; q != nullptr; q = q->next)
        {
            if(p->data[colA - 1] == q->data[colB - 1])
            {
                int values[MaxCol]{};

                for(int i = 0; i<A->Col; i++)
                {
                    values[i] = p->data[i];
                }

                for(int i = 0; i<B->Col; i++)
                {
                    values[A->Col + i] = q->data[i];
                }

                AppendRow(C, values);
            }
        }
    }
    return C;
}

void DestroyTable(HList *&h)
{
    if(h == nullptr)
    {
        return;
    }

    DList *p = h->next;

    while(p != nullptr)
    {
        DList *next = p->next;
        delete p;
        p = next;
    }

    delete h;
    h = nullptr;
}

int main()
{
    HList* A = CreateTable(3);
    HList* B = CreateTable(2);

    int a1[] = {1, 2, 3};
    int a2[] = {2, 3, 3};
    int a3[] = {1, 1, 1};

    int b1[] = {3, 5};
    int b2[] = {1, 6};
    int b3[] = {3, 4};

    AppendRow(A, a1);
    AppendRow(A, a2);
    AppendRow(A, a3);

    AppendRow(B, b1);
    AppendRow(B, b2);
    AppendRow(B, b3);

    // 比较 A 的第 3 列和 B 的第 1 列。
    HList* C = LinkTable(A, B, 3, 1);

    if (C != nullptr) {
        cout << "Result:\n";
        DispTable(C);
        cout << "Rows: " << C->Row << '\n';
    }

    DestroyTable(A);
    DestroyTable(B);
    DestroyTable(C);

    return 0;
}