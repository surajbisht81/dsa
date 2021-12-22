#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
void primefactorize(int n)
{
    int maxn=1000000;
    for(int i=0;i<maxn;i++)
        arr[i]=-1;

    for(int i=2;i<=maxn;i++)
    {
        if(arr[i]==-1)
        for(int j=i;j<=maxn;j=j+i)
        {
           if(arr[j]==-1)
             arr[j]=i;
        }
    }
    while(n>1)
    {
        cout<<arr[n]<<"*";
        n=n/arr[n];
    }
}
int main()
{
    int n;
    cout<<"\nenter n:";
    cin>>n;
    primefactorize(n);
    return 0;
}
