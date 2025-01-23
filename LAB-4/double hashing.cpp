#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> &table, int size, int key)
{
    int index = key % size;
    
    int originalIndex = index;
    int stepSize = (7 - (key % 7));
    while (table[index] != -1)
    {
        index = (index + stepSize) % size;
        if (index == originalIndex)
        {
            cout << "Hash table is full. Cannot insert " << endl;
            return;
        }
    }
    table[index] = key;
}
bool search(const vector<int> &table, int size, int key)
{
    int index = key % size;
    int originalIndex = index;
    int stepSize = (7 - (key % 7));
    while (table[index] != -1)
    {
        if (table[index] == key)
        {
            return true;
        }
        index = (index + stepSize) % size;
        if (index == originalIndex)
        {
            return false;
        }
    }
    return false;
}

void display(const vector<int> &table, int size)
{
   
    for (int i = 0; i < size; i++)
    {
        if (table[i] != -1)
        {
            cout  << table[i] << endl;
        }
        else
        {
            cout << " empty" << endl;
        }
    }
}

int main()
{
    int size;

    cin >> size;

    vector<int> table(size, -1);

    insert(table, size, 10);
    insert(table, size, 20);
    insert(table, size, 30);
    insert(table, size, 10);
    display(table, size);


    return 0;
}