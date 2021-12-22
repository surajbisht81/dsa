#include <bits/stdc++.h>
using namespace std;
#define p 1000000007
#define lli long long int

lli f[1000001];

lli inverse_modulo(lli num,lli n)
{
    lli res=1;
    while(n)
    {
        if(n%2)
           res= (res*num)%p;

        n/=2;
        num=(num*num)%p;
    }
    return res;
}
lli C(int n,int k)
{
    if(n<k) return 0;

    lli res=f[n];
    res=(res*inverse_modulo(f[k],p-2))%p;
    res=(res*inverse_modulo(f[n-k],p-2))%p;
    return res;
}
int main()
{
    int n,k;
    cout<<"\nenter n and k:";
    cin>>n>>k;
    //first find factorial of all nos upto 10^6;
    f[0]=f[1]=1;

    for(int i=2;i<=1000000;i++)
        f[i]= (i*f[i-1])%p;

    cout<<"\nchoosing k from n are = "<<C(n,k);
    return 0;
}
