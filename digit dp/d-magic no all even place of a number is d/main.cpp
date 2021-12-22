#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll dp[12][2];
bool check(string temp,ll d,ll m)
{
    int flag=0;
    for(ll i=0;i<temp.size();i++)
    {
        if(i%2!=0)
        {
            if(temp[i]!=d)
                flag=1;
        }
    }

    /*ll j=stoi(temp);
    if(j%m!=0)
        flag=1;*/

    return flag==0;
}
ll G(string str,ll m,ll d,ll pos=0,ll tight=1,string temp="")
{
    if(pos==str.length())
    {
        if(check(temp,d,m))
            return 1;
        else
            return 0;
    }

    if(dp[pos][tight]!=-1)
        return dp[pos][tight];

    else if(tight==1)
    {
        ll res=0;
        for(ll i=0;i<=str[pos];i++)
        {
            if(i==str[pos]-'0')
                res+=G(str,m,d,pos+1,1,temp+to_string(i));
            else
                res+=G(str,m,d,pos+1,0,temp+to_string(i));
        }
        dp[pos][tight]=res;
        return res;
    }
    else
    {
        ll res=0;
        for(ll i=0;i<=9;i++)
        {
            res+=G(str,m,d,pos+1,0,temp+to_string(i));
        }
        dp[pos][tight]=res;
        return res;
    }
}
int main()
{
   ll c;
   cin>>c;
   while(c--)
   {
       ll a,b,m,d;
       cout<<"\nenter a,b and m and d:";
       cin>>a>>b>>m>>d;

       memset(dp,-1,sizeof(dp));
       string str2=to_string(b);
       ll ans2=G(str2,m,d);

       memset(dp,-1,sizeof(dp));
       string str1=to_string(a);
       ll ans1=G(str1,m,d);

       cout<<"\n ans="<<ans2-ans1;
   }
   return 0;
}
