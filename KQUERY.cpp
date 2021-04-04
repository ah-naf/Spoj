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
#define vi                      vector<int>
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
int val[30001];
vi st[4*30001];

void merge(vi &a , vi &b , vi &c)
{
	int i = 0 , j = 0;

	while(i < a.size() && j < b.size())
	{
		if(a[i] < b[j]) c.push_back(a[i]) , i++;
		else c.push_back(b[j]) , j++;
	}

	while(i < a.size()) c.push_back(a[i]) , i++;
	while(j < b.size()) c.push_back(b[j]) , j++;
}

void build(int si , int ss , int se)
{
	if(ss == se)
	{
		st[si].push_back(val[ss]);
		return;
	}

	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
	merge(st[2*si] , st[2*si+1] , st[si]);
}


int query(int si ,int ss , int se , int qs , int qe , int k)
{
	if(ss > qe || se < qs) return 0;

	if(ss >= qs && se <= qe)
	{
		return st[si].end() - upper_bound(st[si].begin() , st[si].end() , k);
	}

	int mid = (ss + se) / 2;
	return query(2*si , ss , mid , qs , qe , k) + query(2*si + 1 , mid + 1 , se , qs , qe , k);
}

int main()
{
    AHNAF;
	int n , l , r , k , q;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>val[i];
	build(1 , 1 , n);

	cin>>q;
	while(q--)
	{
		cin>>l>>r>>k;
		cout<<query(1 , 1 , n , l , r , k)<<endl;
	}
}


