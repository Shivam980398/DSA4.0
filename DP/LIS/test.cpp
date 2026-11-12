#include <bits/stdc++.h>

using namespace std;

bool check(int n)
{
    if (n % 2 == 0)
        return true;

    if (check(n / 2))
        return true;
    return false;
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