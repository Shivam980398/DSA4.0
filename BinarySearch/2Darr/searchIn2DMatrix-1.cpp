#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE
// TC --> O(N*M)
int searchIn2DMatrix(vector<vector<int>> &matrix, int n, int m, int target)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// Optimal-1 using Binary Search
// TC--> O(N*log2(M))
int searchIn2DMatrixSol_2(vector<vector<int>> &matrix, int n, int m, int target)
{
    for (int i = 0; i < n; i++)
    {
        bool found = binary_search(matrix[i].begin(), matrix[i].end(), target);
        if (found)
            return true;
    }
    return false;
}

// Optimal-2 Using Binary search
// TC--> O(log2(N*M))
int searchIn2DMatrixSol_3(vector<vector<int>> &matrix, int n, int m, int target)
{
    int low = 0, high = n * m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {3, 4, 7, 9},
        {12, 13, 16, 18},
        {20, 21, 23, 29}};

    int k = 23;

    int n = matrix.size();
    int m = matrix[0].size();

    cout << searchIn2DMatrix(matrix, n, m, k) << endl;
    cout << searchIn2DMatrixSol_2(matrix, n, m, k) << endl;
    cout << searchIn2DMatrixSol_3(matrix, n, m, k);
}