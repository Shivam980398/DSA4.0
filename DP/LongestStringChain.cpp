#include <bits/stdc++.h>
using namespace std;

bool checkPredessasor(string P, string S)
{
    if (P.size() != S.size() - 1 || P.size() >= S.size())
        return false;

    int i = 0, j = 0;

    while (i < P.size() && j < S.size())
    {
        if (P[i] == S[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    return i == P.size();
}

int LSC(vector<string> &words, int i, int P)
{
    // int count = 0
    if (i == words.size())
        return 0;

    int take = 0;

    if (P == -1 || checkPredessasor(words[P], words[i]))
        take = 1 + LSC(words, i + 1, i);

    int skip = LSC(words, i + 1, P);
    return max(take, skip);
}
int main()
{
    int n;
    // cin >> n;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    // for (int i = 0; i < n; i++)
    //     cin >> words[i];

    auto comparator = [](string a, string b)
    {
        return a.size() < b.size();
    };
    sort(begin(words), end(words), comparator);

    cout << LSC(words, 1, -1);
}