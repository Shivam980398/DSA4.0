#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &adj[], int u, vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;

    // pehle mere bacho ko stack me dalo
    for (int &v : adj[u])
    {
        if (!visited[v] && dfs(adj, v, visited, st))
            ;
    }

    // fr mujhe stack me dalo
    st.push(u);
}

vector<int> TopSort(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dfs(adj, i, visited, st))
            ;
    }

    vector<int> result;

    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

int main()
{
}