/*________________________Bismillahir Rahmanir Rahim___________________
                                                                      |
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
#define print(a)                for(auto it: a) cout<<it<<" "
#define all(a)                  a.begin(),a.end()
#define sf(v)                   for(auto &it:v) cin>>it
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
const ll mod = 1000000007;
class Matrix {
public:
    ll ar[5][5];
    Matrix operator*(Matrix x) {
        Matrix mat;
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                mat.ar[i][j] = 0;
                for(int k=0; k<2; k++) {
                    ll tmp = ((ar[i][k] % mod) * (x.ar[k][j] % mod)) % mod;
                    mat.ar[i][j] = ((mat.ar[i][j] % mod) + (tmp % mod)) % mod;
                }
            }
        }
        return mat;
    }
};

Matrix matrix_expo(Matrix mat, ll n) {
    Matrix res;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            res.ar[i][j] = (i==j);
        }
    }
    while(n) {
        if(n&1) {
            res = res * mat; n--;
        }
        else {
            mat = mat * mat; n /= 2;
        }
    }
    return res;
}

ll calc(Matrix b, ll m) {
    if(m < 0) return 0;
    Matrix ans = matrix_expo(b, m);
    return ans.ar[0][1];
}

int main()
{
    AHNAF;
    testcase(t) {
        ll n,m;cin>>n>>m;
        Matrix a,b; int f0 = 0, f1 = 1;
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                b.ar[i][j] = !(i+j == 0);
            }
        }
        cout<<((calc(b, m+2) - calc(b,n+1)) + mod)%mod<<endl;
    }

}
