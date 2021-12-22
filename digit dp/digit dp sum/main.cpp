#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
int dp[10][80][2];

bool check(ll sum)
{
    for(auto i:prime)
    {
        if(i==sum)
            return 1;
    }
    return 0;
}
ll G(string str,ll pos=0,ll sum=0,ll tight=1)
{
      if(pos==str.length())
      {
          if(check(sum))
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
                res+=G(str,pos+1,sum+i,1);
              else
                res+=G(str,pos+1,sum+i,0);
          }
          dp[pos][sum][tight]=res;
          return res;
      }
     else
     {
         ll res=0;
         for(ll i=0;i<=9;i++)
         {
             res+=G(str,pos+1,sum+i,0);
         }
         dp[pos][sum][tight]=res;
          return res;
     }
}
int main()
{
    ll l,r;
    cout<<"\nenter l and r:";
    cin>>l>>r;

    l=l-1;
    memset(dp,-1,sizeof(dp));
    string str1=to_string(l);
    ll ans1=G(str1);
    memset(dp,-1,sizeof(dp));
    string str2=to_string(r);
    ll ans2=G(str2);

    cout<<"\n no of nos."<<ans2-ans1<<endl;
    return 0;
}
