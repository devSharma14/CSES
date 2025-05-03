#include <bits/stdc++.h>
using namespace std;

#define lli long long int

lli recursion(lli index, lli n, vector<lli>& v, lli prevIndex, vector<vector<lli>>& dp) {
    if(index == n) {
        return 0;
    }
    if(dp[index][prevIndex+1] != -1)  return dp[index][prevIndex+1];

    lli take = 0;

    if(prevIndex == -1 || v[index] > v[prevIndex]) {
        take = 1 + recursion(index+1, n, v, index, dp);        
    }

    lli skip = recursion(index+1, n, v, prevIndex, dp);

    return dp[index][prevIndex+1] = max(take, skip);
}

void you_can_do_it() {
    lli n;
    cin >> n;
    vector<lli> v(n);
    for(int i=0; i<n; ++i)  cin >> v[i];
    vector<vector<lli>> dp(n+2, vector<lli>(n+2, -1));
    lli answer = recursion(0, n, v, -1, dp);
    cout << answer;
}

int main() {
    int testcase = 1;
    while(testcase--) {
        you_can_do_it();
    }
}
