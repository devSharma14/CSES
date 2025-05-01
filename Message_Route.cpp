#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void you_can_do_it() {
    int v,e;
    cin >> v >> e;
    vector<pair<int,int>> edges;
    for(int i=0; i<e; ++i) {
        int u,v; cin >> u >> v;
        edges.push_back({u,v});
    }
    vector<vector<int>> adjlist(v+1);
    for(int i=0; i<e; ++i) {
        int n = edges[i].first;
        int m = edges[i].second;
        adjlist[n].push_back(m);
        adjlist[m].push_back(n);
    }
    queue<int> q;
    vector<int> parent(v+1,-1);
    vector<bool> visited(v+1,false);
    visited[1] = true;
    q.push(1);
    while(!q.empty()) {
        int par_node = q.front();
        q.pop();
        for(auto nbh : adjlist[par_node]) {
            if(!visited[nbh]) {
                visited[nbh] = true;
                parent[nbh] = par_node;
                q.push(nbh);
            }
        }
    }
    // for(auto it : parent) {
    //     cout<<it<<" ";
    // }
    vector<int> res;
    if(visited[v] == true) {
        int curnode = v;
        while(curnode != -1) {
            res.push_back(curnode);
            curnode = parent[curnode];
        }
        reverse(res.begin(),res.end());
        cout << res.size() << endl;
        for(auto it : res) {
            cout << it << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
}

int main()
{
    int testcase=1; while(testcase--) {you_can_do_it();} 
}