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
int searchIn2DMatrix(vector<vector<int>> &matrix, int target)
{
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

    // cout << "Row with max ones is:" << rowWithMaxOnes_A1(matrix, n, m);
    cout << searchIn2DMatrixSol_2(matrix, n, m, k);
}