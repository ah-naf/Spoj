#include<bits/stdc++.h>
using namespace std;
#define ll                      long long
#define testcase(t)             int t;cin>>t;while(t--)
int main()
{
    testcase(t) {
        string s;ll b;cin>>s>>b;
        if(b == 0) cout<<1<<endl;
        else {
            ll a = s.back() - '0';
            if(a == 0) cout<<0<<endl;
            else {
                ll rem[4]; ll temp = a % 10;
                for(int i=0; i<4; i++) {
                    rem[i] = temp;
                    temp = (temp * a) % 10;
                }
                ll lft = b % 4;
                if(lft == 0) lft = 4;
                cout<<rem[lft-1]<<endl;
            }
        }
    }
}
