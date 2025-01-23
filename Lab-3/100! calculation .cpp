#include <bits/stdc++.h>
using namespace std;

string bigMult(int x, string num)
{
    string ans;
    int carry = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int y = num[i] - '0';
        int m = x * y + carry;
        ans += m % 10 + '0';
        carry = m / 10;
    }
    while (carry)
    {
        ans += carry % 10 + '0';
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    string s = "1";
    for (int i = 1; i <= 100; i++)
    {
        s = bigMult(i, s);
    }

    cout << s;

    return 0;
}