#include <bits/stdc++.h>
using namespace std;

// Naive approach
// TC --> O(n*m)
// SC --> O(1)

int rowWithMaxOnes_A1(vector<vector<int>> &matrix, int n, int m)
{
    int max_cnt = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int cntrow = 0;
        for (int j = 0; j < m; j++)
        {
            cntrow += matrix[i][j];
        }
        if (cntrow > max_cnt)
        {
            max_cnt = cntrow;
            index = i;
        }
    }
    return index;
}

// Optimal using Binary search
// TC --> O(n* log2(m))
// SC --> O(1)
int lower_bound(vector<int> arr, int n, int key)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= key)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int rowWithMaxOnes(vector<vector<int>> &matrix, int n, int m)
{
    int cntMax = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int cntOnes = m - lower_bound(matrix[i], m, 1);
        if (cntOnes > cntMax)
        {
            cntMax = cntOnes;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1}};

    int n = matrix.size();
    int m = matrix[0].size();

    // cout << "Row with max ones is:" << rowWithMaxOnes_A1(matrix, n, m);
    cout << "Row with max ones is:" << rowWithMaxOnes(matrix, n, m);
}