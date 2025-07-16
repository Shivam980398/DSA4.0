#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
//  TC--> O(n1 + n2)
// SC--> O(n1 + n2)
double medianOfTwoSortedArrays1(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> arr3;
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3.push_back(arr1[i++]);
        }
        else
        {
            arr3.push_back(arr2[j++]);
        }
    }
    while (i < n1)
    {
        arr3.push_back(arr1[i++]);
    }
    while (j < n2)
    {
        arr3.push_back(arr2[j++]);
    }
    int totalSize = n1 + n2;

    cout << totalSize;
    if (totalSize % 2 == 1)
    {
        return arr3[totalSize / 2];
    }
    else
    {
        return (double)((double(arr3[totalSize / 2]) + double(arr3[totalSize / 2 - 1])) / 2.0);
    }
}

// Better Approach not using extra space
//  TC--> O(n1 + n2)
// SC--> O(1)

double medianOfTwoSortedArrays2(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;
    int i = 0, j = 0, count = 0;
    int index1 = (n / 2 - 1);
    int index2 = (n / 2);
    int element1 = -1, element2 = -1;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (count == index1)
                element1 = arr1[i];
            if (count == index2)
                element2 = arr1[i];
            count++;
            i++;
        }
        else
        {
            if (count == index1)
                element1 = arr2[j];
            if (count == index2)
                element2 = arr2[j];
            count++;
            j++;
        }
    }
    while (i < n1)
    {
        if (count == index1)
            element1 = arr1[i];
        if (count == index2)
            element2 = arr1[i];
        count++;
        i++;
    }
    while (j < n2)
    {
        if (count == index1)
            element1 = arr2[j];
        if (count == index2)
            element2 = arr2[j];
        count++;
        j++;
    }
    if (n % 2 == 1)
    {
        return element1;
    }

    return (double)((double(element1) + double(element2)) / 2.0);
}

// Optimal Approach using Binary Search
//  TC--> O(log(min(n1, n2)))

double medianOfTwoSortedArrays3(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    if (n1 > n2)
        return medianOfTwoSortedArrays3(arr2, arr1);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

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
        {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
}

int main()
{
    vector<int> arr1 = {1, 3, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15};

    // cout << "Median of two sorted arrays is: " << medianOfTwoSortedArrays1(arr1, arr2) << endl;
    // cout << "Median of two sorted arrays is: " << medianOfTwoSortedArrays2(arr1, arr2) << endl;
    cout << "Median of two sorted arrays is: " << medianOfTwoSortedArrays3(arr1, arr2) << endl;
}