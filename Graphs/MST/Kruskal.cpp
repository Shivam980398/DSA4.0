// Two Things

// ---Sort the edges.
//     Ascending order mai sort krdo acc to weights

// 2. Jo 2 nodes ki baat kr rahe hai
//    pehle dekh lenge
//    agr wo dono connected hai already toh hum us edge ko nhi lenge
//    or agr connected nhi hai toh connect kr denge

// or cheez or humne kaise pta kiya tha ki node u , v se connected nhi hai
// u v connected kyu nhi hai kunki dono alag alag component ka hissa hai
// or humka pta hai ki component ki baat ho rhi toh mtlb DSU ki baat ho rhi hai

// or DSU se hum easily pta kr lete the ki u kis mohale/component ka hissa hai

// Iska mtlb imp cheez ki hume DSU bhi likhna

int find(int x, vector<int> &parent)
{
    if (x == parent[x])
        return x;

    return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
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

int kruskal(vector<vector<int>> &vec, vector<int> &parent, vector<int> &rank)

{
    int sum = 0;

    for (int i = 0)

        for (auto &temp : vec)
        {
            // first smallest element nikala acc to wt
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            // u or v ka parent nikal liya
            int u_parent = find(u, parent);
            int v_parent = find(v, parent);

            //  check kiya u or v ka parent same hai ya nhi , i.e kya dono connected hai
            if (u_parent != v_parent)
            {
                // agr nhi toh connect kr denge
                Union(u, v, parent);

                // or  is edge ko include kiya hai toh sum mai wt add kr denge
                sum += wt;
            }
        }
    return sum;
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    // hum edges is vec mai daal denge
    vector<vector<int>> vec;

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    // fr isko sort kr denge

    for (int u = 0; u < V; u++)
    {
        for (auto &temp : adj[u])
        {
            int v = temp[0];
            int wt = temp[1];

            vec.push_pack({u, v, wt});
        }
    }

    // ab jo vec mila usko sort kr denge acc to wt

    auto comparator = [&](vector<int> &vec1, vector<int> &vec2)
    {
        return vec1[2] < vec2[2];
    }

    sort(begin(vec), end(vec), comparator);

    return kruskal(vec, parent, rank);
}