#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    // Check if multiplication is possible (m should be equal to p)
    if (m != p) {
        cout << "Matrix multiplication not possible. Number of columns of A must be equal to number of rows of B." << endl;
        return 0;
    }

    vector<vector<int>> a(n, vector<int>(m));  // Matrix A (n x m)
    vector<vector<int>> b(p, vector<int>(q));  // Matrix B (p x q)
    vector<vector<int>> c(n, vector<int>(q, 0));  // Result matrix C (n x q), initialized to 0

    // Reading matrix A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Reading matrix B
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> b[i][j];
        }
    }

    // Matrix multiplication: C = A * B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];  // Dot product calculation
            }
        }
    }

    // Output the result matrix C
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
