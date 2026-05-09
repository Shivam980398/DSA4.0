#include <bits/stdc++.h>
using namespace std;

void check(int n, vector<bool> &isPrime)
{

    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2; i * j <= n; j++)
            {
                isPrime[i * j] = false;
            }
        }
    }
}

// calculate all prime numbers upto n using sieve of eratosthenes
int main()
{
    vector<int> result;
    int n = 30;
    vector<bool> isPrime(n + 1, true);
    check(n, isPrime);
    for (int i = 0; i <= n; i++)
    {
        if (isPrime[i])
        {
            result.push_back(i);
        }
    }
    for (int prime : result)
    {
        cout << prime << " ";
    }
    return 0;
}