#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void difusebomb(lli arr[],int key,lli n)
{
    lli temp=n;
    lli output[n]={0};
    int start=0;

    if(key>0)
    {
        while(temp--)
       {
           lli sum=0;
           for(int i=start;i<(start+key);i++)
            {
             sum=sum+arr[((i+1)%n)];
            }
           output[start]=sum;
           start++;
       }
    }
    else
    {
        while(temp--)
        {
            lli sum=0;
            for(int i=start;i>(start+key);i--)
            {
                sum=sum+ arr[(i-1+n)%n];
            }
            output[start]=sum;
            start++;
        }
    }
   for(lli i=0;i<n;i++)
    cout<<output[i]<<" ";
}
int main()
{
    lli n;
    cout<<"\nenter size of array:";
    cin>>n;
    lli  arr[n];
    cout<<"\nprint array:";
    for(lli i=0;i<n;i++)
     cin>>arr[i];

    int key;
    cout<<"\nenter key:";
    cin>>key;

    difusebomb(arr,key,n);
    return 0;
}
