#include <bits/stdc++.h>
using namespace std;

// Optimal Approach using Binary Search
//  TC --> O(log(min(n1,n2)))
//  SC --> O(1)
double kthelementOfTwoSortedArrays(vector<int> &arr1, vector<int> &arr2, int n1, int n2, int k)
{

    int n = n1 + n2;
    if (n1 > n2)
        return kthelementOfTwoSortedArrays(arr2, arr1, n2, n1, k);
    int low = max(k - n2, 0), high = min(k, n1);
    int left = k;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);

        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
}
int main()
{
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int n1 = arr1.size();
    int n2 = arr2.size();
    int k = 4;
    cout << "Kth element of two sorted arrays:" << kthelementOfTwoSortedArrays(arr1, arr2, n1, n2, k);
}