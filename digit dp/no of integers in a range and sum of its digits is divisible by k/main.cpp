#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[12][100][2];

bool check(string temp,ll k)
{
    ll i=stoi(temp);
    if(i%k==0)
        return 1;
    return 0;
}
ll G(string str,ll k,ll pos=0,ll sum=0,ll tight=1,string temp="")
{
    if(pos==str.length())
    {
        if(sum%k==0 && check(temp,k))
            return 1;
        else
            return 0;
    }
    if(dp[pos][sum][tight]!=-1)
        return dp[pos][sum][tight];

    else if(tight==1)
    {
        ll res=0;
        for(ll i=0;i<=str[pos]-'0';i++)
        {
            if(i==str[pos]-'0')
            {
                string j=to_string(i);
                res+=G(str,k,pos+1,sum+i,1,temp+j);
            }
            else
                {
                    string j=to_string(i);
                    res+=G(str,k,pos+1,sum+i,0,temp+j);
                }
        }
        return dp[pos][sum][tight]=res;
    }
    else
    {
        ll res=0;
        for(ll i=0;i<=9;i++)
        {
            string j=to_string(i);
            res+=G(str,k,pos+1,sum+i,0,temp+j);
        }
        return dp[pos][sum][tight]=res;
    }
}
int main()
{
    ll c;
    cout<<"\nenter test cases:";
    cin>>c;
    while(c--)
    {
        ll a,b,k;
        cout<<"\nenter a,b and k:";
        cin>>a>>b>>k;
        string str2=to_string(b);
        memset(dp,-1,sizeof(dp));
        ll ans2=G(str2,k);

        memset(dp,-1,sizeof(dp));
        a=a-1;
        string str1=to_string(a);
        ll ans1=G(str1,k);
        cout<<"\n no of intergers= "<<ans2-ans1;
    }
    return 0;
}
