#include <bits/stdc++.h>
using namespace std;

bool checkDFS(vector<int> &adj[], int u, vector<bool> &visited, vector<bool> &inRecursion)
{
    visited[u] = true;
    inRecursion[u] = true;

    for (auto &v : adj[u])
    {
        if (!visited[v] && checkDFS(adj, i, visited, inRecursion))
        {
            return true;
        }
        else if (inRecursion[v] == true)
        {
            return true;
        }
    }
    inRecursion[u] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visted(V, false);
    vector<bool> inRecursion(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && checkDFS(adj, i.visited, inRecursion))
        {
            return true;
        }
    }
    return false;
}

int main()
{
}