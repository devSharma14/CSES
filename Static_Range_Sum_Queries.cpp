#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void you_can_do_it() {
    lli n, q;
    cin >> n >> q;
    vector<lli> v(n);
    for(int i=0; i<n; ++i)  cin >> v[i];
    vector<lli> pref(n+1);
    pref[0] = 0;
    for(int i=0; i<n; ++i) {
        pref[i+1] = pref[i] + v[i];
    }
    for(int i=0; i<q; ++i) {
        lli l,r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
    }
}

int main()
{
    int testcase=1; while(testcase--) {you_can_do_it();} 
}