#include <bits/stdc++.h>
using namespace std;
#define lli long long int

vector<int> dp(1e6+1,-1);

int recursion(int n) {
    if(n == 0) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    string str = to_string(n);
    int mini = 1e9;
    for(int i=0; i<(int)str.length(); ++i) {
        int digit = str[i] - '0';
        if(digit == 0) {
            continue;
        }
        int temp = n - digit;
        mini = min(mini, 1 + recursion(temp)); 
    }
    return dp[n] = mini;
}

void you_can_do_it() {
    int n;
    cin >> n;
    int answer = recursion(n);
    cout << answer << endl;
}

int main()
{
    int testcase=1; while(testcase--) {you_can_do_it();} 
}