#include <bits/stdc++.h>
using namespace std;

void mergeArrays(int a[], int b[], int arr[], int size_a, int size_b) {
    int i = 0, j = 0;
    for (int k = 0; k < size_a + size_b; k++) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
            // Check if we've reached the end of `a`
            if (i == size_a) a[i] = INT_MAX;
        } else {
            arr[k] = b[j];
            j++;
            // Check if we've reached the end of `b`
            if (j == size_b) b[j] = INT_MAX;
        }
    }
}

int main() {
    int size_a, size_b;

    // Input sizes of arrays `a` and `b`
    cout << "Enter the number of sorted elements in array a: ";
    cin >> size_a;
    cout << "Enter the number of sorted elements in array b: ";
    cin >> size_b;

    int a[size_a + 1], b[size_b + 1], arr[size_a + size_b];

    // Input elements for the array `a`
    cout << "Enter " << size_a << " sorted elements for array a:\n";
    for (int i = 0; i < size_a; i++) cin >> a[i];

    // Input elements for the array `b`
    cout << "Enter " << size_b << " sorted elements for array b:\n";
    for (int i = 0; i < size_b; i++) cin >> b[i];

    // Set sentinel values at the end of useful data in `a` and `b`
    a[size_a] = INT_MAX;
    b[size_b] = INT_MAX;

    // Call the function to merge arrays
    mergeArrays(a, b, arr, size_a, size_b);

    // Output the merged array
    cout << "Merged array:\n";
    for (int i = 0; i < size_a + size_b; i++) cout << arr[i] << " ";

    return 0;
}

