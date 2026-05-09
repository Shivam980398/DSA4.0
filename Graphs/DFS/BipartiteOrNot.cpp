#include <bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int, vector<int>> &adj, vector<int> &color, int curr, int currColor)
{
    color[curr] = currColor;

    for (int v : adj[curr])
    {
        if (color[v] == color[curr])
        {
            return false;
        }
        if (color[v] == -1)
        {
            int colorOfV = 1 - currColor;
            if (dfs(adj, color, v, colorOfV) == false)
                return false;
        }
    }
    return true;
}

bool isBipartite(int V, unordered_map<int, vector<int>> &adj)
{
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(adj, color, i, 1) == false)
                return false;
        }
    }
    return true;
}

int main()
{

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << isBipartite(n, adj);
}