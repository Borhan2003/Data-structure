#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Link
{
public:
    Node *head;
    int size;
    Link()
    {
        head = 0;
        size = 0;
    }
    void Insert(int val)
    {
        Node *nn = new Node;
        if (head == 0)
        {
            nn->data = val;
            head = nn;
            nn->next = 0;
            size++;
            return;
        }
        Node *t = head;
        nn->data = val;

        while (t->next)
        {
            t = t->next;
        }
        t->next = nn;
        nn->next = 0;
        size++;
    }
    void addfirst(int val)
    {
        Node *nn = new Node;
        nn->next = head;
        head = nn;
        nn->data = val;
        size++;
    }
    void Insert(int val, int pos)
    {
        if (pos == 1)
        {
            Node *nn = new Node;
            nn->data = val;
            nn->next = head;
            head = nn;
            size++;
        }
        else if (pos == (size + 1))
        {
            Node *nn = new Node;

            nn->data = val;
            Node *t = head;
            while (t->next)
            {
                t = t->next;
            }
            t->next = nn;
            nn->next = 0;
            size++;
        }
        else
        {
            Node *nn = new Node;
            nn->data = val;
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
    void Delete(int pos)
    {
        Node *prev = head;
        Node *cur;

        for (int i = 1; i <= pos - 2; i++)
        {
            prev = prev->next;
        }
        if (size == 1 and pos == 1)
        {
            head = 0;
            delete prev;
        }
        if (pos == 1)
        {
            Node *t = head;
            head = prev->next;
            delete t;
            size--;
            return;
        }

        cur = prev->next;
        prev->next = cur->next;
        delete cur;
        size--;
    }
    void Print()
    {
        Node *t = head;
        if (size == 0)
        {
            cout << "NO value" << endl;
            return;
        }
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

void Merge(Link &l1, Link &l2)
{
    Node *t1 = l2.head;
    while (t1)
    {
        l1.Insert(t1->data);
        t1 = t1->next;
    }
}
void Sort(Link &l)
{
    Node *t = l.head;
    while (t)
    {
        Node *min = t;
        Node *cur = min->next;
        while (cur)
        {
            if (cur->data < min->data)
            {
                min = cur;
            }
            cur = cur->next;
        }
        if (min != t)
        {
            swap(min->data, t->data);
        }
        t = t->next;
    }
}
int main()
{
    Link l1, l2;
    int n1, n2;
    cin >> n1 >> n2;
    for (int i = 1; i <= n1; i++)
    {
        int x;
        cin >> x;
        l1.Insert(x);
    }
    for (int i = 1; i <= n2; i++)
    {
        int x;
        cin >> x;
        l2.Insert(x);
    }
    l1.Print();
    l2.Print();
    // Merge(l1, l2);
    Sort(l1);
    l1.Print();

    return 0;
}
