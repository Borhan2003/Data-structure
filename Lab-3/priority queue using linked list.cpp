#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node *next;
    Node *prev;
};

Node *head = 0;
Node *tail = 0;
int size = 0;

void addFirst(int item, int prio)
{
    Node *nn = new Node;
    nn->data = item;
    nn->priority = prio;
    nn->next = head;
    nn->prev = 0;
    if (head == NULL)
        tail = nn;
    if (head != 0)
        head->prev = nn;
    head = nn;
    size++;
}

void addLast(int item, int prio)
{
    if (head == NULL)
    {
        addFirst(item, prio);
        return;
    }
    Node *nn = new Node;
    nn->data = item;
    nn->priority = prio;
    nn->next = 0;
    nn->prev = tail;
    tail->next = nn;
    tail = nn;
    size++;
}

void Insert(int prio, int item)
{
    if (size == 0)
    {
        addFirst(item, prio);
    }
    else
    {
        Node *t = head;
        while (t && t->priority <= prio)
        {
            t = t->next;
        }
        if (t == 0)
        {
            addLast(item, prio);
            return;
        }
        else if (t == head)
        {
            addFirst(item, prio);
            return;
        }
        Node *cur = t;
        Node *prev = cur->prev;
        Node *nn = new Node;
        nn->priority = prio;
        nn->data = item;
        nn->next = cur;
        nn->prev = prev;
        prev->next = nn;
        cur->prev = nn;
        size++;
    }
}

void Delete()
{
    if (head == 0)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = 0;
    else
        tail = NULL;
    delete temp;
    size--;
}

void Print()
{
    Node *t = head;
    while (t)
    {
        cout << "Data:" << t->data << " Priority:" << t->priority << endl;
        t = t->next;
    }
    cout << endl;
}

int main()
{
    Insert(10, 1);
    Insert(2, 2);
    Insert(3, 3);
    Insert(3, 4);
    Insert(4, 5);
    Insert(2, 99);
    Print();

    Delete();
    Delete();
    Delete();
    Delete();
    Delete();
    cout << "After Deletion:" << endl;
    Insert(7, 10);
    Print();

    return 0;
}
