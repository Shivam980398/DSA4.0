#include <bits/stdc++.h>
using namespace std;

typedef vector<int> v;

int spanningTree(int V, unordered_map<int, vector<vector<int>>> &adj)
{

    priority_queue<v, vector<v>, greater<v>> pq;

    vector<bool> inMst(V, false);

    pq.push({0, 0, -1});
    int sum = 0;

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int wt = p[0];
        int node = p[1];
        int parent = p[2];

        if (inMst[node])
            continue;

        inMst[node] = true;
        sum += wt;

        for (auto tmp : adj[node])
        {
            int adjNode = tmp[0];
            int adjWt = tmp[1];

            if (!inMst[adjNode])
            {
                pq.push({adjWt, adjNode, node});
            }
        }
    }
    return sum;
}

int main()
{
    unordered_map<int, vector<vector<int>>> adj;
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    cout << spanningTree(V, adj) << endl;
}