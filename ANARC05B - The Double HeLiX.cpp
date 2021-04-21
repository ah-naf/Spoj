/*________________________Bismillahir Rahmanir Rahim___________________
                                                                      |
|                    /\     |     | |\    |     /\     |-------        |
|                   /  \    |     | | \   |    /  \    |               |
|                  /----\   |-----| |  \  |   /----\   |-----          |
|                 /      \  |     | |   \ |  /      \  |               |
|                /        \ |     | |    \| /        \ |               |
|                     14th batch CSE , ID : 12008029                   |
|                     Comilla University                               |
|                     Email : sheikhahnafshifat@gmail.com              |
|______________________________________________________________________*/
#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
#define ll                      long long
#define MAX                     1000007
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define vii                     vector<int>
#define vll                     vector<long long>
#define vp                      vector<pair<ll, ll> >
#define v_min(a)                *min_element(a.begin(),a.end())
#define v_max(a)                *max_element(a.begin(),a.end())
#define v_sum(a)                accumulate(a.begin(),a.end(),0)
#define un(a)                   a.erase(unique(a.begin(),a.end()),a.end())
#define SORT(a)                 sort(a.begin(),a.end())
#define AHNAF                   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define YES                     cout<<"YES"<<endl
#define NO                      cout<<"NO"<<endl
#define testcase(t)             int t;cin>>t;while(t--)
#define reverse(a)              reverse(a.begin(),a.end())
#define ff                      first
#define ss                      second
#define print(a)                for(auto it: a) cout<<it<<" "
#define all(a)                  a.begin(),a.end()
#define sf(v)                   for(auto &it:v) cin>>it
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


int main()
{
    AHNAF;
    while(1) {
        int n;cin>>n;
        if(n == 0) break;
        vll v1(n+1); map<ll, int> m;
        for(int i=1; i<=n; i++) {
            cin>>v1[i]; m[v1[i]] = i;
        }
        int nn;cin>>nn; vll v2(nn+1); vp inter;
        for(int i=1; i<=nn; i++) {
            cin>>v2[i];
            if(m[v2[i]]) {
                inter.pb(mp(m[v2[i]], i));
            }
        }
        inter.pb(mp(v1.size()-1, v2.size()-1));
        vll sufa(v1.size()), sufb(v2.size());
        for(int i=1; i<v1.size(); i++) sufa[i] = sufa[i-1] + v1[i];
        for(int i=1; i<v2.size(); i++) sufb[i] = sufb[i-1] + v2[i];
        pair<int, int> cur = {0,0};
        ll ans = 0;int last;
        for(auto it: inter) {
            ll val1 = sufa[it.ff] - sufa[cur.ff];
            ll val2 = sufb[it.ss] - sufb[cur.ss];
            ans += max(val1, val2);
            cur = it;
        }
        cout<<ans<<endl;
        /*for(auto it: inter) {
            cout<<it.ff<<" "<<it.ss<<endl;
        }
        print(sufa);cout<<endl;
        print(sufb);cout<<endl;*/
    }
}
