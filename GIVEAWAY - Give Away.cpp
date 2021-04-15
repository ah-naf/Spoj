/*________________________Bismillahir Rahmanir Rahim___________________
|                                                                      |
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
#define sf(v)                   for(auto &it: v) cin>>it
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

// Algo :- SQRT Decomposition + Binary Search

int main()
{
    AHNAF;
    int n;cin>>n; vll v(n); sf(v);
    vll block[800];
    int len = (int) sqrt(n + .0) + 1;
    for(int i=0; i<n; i++) {
        block[i/len].pb(v[i]);
    }
    for(int i=0; i<len; i++) SORT(block[i]);
    int q;cin>>q;
    while(q--) {
        int op;cin>>op;
        if(op == 1) {
            int idx;ll val;cin>>idx>>val; idx--;
            int block_num = idx/len; ll init = v[idx];
            int lo = 0, hi = len-1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(block[block_num][mid] == init) {
                    block[block_num][mid] = val;
                    break;
                }
                else if(block[block_num][mid] < init) lo = mid+1;
                else hi = mid - 1;
            }
            v[idx] = val;
            SORT(block[block_num]);
        }
        else {
            int l, r; ll x;cin>>l>>r>>x; int ans = 0; l--, r--;
            for(int i=l; i<=r; ) {
                if(i % len == 0 && i + len - 1 <= r) {
                    ans += (block[i/len].end() - lower_bound(block[i/len].begin(), block[i/len].end(), x));
                    i += len;
                }
                else {
                    if(v[i] >= x) ans++;
                    i++;
                }
            }
            cout<<ans<<endl;
        }
    }
}

