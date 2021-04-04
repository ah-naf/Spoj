/*________________________Bismillahir Rahmanir Rahim___________________
|                                                                      |
|                    AA     H     H NN    N     AA     FFFFFFFF        |
|                   A  A    H     H N N   N    A  A    F               |
|                  AAAAAA   HHHHHHH N  N  N   AAAAAA   FFFFFF          |
|                 A      A  H     H N   N N  A      A  F               |
|                A        A H     H N    NN A        A F               |
|                                                                      |
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
int parent[MAX], size[MAX];
void init(int n) {
    for(int i=1; i<=n; i++) parent[i] = i, size[i] = 1;
}

int _find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = _find(parent[x]);
}

void _union(int x, int y) {
    int a = _find(x), b = _find(y);
    if(a != b) {
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a; size[a] += size[b];
    }
}

int main()
{
    //AHNAF;
    int t;scanf("%d", &t);
    while(t--)
    {
        int n;scanf("%d", &n); init(n*2); int cnt = 1;
        map<string, int> m;
        for(int i=0; i<n; i++) {
            char a[25], b[25];scanf("%s %s", a, b);
            if(!m[a]) m[a] = cnt++;
            if(!m[b]) m[b] = cnt++;
            _union(m[b], m[a]);
            int par = _find(m[b]);
            printf("%d\n", size[par]);
        }
        //for(auto it: m) cout<<it.ff<<" "<<it.ss<<endl;
    }
}


