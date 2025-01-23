#include <bits/stdc++.h>
using namespace std;

void mergeArrays(int a[], int b[], int arr[], int size_a, int size_b)
{
    int i = 0, j = 0;
    for (int k = 0; k < size_a + size_b; k++)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
    }
}

int main()
{
    int size_a, size_b;

    cin >> size_a;
    cin >> size_b;

    int a[size_a + 1], b[size_b + 1], arr[size_a + size_b];

    for (int i = 0; i < size_a; i++)
        cin >> a[i];
    for (int i = 0; i < size_b; i++)
        cin >> b[i];

    a[size_a] = INT_MAX;
    b[size_b] = INT_MAX;

    mergeArrays(a, b, arr, size_a, size_b);

    cout << "Merged array:\n";
    for (int i = 0; i < size_a + size_b; i++)
        cout << arr[i] << " ";

    return 0;
}
