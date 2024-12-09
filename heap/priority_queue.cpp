#include <bits/stdc++.h>
using namespace std;

class Heap
{
    struct val
    {
        int prio;
        int data;
        int time;
    };
    val heap[100000];
    int SIZE = 0;
    int cnt = 0;

public:
    void insert(int x, int prio)
    {

        heap[++SIZE].data = x;
        heap[SIZE].prio = prio;
        heap[SIZE].time = ++cnt;
        int n = SIZE;
        while (n > 1)
        {
            if ((heap[n / 2].prio < heap[n].prio) or ((heap[n / 2].prio == heap[n].prio) and (heap[n / 2].time > heap[n].time)))
            {
                swap(heap[n / 2], heap[n]);
            }
            else
                break;
            n = n / 2;
        }
    }
    void display()
    {
        for (int i = 1; i <= SIZE; i++)
            cout << heap[i].data << " ";
        cout << endl;
    }
    void Delete()
    {
        if (SIZE == 0)
        {
            cout << "Heap is empty. Nothing to delete.\n";
            return;
        }
        swap(heap[1], heap[SIZE]);
        SIZE--;
        int i = 1;

        while (2 * i <= SIZE)
        {
            int largest = i;
            if ((heap[2 * i].prio > heap[largest].prio) or (heap[2 * i].prio == heap[largest].prio and heap[2 * i].time < heap[largest].time))
            {
                largest = 2 * i;
            }
            if ((2 * i + 1 <= SIZE && heap[2 * i + 1].prio > heap[largest].prio) or (heap[2 * i + 1].prio == heap[largest].prio and heap[2 * i + 1].time < heap[largest].time))
            {
                largest = 2 * i + 1;
            }
            if (largest == i)
            {
                break;
            }
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    void Sort()
    {
        while (SIZE != 0)
        {
            cout << heap[1].data << " " << heap[1].prio << " " << heap[1].time << endl;

            Delete();
        }
    }
};
int main()
{
    Heap h;
    h.insert(44, 1);
    h.insert(30, 2);
    h.insert(50, 3);
    h.insert(6, 7);
    h.insert(22, 4);
    h.insert(60, 6);
    h.insert(55, 7);
    h.insert(77, 5);
    h.insert(55, 8);
    h.insert(4, 7);
    h.insert(5, 7);

    // h.display();
    h.Sort();

    return 0;
}