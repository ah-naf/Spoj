#include <bits/stdc++.h>

using namespace std;

#define MAX 1000007
#define ll long long

vector<ll> primes;
bitset<MAX> bs;
void sieve() {
    bs.set();
    for (int i = 2; i <= MAX; i += 2) bs[i] = 0;
    bs[0] = bs[1] = 0;
    primes.push_back(2);
    for (ll i = 3; i <= 11111; i += 2) {
        if (bs[i]) {
            for (ll j = i * i; j <= MAX; j += i) {
                bs[j] = 0;
            }
            // primes.push_back(i);
        }
    }
    for (int i = 3; i <= MAX; i += 2) {
        if (bs[i]) primes.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t; cin>>t;
    while(t--) {
        int n;cin>>n;
        if(n) cout<<1<<endl;
        for(auto it: primes) {
            if(it <= n) cout<<it<<endl;
            else break;
        }
    }
}
