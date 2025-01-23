#include <bits/stdc++.h>
using namespace std;
#define ll long long
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}
int main()
{
    int arr[1000] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 9;
    selectionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}