#include <iostream>
using namespace std;
int Front = 0;
int rear = 0;
int mx = 3;
int arr[100];
void Enque(int item)
{
    if (rear == mx)
    {
        rear = 1;
        arr[rear] = item;
    }
    else
    {
        rear++;
        arr[rear] = item;
    }
    if (Front == 0)
    {
        Front = 1;
    }
}
void Deque()
{
    if (Front == 0 && rear == 0)
    {
        return;
    }
    else if (Front == rear)
    {
        Front = 0;
        rear = 0;
    }
    else
    {
        Front++;
    }
}
void Print()
{
    if (Front < rear)
    {
        for (int i = Front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else if (Front == rear)
    {
        cout << arr[Front];
    }
    else if (rear < Front)
    {
        for (int i = Front; i <= mx; i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = 1; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    Enque(10);
    Enque(20);
    Deque();
    Enque(30);
    Enque(20);
    Print();
    cout << "Front:" << arr[Front];

    return 0;
}
