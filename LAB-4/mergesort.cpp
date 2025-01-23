#include <bits/stdc++.h>
using namespace std;
int arr[1000] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
void merged(int l, int m, int r)
{
    int n = r - l + 1;
    int a[m - l + 2], b[r - m + 1];
    a[m - l + 1] = INT_MAX;
    b[r - m] = INT_MAX;
    for (int i = l, j = 0; i <= m; i++, j++)
    {
        a[j] = arr[i];
    }
    for (int i = m + 1, j = 0; i <= r; i++, j++)
    {
        b[j] = arr[i];
    }
    for (int i = 0, j = 0, k = 0; i < n; i++)
    {
        if (a[j] < b[k])
        {
            arr[l + i] = a[j];
            j++;
        }
        else
        {
            arr[l + i] = b[k];
            k++;
        }
    }
}
void mergedsort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergedsort(l, m);
        mergedsort(m + 1, r);
        merged(l, m, r);
    }
}

int main()
{
    mergedsort(0, 8);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";

    return 0;
}