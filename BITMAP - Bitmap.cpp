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
#define sf(a)                   for(auto &it: a) cin>>it
///--------------Graph Moves--------------------------------------
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
int G[200][200], vis[200][200], dist[200][200];
queue<pair<int, int> > Q;int n,m;
void bfs() {
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++) {
            int xx = cur.ff + fx[i];
            int yy = cur.ss + fy[i];
            if(!vis[xx][yy] && xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
                vis[xx][yy] = 1;
                dist[xx][yy] = dist[cur.ff][cur.ss] + 1;
                Q.push({xx, yy});
            }
        }
    }
}
int main()
{
    AHNAF;
    testcase(t) {
        cin>>n>>m; memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis)); memset(dist, 0, sizeof(dist));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                char x;cin>>x; G[i][j] = x - '0';
                if(G[i][j]) {
                    Q.push({i,j}); vis[i][j] = 1;
                }
            }
        }
        bfs();
        for(int i=1; i<=n; i++)  {
            for(int j=1; j<=m; j++) {
                if(j == 1) cout<<dist[i][j];
                else cout<<" "<<dist[i][j];
            }
            cout<<endl;
        }
    }
}
