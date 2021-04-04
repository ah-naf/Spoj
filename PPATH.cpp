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
vii gr[10001],prime;
int vis[10001], dis[10001];
bool isprime(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
bool isvalid(int a,int b)
{
    int cnt=0;
    while(a)
    {
        if((a%10) != (b%10))
            cnt++;
        a/=10, b/=10;
    }
    if(cnt==1)
        return true;
    else
        return false;
}
void build()
{
    for(int i=1000; i<=9999; i++)
    {
        if(isprime(i))
            prime.pb(i);
    }
    for(int i=0; i<prime.size(); i++)
    {
        for(int j=i+1; j<prime.size(); j++)
        {
            int a=prime[i]; int b=prime[j];
            if(isvalid(a,b))
            {
                gr[a].pb(b);
                gr[b].pb(a);
            }
        }
    }
}
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    vis[n]=1;
    dis[n]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int xx: gr[x])
        {
            if(vis[xx]==0)
            {
                vis[xx]=1;
                dis[xx]=dis[x]+1;
                q.push(xx);
            }
        }
    }
}
int main()
{
    AHNAF;
    build();
    testcase(t)
    {
        for(int i=1000; i<=9999; i++)
        {
            vis[i]=0,dis[i]=0;
        }
        int a,b;
        cin>>a>>b;
        bfs(a);
        cout<<dis[b]<<endl;
    }
}


