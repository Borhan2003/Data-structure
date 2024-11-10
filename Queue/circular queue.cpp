#include <iostream>
using namespace std;

int Front = 0;
int rear = 0;
int mx = 3;   // Maximum size of the queue
int arr[100]; // Array representing the queue

void Enque(int item)
{
    if ((rear + 1 == Front) || (Front == 1 && rear == mx))
    {
        cout << "Queue is full\n";
        return;
    }

    if (rear == mx)
    {
        rear = 1; // Wrap around if rear exceeds max
    }
    else
    {
        rear++;
    }
    arr[rear] = item;
    if (Front == 0)
    {
        Front = 1;
    }
}

void Deque()
{
    if (Front == 0 && rear == 0)
    {
        cout << "Queue is empty\n";
        return;
    }
    else if (Front == rear)
    {
        Front = 0;
        rear = 0;
    }
    else
    {
        if (Front == mx)
        {
            Front = 1; // Wrap around if Front exceeds max
        }

        else
        {
            Front++;
        }
    }
}

void Print()
{
    if (Front == 0 && rear == 0)
    {
        cout << "Queue is empty\n";
        return;
    }

    int i = Front;
    while (i != rear)
    {
        cout << arr[i] << " ";
        if (i == mx)
        {
            i = 1; // Wrap around if i exceeds max
        }
        else
        {
            i++;
        }
    }

    cout << arr[rear] << "\n"; // Print the last element
}

int main()
{
    // Print();
    Enque(1);
    Enque(2);
    Enque(3);
    Enque(4);
    Enque(4);
    Deque();
    Deque();
    Enque(10);
    Enque(11);

    Print();
    if (Front != 0 and Front != rear)
    {
        cout << "Front:" << arr[Front] << endl;
    }

    return 0;
}
