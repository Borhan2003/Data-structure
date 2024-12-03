#include <bits/stdc++.h>
using namespace std;
class Heap
{
    int heap[100000], SIZE = 0;

public:
    void insert(int x)
    {
        heap[++SIZE] = x;
        int n = SIZE;
        while (n > 1)
        {
            if (heap[n / 2] < heap[n])
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
            cout << heap[i] << " ";
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
        { // Ensure the current node has at least one child
            int largest = i;
            if (heap[2 * i] > heap[largest])
            { // Compare with left child
                largest = 2 * i;
            }
            if (2 * i + 1 <= SIZE && heap[2 * i + 1] > heap[largest])
            { // Compare with right child
                largest = 2 * i + 1;
            }
            if (largest == i)
            { // If the parent is already the largest, stop
                break;
            }
            swap(heap[i], heap[largest]);
            i = largest; // Move to the largest child
        }
    }
    void Sort()
    {
        while (SIZE != 0)
        {
            cout << heap[1] << " ";
            Delete();
        }
    }
};
int main()
{
    Heap h;
    h.insert(44);
    h.insert(30);
    h.insert(50);
    h.insert(22);
    h.insert(60);
    h.insert(55);
    h.insert(77);
    h.insert(55);

    h.Sort();

    return 0;
}
