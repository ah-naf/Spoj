#include <bits/stdc++.h>

using namespace std;

#define MAX 10000007
#define ll long long

//*******SIEVE***********//

vector<ll> primes;
bitset<MAX> bs;
ll ar[MAX+2];
ll csum[15][MAX+2];
vector<ll> lucky;
void sieve() {
    bs.set();
    //for (int i = 4; i <= MAX; i += 2) bs[i] = 0, ar[i] = 1;
    //bs[0] = bs[1] = 0; ar[2] = 1; ar[1] = 1;
    primes.push_back(2);
    for (ll i = 2; i <= MAX; i += 1) {
        if (ar[i] == 0) {
            for (ll j = i; j <= MAX; j += i) {
                bs[j] = 0;
                ar[j]++;
            }
            // primes.push_back(i);
        }
    }
    for(ll i=3; i<=MAX; i+=2) {
        if(bs[i]) primes.push_back(i);
    }
    for(int i=0; i<=10; i++) {
        for(int j=1; j<=MAX; j++) {
            csum[i][j] = csum[i][j-1] + (ar[j] == i);
        }
    }
}



int main()
{
    sieve();
    int t; cin>>t;
    while(t--) {
        int a,b,n;cin>>a>>b>>n;

        cout<<csum[n][b] - csum[n][a-1]<<endl;
    }
}
