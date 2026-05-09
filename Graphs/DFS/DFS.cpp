#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &adj, int start, vector<bool> &visited)
{
    if (visited[start])
        return;
    visited[start] = true;
    cout << start << " ";
    for (int neighbor : adj[start])
    {

        if (!visited[neighbor])
            DFS(adj, neighbor, visited);
    }
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1},
        {1, 2}};
    vector<bool> visited(graph.size(), false);
    DFS(graph, 0, visited);
    return 0;
}