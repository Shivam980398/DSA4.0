#include <bits/stdc++.h>

using namespace std;

void union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if (x_parent == y_parent)
        return;

    if (rank[x_parent] > rank[y_parent])
    {
        parent[y_parent] = x_parent;
    }
    else if (rank[x_parent] < rank[y_parent])
    {
        parent[x_parent] = y_parent;
    }
    else
    {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}

int find(int i, vector<int> &parent)
{
    if (i == parent[i])
    {
        return i;
    }

    return parent[i] = find(parent[i].parent);
}

bool detectCycle(int V, vector<int> adj[])

{

    vector<int> parent;
    vector<int> rank;
    parent.resize(V);
    rank.resize(V);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }
    for (int u = 0; u < V; u++)
    {
        for (int &v : adj[u])
        {

            if (u < v)
            {
                int u_parent = find(u, parent);
                int v_parent = find(v, parent);

                if (u_parent == v_parent)
                    return true;

                Union(u, v);
            }
        }
    }
}

int main()
{
}