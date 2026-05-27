#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
vector<int> Dijkstra(int n, int source, unordered_map<int, vector<vector<int>>> &adj)
{
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<int> result(n, INT_MAX);

    pq.push({0, source});
    result[source] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;

        pq.pop();

        for (auto x : adj[node])
        {
            int adjNode = x[0];
            int d = x[1];

            if (d + dist < result[adjNode])
            {
                result[adjNode] = d + dist;
                pq.push({d + dist, adjNode});
            }
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<vector<int>>> adj;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> result = Dijkstra(n, source, adj);

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
}