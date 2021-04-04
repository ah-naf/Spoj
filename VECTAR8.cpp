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
#define MAX                     1000000
#define pb(x)                   push_back(x)
#define vll                     vector<long long>
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
vector<ll> primes;
bitset<MAX> bs;
ll cnt[MAX+2];
bool check(ll n) {
    ll dig = 0;
    ll tmp = n;
    while(n) {
        if(n % 10 == 0) return false;
        n /= 10;
        dig++;
    }
    ll div = exp(10LL, dig-1);
    n = tmp;
    while(n) {
        n %= div;
        div /= 10;
        if(n && bs[n] == 0) return false;
    }
    return true;
}
void sieve()
{
    bs.set();
    for(int i=2; i<=MAX;i+=2) bs[i]=0;
    bs[0]=bs[1]=0;bs[2] = 1;
    primes.push_back(2);
    for(ll i=3; i*i<=MAX; i+=2)
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
    for(ll i=2; i<+MAX; i++) {
        cnt[i] = cnt[i-1];
        if(bs[i]) {
            if(check(i)) cnt[i]++;
        }
    }

}

int main()
{
    sieve();
    int t;scanf("%d", &t);
    while(t--) {
        int n;scanf("%d", &n);  bool c = true;
        printf("%lld\n", cnt[n]);
    }
}


