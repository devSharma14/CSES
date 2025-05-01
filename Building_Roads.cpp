#include <bits/stdc++.h>
using namespace std;
#define lli long long int;

vector<int> parent;

class DisjointSet
{
public:
    int n;
    vector<int> rank;
    DisjointSet(int n)
    {
        this->n = n;
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void print_par()
    {
        for (int i = 0; i <= n; ++i)
        {
            cout << "node : " << i << " parent: " << findUPar(i) << endl;
        }
    }
};

void you_can_do_it()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> vec;
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        vec.push_back({u, v});
    }
    // ans : total components - 1
    // and i can join any ending point of a component with the starting point of any other component
    DisjointSet ds(v);
    for (int i = 0; i < e; ++i)
    {
        int u = vec[i].first;
        int v = vec[i].second;
        if (ds.findUPar(u) != ds.findUPar(v))
        {
            ds.unionByRank(u, v);
        }
    }
    set<int> s;
    for (int i = 1; i <= v; ++i)
    {
        s.insert(ds.findUPar(i));
    }
    cout << s.size() - 1 << endl;
    int first = *s.begin();
    for (auto it : s)
    {
        if (it == first)
        {
            continue;
        }
        else
        {
            cout << first << " " << it << endl;
        }
    }
}

int main()
{
    int testcase = 1;
    while (testcase--)
    {
        you_can_do_it();
    }
}