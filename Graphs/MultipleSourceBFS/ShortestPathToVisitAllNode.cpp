#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int shortestPathLength(vector<vector<int>> &graph)
{

    int V = graph.size();

    queue<P> q;
    set<P> visited;

    for (int i = 0; i < V; i++)
    {
        int mask = 1 << i;
        q.push({i, mask});
        visited.insert({i, mask});
    }

    int allStateVisited = (1 << V) - 1;

    int path = 0;

    while (!q.empty())
    {
        int size = q.size();

        path++;
        while (size--)
        {

            auto temp = q.front();
            int node = temp.first;
            int mask = temp.second;
            q.pop();

            for (auto adj : graph[node])
            {
                int nextMask = mask | (1 << adj);

                if (nextMask == allStateVisited)
                    return path;

                if (visited.find({adj, nextMask}) == visited.end())
                {
                    q.push({adj, nextMask});
                    visited.insert({adj, nextMask});
                }
            }
        }
    }
    return 0;
}

int main()
{

    vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};

    cout << shortestPathLength(graph);
}