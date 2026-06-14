// Intution
// Which data structure to use
// What to put in that data structure

// Humara goal kya hai ki jo edges chunege hum wo minimum wt wale hone chahiye
// or saare  vertices connected bhi hone chahiye

//    0---3------4
//    |   |      | \
//    |   |      |  \
//    1---2      5---6

// hume chahiye wt ,ki kisi edge tk jane ka kitna wt h
// hume chahiye node ki kis node pr ja rahe hai
// or kaha se aaye h , ye sab hume daalna hoga DS m

// {wt,node,parent}

// Ab DS kon sa use krna hai
// MST mai humara goal hai minimum sum of all nodes wt and all nodes connected
// Toh hum kya krenge jo bhi node wt small hai usko connect krenge,
// ya fr uska sum he add krenge total sum mai

// Toh hume ek esa DS chahiye jisme, minimum wt top pr mil jaye,

// ..toh esa kon sa DS hai jo min element top pr maintain krta
// or O(1) mai hume deta hai wo hai heap i.e Priority queue.
// But minheap wala,
// Or sabse humne edge wt ko kyu rakha taki jo min heap hai na, wo kya krega jo sabse pehla bnda i.e wt uske acc minheap bna dega
// Ab hume pta chal gya ki kya use krna hai usme kya store krna hai.

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