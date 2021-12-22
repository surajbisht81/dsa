#include <bits/stdc++.h>
using namespace std;

void primefactor(int n)
{
    for(int i=2;i*i<=n;i++)
    {
       int cnt=0;
        if(n%i==0)
        {
          while(n%i==0)
          {
             n=n/i;
             cnt++;
          }
         cout<<i<<"^"<<cnt<<" ";
        }
    }
     if(n>1)
        cout<<n<<"^1";
}
int main()
{
    int n;
    cout<<"\nenter n:";
    cin>>n;
    primefactor(n);
    return 0;
}
