// Book Allocaftion Problem
//  Problem: Allocate books to students such that the maximum number of pages allocated to a student is minimized.
//  Input: Number of books, number of students, and an array representing the number of pages in each book.
//  Output: The minimum possible value of the maximum number of pages allocated to a student.
#include <bits/stdc++.h>
using namespace std;

int checkPainters(int arr[], int n, int areas)
{
    int painters = 1;
    int current_wall = 0;
    for (int i = 0; i < n; i++)
    {
        if (current_wall + arr[i] <= areas)
        {
            current_wall += arr[i];
        }
        else
        {
            painters++;
            current_wall = arr[i];
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