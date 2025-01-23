#include <bits/stdc++.h>

using namespace std;

// Function to calculate the nth Fibonacci number
string fibonacci(int n)
{
    if (n == 1 || n == 2)
        return "1";

    vector<int> a(5000, 0); // Array to store large Fibonacci numbers
    vector<int> b(5000, 0);
    vector<int> c(5000, 0);

    a[0] = b[0] = 1; // F1 = F2 = 1
    int a_size = 1, b_size = 1, c_size;

    for (int i = 3; i <= n; i++)
    {
        int carry = 0;
        c_size = max(a_size, b_size);

        for (int j = 0; j < c_size; j++)
        {
            int sum = a[j] + b[j] + carry;
            c[j] = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0)
        {
            c[c_size] = carry;
            c_size++;
        }

        // Shift arrays for the next iteration
        a = b;
        a_size = b_size;
        b = c;
        b_size = c_size;
    }

    // Convert the result array to string
    string result;
    for (int i = c_size - 1; i >= 0; i--)
    {
        result += (c[i] + '0');
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter the value of n (1 <= n <= 500): ";
    cin >> n;

    if (n < 1 || n > 500)
    {
        cout << "Invalid input. Please enter a value between 1 and 500." << endl;
        return 1;
    }

    string result = fibonacci(n);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}
