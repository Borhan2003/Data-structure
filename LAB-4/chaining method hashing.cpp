#include <bits/stdc++.h>
using namespace std;

void insert(vector<vector<int>> &table, int size, int key)
{
    int index = key % size;
    table[index].push_back(key);
}

bool search(const vector<vector<int>> &table, int size, int key)
{
    int index = key % size;
    for (int storedKey : table[index])
    {
        if (storedKey == key)
        {
            return true;
        }
    }
    return false;
}

void display(const vector<vector<int>> &table, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << i << " -> ";
        for (int key : table[i])
        {
            cout << key << " ";
        }
        cout << endl;
    }
}

int main()
{
    int size;
    cin >> size;
    vector<vector<int>> table(size);
    insert(table, size, 1);
    insert(table, size, 2);
    insert(table, size, 3);
    display(table, size);

    return 0;
}
