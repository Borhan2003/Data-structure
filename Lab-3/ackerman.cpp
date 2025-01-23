#include <bits/stdc++.h>
using namespace std;

int Ackerman(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 and n > 0)
    {
        return Ackerman(m - 1, Ackerman(m, n - 1));
    }
    else if (m > 0 && n == 0)
    {
        return Ackerman(m - 1, 1);
    }
}

int main()
{

    cout << Ackerman(2, 2);

    return 0;
}