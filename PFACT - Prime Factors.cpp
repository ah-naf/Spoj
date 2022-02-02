#include <bits/stdc++.h>

using namespace std;

#define MAX 123456
#define ll long long

//*******SIEVE***********//
vector<ll> primes;
bitset<MAX> bs;
ll ar[MAX];
void sieve() {
    bs.set();
    for (int i = 4; i <= MAX; i += 2) bs[i] = 0, ar[i] = 2;
    bs[0] = bs[1] = 0;
    primes.push_back(2);
    for (ll i = 3; i <= 9999; i += 2) {
        if (bs[i]) {

            ar[i] = i;
            for (ll j = i * i; j <= MAX; j += i) {
                bs[j] = 0;
                ar[j] = i;
            }
            // primes.push_back(i);
        }
    }
    for(int i=3; i<=MAX; i+=2) {
        if(bs[i]) primes.push_back(i), ar[i] = i;
    }
}

int main() {
    sieve();
    set<int> ans;
    for (int i = 2; i <= 100000; i++) {
        int n;
        printf("%d: ", i);
        n = i; bool chk = true;
        while (ar[n]) {
            ans.insert(ar[n]);
            n /= ar[n];
            chk = false;
        }
        for (auto it : ans) printf("%d ", it);
        if(chk) printf("%d",i);
        printf("\n");
        ans.clear();
    }
}
