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
#define sf(v)                   for(auto &it: v) cin>>it
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
bool checkbit(int mask,int bit){return mask & (1<<bit);}
int setbit(int mask,int bit){ return mask | (1<<bit) ; }
int clearbit(int mask,int bit){return mask & ~(1<<bit);}
int togglebit(int mask,int bit){return mask ^ (1<<bit);}
//--------------------------------------------------------------//
struct segtree {

    int size;
    vector<int> val;

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        val.assign(4*size, 0LL);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                val[x]=a[lx];// sum and minimum
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        val[x] = val[2 * x + 1] + val[2 * x + 2]; // sum
        //val[x] = min(val[2 * x + 1], val[2 * x + 2]); // minimum
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            val[x] = v;// sum and minimum
            return ;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        val[x] = val[2 * x + 1] + val[2 * x + 2]; // sum
        //val[x] = min(val[2 * x + 1], val[2 * x + 2]); // minimum
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if(lx >= r | l >=rx) return 0; // to calculate sum in a segment
        //if(lx >= r || l >=rx) return INT_MAX; // to calculate minimum in a segment
        if(lx >= l && rx <= r) return val[x];
        int m = (lx + rx)/2;
        long long s1 = sum(l, r, 2 * x + 1, lx, m);
        long long s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;// to calculate sum in a segment
        //return min(s1,s2); // to calculate minimum in a segment

    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

};

int main()
{
    AHNAF;
    testcase(t)
    {
        map<string , int> m;
        int n;cin>>n;
        segtree st; st.init(n);
         string s1[n+3], s2[n+3];
        for(int i=0; i<n; i++) cin>>s1[i];
        for(int i=0; i<n; i++) cin>>s2[i], m[s2[i]] = i+1;
        vii v(n);int ans = 0;
        for(int i=0; i<n; i++) v[i] = m[s1[i]];
        for(int i=0; i<n; i++) {
            ans += st.sum(v[i]-1, n);
            st.set(v[i]-1, 1);
        }
        cout<<ans<<endl;
    }
}


