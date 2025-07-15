#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
//  TC--> O(k * n)
// SC--> O(n)
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

// Better Approach using Priority Queue
//  TC--> O(k * log(n))
// SC--> O(n)
int minDist(vector<int> &stations, int k, int n)
{
    priority_queue<pair<long double, int>> pq;
    vector<int> howMany(n - 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({(stations[i + 1] - stations[i]), i});
    }

    for (int GS = 1; GS <= k; GS++)
    {

        pair<long double, int> tp = pq.top();
        pq.pop();
        int SecIndex = tp.second;
        howMany[SecIndex]++;
        long double newSectionLength = (stations[SecIndex + 1] - stations[SecIndex]) / (howMany[SecIndex] + 1);
        pq.push({newSectionLength, SecIndex});
    }
    return pq.top().first;
}

// Optimal Approach using Binary Search
//  TC--> O(n * log(maxDistance))
// SC--> O(1)

int noOfGasStationsRequired(long double mid, vector<int> &stations)
{
    int count = 0;
    for (int i = 1; i < stations.size(); i++)
    {
        int noInBetween = (stations[i] - stations[i - 1]) / mid;
        if ((stations[i] - stations[i - 1]) / mid == noInBetween * mid)
        {
            noInBetween--;
        }
        count += noInBetween;
    }
    return count;
}
int minDistOptimal(vector<int> &stations, int k, int n)
{
    long double low = 0, high = 0;

    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(stations[i + 1] - stations[i]));
    }

    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / 2.0;
        int count = noOfGasStationsRequired(mid, stations);
        if (count > k)
            low = mid;

        else
            high = mid;
    }
    return high;
}

int main()
{
    // vector<int> stations = {1, 13, 17, 23};
    vector<int> stations = {1, 2, 3, 4, 5, 6};
    int k = 3; // Number of gas stations to be added
    int n = stations.size();
    // cout << minDistance(stations, k, n);
    // cout << minDist(stations, k, n);
    cout << minDistOptimal(stations, k, n);
}