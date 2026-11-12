#include <bits/stdc++.h>

using namespace std;

bool check(n)
{
    if (n <= 0)
        return false;

    while (n % 2 == 0)
    {
        n = n / 2;
    }
    return n == 1;
}

void solve(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            cout << "POWER" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
}

int main()
{
    int n = 7;
    solve(n);
}