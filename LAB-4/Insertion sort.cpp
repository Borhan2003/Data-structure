#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int arr[1000] = {INT_MIN, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}