// Problem: Painter's Partition Problem
// Problem: Allocate areas to painters such that the maximum area allocated to a painter is minimized.
#include <bits/stdc++.h>
using namespace std;

int checkPainters(int arr[], int n, int areas)
{
    int painters = 1;
    int current_area = 0;
    for (int i = 0; i < n; i++)
    {
        if (current_area + arr[i] <= areas)
        {
            current_area += arr[i];
        }
        else
        {
            painters++;
            current_area = arr[i];
        }
    }
    return painters;
}
int findLargestMinDistance(int arr[], int n, int k)
{
    int low = *max_element(arr, arr + n);
    int high = accumulate(arr, arr + n, 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int no_of_painters = checkPainters(arr, n, mid);

        if (no_of_painters > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int unitArea[] = {10, 20, 30, 40};
    int painter = 2;
    int n = sizeof(unitArea) / sizeof(unitArea[0]);
    cout << "Minimum pages: " << findLargestMinDistance(unitArea, n, painter) << endl;
    return 0;
}