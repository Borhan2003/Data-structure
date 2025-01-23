#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mat(100, vector<int>(100, 0));

int main()
{

    int n, e;

    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1; // undirected graph
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}