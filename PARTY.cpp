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
#define v_sum(a)                accumulate(a.begin(),a.end(),0LL)
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
bool checkbit(int mask,int bit)
{
    return mask & (1<<bit);
}
int setbit(int mask,int bit)
{
    return mask | (1<<bit) ;
}
int clearbit(int mask,int bit)
{
    return mask & ~(1<<bit);
}
int togglebit(int mask,int bit)
{
    return mask ^ (1<<bit);
}
//--------------------------------------------------------------//
int dp[505][505];
int fee[505], fun[505];
int func(int ind, int rem) {
    if(ind < 0 || rem <= 0) return 0;
    if(dp[ind][rem] != -1) return dp[ind][rem];
    int val1 = 0, val2 = 0;
    if(rem - fee[ind] >= 0) {
        val1 = fun[ind] + func(ind-1, rem - fee[ind]);
    }
    val2 = func(ind-1, rem);
    return dp[ind][rem] = max(val1, val2);
}
int main()
{
    AHNAF;
    int budget, party;
    while(cin>>budget>>party && budget && party) {
        memset(dp, -1, sizeof(dp)); memset(fee, 0, sizeof(fee)); memset(fun, 0, sizeof(fun));
        for(int i=0; i<party; i++) {
            cin>>fee[i]>>fun[i];
        }
        //for(int i = 0; i < 501; ++i)
		//	func(party-1, i);
        int ans = func(party - 1, budget);
        int i;
        for(i = budget; i >= 0; i--) {
            if(func(party-1, i) != ans) break;
        }
        cout<<i+1<<" "<<ans<<endl;
        //cout<<ans<<endl;
        /*for(int i=0; i<=500; i++) {
            cout<<dp[party-1][i]<<" ";
            if(dp[party-1][i] == ans) {
                cout<<i<<" "<<ans<<endl;
                break;
            }
        }*/
        //cout<<endl;
    }
}



