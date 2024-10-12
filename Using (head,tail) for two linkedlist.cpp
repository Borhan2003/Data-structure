#include<bits/stdc++.h>
using namespace std;
// many problem we may have to return head and tail at the same time . But , it is not possible as function return one pointer .
//so using struct for making list class , and returning list . which contai two pointer ,head and tail .
struct Node{
    int data;
    Node* next;
};

struct List{
    Node* head = 0;
    Node* tail = 0;
};
List addFirst(List lst, int val)
{
    Node* nn = new Node;
    nn->data = val;
    nn->next = lst.head;
    lst.head = nn;
    if(lst.head == 0) {
        lst.tail = nn;
    }

    return lst;
}
/// 8 6 5
List addLast(List lst, int val)
{
    Node* nn = new Node;
    nn->data = val;
    nn->next = 0;
    
    if(lst.head == 0) {
        lst.head = lst.tail = nn;
        return lst;
    }

    (lst.tail)->next = nn;
    lst.tail = nn;
    return lst;
}
void Print(List lst)
{
    while(lst.head != 0)
    {
        cout << lst.head->data << " ";
        lst.head = lst.head->next;
    }
}
int main()
{
    List list1;


    list1 = addFirst(list1, 6);
    list1 = addFirst(list1, 7);
    list1 = addFirst(list1, 8);
    list1 = addFirst(list1, 9);
    Print(list1);

    return 0;
}


