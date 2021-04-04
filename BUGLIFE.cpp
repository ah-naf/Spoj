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
vii gr[10005];
int col[10005];
int flag;
void dfs(int n,int ccol)
{
    if(col[n]==0)
    {
        col[n]=ccol;
    }
    else if(col[n]!=ccol)
    {
        flag=1;return;
    }
    else return;
    for(int x: gr[n])
    {
        if(ccol==1) dfs(x,2);
        else dfs(x,1);
    }
}
int main()
{
    AHNAF;
    int sc=0;
    testcase(t)
    {
        int v,e;cin>>v>>e;
        for(int i=0; i<10005; i++) gr[i].clear();
        memset(col, 0, sizeof(col));
        for(int i=0; i<e; i++)
        {
            int x,y;cin>>x>>y;
            gr[x].pb(y);gr[y].pb(x);
        }
        flag=0;
        for(int i=1; i<=v; i++)
        {
            if(col[i]==0)
            {
                dfs(i,1);
            }
            if(flag) break;
        }
        if(flag)
        {
           cout<<"Scenario #"<<++sc<<":"<<endl;
           cout<<"Suspicious bugs found!"<<endl;
        }
        else
        {
            cout<<"Scenario #"<<++sc<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }
    }

}


