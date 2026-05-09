#include <bits/stdc++.h>
using namespace std;

bool checkCycle(vector<vector<int>> &adj, int &V, vector<int> &indegree)
{

    queue<int> q;
    int count = 0;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            count++;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
            {
                q.push(v);
                count++;
            }
        }
    }
    if (count == V)
    {
        return false;
    }
    return true;
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
        // adj[v].push_back(u);5
    }

    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto &v : adj[i])
        {
            indegree[v]++;
        }
    }

    if (checkCycle(adj, V, indegree))
    {
        cout << "true" << endl;
        return 0;
    }

    cout << "false" << endl;
}