#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int n = 0, m = 0;

int dp[5001][5001];

/*int recursion(string s1, string s2, int index1, int index2) {
    if(index1 < 0) {
        return index2+1;
    }

    if(index2 < 0) {
        return index1+1;
    }

    if(dp[index1][index2] != -1)    return dp[index1][index2];

    int mini = INT_MAX;
    if(s1[index1] == s2[index2]) {
        return recursion(s1, s2, index1-1, index2-1);
    }
    else {
        // delete operation: either delete the character from the s1 or s2
        int del = 1 + min(recursion(s1, s2, index1-1, index2) , recursion(s1, s2, index1, index2-1));

        // add/replace operation are exactly same
        int option2 = 1 + recursion(s1, s2, index1-1, index2-1);

        mini = min(del, option2);
    }
    return dp[index1][index2] = mini;
}*/

void you_can_do_it() {
    string s1, s2;
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    // dp[i][j] : min opr to make string [0..i] & [0..j] equal
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=m; ++j) {
            if(i==0) {
                dp[i][j] = j;
            }
            if(j==0) {
                dp[i][j] = i;
            }
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                int mini = INT_MAX;
                int del = 1 + min(dp[i-1][j], dp[i][j-1]);
                int option2 = 1 + dp[i-1][j-1];
                mini = min(del, option2);
                dp[i][j] = mini;
            }
        }
    }
    cout << dp[n][m];
}

int main()
{
    int testcase=1; while(testcase--) {you_can_do_it();} 
}