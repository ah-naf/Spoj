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
#define mod                     10000007
ll bigmod(ll base,ll power,ll m)
{
    if(power==0)
        return 1;
    if(power&1)
    {
        ll y=base%m;
        ll x=(bigmod(base,power-1,m)) % m;
        return (x*y)%m ;
    }
    else if(power%2==0)
    {
        ll x=bigmod(base,power/2,m) % m;
        return (x*x)%m;
    }
}

int main()
{
    AHNAF;
    int n,k;
    while(scanf("%d %d",&n,&k), k)
    {

            long long int s1, s2,s3,s4;
            s1 = (2 * bigmod(n-1,n-1,mod) ) % mod;
            s2 = (2 * bigmod(n-1,k,mod) ) % mod;
            s3 = bigmod(n,k,mod);
            s4 = bigmod(n,n,mod);
            ll ans=(s1+s2+s3+s4)% mod;
        cout<<ans<<endl;

    }

}

