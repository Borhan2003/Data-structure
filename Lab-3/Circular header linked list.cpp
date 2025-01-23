#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertNode(Node *&head, int data)
{
    Node *newNode = createNode(data);
    if (head == nullptr)
    {
        head = newNode;
        head->next = head; // Point to itself
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to delete a node with a given key
void deleteNode(Node *&head, int key)
{
    if (head == nullptr) return;

    Node *temp = head;
    Node *prev = nullptr;

    // If head node itself holds the key
    if (temp->data == key)
    {
        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        if (head->next == head)   // Single node case
        {
            delete head;
            head = nullptr;
        }
        else
        {
            last->next = head->next;
            delete head;
            head = last->next;
        }
        return;
    }

    // Search for the key to be deleted
    while (temp->next != head && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp->data != key) return;

    // Unlink the node from the linked list
    prev->next = temp->next;
    delete temp;
}

// Function to display the circular linked list
void displayList(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    while (temp != head);
    cout << "HEAD" << endl;
}

int main()
{
    Node *head = nullptr;

    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);

    cout << "Circular linked list: ";
    displayList(head);

    deleteNode(head, 20);
    cout << "Circular linked list after deleting 20: ";
    displayList(head);

    deleteNode(head, 30);
    deleteNode(head, 10);
    cout << "Circular linked list after deleting all nodes: ";
    displayList(head);

    return 0;
}
