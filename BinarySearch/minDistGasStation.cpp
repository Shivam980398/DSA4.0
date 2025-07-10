#include <bits/stdc++.h>
using namespace std;

int minDistance(vector<int> &stations, int k, int n)
{
    vector<int> howMany(n - 1, 0);
    for (int i = 1; i <= k; i++)
    {
        long double maxSection = -1;
        int maxIndex = -1;
        for (int j = 0; j < n - 1; j++)
        {
            long double diff = (stations[j + 1] - stations[j]);
            long double sectionlength = (diff / (long double)(howMany[j] + 1));
            if (sectionlength > maxSection)
            {
                maxSection = sectionlength;
                maxIndex = j;
            }
        }
        howMany[maxIndex]++;
    }

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = (stations[i + 1] - stations[i]);
        long double sectionlength = (diff / (long double)(howMany[i] + 1));
        maxAns = max(maxAns, sectionlength);
    }

    return maxAns;
}

int main()
{
    vector<int> stations = {1, 13, 17, 23};
    // vector<int> stations = {1, 7};
    int k = 5; // Number of gas stations to be added
    int n = stations.size();
    cout << minDistance(stations, k, n);
}