#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
  Node *prev;
};
Node *head = 0;
Node *tail = 0;
int SIZE = 0;
void addFirst(int item)
{
  Node *nn = new Node;
  nn->data = item;
  nn->next = head;
  nn->prev = 0;
  if (head == NULL)
    tail = nn;
  if (head != 0) // _ _ _ _
    head->prev = nn;
  head = nn;
  SIZE++;
}
void addLast(int item)
{
  if (head == NULL)
  {
    addFirst(item);
    return;
  }
  Node *nn = new Node;
  nn->data = item;
  nn->next = 0;
  nn->prev = tail;
  tail->next = nn;
  tail = nn;
  SIZE++;
}
void Insert(int pos, int item)
{
  if (pos == 1)
    addFirst(item);
  else if (pos == SIZE + 1)
    addLast(item);
  else
  {
    Node *nn = new Node;
    nn->data = item;
    Node *pre = head;
    for (int i = 1; i <= pos - 2; i++)
      pre = pre->next;
    Node *cur = pre->next;
    nn->next = cur; //_ _ - _ _ _
    nn->prev = pre;
    cur->prev = nn;
    pre->next = nn;
    SIZE++;
  }
}
void headdlt()
{
  Node *temp = head;
  head = head->next;
  if (head != NULL)
    head->prev = 0;
  delete temp;
  SIZE--;
}
void taildlt()
{
  Node *temp = tail;
  tail = tail->prev;
  if (tail != NULL)
    tail->next = 0;
  delete temp;
  SIZE--;
}
void Delete(int pos)
{
  if (SIZE == 0 or pos < 1 or pos > SIZE)
  {
    cout << "Invalid position!" << endl;
    return;
  }
  if (pos == 1)
  {
    headdlt();
    return;
  }
  else if (pos == SIZE)
  {
    taildlt();
    return;
  }
  else
  {
    Node *pre = head;
    for (int i = 1; i < pos - 1; i++)
      pre = pre->next;
    Node *cur = pre->next; //_ _ _ _ _
    Node *nextNode = cur->next;
    pre->next = nextNode;
    nextNode->prev = pre;
    delete cur;
    SIZE--;
  }
}
void Print(bool ltor)
{
  if (ltor)
  {
    cout << "Left to Right : ";
    Node *ptr = head;
    while (ptr)
    {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
    cout << endl;
  }
  else
  {
    cout << "Right to Left : ";
    Node *ptr = tail;
    while (ptr)
    {
      cout << ptr->data << " ";
      ptr = ptr->prev;
    }
    cout << endl;
  }
}

int main()
{
  addLast(10);
  addLast(11);
  addLast(12);
  addLast(13);
  Print(1);
  // Print(0);
  Insert(3, 14);
  Print(1);
  Delete(2);
  Print(1);
}