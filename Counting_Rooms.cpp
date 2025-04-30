#include <bits/stdc++.h>
using namespace std;
#define lli long long int;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n, m;

void bfs(int i, int j, vector<vector<char>>& mat, vector<vector<bool>>& vis) {
    vis[i][j] = true;
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i) {
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == '.') {
                q.push({nrow,ncol});
                vis[nrow][ncol] = true;
            }
        }
    }
}

void you_can_do_it() {
    cin>>n>>m;
    vector<vector<char>> mat(n, vector<char>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin>>mat[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    
}

int main()
{
    int testcase=1; while(testcase--) {you_can_do_it();} 
}