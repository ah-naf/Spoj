/*________________________Bismillahir Rahmanir Rahim___________________
                                                                      |
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
#define MAX                     100000008
#define pb(x)                   push_back(x)
#define vll                     vector<long long>
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
vector<ll> primes;
bitset<MAX> bs;
vector<pair<ll, ll> > ans(MAX+1);
void sieve()
{
    bs.set();
    for(int i=2; i<=MAX; i+=2)
        bs[i]=0;
    bs[0]=bs[1]=0;
    bs[2] = 1;
    primes.push_back(2);
    for(ll i=3; i*i <= MAX; i+=2)
    {
        if(bs[i])
        {
            for(ll j=i*i; j<=MAX; j+=i)
            {
                bs[j] = 0;
            }
            //primes.push_back(i);
        }
    }
    for(ll i = 3; i<=MAX; i+=2) {
        if(bs[i]) {
            primes.push_back(i);
        }
    }

}
ll SOD( ll n ) {
    ll res = 1;
    ll sqrtn = sqrt ( n );
    for ( ll i = 0; i < primes.size() && primes[i] <= sqrtn; i++ ) {
        if ( n % primes[i] == 0 ) {
            ll tempSum = 1; // Contains value of (p^0+p^1+...p^a)
            ll p = 1;
            while ( n % primes[i] == 0 ) {
                n /= primes[i];
                p *= primes[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 ) {
        res *= ( n + 1 ); // Need to multiply (p^0+p^1)
    }
    return res;
}
int main()
{
    sieve();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        ll ans = SOD(n);
        printf("%lld\n", ans - n);
    }
}


