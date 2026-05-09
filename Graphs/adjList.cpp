

// vertices : 0, 1, 2, 3
// prerequisites =  [[ 1, 0 ]], [ 2, 0 ], [ 2, 1 ], [ 3, 1 ];

unordered_map<int, vector<int>> adj;

for (vector<int> &vec : prerequisites)
{
    int u = vec[0];
    int v = vec[1];

    adj[u].push_back(v);
}