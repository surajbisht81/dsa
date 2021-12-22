#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[10][10][2];
ll G(string str,ll pos=0,ll cnt=0,ll tight=1)
{
    if(pos==str.length())
    {
        if(cnt>0)
            return 1;
        else
            return 0;
    }
    if(dp[pos][cnt][tight]!=-1)
        return dp[pos][cnt][tight];
    else if(tight==1)
    {
        ll res=0;
        for(ll i=0;i<=str[pos]-'0';i++)
        {
            if(i==3 && str[pos]-'0'==3)
            {
                res+=G(str,pos+1,cnt+1,1);
            }
            else if(i==3 && str[pos]-'0'!=3)
            {
                res+=G(str,pos+1,cnt+1,0);
            }
            else if(i==str[pos]-'0')
               res+=G(str,pos+1,cnt,1);

            else
                res+=G(str,pos+1,cnt,0);
        }
        dp[pos][cnt][tight]=res;
        return res;
    }
    else
    {
        ll res=0;
        for(ll i=0;i<=9;i++)
        {
            if(i==3)
                res+=G(str,pos+1,cnt+1,0);
            else
                res+=G(str,pos+1,cnt,0);
        }
        dp[pos][cnt][tight]=res;
        return res;
    }
}
int main()
{
    ll c;
    cin>>c;
    while(c--)
    {
     ll l;
     cout<<"\ndistance shown by meter:";
     cin>>l;
     string str=to_string(l);
     memset(dp,-1,sizeof(dp));
     cout<<"\noriginal distance measured is="<<l-G(str);
    }
    return 0;
}
