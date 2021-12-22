#include <bits/stdc++.h>
using namespace std;

/*int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int N,cnt=0,res=0;
       cin>>N;
       while(N>0)
       {
           res=N & 1;
           if(res==1)
            cnt++;
           N=N>>1;
       }
       cout<<cnt<<endl;
   }
}*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        int n;
        cin>>n;
        while(n>0)
        {
            n=n & (n-1);
            cnt++;
        }
        cout<<cnt<<endl;
    }
}
