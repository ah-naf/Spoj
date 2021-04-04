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
#define testcase(t)             int t;cin>>t;while(t--)
int main()
{
    //AHNAF;
    testcase(t)
    {
        ll a3,an3,sum,d,n,a;
        cin>>a3>>an3>>sum;
        n = (2*sum)/(a3+an3);
        d = (an3-a3)/(n-5);
        a = a3-(2*d);
        cout<<n<<endl;
        for(int i=0;i<n;i++)
            cout<<(a+(i*d))<<" ";
        cout<<endl;
    }
}


