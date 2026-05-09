#include <bits/stdc++.h>
using namespace std;

bool checkCycle(vector<vector<int>> &adj, int &u, vector<bool> &visited, int parent)
{
    visited[u] = true;

    for (auto &v : adj[u])
    {
        if (v == parent)
            continue;
        if (visited[v])
            return true;
        if (checkCycle(adj, v, visited, u))
            return true;
    }
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && checkCycle(adj, i, visited, -1))
        {
            cout << "true" << endl;
            return 0;
        }
    }
    cout << "false" << endl;
}