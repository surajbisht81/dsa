#include <bits/stdc++.h>
using namespace std;
// this is efficient method with tc O(log n);
int power(int a,int n)
{
    int res=1;
    while(n)
    {
        if(n%2)
        {
            res=res*a;
            n--;
        }
        else
        {
            a=a*a;
            n=n/2;
        }
    }
    return res;
}
int main()
{
    int a,n;
  cout<<"\nenter base:";
  cin>>a;
  cout<<"\nenter power:";
  cin>>n;
  cout<<"\npower is:"<<power(a,n);
  return 0;
}
