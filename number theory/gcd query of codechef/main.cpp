#include <bits/stdc++.h>
#define lli long long int
using namespace std;
 lli pre[100005],suf[100005];
int gcd(int a,int b)
 {
     if(b==0)
        return a;
     return gcd(b,a%b);
 }
int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        int q;
        cin>>q;
        lli arr[n];
        for(lli i=1;i<=n;i++)
          cin>>arr[i];

        pre[0]=suf[n+1]=0;
        for(lli i=1;i<=n;i++)
            pre[i]= gcd(pre[i-1],arr[i]);

        for(lli i=n;i>=1;i--)
            suf[i]=gcd(suf[i+1],arr[i]);
        while(q--)
        {
         int l,r;
         cout<<"\nenter left and right query:";
         cin>>l>>r;
         cout<<gcd(pre[l-1],suf[r+1]);
        }
    }
    return 0;
}
