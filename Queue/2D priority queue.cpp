#include <bits/stdc++.h>
using namespace std;
string arr[100][100];
int mx = 6;
int Front[6];
int rear[6];

void Enque(string item, int prio)
{
    if ((rear[prio] + 1 == Front[prio]) || (Front[prio] == 1 && rear[prio] == mx))
    {
        cout << "Queue is full\n";
        return;
    }

    if (rear[prio] == mx)
    {
        rear[prio] = 1; // Wrap around if rear exceeds max
    }
    else
    {
        rear[prio]++;
    }
    arr[prio][rear[prio]] = item;
    if (Front[prio] == 0)
    {
        Front[prio] = 1;
    }
}
void Deque()
{
    int prio;
    for (int i = 1; i <= 5; i++)
    {
        if (Front[i] != 0 and rear[i] != 0)
        {
            prio = i;
            break;
        }
    }
    if (Front[prio] == 0 && rear[prio] == 0)
    {
        cout << "Queue is empty\n";
        return;
    }
    else if (Front[prio] == rear[prio])
    {
        Front[prio] = 0;
        rear[prio] = 0;
    }
    else
    {
        if (Front[prio] == mx)
        {
            Front[prio] = 1;
        }
        else
        {
            Front[prio]++;
        }
    }
}
void Print()
{
    for (int i = 1; i <= 5; i++)
    {
        if (Front[i] == 0 && rear[i] == 0)
        {
            cout << "Queue is empty\n";
            continue;
        }
        int in = Front[i];
        while (in != rear[i])
        {
            cout << arr[i][in] << " ";
            if (in == mx)
            {
                in = 1;
            }
            else
            {
                in++;
            }
        }

        cout << arr[i][rear[i]] << "\n";
    }
}

int main()
{

    Enque("AAA", 1);
    Enque("BBB", 2);
    Enque("CCC", 3);
    Enque("DDD", 4);
    Enque("EEE", 4);
   // Deque();
    Print();
    Enque("FFF", 1);
     Print();
    return 0;
}
