#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
//  TC--> O(n1 + n2)
// SC--> O(n1 + n2)
// double medianOfTwoSortedArrays(vector<int> &arr1, vector<int> &arr2)
// {
//     int n1 = arr1.size();
//     int n2 = arr2.size();
//     vector<int> arr3;
//     int i = 0, j = 0;

//     while (i < n1 && j < n2)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             arr3.push_back(arr1[i++]);
//         }
//         else
//         {
//             arr3.push_back(arr2[j++]);
//         }
//     }
//     while (i < n1)
//     {
//         arr3.push_back(arr1[i++]);
//     }
//     while (j < n2)
//     {
//         arr3.push_back(arr2[j++]);
//     }
//     int totalSize = n1 + n2;

//     cout << totalSize;
//     if (totalSize % 2 == 1)
//     {
//         return arr3[totalSize / 2];
//     }
//     else
//     {
//         return (double)((double(arr3[totalSize / 2]) + double(arr3[totalSize / 2 - 1])) / 2.0);
//     }
// }

// Better Approach not using extra space
//  TC--> O(n1 + n2)
// SC--> O(1)

double medianOfTwoSortedArrays(vector<int> &arr1, vector<int> &arr2)
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
int main()
{
    vector<int> arr1 = {1, 3, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15};

    cout << "Median of two sorted arrays is: " << medianOfTwoSortedArrays(arr1, arr2) << endl;
}