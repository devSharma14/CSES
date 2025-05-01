#include <bits/stdc++.h>
using namespace std;
#define lli long long int;

int dp[501][501];

int recursion(int n, int m) {
    if(n == m) {
        return 0;
    }
    if(dp[n][m] != -1) {
        return dp[n][m];
    }
    /*
    horizontal cuts:
        left      right
        1 * m | n-1 * m 
        2 * m | n-2 * m
        ...
        n-1 * m |  1 * m

    vertical cuts:
        left     right
        n * 1 | n * m-1
        n * 2 | n * m-2
        ...
        n * m-1 | n * 1
    */

    int minimum_moves = INT_MAX;

    for(int i=1; i<=n-1; ++i) {
        minimum_moves = min(minimum_moves, 1 + recursion(i,m) + recursion(n-i,m));
    }

    for(int j=1; j<=m-1; ++j) {
        minimum_moves = min(minimum_moves, 1 + recursion(n,j) + recursion(n,m-j));
    }

    return dp[n][m] = minimum_moves;
}

void you_can_do_it() {
    int n,m;
    cin>>n>>m;
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=m; ++j) {
            dp[i][j] = -1;
        }
    }
    int ans = recursion(n,m);
    cout << ans;
}

int main()
{
    int testcase=1; while(testcase--) {you_can_do_it();} 
}