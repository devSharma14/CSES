#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

char dir[] = {'U','D','L','R'};

int n, m;

string answer = "";

bool can = false;

void bfs(int si, int sj, int ei, int ej, vector<vector<char>>& mat, vector<vector<bool>>& vis, vector<vector<int>>& parent_dir, vector<vector<pair<int,int>>>& parent_cell) {
    vis[si][sj] = true;
    string curr = "";
    queue<pair<int,int>> q;   // coords 
    q.push({si,sj});
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i) {
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] != '#') {
                vis[nrow][ncol] = true;
                parent_dir[nrow][ncol] = i;
                parent_cell[nrow][ncol] = {r,c};
                if(nrow == ei && ncol == ej) {
                    can = true;
                    break;
                }                
                q.push({nrow,ncol});
            }
        }
    }
}

void you_can_do_it() {
    cin>>n>>m;
    vector<vector<int>> parent_dir(n, vector<int>(m, -1));  // this will store the direction which we took from previous parent cell to reach current cell
    vector<vector<pair<int,int>>> parent_cell(n, vector<pair<int,int>>(m, {-1,-1}));    // this will store the parent cell's coordinate of the current cell
    vector<vector<char>> mat(n, vector<char>(m));
   
    int si=0, sj=0; // start indices
    int ei=0, ej=0; // end indices
   
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin>>mat[i][j];
            if(mat[i][j] == 'A') {
                si=i;
                sj=j;
            }
            if(mat[i][j] == 'B') {
                ei=i;
                ej=j;
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    // cout<<si<<" "<<sj<<" "<<ei<<" "<<ej<<" "<<endl;
    bfs(si, sj, ei, ej, mat, vis, parent_dir, parent_cell);
    if(can) {
        string path = "";
        int curr_row = ei, curr_col = ej;
        while(curr_row != si || curr_col != sj) {
            int d = parent_dir[curr_row][curr_col];
            path += dir[d];
            auto parent = parent_cell[curr_row][curr_col];
            int pr = parent.first;
            int pc = parent.second;
            curr_row = pr;
            curr_col = pc;
        }
        reverse(path.begin(),path.end());
        cout<<"YES\n";
        cout<<path.size()<<"\n";
        cout<<path<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}

int main()
{
    int testcase=1; while(testcase--) {you_can_do_it();} 
}