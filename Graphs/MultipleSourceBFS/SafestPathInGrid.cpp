#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool bfs(vector<vector<int>> &temp, int mid, int m, int n)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    if (temp[0][0] < mid)
        return false;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (i == m - 1 && j == n - 1)
            return true;

        for (auto dir : directions)
        {
            int i_ = dir[0] + i;
            int j_ = dir[1] + j;

            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_] && temp[i_][j_] >= mid)
            {

                q.push({i_, j_});
                visited[i_][j_] = true;
            }
        }
    }
    return false;
}

void maximumSafenessFactor(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    vector<vector<int>> temp(m, vector<int>(n, 0));
    int result = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (grid[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int level = 0;
    while (!q.empty())
    {
        int N = q.size();

        while (N--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            temp[i][j] = level;
            for (auto dir : directions)
            {
                int i_ = dir[0] + i;
                int j_ = dir[1] + j;

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_])
                {

                    q.push({i_, j_});
                    visited[i_][j_] = true;
                }
            }
        }
        level++;
    }
    int r = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            r = max(temp[i][j], r);
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

    int l = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (bfs(temp, mid, m, n))
        {
            result = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << result;
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};

    maximumSafenessFactor(grid);
}