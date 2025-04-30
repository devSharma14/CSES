#include <bits/stdc++.h>
using namespace std;
 
#define lli long long int
 
void you_can_do_it() {
    lli n;
    cin>>n;
    cout<<n<<" ";
    if(n==1) {
        return;
    }
    while(1) {
        if(n%2 == 0) {
            n /= 2;
            cout << n << " ";
        }
        else {
            n = n*3 + 1;
            cout << n << " ";
        }
        if(n == 1)  break;
    }
}
 
int main()
{
    int testcase=1; while(testcase--) {you_can_do_it();} 
}