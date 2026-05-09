#include <bits/stdc++.h>

using namespace std;
void BFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    result.push_back(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int &v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                result.push_back(v);
            }
        }
    }
}
int main()
{
    unordered_map<int, vector<int>> adj;
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2};
    vector<int> result;
    vector<bool> visited(adj.size(), false);
    BFS(adj, 0, visited, result);
    for (int node : result)
    {
        cout << node << " ";
    }
    return 0;
}