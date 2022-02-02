#include <bits/stdc++.h>

using namespace std;

#define MAX 100000009
#define ll long long

//*******SIEVE***********//
vector<ll> primes;
bitset<MAX> bs;
// ll ar[MAX];
void sieve() {
    bs.set();
    for (int i = 4; i <= MAX; i += 2) bs[i] = 0;
    bs[0] = bs[1] = 0;
    primes.push_back(2);
    for (ll i = 3; i <= 55555; i += 2) {
        if (bs[i]) {

            // ar[i] = i;
            for (ll j = i * i; j <= MAX; j += i) {
                bs[j] = 0;
                // ar[j] = i;
            }
            // primes.push_back(i);
        }
    }
    for(int i=3; i<=MAX; i+=2) {
        if(bs[i]) primes.push_back(i);
    }
}

int main() {
    sieve();
    int t;scanf("%d", &t);
    while(t--) {
        ll n; scanf("%lld", &n); ll ans = 1;
        for(auto it: primes) {
            if(it*it > n) break;
            ll cnt = 1;
            while(n % it == 0) {
                cnt++;
                n /= it;
            }
            // cout<<n<<endl;
            ans *= cnt;
        }
        if(n > 1) ans *= 2;
        printf("%lld\n", ans);
    }
}
