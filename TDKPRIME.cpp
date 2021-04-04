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
#define MAX                     100000000
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
#define YES                     cout<<"Yes"<<endl
#define NO                      cout<<"No"<<endl
#define testcase(t)             int t;cin>>t;while(t--)
#define reverse(a)              reverse(a.begin(),a.end())
#define ff                      first
#define ss                      second
#define print(a)                for(auto it: a) cout<<it<<" "
vector<ll> primes;
vector<bool> bs(MAX, true);
void sieve()
{
    for(ll i=4; i<=MAX; i+=2)
        bs[i]=false;
    bs[0]=bs[1]=false;

    primes.push_back(2);
    for(ll i=3; i*i<=MAX; i+=2)
    {
        if(bs[i])
        {
            for(ll j=i*i; j<=MAX; j=j+(2*i))
            {
                bs[j] = false;
            }

        }
    }
    for(int i=3; i<=MAX; i+=2)
    {
        if(bs[i]) primes.pb(i);
    }

}
int main()
{
    AHNAF;
    sieve();
    testcase(t)
    {
        ll n;
        cin>>n;
        cout<<primes[n-1]<<endl;
    }
}



