#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli long long int
#define REP(i,n) for(int i=0;i<2;i++)
lli arr[100],I[2][2],T[2][2];
void multiply(lli A[][2],lli B[][2])
{
    int res[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            res[i][j]=0;
            for(int k=0;k<2;k++)
            {
                res[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

   for(int i=0;i<2;i++)
       for(int j=0;j<2;j++)
        A[i][j]=res[i][j];
}
int fib(int a,int b,int n)
{
    if(n<=2)
        return arr[n];

    I[0][0]=I[1][1]=1;
    I[0][1]=I[1][0]=0;

    T[0][0]=0;
    T[0][1]=T[1][0]=T[1][1]=1;
    n=n-1;

    while(n)
    {
        if(n%2)
        {
            multiply(I,T);
            n--;
        }
        else
        {
            multiply(T,T);
            n/=2;
        }
    }
   for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      T[i][j]=I[i][j];

    lli Fn=a*T[0][0] +b*T[1][0];
    return Fn;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cout<<"\nenter first and second term :";
        cin>>a>>b;
        int n;
        cout<<"\nenter n:";
        cin>>n;
        cout<<"\nnth term is:"<<fib(a,b,n);
    }
    return 0;
}
