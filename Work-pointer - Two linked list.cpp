#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* addLast(Node* start, int item)
{
    Node* nn = new Node;
    nn->data = item;
    nn->next = 0;
    if(start == 0) {
        start = nn;
        return start;
    }
    Node* ptr = start;
    while(ptr->next != 0) {
        ptr = ptr->next;
    }
    ptr->next = nn;
    return start;
}
void Print(Node* start)
{
    Node* ptr = start;
    while(ptr != 0) {
        cout << (*ptr).data << " ";
        ptr = (*ptr).next;
    }
    cout << endl;
}
Node* Merge(Node* head1, Node* head2)
{
    if(head1 == 0) {
        head1 = head2;
        return head1;
    }
    Node* ptr = head1;
    while(ptr->next != 0) {
        ptr = ptr->next;
    }
    ptr->next = head2;
}
int main()
{

    Node* list1 = 0;
    Node* list2 = 0;

    list2 = addLast(list2, 3);
    list2 = addLast(list2, 7);
    list2 = addLast(list2, 17);

    // Print(list1);

    Print(list2);

    list1 = Merge(list1, list2);
    Print(list1);


    return 0;
}