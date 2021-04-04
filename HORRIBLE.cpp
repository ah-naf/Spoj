/*________________________Bismillahir Rahmanir Rahim___________________
|                                                                      |
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
struct item {
    ll sum, prop;
};
ll size; vector<item> tree;

void update(int l, int r, ll v, int x, int lx, int rx) {
    if(lx > r || l > rx) return;
    if(lx >= l && rx <= r) {
        tree[x].sum += ((rx - lx + 1) * v);
        tree[x].prop += v;
        return;
    }
    int m = (lx + rx) / 2;
    update(l, r, v, 2 * x, lx, m);
    update(l, r, v, 2 * x + 1, m + 1, rx);
    tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum + ((rx - lx + 1) * tree[x].prop);
}

void update(int l, int r, ll v) {
    update(l, r, v, 1, 1, size);
}

ll query(int l, int r, int x, int lx, int rx, ll carry) {
    if(lx > r || l > rx) return 0;
    if(lx >= l && rx <= r) {
        return tree[x].sum + (carry * (rx - lx + 1));
    }
    int m = (lx + rx) / 2;
    ll s1 = query(l, r, 2 * x, lx, m, carry + tree[x].prop);
    ll s2 = query(l, r, 2 * x + 1, m + 1, rx, carry + tree[x].prop);
    return s1 + s2;
}

ll query(int l, int r) {
    return query(l, r, 1, 1, size, 0);
}

int main()
{
    AHNAF; int ca = 0;
    testcase(t) {
        ll n, q;cin>>n>>q;
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size);
        //cout<<"Case "<<++ca<<":"<<endl;
        while(q--) {
            int op;cin>>op;
            if(op) {
                int l, r;cin>>l>>r;//l++; r++;
                cout<<query(l, r)<<endl;
            }
            else {
                int l,r; ll v;cin>>l>>r>>v;
                //l++;r++;
                update(l, r, v);
            }
        }
        tree.clear();
    }

}


