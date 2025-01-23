#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
ll factorialNonRecursive(int n)
{
    ll fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int main()
{
    int n;
    cout << "Enter the number to find the factorial: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    cout << "Factorial of " << n << " is " << factorialNonRecursive(n) << endl;
    return 0;
}