#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Linked
{
public:
    Node *head = 0;
    Node *tail = 0;
    int size = 0;

    void print()
    {
        Node *t = head;

        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
    void addfirst(int val)
    {

        Node *nn = new Node;
        nn->next = head;
        nn->data = val;
        head = nn;
        size++;
        if (head == 0)
            tail = nn;
    }
    void Insert(int val, int pos)
    {
        Node *nn = new Node;
        nn->data = val;
        if (pos == 1)
        {
            nn->next = head;
            head = nn;
            size++;
        }
        else if (pos == size + 1)
        {
            tail->next = nn;
            nn->next = 0;
            tail = nn;
            size++;
        }
        else
        {
            Node *prev = head;
            Node *cur;
            for (int i = 1; i <= pos - 2; i++)
            {
                prev = prev->next;
            }
            cur = prev->next;
            nn->next = prev->next;
            prev->next = nn;
            size++;
        }
    }
    void InsertLast(int val)
    {
        Node *nn = new Node;
        if (head == 0)
        {
            nn->data = val;
            head = nn;
            tail = nn;
            nn->next = 0;
            size++;
            return;
        }

        nn->data = val;

        tail->next = nn;
        tail = nn;
        tail->next = 0;
        size++;
    }
    void Delete(int pos)
    {
        if (pos == 1)
        {
            Node *p = head;
            head = head->next;
            delete p;
            size--;
            return;
        }
        Node *prev = head;
        Node *cur;
        for (int i = 1; i <= pos - 2; i++)
        {
            prev = prev->next;
        }
        cur = prev->next;
        prev->next = cur->next;
        tail=prev;

        delete cur;
    }
};

int main()
{
    cout << "hello" << endl;
    Linked l1, l2, l3;

    l1.InsertLast(0);
    l1.InsertLast(1);
    l1.InsertLast(2);
    l1.InsertLast(3);
    l1.print();
    l2.addfirst(-1);
    l2.addfirst(-2);
    l2.addfirst(-3);
    l2.print();
    l3 = l2;
    l3.print();

    l1.tail->next = l2.head;
    l1.tail = l2.tail;
    l1.print();
    l1.Delete(1);
    l1.Insert(8, 3);
     l1.Delete(7);
    l1.print();
    cout<<l1.tail->data;

    return 0;
}
