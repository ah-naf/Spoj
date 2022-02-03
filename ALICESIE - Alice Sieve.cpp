#include <bits/stdc++.h>

using namespace std;

#define MAX 1000009
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
    //sieve();
    int t;scanf("%d", &t);
    while(t--) {
        int n;cin>>n;
        cout<<(n+1)/2<<endl;
    }
}
