#include <bits/stdc++.h>
using namespace std;

class Heap
{
    struct val
    {
        int prio;
        int data;
        int timestamp; // To track insertion order
    };

    val heap[100000];
    int SIZE = 0;        // Tracks the current size of the heap
    int currentTime = 0; // Monotonic counter for insertion order

public:
    void insert(int x, int prio)
    {
        heap[++SIZE].data = x;
        heap[SIZE].prio = prio;
        heap[SIZE].timestamp = ++currentTime; // Assign unique timestamp for each insertion

        int n = SIZE;
        // Heapify up
        while (n > 1)
        {
            if (heap[n / 2].prio < heap[n].prio ||
                (heap[n / 2].prio == heap[n].prio && heap[n / 2].timestamp > heap[n].timestamp))
            {
                // Compare by priority, then by timestamp
                swap(heap[n / 2], heap[n]);
            }
            else
            {
                break;
            }
            n = n / 2;
        }
    }

    void display()
    {
        if (SIZE == 0)
        {
            cout << "Heap is empty.\n";
            return;
        }
        for (int i = 1; i <= SIZE; i++)
        {
            cout << "(" << heap[i].data << ", " << heap[i].prio << ", " << heap[i].timestamp << ") " << endl;
        }
        cout << endl;
    }

    void Delete()
    {
        if (SIZE == 0)
        {
            cout << "Heap is empty. Nothing to delete.\n";
            return;
        }
        swap(heap[1], heap[SIZE]); // Move the last element to the root
        SIZE--;                    // Decrease the size of the heap

        int i = 1;
        // Heapify down
        while (2 * i <= SIZE)
        {
            int largest = i;
            if (heap[2 * i].prio > heap[largest].prio ||
                (heap[2 * i].prio == heap[largest].prio && heap[2 * i].timestamp < heap[largest].timestamp))
            {
                largest = 2 * i;
            }
            if (2 * i + 1 <= SIZE &&
                (heap[2 * i + 1].prio > heap[largest].prio ||
                 (heap[2 * i + 1].prio == heap[largest].prio && heap[2 * i + 1].timestamp < heap[largest].timestamp)))
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
        if (SIZE == 0)
        {
            cout << "Heap is empty. Nothing to sort.\n";
            return;
        }
        while (SIZE != 0)
        {
            cout << heap[1].data << " " << heap[1].prio << endl;
            ;         // Output the root
            Delete(); // Remove the root
        }
        cout << endl;
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
    h.insert(33, 4);

    h.display();
    // h.Sort();

    // cout << "Heap elements (data, priority, timestamp): ";
    // h.display();

    // cout << "Sorted elements: ";
    // h.Sort();

    return 0;
}
