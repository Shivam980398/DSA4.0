#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    int result = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        { // If n is odd
            result *= x;
        }
        x *= x; // Square the base
        n /= 2; // Divide n by 2
    }
    return result;
}

// recursive version
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int half = power(a, b / 2);
    int result = half * half;
    if (b % 2 == 1)
    {
        result *= a;
    }
    return result;
}
// Time complexity: O(log n)

int main()
{
    int x = 2, n = 10;
    cout << power(x, n) << endl; // Output: 1024
    return 0;
}