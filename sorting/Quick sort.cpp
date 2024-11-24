#include <bits/stdc++.h>
using namespace std;
#define ll long long
int arr[100] = {19, 3, 3, 9, 3, 3, 3, 3, 9};
int part(int l, int h)//hoarepartition
{

    int piv = arr[l];
    int i = l - 1;
    int j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < piv);
        do
        {
            j--;
        } while (arr[j] > piv);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}
void quicksort(int l, int r)
{
    if (l < r)
    {
        int p = part(l, r);
        quicksort(l, p);
        quicksort(p + 1, r);
    }
}
int main()
{
    quicksort(0, 7);

    for (int i = 0; i <= 7; i++)
        cout << arr[i] << " ";

    return 0;
}
