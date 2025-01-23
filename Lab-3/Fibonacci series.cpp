#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll fib(ll n)
{
    if (n == 0)
    {
        return n;
    }
    if (n == 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}
ll fib1(ll n)// non recursive
{

    ll a = 0, b = 1, c;
    for (ll i = 1; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    double n;

    cin >> n;
    cout << fib(n) << endl;
    cout << fib1(n) << endl;
    return 0;
}