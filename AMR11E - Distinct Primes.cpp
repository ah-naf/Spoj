#include <bits/stdc++.h>

using namespace std;

#define MAX 100009
#define ll long long

//*******SIEVE***********//
vector<ll> primes;
bitset<MAX> bs;
ll ar[MAX+2];
vector<ll> lucky;
void sieve() {
    bs.set();
    for (int i = 4; i <= MAX; i += 2) bs[i] = 0, ar[i] = 1;
    bs[0] = bs[1] = 0; ar[2] = 2; ar[1] = 1;
    primes.push_back(2);
    for (ll i = 3; i <= 5555; i += 2) {
        if (bs[i]) {
            for (ll j = 2 * i; j <= MAX; j += i) {
                bs[j] = 0;
                ar[j]++;
            }
            // primes.push_back(i);
        }
    }
    for(ll i=3; i<=MAX; i+=2) {
        if(bs[i]) primes.push_back(i), ar[i] = 1;
    }
    for(int i=2; i<=MAX; i++) {
        if(ar[i] >= 3) lucky.push_back(i);
    }
}

int main() {
    sieve();
    int t;cin>>t;
    //cout<<endl;
    while(t--) {
        int n;cin>>n;
        cout<<lucky[n-1]<<endl;
    }
}
