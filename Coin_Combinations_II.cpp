#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int mod = 1000000007;

/*
int recursion(int index, vector<int>& v, int target, vector<vector<int>>&dp) {
    if(target == 0) {
        return 1;
    }
    if(index == 0) {
        if(target % v[0] == 0) {
            return 1;
        }
        return 0;
    }
    if(dp[index][target] != -1) return dp[index][target];
    int take = 0, skip = 0, res = 0;
    if(v[index] <= target) {
        take = recursion(index, v, target-v[index], dp);
    }
    skip = recursion(index-1, v, target, dp);
    res += take + skip;
    return dp[index][target] = res%mod;
}
*/

void you_can_do_it() {
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for(int i=0; i<n; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> dp(n, vector<int>(target+1,0));

    // dp[i][j] represents the state : no of ways to make sum j using first (i+1) coins

    // exactly 1 way to make sum 0 using any index i.e. do not choose it
    for(int i=0; i<n; ++i)  dp[i][0] = 1;

    for(int i=1; i<=target; ++i) {
        if(i%v[0] == 0) {
            dp[0][i] = 1;
        }
    }

    for(int i=1; i<n; ++i) {
        int res = 0;
        int take = 0;
        int skip = 0;
        for(int j=1; j<=target; ++j) {
            if(v[i] <= j) {
                take = dp[i][j - v[i]];
            }
            skip = dp[i-1][j];
            res = take + skip;
            dp[i][j] = res%mod;
        }
    }

    // dp[n][target] represents total no of ways to form target using all elements of v
    cout << dp[n-1][target]%mod;
}

int main()
{
    int testcase=1; while(testcase--) {you_can_do_it();} 
}