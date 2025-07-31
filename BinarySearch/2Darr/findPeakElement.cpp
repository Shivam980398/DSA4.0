#include <bits/stdc++.h>
using namespace std;

int maxElement(vector<vector<int>> &mat, int n, int m, int mid)
{
    int maxRow = -1, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][mid] > maxRow)
        {
            maxRow = mat[i][mid];
            index = i;
        }
    }
    return index;
}

pair<int, int> findPeak(vector<vector<int>> &mat, int n, int m)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = maxElement(mat, n, m, mid);

        int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
        int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;
        if (mat[row][mid] > left && mat[row][mid] > right)
            return {row, mid};
        else if (mat[row][mid] < left)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> arr = {
        {4, 2, 5, 1, 4, 5},
        {2, 1, 3, 2, 3, 2},
        {1, 2, 6, 0, 1, 3},
        {3, 1, 2, 3, 7, 2}};
    int n = arr.size();
    int m = arr[0].size();

    // Find peak element
    pair<int, int> peak = findPeak(arr, n, m);
    cout << "Peak element is: " << peak.first << peak.second << endl;

    return 0;
}