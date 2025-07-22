#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE
// TC --> O(N*M)
pair<int, int> searchIn2DMatrix(vector<vector<int>> &matrix, int n, int m, int target)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// Optimal-1 using Binary Search in the loop
// TC--> O(N*log2(M))

int binarySearch(vector<int> &row, int target)
{
    int low = 0, high = row.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (row[mid] == target)
            return mid;
        else if (row[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
pair<int, int> searchIn2DMatrixSol_2(vector<vector<int>> &matrix, int n, int m, int target)
{
    for (int i = 0; i < n; i++)
    {
        int col = binarySearch(matrix[i], target);
        // cout << col << endl;

        if (col != -1)
            return {i, col};
    }
    return {-1, -1};
}

// Optimal-2 Binary Search
// TC-->O(n+m)
pair<int, int> searchIn2DMatrixSol_3(vector<vector<int>> &matrix, int n, int m, int target)
{
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {

        if (matrix[row][col] == target)
            return {row, col};
        else if (matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int k = 6;

    int n = matrix.size();
    int m = matrix[0].size();

    auto res1 = searchIn2DMatrix(matrix, n, m, k);
    auto res2 = searchIn2DMatrixSol_2(matrix, n, m, k);
    auto res3 = searchIn2DMatrixSol_3(matrix, n, m, k);

    cout << res1.first << " " << res1.second << endl;
    cout << res2.first << " " << res2.second << endl;
    cout << res3.first << " " << res3.second << endl;
}