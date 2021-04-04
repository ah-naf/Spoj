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
#define print(a)               for(auto it: a) cout<<it<<" "

int main()
{
    AHNAF;int ca=0;
    while(1)
    {
        string a;cin>>a;
        if(a[0]=='-') break;
        stack<char> s;
        for(int i=0; i<a.size(); i++) {
            if(s.empty()) {
                s.push(a[i]);
            }
            else if(a[i]=='}' && s.top()=='{') {
                s.pop();
            }
            else s.push(a[i]);
        }
        int cnt1=0,cnt2=0;
        while(!s.empty()) {
            if(s.top()=='{') cnt1++;
            else cnt2++;
            s.pop();
        }
        cnt1=(cnt1+1)/2;
        cnt2=(cnt2+1)/2;
        cout<<++ca<<". "<<cnt1+cnt2<<endl;
    }
}
