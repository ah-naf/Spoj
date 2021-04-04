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
bool checkbit(int mask,int bit){return mask & (1<<bit);}
int setbit(int mask,int bit){ return mask | (1<<bit) ; }
int clearbit(int mask,int bit){return mask & ~(1<<bit);}
int togglebit(int mask,int bit){return mask ^ (1<<bit);}
//--------------------------------------------------------------//
int BLOCK = 555;
vii v; int n,m, sum = 0, cnt[1111111];
struct node{
    int L, R, i;
};

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}
void add(int x) {
    cnt[v[x]]++;
    if(cnt[v[x]] == 1) sum++;
}
void remove(int x) {
    cnt[v[x]]--;
    if(cnt[v[x]] == 0) sum--;
}
int main()
{
    AHNAF;
    cin>>n; v.resize(n); sf(v);
    int m;cin>>m;
    node Q[m+3];
    for(int i=0; i<m; i++) {
        int l, r;cin>>l>>r; l--, r--;
        Q[i].L = l, Q[i].R = r;
        Q[i].i = i;
    }
    sort(Q, Q+m, cmp);
    int ans[m+3];
    int cur_l = 0, cur_r = -1;
    for(int i=0; i<m; i++) {
        while (cur_l > Q[i].L) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < Q[i].R) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < Q[i].L) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > Q[i].R) {
            remove(cur_r);
            cur_r--;
        }
        ans[Q[i].i] = sum;
    }
    for(int i=0; i<m; i++) cout<<ans[i]<<endl;
}


