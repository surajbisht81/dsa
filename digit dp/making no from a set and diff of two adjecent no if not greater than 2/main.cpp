#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[12][12];
ll G(ll n,vector<ll> v,ll pos=0,ll prev=0)
{
    if(pos==n)
    {
        return 1;
    }
    if(dp[pos][prev]!=-1)
        return dp[pos][prev];

    ll res=0;
    for(ll i=0;i<v.size();i++)
    {
        if(prev==0 || abs(v[i]-prev)<=2)
            res+=G(n,v,pos+1,v[i]);
    }
    dp[pos][prev]=res;
    return res;
}
int main()
{
    cout<<"\nenter test case:";
    int c;
    cin>>c;
    while(c--)
    {
        cout<<"\nenter m and n:";
        ll m,n;
        cin>>m>>n;
        vector<ll> v(m);
        for(ll i=0;i<m;i++)
            cin>>v[i];
        memset(dp,-1,sizeof(dp));
        cout<<"\n total nos are="<<G(n,v);
    }
    return 0;
}
