#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

ll dp[20][2];
bool check(string temp)
{
    ll n=stoi(temp);
    ll r=0,rev=0;
    while(n!=0)
    {
        r=n%10;
        rev=rev*10+r;
        n=n/10;
    }
    if(n==rev)
        return 1;
    else
        return 0;
}
ll G(string str,ll pos=0,ll tight=1,string temp="")
{
    if(pos==str.length())
    {
        if(check(temp))
        {
            cout<<temp<<endl;
            return 1;
        }
        else
            return 0;
    }
    if(dp[pos][tight]!=-1)
        return dp[pos][tight];

    else if(tight==1)
    {
        ll res=0;
        for(ll i=0;i<=str[pos]-'0';i++)
        {
            if(i==str[pos]-'0')
                res+=G(str,pos+1,1,temp+to_string(i));
            else
               res+=G(str,pos+1,0,temp+to_string(i));
        }
        dp[pos][tight]=res;
        return res;
    }

    else
    {
        ll res=0;
        for(ll i=0;i<=9;i++)
        {
            res+=G(str,pos+1,0,temp+to_string(i));
        }
        dp[pos][tight]=res;
        return res;
    }
}
int main()
{
    ll c;
    cin>>c;
    for(ll m=1;m<=c;m++)
     {
        ll i,j;
        cout<<"\nenter i and j:";
        cin>>i>>j;

        i=i-1;
        string str1=to_string(i);
        memset(dp,-1,sizeof(dp));
        ll ans1=G(str1);

        string str2=to_string(j);
        memset(dp,-1,sizeof(dp));
        ll ans2=G(str2);

        cout<<"Case "<<m<<":"<<abs(ans2-ans1)<<endl;
    }
    return 0;
}
