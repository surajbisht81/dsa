#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    int res=1;
    for(int i=1;i*i<=b;i++)
     if(b%i==0)
     {
         int temp= a%i;
         if(temp==0)
            res=max(res,i);
         temp=a% (b/i);
         if(temp==0)
            res=max(res,b/i);
     }
     return res;
}
int main()
{
    int a,b;
    cout<<"\nenter a and b:";
    cin>>a>>b;
    cout<<"\n gcd ="<<gcd(a,b);
    return 0;
}
